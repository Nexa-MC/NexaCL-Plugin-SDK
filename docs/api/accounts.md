# Accounts

Contract: `nexa.accounts/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### List

`PageRequest -> Page<AccountPublic>`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Query |
| Permission | `nexa.accounts.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ReadPublic

`EntityRequest -> AccountPublic`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Query |
| Permission | `nexa.accounts.read` |
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
| Permission | `nexa.accounts.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Read bounded batches, handle resynchronization and release the subscription before retirement. Respect cancellation and the caller budget.

### Select

`EntityRequest -> AccountPublic`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Mutation |
| Permission | `nexa.accounts.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### BeginSignIn

`SignInRequest -> SignInChallenge`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Operation |
| Permission | `nexa.accounts.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### ContinueSignIn

`SignInContinue -> SignInChallenge`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Operation |
| Permission | `nexa.accounts.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### CancelSignIn

`EntityRequest -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Mutation |
| Permission | `nexa.accounts.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Refresh

`EntityRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Operation |
| Permission | `nexa.accounts.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### SignOut

`EntityRequest -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Mutation |
| Permission | `nexa.accounts.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Remove

`EntityRequest -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Mutation |
| Permission | `nexa.accounts.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### ReadLaunchEligibility

`EntityRequest -> LaunchEligibility`

| Property | Contract |
| --- | --- |
| SDK method ID | `11` |
| Kind | Query |
| Permission | `nexa.accounts.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### RequestLaunchGrant

`GrantRequest -> LaunchGrant`

| Property | Contract |
| --- | --- |
| SDK method ID | `12` |
| Kind | Operation |
| Permission | `nexa.accounts.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### ReadWardrobe

`EntityRequest -> Wardrobe`

| Property | Contract |
| --- | --- |
| SDK method ID | `13` |
| Kind | Query |
| Permission | `nexa.accounts.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### PreviewSkin

`SkinRequest -> BlobRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `14` |
| Kind | Query |
| Permission | `nexa.accounts.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### UploadSkin

`SkinRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `15` |
| Kind | Operation |
| Permission | `nexa.accounts.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### SetCape

`CapeSelection -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `16` |
| Kind | Operation |
| Permission | `nexa.accounts.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### RegisterProvider

`ProviderDescriptor -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `17` |
| Kind | Registration |
| Permission | `nexa.accounts.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

