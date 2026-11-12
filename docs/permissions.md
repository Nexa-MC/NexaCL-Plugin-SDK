# Permissions, ownership and confirmation

A plugin manifest requests permissions. The Host decides which are granted.
Negotiating a contract, constructing a typed wrapper and requesting a permission
are separate steps. `RequiredCapabilities` can reject loading; optional contracts
must be tested before use. Permission revocation invalidates cached access too.

Every operation's exact permission and legal phases appear in the generated API
reference. Queries cannot be used to smuggle nested mutations through a provider
callback. Initialize/PostInitialize/Checkup/Finalize operate on staged state;
activation publishes the dependency group atomically. Do not store stage tokens
for later Active calls.

IDs, revisions, cursors, file grants, subscriptions and registrations are opaque.
They are not filesystem paths, integers to increment or tokens to copy between
plugins. Ownership includes the admitted load instance, not just the plugin ID.
A stopped plugin must release local views and stop issuing calls. The Host retires
its resources and cancels retained work.

For a destructive or externally visible operation, first request a preview/plan.
Show the Host-owned confirmation, then execute the exact plan and expected
revision. The Host rechecks state after confirmation. Reusing a consumed plan,
changing its inputs or carrying it across a load is an error. Do not retry an
ambiguous effect with a fresh idempotency key: first inspect its operation record.

Files require explicit grants. A displayed path does not confer access to siblings
or parents. URL, process and account operations remain subject to their domain
policies. Account credentials and bearer tokens are not returned as public account
metadata. Logs and diagnostics must not persist private tokens or grants.

## 简体中文

声明、授权和能力协商是三件事。文件、账户、计划、游标和订阅都受当前插件与加载实例约束。
修改操作遵循“预览—宿主确认—按版本执行”，不能自行绕过确认或重放不确定的副作用。
