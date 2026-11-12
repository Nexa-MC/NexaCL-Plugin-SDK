# RootRequest

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Root` | [`RootRef`](../models/rootref.md) | Structured RootRef value; follow its linked field contract. |

## Used directly by

- [Minecraft.Instances.Discover](../minecraft-instances.md#discover)
- [Minecraft.Instances.RemoveRoot](../minecraft-instances.md#removeroot)
- [Minecraft.Java.Discover](../minecraft-java.md#discover)

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
