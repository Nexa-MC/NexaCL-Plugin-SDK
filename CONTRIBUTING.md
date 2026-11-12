# Contributing

Use .NET 10 and Python 3.12. Build the solution, run the SDK tests and verify
generated output with `python eng/generate_abi100.py --verify`. C/Wasm changes also
require Clang/wasm-ld builds; public contract changes require the NativeAOT smoke.

Edit `contracts/abi100.json`, then regenerate C# models/wrappers/schemas and C
bindings. Do not edit generated files by hand. Preserve existing numeric IDs,
model fields and transitive schema fingerprints for compatible additions. Add a
new contract/version for an actual breaking change. Update API reference and
examples alongside implementation.

This repository owns authoring contracts only. Host execution belongs to
PluginSidecar; application mapping belongs to NexaCL. Do not introduce runtime
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
