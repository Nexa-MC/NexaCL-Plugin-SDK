# Tasks

Contract: `nexa.tasks/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### CreateOwned

`TaskCreate -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Mutation |
| Permission | `nexa.tasks.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Report

`TaskProgress -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Mutation |
| Permission | `nexa.tasks.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Complete

`TaskCompletion -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Mutation |
| Permission | `nexa.tasks.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Fail

`TaskFailure -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Mutation |
| Permission | `nexa.tasks.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### List

`PageRequest -> Page<OperationRecord>`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Query |
| Permission | `nexa.tasks.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Read

`EntityRequest -> OperationRecord`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Query |
| Permission | `nexa.tasks.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Watch

`WatchRequest -> SubscriptionRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Subscription |
| Permission | `nexa.tasks.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Read bounded batches, handle resynchronization and release the subscription before retirement. Respect cancellation and the caller budget.

### Cancel

`OperationRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Mutation |
| Permission | `nexa.tasks.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Retry

`OperationRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Mutation |
| Permission | `nexa.tasks.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Dismiss

`EntityRequest -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Mutation |
| Permission | `nexa.tasks.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

