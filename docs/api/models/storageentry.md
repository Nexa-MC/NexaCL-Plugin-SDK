# StorageEntry

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Key` | `string` | Key within this model’s owning namespace or record. It does not grant access outside that owner. |
| `Value` | [`StorageValue`](../models/storagevalue.md) | Payload interpreted using the accompanying or declared schema; Null is not a substitute for an error. |

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
