# 贡献指南

需要 .NET 10、Python 3.12；C/Wasm 绑定需要 Clang 和 wasm-ld。
Beta 冻结 `contracts/abi100.json` 和 Bootstrap V1，不再直接追加方法或字段。
新增契约行为使用不可变 EXP_ID，遵循[契约演进](docs/zh-CN/guides/contract-evolution.md)，
运行 `python eng/verify_evolution.py --base <前一提交>`。同步更新文档、示例和测试，验证 NativeAOT。

SDK 只维护开发契约，执行、验证和业务适配属于 PluginSidecar，NexaCL 只提供通用宿主 ABI。
不要通过引用或复制 Host 实现让 SDK 失去独立性。文档以英文为主，主要入口保留简中。
