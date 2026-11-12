# Business provider callbacks

SDK `0.2.0-alpha.10` adds `BusinessProviderCall` without changing existing
operation IDs, `ProviderDescriptor`, or model fingerprints. A Host must explicitly
implement each provider family. Registering a descriptor does not create a generic
permission to intercept arbitrary launcher operations.

A read provider registers a callback in `OnPreInitialize` and submits its descriptor
during `OnInitialize`. Set `SchemaHash` to
`Abi100Schemas.BusinessProviderCall.Digest`, `Configuration` to
`Abi100Schemas.Empty`, `ContractVersion` to `100`, and `SupportedScopes` to
`["application"]`. The ID belongs to the plugin's namespace; built-in IDs cannot
be replaced. Capabilities are exact method names from the Host's documented table.

The callback decodes `BusinessProviderCall`, checks its `Kind`, `Method`,
`InputSchema` and `OutputSchema`, decodes `Inputs` using the stated model, and
returns the encoded output model directly. Page results use generated helpers such
as `Abi100Schemas.PageOfCatalogProject`. Do not return another envelope.

The current read-provider boundary supports `ExplicitRequest` selection and
`Queue`, `RejectDuplicate`, or `Parallel` concurrency. Parallel execution is
bounded to four active calls; queued admission is bounded to 32. The descriptor's
1–30000 ms deadline includes queue time and is capped by the caller's budget.
Cancellation propagates from both caller and provider retirement. The registration
cannot be released while a callback holds it. Nested Host mutations are rejected.

`FailOperation` retains a callback's error code. `Unavailable` maps failed callback
replies to `PROVIDER_UNAVAILABLE`. Invalid output still fails schema validation.
`RetryBounded` and `ReplacePending` are rejected until a family defines their exact
semantics. A caller must not infer retry safety from an error.

Providers remain invisible until atomic activation and disappear on stop/abort.
The Host validates the result's schema and must additionally validate domain
identity, scope, pagination and provenance before consuming it.

## 简体中文

alpha.9 新增业务 Provider 回调信封及集合 schema，已有 ABI 保持兼容。
插件在预初始化时注册回调、初始化时注册描述符；只有宿主已接入的业务族可用。
回调接收 `BusinessProviderCall`，按指定 schema 解码输入并直接返回类型化结果。
注册在激活后可见，退出时取消在途调用。查询回调不能执行宿主修改操作。
并发、排队和超时均有上限；重试及替换等待任务策略暂不接受。
