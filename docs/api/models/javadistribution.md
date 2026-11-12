# JavaDistribution

[Model index](../models.md) · [API index](../index.md).

This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.

| Field | Type | Meaning |
| --- | --- | --- |
| `Provider` | `QualifiedId` | Identity or revision in this model’s domain; preserve ownership and exact spelling. |
| `Version` | `string` | Domain value named by this field; additional accepted values and bounds are determined by the operation and Host policy. |
| `Architecture` | `string` | Domain value named by this field; additional accepted values and bounds are determined by the operation and Host policy. |
| `OperatingSystem` | `string` | Domain value named by this field; additional accepted values and bounds are determined by the operation and Host policy. |
| `Download` | [`DownloadPlan`](../models/downloadplan.md) | Structured DownloadPlan value; follow its linked field contract. |

For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.
