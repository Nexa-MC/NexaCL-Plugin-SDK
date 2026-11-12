# Advanced Desktop UI sample

Build with `python eng/build_wasm_sample.py --clang <wasi-clang>` and load
`artifacts/wasm-sample/advanced.zip` from a compatible NexaCL developer-mode plugin
manager. The Host SDK remains pinned independently of these authoring assets.

The sample registers a page, component, contribution to `nexa:plugins/content`,
command, and page-scoped `Ctrl+Alt+P` shortcut. The input-bearing action returns
`TextResult`; the command accepts `Empty`. Both use the Host confirmation service.
Handler 2 accepts drawing input callbacks. The `canvas` dynamic slot is reserved
for an owned drawing surface. No handler can read arbitrary Host controls.

NexaCL's Desktop contract tests exercise dialogs, model revisions, drawing,
subscriptions and retirement using this exact Wasm sample. Production packages
still require the normal Market admission flow; local developer approval does
not confer publisher or entitlement verification.
