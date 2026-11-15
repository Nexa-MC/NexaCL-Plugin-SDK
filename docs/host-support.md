# Host implementation snapshot

Use this page to distinguish a declared SDK operation from an implemented launcher
route. The recorded PluginSidecar runtime maps **358/358** ABI 100 operations.
**0 operations remain unmapped.**
Host revision: `42ad7a1a3c7279d1cbc093d765e87c98f3878fff`.
Runtime revision: `c455625aa99885044607c7b2fc160e41806d657a` in `Nexa-MC/PluginSidecar`.

ABI 100 mappings are owned by the independent PluginSidecar; NexaCL exposes generic native Sidecar services only. This records development source compatibility, not a shipped launcher Alpha or enabled production Market delivery.

## What the count means

A mapping still requires permission, legal phase, ownership, supported platform and
business preconditions. It does not promise complete provider families or every
option in a request. The SDK deliberately describes the complete catalog so
compatible Hosts can implement more routes. Older released Alphas can map fewer.

The current custom catalog provider supports seven read methods. Custom catalog
installation and favorites are not implied. Java providers use verified ZIP archives; managed Mojang offers use the separate
multi-file distribution path. Provider families, supported fields and budgets are
documented in the [business provider guide](business-providers.md).
Market acquisition, native consent, signed installation and offline recovery are
implemented in the separate native Sidecars. Production still requires the server
signing secret, reviewed publisher public pin, database migration and independently
published Sidecar images. SDK Beta availability does not imply that deployment is enabled.

## Before requiring a capability

Check the actual Host's negotiated capabilities, then handle per-call unavailability.
Make a nonessential feature optional and explain why its UI is unavailable. Do not
replace a failed operation with a successful empty result or a private implementation
that bypasses Host ownership. Source mappings are recorded in
`contracts/host-support.json`; update them only from implementation evidence.
The ABI catalog contains no per-Host status. The retained C/C# descriptor field
`HostBinding` has the neutral value `HostDefined` for compatibility; it is not
a runtime support flag.

## Gaps by capability group

No groups have unmapped operations in this Host revision.

## Unmapped operations

None in the recorded Host revision.

[API reference](api/index.md) · [Migration](migration.md)
