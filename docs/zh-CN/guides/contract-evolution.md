# Beta 之后如何演进插件契约

SDK `0.2.0-beta.1` 冻结 Bootstrap V1、ABI 100 的 358 个操作、数据模型和 22 个保留的历史槽位。
冻结对象包括字段、编号、schema、权限、调用阶段、错误和副作用。升级 SDK 包版本不意味着可以更改这些契约。

## 何时分配 EXP_ID

新增能力、操作、字段或可观察行为均分配新的 EXP_ID，即使它在源代码层面看似兼容。
恢复文档所承诺行为的实现修复、文字纠正和构建工具调整不需要人为分配实验 ID；
修改说明中应说明理由，并提供回归验证。

插件 SDK 由 PluginSidecar 实现。NexaCL 只通过通用 Sidecar ABI 提供宿主能力，
不为插件 SDK 的方法逐项编写适配。实验能力不得让宿主反向依赖插件 SDK。
新增通用宿主能力遵循宿主 ABI 自己的兼容规则。

## 注册与验证

1. 用 `python -c "import uuid; print(uuid.uuid4())"` 生成新的 UUID，永不复用。
2. 新建 `contracts/experiments/<EXP_ID>.json`，包含 `expId`、`baseAbi: 100`、
   唯一的 `nexa.experimental.*` 契约名、`operations` 和 `semantics`。完整描述输入输出、
   权限、阶段、取消、错误、资源归属和副作用。文件定义固定行为，不指向“最新版实现”。
3. 在 `contracts/evolution.json` 中登记 `expId`、`schema`、文件的 SHA-256（`sha256`）、
   `status: "experimental"` 和本地 Markdown 文档路径 `documentation`。
   强类型 SDK 包装、Sidecar 实现、文档和兼容测试一起提交。
4. 运行 `python eng/verify_evolution.py --base <前一提交>`，再执行生成代码检查、SDK、
   NativeAOT 和 guest 测试。发布前与上一公开版本比较。

初始注册表**没有已发布的实验能力**。校验器测试中的 UUID 仅为测试数据。
登记 ID 不代表实现已经存在，更不代表当前 Sidecar 已支持它。

## 协商和调用

在预初始化阶段调用 `GetExperimentABI(EXP_ID, options)`；成功后，把返回的
`ExperimentRef` 加入草稿，再执行 Make。随后通过最终上下文的
`GetExperiment<T>(EXP_ID)` 获取接口。C/Wasm 可用 `nx_has_experiment` 检查最终上下文，
并在调用选项中携带 `experiment_id`；这些函数本身不授予实验权限。

可选实验不可用时禁用相应功能；必需实验不可用时保留真实错误并停止加载。
不能改走稳定的 `GetAbility` 绕过实验协商。

## 永久兼容

公开的 EXP_ID 及 schema 不得删除或改变含义。不兼容行为使用新 ID。
未来合入新的稳定 ABI 时，原 ID、原行为以及执行它所需的基础 ABI 仍须保留，
可使用语义等价的适配器。转正只把状态改为 `promoted`，不删除原定义或悄悄重定向。

CI 校验冻结文件的摘要，并与前一 Git 修订比较实验注册表；同时修改契约和基线摘要
也会被拒绝。行为兼容仍需测试，摘要无法证明权限、取消和资源释放正确。
