# Nexa ABI 100 C/Wasm SDK

This package contains all 342 v0.2 operations and the 22 preserved preview slots,
with typed model views, builders, arrays, optionals, enum codecs and result readers.
It also includes the generic guest continuation and callback API. The Host remains
authoritative for capability availability, permissions, scope and lifecycle.

Include `<nexa/abi100.h>`. Headers are freestanding C11 and require no standard
library, WASI or system imports. Models borrow the bytes supplied to the decoder;
keep those buffers alive and do not overwrite them while views are in use.

For the packaged example, with Clang and wasm-ld available:

```sh
clang --target=wasm32-unknown-unknown -std=c11 -O2 -ffreestanding -fno-builtin -nostdlib -I include samples/WasmHello/plugin.c -Wl,--no-entry -Wl,--export-memory -Wl,--initial-memory=262144 -Wl,--max-memory=524288 -o plugin.wasm
```

The repository's `eng/build_wasm_sample.py` additionally builds conformance
fixtures; run that script from a repository checkout. See `docs/wasm-sdk.md` for
wire format, lifecycle, business callbacks and package trust. `SHA256.json`
records archive file digests for reproducibility; it is not a Market signature.

SDK completeness does not imply every Host business route is installed.
Unsupported operations return a structured failure. Apache-2.0.
