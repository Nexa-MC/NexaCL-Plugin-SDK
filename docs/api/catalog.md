# Catalog

Contract: `nexa.catalog/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### ListProviders

`PageRequest -> Page<ProviderDescriptor>`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Query |
| Permission | `nexa.catalog.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### DescribeProvider

`QualifiedRequest -> ProviderDescriptor`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Query |
| Permission | `nexa.catalog.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### RegisterProvider

`ProviderDescriptor -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Registration |
| Permission | `nexa.catalog.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Search

`CatalogSearch -> Page<CatalogProject>`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Query |
| Permission | `nexa.catalog.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ReadProject

`ResourceRef -> CatalogProject`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Query |
| Permission | `nexa.catalog.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ListVersions

`CatalogVersionQuery -> Page<CatalogVersion>`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Query |
| Permission | `nexa.catalog.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ReadVersion

`ResourceVersionRef -> CatalogVersion`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Query |
| Permission | `nexa.catalog.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ReadChangelog

`ResourceVersionRef -> TextResult`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Query |
| Permission | `nexa.catalog.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ResolveFiles

`ResourceVersionRef -> Page<CatalogFile>`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Query |
| Permission | `nexa.catalog.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ResolveDependencies

`ResourceVersionRef -> Page<CatalogDependency>`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Query |
| Permission | `nexa.catalog.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ListFavorites

`PageRequest -> Page<CatalogProject>`

| Property | Contract |
| --- | --- |
| SDK method ID | `11` |
| Kind | Query |
| Permission | `nexa.catalog.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### SetFavorite

`FavoriteChange -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `12` |
| Kind | Mutation |
| Permission | `nexa.catalog.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### PlanInstall

`CatalogInstallRequest -> ContentPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `13` |
| Kind | Query |
| Permission | `nexa.catalog.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### PlanUpdate

`CatalogInstallRequest -> ContentPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `14` |
| Kind | Query |
| Permission | `nexa.catalog.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ExecutePlan

`PlanRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `15` |
| Kind | Operation |
| Permission | `nexa.catalog.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### RegisterCollection

`ResourceCollection -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `16` |
| Kind | Registration |
| Permission | `nexa.catalog.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### RegisterTranslationProvider

`ProviderDescriptor -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `17` |
| Kind | Registration |
| Permission | `nexa.catalog.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Not mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

