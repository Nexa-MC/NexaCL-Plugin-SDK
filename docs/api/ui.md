# UI

Contract: `nexa.ui/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### RegisterPage

`UIPage -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Registration |
| Permission | `nexa.ui.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RegisterComponent

`UIComponent -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Registration |
| Permission | `nexa.ui.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RegisterContribution

`UIContribution -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Registration |
| Permission | `nexa.ui.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RegisterViewReplacement

`UIViewReplacement -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Registration |
| Permission | `nexa.ui.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RegisterNavigation

`UINavigation -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `11` |
| Kind | Registration |
| Permission | `nexa.ui.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RegisterCommand

`UICommand -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `12` |
| Kind | Registration |
| Permission | `nexa.ui.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RegisterShortcut

`UIShortcut -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `13` |
| Kind | Registration |
| Permission | `nexa.ui.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### ShowDialog

`UIDialog -> UIDialogRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `14` |
| Kind | Operation |
| Permission | `nexa.ui.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### CloseDialog

`EntityRequest -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `15` |
| Kind | Mutation |
| Permission | `nexa.ui.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Navigate

`UINavigateRequest -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `16` |
| Kind | Mutation |
| Permission | `nexa.ui.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Notify

`UINotification -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `17` |
| Kind | Mutation |
| Permission | `nexa.ui.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### PublishModel

`UIModelUpdate -> StateSnapshot`

| Property | Contract |
| --- | --- |
| SDK method ID | `18` |
| Kind | Mutation |
| Permission | `nexa.ui.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### UpdateModel

`UIModelUpdate -> StateSnapshot`

| Property | Contract |
| --- | --- |
| SDK method ID | `19` |
| Kind | Mutation |
| Permission | `nexa.ui.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### WatchViewLifecycle

`UIViewWatch -> SubscriptionRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `20` |
| Kind | Subscription |
| Permission | `nexa.ui.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Read bounded batches, handle resynchronization and release the subscription before retirement. Respect cancellation and the caller budget.

### ListExtensionTargets

`PageRequest -> Page<UIViewContract>`

| Property | Contract |
| --- | --- |
| SDK method ID | `21` |
| Kind | Query |
| Permission | `nexa.ui.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### DescribeViewContract

`QualifiedRequest -> UIViewContract`

| Property | Contract |
| --- | --- |
| SDK method ID | `22` |
| Kind | Query |
| Permission | `nexa.ui.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### CreateDrawingSurface

`DrawingSurfaceRequest -> DrawingSurfaceRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `23` |
| Kind | Operation |
| Permission | `nexa.ui.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### SubmitDrawCommands

`DrawSubmission -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `24` |
| Kind | Mutation |
| Permission | `nexa.ui.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### SubscribeInput

`InputSubscription -> SubscriptionRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `25` |
| Kind | Subscription |
| Permission | `nexa.ui.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Read bounded batches, handle resynchronization and release the subscription before retirement. Respect cancellation and the caller budget.

