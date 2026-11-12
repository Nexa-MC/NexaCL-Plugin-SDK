# Platform

Contract: `nexa.platform/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### Describe

`Empty -> PlatformDescription`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Query |
| Permission | `nexa.platform.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### OpenUri

`UriRef -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Mutation |
| Permission | `nexa.platform.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RevealFile

`FileRef -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Mutation |
| Permission | `nexa.platform.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Notify

`UINotification -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Mutation |
| Permission | `nexa.platform.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### ReadClipboard

`Empty -> ClipboardContent`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Query |
| Permission | `nexa.platform.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### WriteClipboard

`ClipboardContent -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Mutation |
| Permission | `nexa.platform.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### PickFile

`FilePick -> FileRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Operation |
| Permission | `nexa.platform.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### QueryPower

`Empty -> PowerState`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Query |
| Permission | `nexa.platform.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### QueryDisplay

`Empty -> Page<DisplayInfo>`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Query |
| Permission | `nexa.platform.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### QueryArchitecture

`Empty -> ArchitectureInfo`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Query |
| Permission | `nexa.platform.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

