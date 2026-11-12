# ServiceBinding

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Handle` | `ulong` | Domain value named by this field; additional accepted values and bounds are determined by the operation and Host policy. |
| `Provider` | `string` | Domain value named by this field; additional accepted values and bounds are determined by the operation and Host policy. |
| `ProviderLoadInstance` | `Guid` | Domain value named by this field; additional accepted values and bounds are determined by the operation and Host policy. |
| `Contract` | `QualifiedId` | Identity or revision in this model’s domain; preserve ownership and exact spelling. |
| `Version` | `ulong` | Domain value named by this field; additional accepted values and bounds are determined by the operation and Host policy. |

## Used directly by

- [Plugins.BindService](../plugins.md#bindservice)
- [Plugins.ReleaseBinding](../plugins.md#releasebinding)

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
