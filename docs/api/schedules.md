# Schedules

Contract: `nexa.schedules/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### Register

`ScheduleDefinition -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Registration |
| Permission | `nexa.schedules.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### List

`PageRequest -> Page<ScheduleState>`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Query |
| Permission | `nexa.schedules.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Enable

`QualifiedRequest -> ScheduleState`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Mutation |
| Permission | `nexa.schedules.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Disable

`QualifiedRequest -> ScheduleState`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Mutation |
| Permission | `nexa.schedules.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### TriggerNow

`QualifiedRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Operation |
| Permission | `nexa.schedules.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### ReadNextRun

`QualifiedRequest -> ScheduleState`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Query |
| Permission | `nexa.schedules.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

