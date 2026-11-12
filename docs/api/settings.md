# Settings

Contract: `nexa.settings/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### RegisterSchema

`SettingSchema -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Registration |
| Permission | `nexa.settings.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RegisterPage

`UIPage -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Registration |
| Permission | `nexa.settings.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Get

`SettingQuery -> StateSnapshot`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Query |
| Permission | `nexa.settings.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### GetEffective

`SettingQuery -> EffectiveSetting`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Query |
| Permission | `nexa.settings.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Watch

`SettingQuery -> SubscriptionRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Subscription |
| Permission | `nexa.settings.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Read bounded batches, handle resynchronization and release the subscription before retirement. Respect cancellation and the caller budget.

### PreviewChange

`SettingChange -> MutationPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Query |
| Permission | `nexa.settings.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Review the plan and execute its exact ID/revision through the corresponding commit operation. Respect cancellation and the caller budget.

### Apply

`PlanRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Operation |
| Permission | `nexa.settings.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Reset

`SettingQuery -> StateSnapshot`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Mutation |
| Permission | `nexa.settings.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Migrate

`SettingMigration -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Operation |
| Permission | `nexa.settings.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### ListProfiles

`PageRequest -> Page<SettingsProfile>`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Query |
| Permission | `nexa.settings.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### SaveProfile

`SettingsProfile -> SettingsProfile`

| Property | Contract |
| --- | --- |
| SDK method ID | `11` |
| Kind | Mutation |
| Permission | `nexa.settings.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### SelectProfile

`EntityRequest -> SettingsProfile`

| Property | Contract |
| --- | --- |
| SDK method ID | `12` |
| Kind | Mutation |
| Permission | `nexa.settings.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### BeginTemporaryOverlay

`SettingsOverlay -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `13` |
| Kind | Mutation |
| Permission | `nexa.settings.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### EndTemporaryOverlay

`RegistrationRequest -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `14` |
| Kind | Mutation |
| Permission | `nexa.settings.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

