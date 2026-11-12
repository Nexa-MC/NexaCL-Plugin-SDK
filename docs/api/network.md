# Network

Contract: `nexa.network/100`. [Capability index](index.md).

All calls return `AbiReply<T>`; inspect success before reading the value.
The Host verifies permission, lifecycle phase, ownership and business preconditions.
Mapped status records a development snapshot, not a promise for every released launcher.

### Request

`NetworkRequest -> NetworkResponse`

| Property | Contract |
| --- | --- |
| SDK method ID | `1` |
| Kind | Operation |
| Permission | `nexa.network.write` |
| Legal phases | Active |
| Idempotency | OutcomeMayBeUnknown |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### OpenResponseStream

`EntityRequest -> BlobRef`

| Property | Contract |
| --- | --- |
| SDK method ID | `2` |
| Kind | Operation |
| Permission | `nexa.network.write` |
| Legal phases | Active |
| Idempotency | OutcomeMayBeUnknown |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Cancel

`OperationRequest -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `3` |
| Kind | Mutation |
| Permission | `nexa.network.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### OpenConnection

`NetworkConnectionRequest -> NetworkConnection`

| Property | Contract |
| --- | --- |
| SDK method ID | `4` |
| Kind | Operation |
| Permission | `nexa.network.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Listen

`NetworkConnectionRequest -> NetworkConnection`

| Property | Contract |
| --- | --- |
| SDK method ID | `5` |
| Kind | Operation |
| Permission | `nexa.network.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

### Send

`NetworkSend -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `6` |
| Kind | Mutation |
| Permission | `nexa.network.write` |
| Legal phases | Active |
| Idempotency | OutcomeMayBeUnknown |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Receive

`NetworkReceive -> NetworkPacket`

| Property | Contract |
| --- | --- |
| SDK method ID | `7` |
| Kind | Operation |
| Permission | `nexa.network.write` |
| Legal phases | Active |
| Idempotency | OutcomeMayBeUnknown |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Respect cancellation and the caller budget.

### Close

`NetworkConnection -> Empty`

| Property | Contract |
| --- | --- |
| SDK method ID | `8` |
| Kind | Mutation |
| Permission | `nexa.network.write` |
| Legal phases | Active |
| Idempotency | RequiredKey |
| Host status | Mapped in recorded Host snapshot |

Input and output fields are defined in [models](models.md). Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. Respect cancellation and the caller budget.

