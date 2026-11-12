# DefinitionUpdate

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Definition` | [`Definition`](../models/definition.md) | Structured Definition value; follow its linked field contract. |
| `ExpectedRevision` | `Revision` | Revision observed before this change. Preserve it exactly; a mismatch requires re-reading and reconciling the target. |

## Used directly by

- [Definitions.UpdateOwned](../definitions.md#updateowned)

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
