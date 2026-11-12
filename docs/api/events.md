# Events

Contract: `nexa.events/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### Describe

`QualifiedRequest -> EventDescriptor`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Query |
| Permission | `nexa.events.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Subscribe

`EventSubscribeRequest -> SubscriptionRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Registration |
| Permission | `nexa.events.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Read bounded batches, handle resynchronization and release the subscription before retirement. Respect cancellation and the caller budget.

### Define

`EventDescriptor -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Registration |
| Permission | `nexa.events.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Publish

`EventEnvelope -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Mutation |
| Permission | `nexa.events.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Unsubscribe

`RegistrationRequest -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Mutation |
| Permission | `nexa.events.write` |
| Legal phases | Active, Stop |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### UnsubscribeSubscription

`SubscriptionRef -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `11` |
| Kind | Mutation |
| Permission | `nexa.events.write` |
| Legal phases | Active, Stop |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RegisterSubscription

`EventSubscribeRequest -> EventSubscriptionRegistration`

| Property | Contract |
| --- | --- |
| SDK method ID | `12` |
| Kind | Registration |
| Permission | `nexa.events.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

