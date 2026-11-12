# CatalogTranslationInput

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Project` | [`CatalogProject`](../models/catalogproject.md) | Structured CatalogProject value; follow its linked field contract. |
| `Locale` | `string` | Domain value named by this field; additional accepted values and bounds are determined by the operation and Host policy. |

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
