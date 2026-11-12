# NexaCL 插件 SDK

[English](README.md) · [详细文档](https://docs.pcln.top/plugin-sdk/) · [模板仓库](https://github.com/Nexa-MC/NexaCL-Plugin-Template)

这是面向插件开发者、衍生启动器开发者和贡献者的独立公开 SDK 仓库，直接替代
原 `PCL-N-Plugin-SDK`，保留原有 Git 历史。新版使用 Bootstrap V1 和 ABI 100，
不再沿用 `PCL.N.Plugin.*` 的进程内注入接口；旧插件需要按迁移指南移植。

SDK 包含两个 NuGet 包、33 个能力分组、346 个类型化操作、245 个模型，以及同源生成的
C/Wasm 绑定和历史预览绑定。PluginSidecar 负责执行及准入，NexaCL 负责业务和确认界面。
普通插件使用无 imports 的 `nexa-wasm-1`；C# 示例展示加载契约，不表示启动器允许直接装载 CLR DLL。

## 开始开发

直接使用 [NexaCL-Plugin-Template](https://github.com/Nexa-MC/NexaCL-Plugin-Template)
创建仓库。自行构建本仓库需要 .NET 10、Python 3.12、Clang 和 wasm-ld：

```sh
dotnet build NexaCL-Plugin-SDK.slnx -c Release
python eng/generate_abi100.py --verify
python eng/build_wasm_sample.py --clang clang
dotnet run --project tests/Nexa.Plugin.Sdk.Tests -c Release --no-build
```

构建结果 `artifacts/wasm-sample/desktop.zip` 可在支持该契约的 NexaCL 开发版本中，
开启开发者模式后，通过插件管理页选择并审阅安装。参见[入门流程](docs/quickstart.md)、
[打包和分发](docs/packaging.md)、[宿主接入状态](docs/host-support.md)。

SDK 版本为 **0.2.0-alpha.12**，通过本仓库 GitHub Releases 提供固定版本开发包。
解压后将 `packages/` 添加为本地 NuGet 源，同时保留 nuget.org；这不代表已发布到 NuGet.org。
alpha.9 到本次拆仓保持 ABI 100 契约兼容；旧 PCL SDK 不具备二进制兼容性。

文档默认英文，主要入口提供简中。完整 API 文档逐项列出参数、结果、权限、阶段和幂等要求。
SDK 中存在接口不代表当前启动器已经接入；必须检查协商结果和结构化错误。

[贡献指南](CONTRIBUTING.zh-CN.md) · [迁移指南](docs/migration.md) · [许可证](LICENSE)
