# Minecraft.Java

Contract: `nexa.minecraft.java/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### List

`PageRequest -> Page<JavaRuntime>`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Query |
| Permission | `nexa.minecraft.java.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Discover

`RootRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Operation |
| Permission | `nexa.minecraft.java.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Inspect

`FileRef -> JavaRuntime`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Query |
| Permission | `nexa.minecraft.java.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ReadRequirements

`EntityRequest -> JavaRequirements`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Query |
| Permission | `nexa.minecraft.java.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ResolveSelection

`JavaSelection -> JavaRuntime`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Query |
| Permission | `nexa.minecraft.java.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### SelectGlobal

`JavaSelection -> JavaRuntime`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Mutation |
| Permission | `nexa.minecraft.java.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### SelectForInstance

`JavaSelection -> JavaRuntime`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Mutation |
| Permission | `nexa.minecraft.java.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### ListDistributions

`PageRequest -> Page<JavaDistribution>`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Query |
| Permission | `nexa.minecraft.java.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### PrepareInstall

`JavaInstallRequest -> MutationPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Query |
| Permission | `nexa.minecraft.java.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Review the plan and execute its exact ID/revision through the corresponding commit operation. Respect cancellation and the caller budget.

### Install

`PlanRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Operation |
| Permission | `nexa.minecraft.java.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Remove

`EntityRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `11` |
| Kind | Operation |
| Permission | `nexa.minecraft.java.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### RegisterDistributionProvider

`ProviderDescriptor -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `12` |
| Kind | Registration |
| Permission | `nexa.minecraft.java.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### ListManagedDistributions

`PageRequest -> Page<ManagedJavaOffer>`

| Property | Contract |
| --- | --- |
| SDK method ID | `13` |
| Kind | Query |
| Permission | `nexa.minecraft.java.read` |
| Legal phases | Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### PrepareManagedInstall

`ManagedJavaInstallRequest -> MutationPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `14` |
| Kind | Query |
| Permission | `nexa.minecraft.java.read` |
| Legal phases | Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Review the plan and execute its exact ID/revision through the corresponding commit operation. Respect cancellation and the caller budget.

