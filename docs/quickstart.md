# Build a first plugin

## Choose the executable profile

Use the `wasm/` project in NexaCL-Plugin-Template for an executable Desktop plugin.
The C# contract example is for developers implementing or testing Bootstrap-facing
code; it does not bypass the production Wasm admission policy. A plugin executes
in an isolated Sidecar and calls the Host through the existing binary protocol.

## Build from this repository

Install .NET SDK 10, Python 3.12 and Clang with `wasm-ld`. On Debian/Ubuntu the C
compiler prerequisites are supplied by `clang` and `lld`. A WASI SDK Clang is also
accepted, but these examples explicitly select `wasm32-unknown-unknown`, disable
imports and link without WASI or the C standard library.

Run the README commands. `eng/build_wasm_sample.py` produces deterministic ZIPs:

| Output | Behavior |
| --- | --- |
| `plugin.zip` | Register a definition during initialization |
| `desktop.zip` | Register a plugin page and an action; read scoped launcher state |
| `advanced.zip` | Verified page/component assets, dialog fields and contributions |
| `workflow.zip` | Exercise an owned workflow through Host capabilities |

## Install and observe

Use a development build whose Host support matches the plugin's required
contracts. Enable developer mode and open plugin management. Select the ZIP,
review its manifest, digest and permissions, and choose one-time loading or saved
admission where offered. Saved local packages remain subject to developer-mode
checks at restart. Inspect load findings if negotiation or Checkup fails.

Do not edit a ZIP after computing its payload hashes. Rebuild it and review the
new bytes. A changed plugin ID creates a different ownership namespace; do not
reuse another author's ID to gain access to their storage or handles.

## Modify the example

Change the plugin ID consistently in the manifest and qualified registration IDs.
Declare the smallest permission set; list mandatory contracts as required and
optional features as optional. Edit NXML files as package assets rather than
injecting host controls. Route mutations through actions/operations so the Host
can retain confirmation and cancellation semantics. Rebuild after any asset edit.

## Verification checklist

The SDK contract tests check encoding, negotiation and facade lifetimes. Runtime
integration tests belong to PluginSidecar; application tests belong to NexaCL.
Test rejection as well as success: denied permission, unsupported capability,
expired plan, stale revision, cancellation and plugin shutdown while work is active.
Never convert these failures into a successful empty result.

## 简体中文

优先使用模板的 Wasm 项目。修改插件 ID、权限和页面后重新打包，通过开发者模式审阅安装。
C# 示例用于契约开发与测试，不是绕过 Wasm 准入的入口。调试时同时检查加载阶段、错误码、
操作 ID、权限和宿主接入状态；不要把失败处理成成功空结果。
