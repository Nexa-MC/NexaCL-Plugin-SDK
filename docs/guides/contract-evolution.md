# Evolving a plugin contract after Beta

SDK `0.2.0-beta.1` freezes Bootstrap V1, the 358 ABI 100 operations, their
models and the 22 retained legacy slots. The freeze concerns the contract a
plugin observes: fields, numeric IDs, schemas, permissions, phases, errors and
side effects. A new SDK package version does not authorize changing that contract.

## Decide whether a change needs an EXP_ID

Allocate an EXP_ID for a new capability, operation, field or observable behavior.
Use a new experimental contract even when an addition would have been source
compatible. An implementation fix that restores the documented behavior,
editorial correction or build-tool change does not need an artificial EXP_ID.
Explain that distinction in the change description and retain regression evidence.

The plugin SDK is implemented by PluginSidecar. NexaCL supplies general Host
capabilities through its Sidecar ABI; it does not implement plugin-specific SDK
methods. A plugin experiment must not create a dependency from the launcher back
to the plugin SDK. A new general Host capability follows the Host ABI's separate
compatibility rules.

## Register an experiment

1. Generate a fresh UUID, for example with `python -c "import uuid; print(uuid.uuid4())"`.
   Never reuse an ID, including one whose implementation was later superseded.
2. Add `contracts/experiments/<EXP_ID>.json`. Include `expId`, `baseAbi: 100`, a
   unique `nexa.experimental.*` contract ID, `operations` and `semantics`. Describe
   request and response schemas, permissions, phases, cancellation, failure
   results, resource ownership and observable effects completely. The document
   is an immutable definition, not a pointer to whichever implementation is newest.
3. Add a record to `contracts/evolution.json` with `expId`, `schema`, the exact
   file's SHA-256 as `sha256`, `status: "experimental"` and a local Markdown
   `documentation` path. Add a typed SDK view and the corresponding Sidecar
   implementation and compatibility tests together.
4. Run `python eng/verify_evolution.py --base <previous-commit>`, the SDK tests,
   generated-code checks and NativeAOT/guest tests. Review the diff against the
   previous published release before assigning a new package version.

The registry initially contains **no published experiments**. The UUID used in
the verifier's unit tests is a fixture, not an assigned public capability. A
registry entry alone does not make an experiment executable or supported.

## Negotiate before use

During pre-initialization, request `GetExperimentABI(EXP_ID, options)`. Include
only a successful Host-issued `ExperimentRef` in the draft before calling Make.
Use the resulting final context's `GetExperiment<T>(EXP_ID)` for the typed view.
For C/Wasm, inspect `nx_has_experiment` and carry `experiment_id` in the call
options. Neither helper grants an experiment or adds it to a confirmed context.
An unavailable optional experiment disables its feature; an unavailable required
experiment fails loading with the actual error. Never retry through the stable
`GetAbility` path to bypass experiment negotiation.

## Preserve published behavior

A published EXP_ID and its schema are permanent. Incompatible changes receive
another ID. Promotion into a later stable ABI retains the old experimental ID
and its original behavior, including the base ABI needed to execute it. An
adapter is acceptable only when it preserves those semantics. Mark promotion
with `status: "promoted"`; do not remove the old schema or redirect it silently.

CI checks frozen file hashes and compares the registry against the previous Git
revision. Changing a baseline hash together with the contract fails that check.
Compatibility tests must still cover behavior: hashes cannot prove that an
implementation honors permissions, cancellation or resource ownership.
