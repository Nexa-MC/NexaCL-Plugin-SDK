# Plugin loading contract — ABI v0.2

Design input: [v0.2 proposal](specifications/plugin-abi-v0.2.proposal.zh-CN.md).
The v0.1 proposal is retained as loading history where compatible. Host traffic
continues to use the existing NexaCL binary Sidecar ABI; no JSON framing or new
transport message IDs are introduced.
Local managed facades never cross that boundary; adapters send opaque handles
and explicit bounded data through reviewed upstream operations.

## Preview compatibility

The independent SDK starts at `0.2.0-alpha.10`. Extraction from alpha.9 preserves
existing ABI 100 operation numbers, model fields, schema fingerprints and Bootstrap
signatures. Package version, Bootstrap version and negotiated ABI version are
separate axes. Earlier v0.1 prototypes and legacy PCL.N.Plugin.* plugins must be
ported; the repository replacement does not make those binaries compatible.

## Unified context

`GetABIContext` returns a Draft `ABIContext`; Host-confirmed `MakeABIContext`
returns the final facade. `GetExpermentABI` retains its intentional spelling.
Requests must be positive multiples of 100 and never implicitly fall back.
`AbiReply<T>.Fail` carries a structured error and default value (null for local
facades, zero for opaque handles). Ready does not mean Active.

Bootstrap freezes only the generic context facade:

- `Info`: immutable identity, opaque handle, stable version, confirmed experiment
  and capability descriptions, permissions and session/permit information.
- `GetAbility(contractId)`: access an already confirmed capability.
- `GetExperiment(expId, contractId)`: access an interface belonging to an already
  confirmed experiment. Neither accessor negotiates, grants permission or calls Make.

Initialize, PostInitialize, Checkup and Finalize receive **the same final
ABIContext**, plus an independently issued StageContext. StageContext owns the
StageInvocationId, cancellation, budget and optional read-only CheckupInfo.
Its monotonic remaining budget starts when the local callback context is created;
creating another SDK view does not reset it. Abort can carry a null final context
when negotiation failed. Stop carries the original final context.

## ABI 100 SDK views

Use `abi.AsAbi100()` for runtime views and `abi.ForStage100(stage)` inside a load
callback. Both expose all 33 public capability groups, including the nine Minecraft subgroups.
`Experiments` exposes confirmed experimental views; `TryGet<T>` preserves missing
capability errors and `IsAvailable<T>` offers a convenience check.
`Abi100Draft.Require/Optional/Include` assembles immutable Make inputs.
Views lazily request exact contract IDs and preserve structured Host errors.
A different stable ABI is rejected, never silently upgraded. `GetExperiment<T>`
uses the static `IExperimentView<T>` ContractId/Create mapping; no reflection is
used. Saved experiment proxies recheck access before dispatch.

| Contract | Callable methods | Notes |
| --- | --- | --- |
| `nexa.events/100` | 1, 2, 4, 5 | Slot 3 reserved; no service export |
| `nexa.ui/100` | 1–6 | Existing UI methods |
| `nexa.interplugin/100` | 1–7 | ExportService = 6; Probe = 7 |
| `nexa.diagnostics/100` | 1–4 | Report, ReportFinding, QueryRegistrations, QueryBindingStatus |
| `nexa.resources/100` | 1 | RegisterCleanup |

These 22 historical methods keep their dispatch meaning. The v0.2 catalog adds
341 operations with typed requests and replies. Each entry records phase,
permission, idempotency and pending Host mapping. Contract IDs, schemas and
permissions are preview design choices until Host mapping is reviewed. Diagnostic source/ownership is assigned by Host.
The pre-Make `PreInitContext.Resources` port and post-Make `api.Resources` MUST
map to one instance resource table, preserving operation IDs and avoiding duplicate
cleanup. This SDK does not create another cleanup registry.

