# ContentInspectionRequest

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Provider` | `QualifiedId` | Identity or revision in this model’s domain; preserve ownership and exact spelling. |
| `File` | [`FileRef`](../models/fileref.md) | Structured FileRef value; follow its linked field contract. |

## Used directly by

- [Minecraft.Content.InspectWithProvider](../minecraft-content.md#inspectwithprovider)

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
