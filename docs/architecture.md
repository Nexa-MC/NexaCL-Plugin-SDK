# SDK ownership

This repository owns Bootstrap V1, ABI 100 models/wrappers, C/Wasm headers,
generators, authoring documentation and examples. PluginSidecar owns execution,
Host authority, encrypted package delivery and the Wasm interpreter. NexaCL owns
application mappings and UI confirmation. Runtime repositories consume immutable
SDK packages, never a second editable copy of these contracts.

The initial extraction preserves every ABI 100 operation, model and schema digest
from PluginSidecar commit 577f819fd4bd1265ffa629885398887feb13bd65. SDK-local numeric
IDs are not Host transport opcodes; the existing binary Host protocol is unchanged.
Legacy PCL.N.Plugin.* APIs are replaced, with history retained in Git. They are not
binary-compatible with the Nexa Bootstrap/ABI system.
