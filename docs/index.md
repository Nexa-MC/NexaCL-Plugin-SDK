# SDK documentation

Read the quickstart first, then choose capabilities from the reference. Package
versions do not select an ABI implicitly and a generated wrapper does not grant
Host authority.

| Topic | Guide |
| --- | --- |
| First plugin and build requirements | [Quickstart](quickstart.md) |
| Loading, stages, negotiation, retirement | [Loading contract](loading-contract.md) |
| C/Wasm encoding and continuation calls | [Wasm SDK](wasm-sdk.md) |
| Permission and resource ownership | [Permissions](permissions.md) |
| Host operations, storage, events and workflows | [Runtime behavior](runtime-services.md) |
| Read provider envelopes and schemas | [Business providers](business-providers.md) |
| Every capability method | [API reference](api/index.md) |
| Every DTO and enumeration | [Models](api/models.md) |
| Available launcher mappings | [Host support](host-support.md) |
| Package layout and releases | [Packaging](packaging.md) |
| Failures and troubleshooting | [Errors](errors.md) |
| Legacy SDK and ABI migration | [Migration](migration.md) |
| Ownership and maintenance | [Architecture](architecture.md) |

## 简体中文

建议依次阅读入门、加载契约、权限、所需能力的 API 文档，再构建模板项目。
ABI 方法编号只属于 SDK 调度表，不是宿主二进制通信操作码。旧 PCL 插件不能通过换包名自动迁移。
