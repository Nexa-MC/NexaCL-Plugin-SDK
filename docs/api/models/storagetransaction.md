# StorageTransaction

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Token` | `Guid` | Opaque Host-issued handle token. Keep it with its owner and resource type. |
| `Namespace` | [`StorageNamespace`](../models/storagenamespace.md) | Private storage namespace identity or handle. It remains subject to current-load ownership. |
| `Revision` | `Revision` | Opaque version token issued by the owner. Do not increment it or substitute another object’s revision. |

## Used directly by

- [Storage.BeginTransaction](../storage.md#begintransaction)

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
