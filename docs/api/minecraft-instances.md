# Minecraft.Instances

Contract: `nexa.minecraft.instances/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### List

`InstanceListRequest -> Page<InstanceSummary>`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Query |
| Permission | `nexa.minecraft.instances.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Read

`EntityRequest -> InstanceDetails`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Query |
| Permission | `nexa.minecraft.instances.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Watch

`WatchRequest -> SubscriptionRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Subscription |
| Permission | `nexa.minecraft.instances.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Read bounded batches, handle resynchronization and release the subscription before retirement. Respect cancellation and the caller budget.

### Discover

`RootRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Operation |
| Permission | `nexa.minecraft.instances.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### ListRoots

`PageRequest -> Page<RootRegistration>`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Query |
| Permission | `nexa.minecraft.instances.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### AddRoot

`RootRegistration -> RootRegistration`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Mutation |
| Permission | `nexa.minecraft.instances.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RemoveRoot

`RootRequest -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Mutation |
| Permission | `nexa.minecraft.instances.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### PrepareCreate

`InstanceCreateRequest -> MutationPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Query |
| Permission | `nexa.minecraft.instances.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Review the plan and execute its exact ID/revision through the corresponding commit operation. Respect cancellation and the caller budget.

### CommitCreate

`PlanRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Operation |
| Permission | `nexa.minecraft.instances.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Select

`EntityRequest -> InstanceSummary`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Mutation |
| Permission | `nexa.minecraft.instances.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Rename

`InstanceRenameRequest -> InstanceSummary`

| Property | Contract |
| --- | --- |
| SDK method ID | `11` |
| Kind | Mutation |
| Permission | `nexa.minecraft.instances.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### PrepareClone

`InstanceCloneRequest -> MutationPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `12` |
| Kind | Query |
| Permission | `nexa.minecraft.instances.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Review the plan and execute its exact ID/revision through the corresponding commit operation. Respect cancellation and the caller budget.

### CommitClone

`PlanRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `13` |
| Kind | Operation |
| Permission | `nexa.minecraft.instances.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### PrepareDelete

`InstanceDeleteRequest -> MutationPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `14` |
| Kind | Query |
| Permission | `nexa.minecraft.instances.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Review the plan and execute its exact ID/revision through the corresponding commit operation. Respect cancellation and the caller budget.

### CommitDelete

`PlanRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `15` |
| Kind | Operation |
| Permission | `nexa.minecraft.instances.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### ReadIdentity

`EntityRequest -> InstanceSummary`

| Property | Contract |
| --- | --- |
| SDK method ID | `16` |
| Kind | Query |
| Permission | `nexa.minecraft.instances.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ReadEffectiveSettings

`EntityRequest -> Page<EffectiveSetting>`

| Property | Contract |
| --- | --- |
| SDK method ID | `17` |
| Kind | Query |
| Permission | `nexa.minecraft.instances.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### OpenDirectory

`EntityRequest -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `18` |
| Kind | Mutation |
| Permission | `nexa.minecraft.instances.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

