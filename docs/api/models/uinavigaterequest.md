# UINavigateRequest

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Page` | `QualifiedId` | Identity or revision in this model’s domain; preserve ownership and exact spelling. |
| `Arguments` | `AbiValue` | Domain value named by this field; additional accepted values and bounds are determined by the operation and Host policy. |

## Used directly by

- [UI.Navigate](../ui.md#navigate)

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
