# DefinitionQuery

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Registry` | `QualifiedId` | Identity or revision in this model’s domain; preserve ownership and exact spelling. |
| `Id` | `QualifiedId` | Identity in this model’s domain. Use the identity issued or declared for this object, not a display name or filesystem path. |

## Used directly by

- [Definitions.Get](../definitions.md#get)

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
