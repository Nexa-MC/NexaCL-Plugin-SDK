# Diagnostics

Contract: `nexa.diagnostics/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### Log

`DiagnosticReport -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Mutation |
| Permission | `nexa.diagnostics.write` |
| Legal phases | PreInitialize, Initialize, PostInitialize, Checkup, Finalize, Active, Abort, Stop |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Report

`DiagnosticReport -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Mutation |
| Permission | `nexa.diagnostics.write` |
| Legal phases | PreInitialize, Initialize, PostInitialize, Checkup, Finalize, Active, Abort, Stop |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### CreateSpan

`DiagnosticSpan -> SpanRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Mutation |
| Permission | `nexa.diagnostics.write` |
| Legal phases | PreInitialize, Initialize, PostInitialize, Checkup, Finalize, Active, Abort, Stop |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### ReadOwnReports

`PageRequest -> Page<DiagnosticReport>`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Query |
| Permission | `nexa.diagnostics.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