```csharp
public async ValueTask<AbiReply<CheckupResult>> OnCheckup(ABIContext abi, StageContext stage)
{
    using var api = abi.ForStage100(stage);
    var result = await api.Plugins.ReadOwnLoadReport(new Empty(),
        new(Guid.NewGuid(), stage.Budget, stage.Cancellation));
    return result.Success
        ? AbiReply<CheckupResult>.Ok(new(CheckupStatus.Passed, [], []))
        : AbiReply<CheckupResult>.Fail(result.Error!);
}
```

Dispose the stage view before returning. It attaches the stage invocation ID,
links cancellation and forwards the smaller remaining/caller budget. Saved proxies
from a disposed view fail with STAGE_FROZEN. Runtime views do not inherit stage IDs
or deadlines. This convenience is **not authorization**: callers can retain or
recreate StageContext and can call Bootstrap facades directly. The coordinator must
retire invocation IDs on callback completion; Host must reject stale IDs, wrong
phases, cross-instance access, expired contexts and missing permissions on every
call. It must also reject unconfirmed experiments through either accessor.

ExportService is valid in Initialize, Bind in PostInitialize, Probe in Checkup,
and ordinary Call in Active. Finalize cannot add registrations. Abort/Stop only
allow corresponding cleanup, unbinding and diagnostic operations. Merely retaining
`api.Plugins` must never broaden the allowed methods.

## Verification and remaining integration

Tests cover all 22 dispatch slots, reserved event slot exclusion, exact UInt64,
structured error propagation, lazy views, draft/unconfirmed experiment errors,
stage-ID forwarding and conflict rejection, disposed proxies, runtime budgets,
and a real in-memory sample using a private SDK against shared Bootstrap types.
The repository also contains a real local Host authority and coordinator. Tests
exercise exact Make admission, phase leases, timeout/idempotency handling,
required-dependency groups, hot-conflict stop closure, atomic publication and
instance-owned cleanup. A signed encrypted package is reopened offline and loaded
through either actual Wasmtime callbacks or a declarative entry. These tests use
the production kernel with explicit trusted schema policies, not fake route
replies. The separately labelled SDK tests still use test ports.

The Desktop composition, authenticated remote loading port, actual business
adapters and full proposal scenario matrix remain incomplete. No experimental
capabilities are currently offered; existing experiment IDs must gain retained
compatibility fixtures when implementations are added.

## v0.2 data and authority

`contracts/abi100.json` is the machine-readable source; generated source uses static
codecs over the closed Bootstrap value union. No reflection dispatcher or CLR
object serialization is added. The JSON catalog is build input, not IPC data.
`Snapshot<T>` includes revision, schema version and observation time. Pages carry
opaque cursors. Definitions in `DeclarativeContentPack` use the same `Definition`
as code registration; this does not introduce a second content-pack file format.

All methods require Host validation of schemas and effect-specific scopes.
Catalog `.read`/`.write` permissions identify draft capability families and are
not substitutes for target grants. An acquisition such as Storage.OpenNamespace
can only open the caller's already authorized namespace during initialization.
Network receive/stream operations consume external state and are Active-only.
No automatic retry is performed; uncertain external outcomes remain explicit.

`InvocationOptions` carries expected revision, idempotency key, correlation and
causation IDs. `AbiError` carries localized message parameters and operation ID.
The SDK facade does not implement durable idempotency or mutation-plan confirmation.
The Host kernel separately owns per-load replay, persistent workflow checkpoints
and the trusted action-confirmation port described in [runtime services](runtime-services.md).
Opaque FileRef/BlobRef and service bindings retain their load-instance identity.

OnActivated receives an InvocationContext only after atomic commit. It is not a
seventh loading stage. Events/workflow callbacks need their own invocation scope.
Raw CoreCLR development loading is not allowed as the production isolation
boundary. Service/provider descriptors, Java arguments and public launch profiles
must be checked against actual execution effects; a provider's own metadata is
not proof that it cannot delegate arbitrary native execution.
