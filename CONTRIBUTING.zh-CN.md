# 贡献指南

需要 .NET 10、Python 3.12；C/Wasm 绑定需要 Clang 和 wasm-ld。
修改 `contracts/abi100.json` 后重新生成代码，不手改生成文件。保持已有编号、字段和 schema 指纹；
真正的破坏性变化需要新契约或版本。同步更新 API 文档、示例和测试，并验证 NativeAOT。

SDK 只维护开发契约，执行和验证属于 PluginSidecar，业务接入属于 NexaCL。
不要通过引用或复制 Host 实现让 SDK 失去独立性。文档以英文为主，主要入口保留简中。
