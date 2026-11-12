# Workflows

Contract: `nexa.workflows/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### Register

`WorkflowDefinition -> RegistrationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Registration |
| Permission | `nexa.workflows.write` |
| Legal phases | Initialize |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Validate

`WorkflowDefinition -> ValidationReport`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Query |
| Permission | `nexa.workflows.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Preview

`WorkflowRequest -> MutationPlan`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Query |
| Permission | `nexa.workflows.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Review the plan and execute its exact ID/revision through the corresponding commit operation. Respect cancellation and the caller budget.

### Start

`WorkflowRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Operation |
| Permission | `nexa.workflows.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### Read

`EntityRequest -> OperationRecord`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Query |
| Permission | `nexa.workflows.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Watch

`WatchRequest -> SubscriptionRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Subscription |
| Permission | `nexa.workflows.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Read bounded batches, handle resynchronization and release the subscription before retirement. Respect cancellation and the caller budget.

### Cancel

`OperationRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Mutation |
| Permission | `nexa.workflows.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### ListRuns

`PageRequest -> Page<OperationRecord>`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Query |
| Permission | `nexa.workflows.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Resume

`WorkflowRunRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `9` |
| Kind | Operation |
| Permission | `nexa.workflows.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### RetryStep

`WorkflowStepRequest -> OperationRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `10` |
| Kind | Operation |
| Permission | `nexa.workflows.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Track the returned operation through Tasks; admission is not completion. Respect cancellation and the caller budget.

### ExplainPlan

`WorkflowRequest -> ValidationReport`

| Property | Contract |
| --- | --- |
| SDK method ID | `11` |
| Kind | Query |
| Permission | `nexa.workflows.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### ReadRunTrace

`EntityRequest -> WorkflowTrace`

| Property | Contract |
| --- | --- |
| SDK method ID | `12` |
| Kind | Query |
| Permission | `nexa.workflows.read` |
| Legal phases | Initialize, PostInitialize, Checkup, Finalize, Active |
| Idempotency | ReadOnly |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

