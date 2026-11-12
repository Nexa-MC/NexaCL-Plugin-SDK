# Minecraft.Worlds

Contract: `nexa.minecraft.worlds/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### List

`EntityRequest -> Page<WorldSummary>`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Query |
| Permission | `nexa.minecraft.worlds.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Read

`EntityRequest -> WorldSummary`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Query |
| Permission | `nexa.minecraft.worlds.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ReadMetadata

`EntityRequest -> WorldMetadata`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Query |
| Permission | `nexa.minecraft.worlds.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Copy

`WorldCopyRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Operation |
| Permission | `nexa.minecraft.worlds.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Rename

`WorldRenameRequest -> WorldSummary`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Mutation |
| Permission | `nexa.minecraft.worlds.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### PlanDelete

`EntityRequest -> MutationPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Query |
| Permission | `nexa.minecraft.worlds.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Review the plan and execute its exact ID/revision through the corresponding commit operation. Respect cancellation and the caller budget.

### ListDataPacks

`EntityRequest -> Page<ContentItem>`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Query |
| Permission | `nexa.minecraft.worlds.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### PlanSetDataPack

`DataPackSelection -> MutationPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Query |
| Permission | `nexa.minecraft.worlds.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Review the plan and execute its exact ID/revision through the corresponding commit operation. Respect cancellation and the caller budget.

### ApplyDataPackPlan

`PlanRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Operation |
| Permission | `nexa.minecraft.worlds.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Backup

`EntityRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Operation |
| Permission | `nexa.minecraft.worlds.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### PreviewRestore

`BackupRestore -> MutationPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `11` |
| Kind | Query |
| Permission | `nexa.minecraft.worlds.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Review the plan and execute its exact ID/revision through the corresponding commit operation. Respect cancellation and the caller budget.

### Restore

`PlanRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `12` |
| Kind | Operation |
| Permission | `nexa.minecraft.worlds.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### ReadHealth

`EntityRequest -> IntegrityReport`

| Property | Contract |
| --- | --- |
| SDK method ID | `13` |
| Kind | Query |
| Permission | `nexa.minecraft.worlds.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

