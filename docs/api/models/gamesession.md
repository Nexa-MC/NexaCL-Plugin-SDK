# GameSession

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Id` | `EntityId` | Identity in this model’s domain. Use the identity issued or declared for this object, not a display name or filesystem path. |
| `Instance` | `EntityId` | Identity or revision in this model’s domain; preserve ownership and exact spelling. |
| `StartedAt` | `DateTimeOffset` | Domain value named by this field; additional accepted values and bounds are determined by the operation and Host policy. |
| `Running` | `bool` | Domain value named by this field; additional accepted values and bounds are determined by the operation and Host policy. |

## Used directly by

- [Minecraft.Processes.ReadSession](../minecraft-processes.md#readsession)

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
