# NexaCL Plugin SDK

[简体中文](README.zh-CN.md) · [Documentation](https://docs.pcln.top/en/plugin-sdk/) · [Template repository](https://github.com/Nexa-MC/NexaCL-Plugin-Template)

The independent, public SDK for NexaCL plugin authors, derived launcher developers
and contributors. This repository replaces `PCL-N-Plugin-SDK`; its Git history is
retained. New plugins use Nexa Bootstrap V1 and negotiated ABI 100, not the legacy
`PCL.N.Plugin.*` injection API.

## What is included

- `Nexa.Plugin.Bootstrap.V1`: loading lifecycle, negotiation, generic values and errors.
- `Nexa.Plugin.Sdk.Abi100`: 33 capability groups, 358 typed operations, 261 models,
  schema validators and 22 retained preview dispatch slots.
- `sdk/wasm/include/nexa`: freestanding C/Wasm bindings generated from the same contract.
- Executable examples, contract tests, NativeAOT smoke and complete API reference.

PluginSidecar owns execution and admission. NexaCL owns application services and
user confirmation. Neither runtime is embedded in this authoring SDK.
The production executable profile is import-free `nexa-wasm-1`; the managed sample
illustrates the Bootstrap contract and is not an ordinary Desktop-loadable DLL.

## Start developing

Create a repository from [NexaCL-Plugin-Template](https://github.com/Nexa-MC/NexaCL-Plugin-Template),
or build the checked-in examples with .NET 10, Python 3.12 and Clang/wasm-ld:

```sh
dotnet build NexaCL-Plugin-SDK.slnx -c Release
python eng/generate_abi100.py --verify
python eng/build_wasm_sample.py --clang clang
dotnet run --project tests/Nexa.Plugin.Sdk.Tests -c Release --no-build
```

The Desktop example is `artifacts/wasm-sample/desktop.zip`. A compatible NexaCL
build must enable developer mode and approve the package and requested permissions.
See [the walkthrough](docs/quickstart.md), [packaging](docs/packaging.md) and
[host support](docs/host-support.md) before choosing required capabilities.

## Distribution and compatibility

SDK version: **0.2.0-alpha.13**. Download immutable bundles from
[GitHub Releases](https://github.com/Nexa-MC/NexaCL-Plugin-SDK/releases).
The bundle contains two NuGet packages and the C/Wasm SDK. Add its `packages/`
directory as a local NuGet source alongside nuget.org. No NuGet.org publication is
implied. See [migration](docs/migration.md) before replacing an old SDK reference.

SDK availability does not mean every launcher implements every operation. Negotiate
required and optional contracts, handle structured failures, and inspect the
[per-operation reference](docs/api/index.md). Publisher authenticity and Market
entitlements belong to Host distribution; checksums alone do not establish them.

[Contributing](CONTRIBUTING.md) · [Security](SECURITY.md) · [Apache-2.0](LICENSE)
