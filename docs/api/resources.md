# Resources

Contract: `nexa.resources/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### RegisterCleanup

`CleanupRequest -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Registration |
| Permission | `nexa.resources.write` |
| Legal phases | PreInitialize, Initialize, PostInitialize, Checkup, Finalize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Release

`RegistrationRequest -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Mutation |
| Permission | `nexa.resources.write` |
| Legal phases | PreInitialize, Initialize, PostInitialize, Checkup, Finalize, Active, Abort, Stop |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### ReadSubscription

`SubscriptionRead -> SubscriptionBatch`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Mutation |
| Permission | `nexa.resources.read` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### ReleaseSubscription

`SubscriptionRef -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Mutation |
| Permission | `nexa.resources.write` |
| Legal phases | Active, Stop |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

