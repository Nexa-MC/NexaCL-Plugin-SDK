# Files

Contract: `nexa.files/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### Pick

`FilePick -> FileRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Operation |
| Permission | `nexa.files.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### List

`FileQuery -> Page<FileStat>`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Query |
| Permission | `nexa.files.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Stat

`FileRef -> FileStat`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Query |
| Permission | `nexa.files.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Read

`FileRead -> BlobRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Query |
| Permission | `nexa.files.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### WriteAtomic

`FileWrite -> FileStat`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Mutation |
| Permission | `nexa.files.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Watch

`FileRef -> SubscriptionRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Subscription |
| Permission | `nexa.files.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Read bounded batches, handle resynchronization and release the subscription before retirement. Respect cancellation and the caller budget.

### PrepareMove

`FileMove -> MutationPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Query |
| Permission | `nexa.files.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Review the plan and execute its exact ID/revision through the corresponding commit operation. Respect cancellation and the caller budget.

### Move

`PlanRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Operation |
| Permission | `nexa.files.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### PrepareDelete

`FileDelete -> MutationPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Query |
| Permission | `nexa.files.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Review the plan and execute its exact ID/revision through the corresponding commit operation. Respect cancellation and the caller budget.

### Delete

`PlanRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Operation |
| Permission | `nexa.files.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### OpenPackageFile

`PackageFileRequest -> FileRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `11` |
| Kind | Query |
| Permission | `nexa.files.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

