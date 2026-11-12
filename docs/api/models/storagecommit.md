# StorageCommit

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Transaction` | [`StorageTransaction`](../models/storagetransaction.md) | Structured StorageTransaction value; follow its linked field contract. |
| `Writes` | [`StorageWrite[]`](../models/storagewrite.md) | Structured StorageWrite value; follow its linked field contract. A bounded collection; do not assume an unbounded result or unspecified ordering. |

## Used directly by

- [Storage.Commit](../storage.md#commit)

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
