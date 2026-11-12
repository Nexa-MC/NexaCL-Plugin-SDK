# StorageKey

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Namespace` | [`StorageNamespace`](../models/storagenamespace.md) | Private storage namespace identity or handle. It remains subject to current-load ownership. |
| `Key` | `string` | Private entry key inside the supplied namespace. |

## Used directly by

- [Storage.Read](../storage.md#read)

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
