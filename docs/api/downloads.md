# Downloads

Contract: `nexa.downloads/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### Resolve

`DownloadPlan -> DownloadPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Query |
| Permission | `nexa.downloads.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Start

`DownloadPlan -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Operation |
| Permission | `nexa.downloads.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Read

`EntityRequest -> DownloadState`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Query |
| Permission | `nexa.downloads.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Watch

`WatchRequest -> SubscriptionRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Subscription |
| Permission | `nexa.downloads.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Read bounded batches, handle resynchronization and release the subscription before retirement. Respect cancellation and the caller budget.

### Pause

`OperationRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Mutation |
| Permission | `nexa.downloads.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Resume

`OperationRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Mutation |
| Permission | `nexa.downloads.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Cancel

`OperationRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Mutation |
| Permission | `nexa.downloads.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Verify

`EntityRequest -> IntegrityReport`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Query |
| Permission | `nexa.downloads.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### RegisterSourceResolver

`ProviderDescriptor -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Registration |
| Permission | `nexa.downloads.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RegisterTransferProvider

`ProviderDescriptor -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Registration |
| Permission | `nexa.downloads.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

