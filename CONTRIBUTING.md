# Contributing

Use .NET 10 and Python 3.12. Build the solution, run the SDK tests and verify
generated output with `python eng/generate_abi100.py --verify`. C/Wasm changes also
require Clang/wasm-ld builds; public contract changes require the NativeAOT smoke.

The Beta ABI 100 catalog and Bootstrap V1 are frozen. Do not append methods or
fields to `contracts/abi100.json` or edit generated files by hand. New contract
behavior requires an immutable EXP_ID; follow [contract evolution](docs/guides/contract-evolution.md)
and run `python eng/verify_evolution.py --base <previous-commit>`. Keep the old
experimental schemas and behavior after promotion. Update API reference and
examples alongside implementation. Behavior-preserving fixes remain possible.

This repository owns authoring contracts only. Host execution belongs to
PluginSidecar, including application mapping through the general Sidecar Host ABI. Do not introduce runtime
implementation project references into the SDK or copy private Host code here.
Document the capability's inputs, outputs, permission, phases, idempotency and
cleanup behavior. Test invalid input, revocation and retirement where relevant.

The primary documentation language is English. Keep README and contributor entry
points available in Simplified Chinese. Link detailed references from docs/index.md.

## Documentation changes

Follow [the editorial standard](docs/documentation.md). Update source examples before
explaining a behavior; `python eng/sync_doc_examples.py` copies the complete tutorial
examples and `--verify` rejects drift. Edit `eng/reference-notes.json` for reviewed
API behavior, then run `python eng/generate_docs.py`. Keep primary Chinese guides in
`docs/zh-CN`; generated English technical fallbacks are labelled and synchronized.

Run `python eng/verify_docs.py` and compile changed Wasm examples. Publish source
changes before synchronizing the website, so provenance links resolve to real files.
The public documentation entry is https://docs.pcln.top/en/plugin-sdk/.
