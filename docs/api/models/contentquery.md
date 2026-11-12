# ContentQuery

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Instance` | `EntityId` | Identity or revision in this model’s domain; preserve ownership and exact spelling. |
| `Kind` | `QualifiedId?` | Identity or revision in this model’s domain; preserve ownership and exact spelling. Nullable; omission is distinct from an empty value. No implicit default is promised by this type. |
| `Page` | [`PageRequest`](../models/pagerequest.md) | Structured PageRequest value; follow its linked field contract. |

## Used directly by

- [Minecraft.Content.List](../minecraft-content.md#list)

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
