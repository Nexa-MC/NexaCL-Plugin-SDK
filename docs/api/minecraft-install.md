# Minecraft.Install

Contract: `nexa.minecraft.install/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### ListGameVersions

`PageRequest -> Page<GameVersion>`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Query |
| Permission | `nexa.minecraft.install.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ListLoaderVersions

`LoaderVersionRequest -> Page<LoaderVersion>`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Query |
| Permission | `nexa.minecraft.install.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### InspectLocalInstaller

`FileRef -> InstallerInspection`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Query |
| Permission | `nexa.minecraft.install.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ReadDraft

`EntityRequest -> InstallDraft`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Query |
| Permission | `nexa.minecraft.install.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### UpdateDraft

`InstallDraftUpdate -> InstallDraft`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Mutation |
| Permission | `nexa.minecraft.install.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### ValidateDraft

`InstallDraft -> ValidationReport`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Query |
| Permission | `nexa.minecraft.install.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ResolvePlan

`InstallDraft -> InstallPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Query |
| Permission | `nexa.minecraft.install.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### PreviewPlan

`EntityRequest -> InstallPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Query |
| Permission | `nexa.minecraft.install.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ExecutePlan

`PlanRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Operation |
| Permission | `nexa.minecraft.install.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Cancel

`OperationRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Mutation |
| Permission | `nexa.minecraft.install.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### ListRecoveries

`PageRequest -> Page<RecoveryRecord>`

| Property | Contract |
| --- | --- |
| SDK method ID | `11` |
| Kind | Query |
| Permission | `nexa.minecraft.install.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ResumeRecovery

`EntityRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `12` |
| Kind | Operation |
| Permission | `nexa.minecraft.install.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### DiscardRecovery

`EntityRequest -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `13` |
| Kind | Mutation |
| Permission | `nexa.minecraft.install.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RegisterTemplate

`InstallTemplate -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `14` |
| Kind | Registration |
| Permission | `nexa.minecraft.install.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RegisterLoaderProvider

`ProviderDescriptor -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `15` |
| Kind | Registration |
| Permission | `nexa.minecraft.install.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

