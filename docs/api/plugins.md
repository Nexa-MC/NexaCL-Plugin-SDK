# Plugins

Contract: `nexa.interplugin/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### ExportService

`ServiceDefinition -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Registration |
| Permission | `nexa.interplugin.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### DescribeService

`ServiceLookup -> PublicContract`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Query |
| Permission | `nexa.interplugin.read` |
| Legal phases | PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### BindService

`ServiceLookup -> ServiceBinding`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Registration |
| Permission | `nexa.interplugin.write` |
| Legal phases | PostInitialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### ProbeService

`ServiceProbe -> ValidationReport`

| Property | Contract |
| --- | --- |
| SDK method ID | `11` |
| Kind | Query |
| Permission | `nexa.interplugin.read` |
| Legal phases | Checkup |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### CallService

`ServiceCall -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `12` |
| Kind | Operation |
| Permission | `nexa.interplugin.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### WatchAvailability

`ServiceLookup -> SubscriptionRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `13` |
| Kind | Subscription |
| Permission | `nexa.interplugin.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Read bounded batches, handle resynchronization and release the subscription before retirement. Respect cancellation and the caller budget.

### ReleaseBinding

`ServiceBinding -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `14` |
| Kind | Mutation |
| Permission | `nexa.interplugin.write` |
| Legal phases | PostInitialize, Active, Stop |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### ReadOwnLoadReport

`Empty -> LoadReport`

| Property | Contract |
| --- | --- |
| SDK method ID | `15` |
| Kind | Query |
| Permission | `nexa.interplugin.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

