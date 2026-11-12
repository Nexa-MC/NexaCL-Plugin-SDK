# Predicates

Contract: `nexa.predicates/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### Register

`PredicateDefinition -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Registration |
| Permission | `nexa.predicates.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Evaluate

`PredicateRequest -> PredicateResult`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Query |
| Permission | `nexa.predicates.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Describe

`QualifiedRequest -> PredicateDefinition`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Query |
| Permission | `nexa.predicates.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

