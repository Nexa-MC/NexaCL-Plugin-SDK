# Errors and troubleshooting

Check `AbiReply<T>.Success` before reading `Value`. On failure preserve the
structured `AbiError`: code, message key/parameters, phase, plugin/load identity,
operation/correlation IDs and retryability. A default `Value` is not a valid empty
success result. Propagate useful errors instead of throwing away their identity.

| Situation | Typical response |
| --- | --- |
| Contract absent or not negotiated | Disable an optional feature; correct required capability metadata |
| Permission denied/revoked | Explain the denied feature; do not seek another route to bypass it |
| Wrong phase or retired stage | Use the final context and the current lifecycle scope |
| Schema invalid/message too large | Validate the model, collection size and exact schema fingerprint |
| Stale revision/conflict | Re-read and prepare a fresh plan; obtain fresh confirmation if needed |
| Invalid/expired/wrong-owner handle | Obtain a new handle in the current load; never fabricate one |
| Cancellation/deadline | Stop local work and release owned resources |
| Provider unavailable | Keep the feature unavailable or select another explicitly supported provider |
| Outcome unknown | Inspect the operation/journal; do not assume the effect did not happen |

A load failure before activation invokes abort cleanup. A running plugin uses stop
cleanup. Cleanup deadlines exist even if your callback has failed. Do not block a
Host callback waiting synchronously for another Host call. C/Wasm calls yield and
resume through the guest continuation protocol; raw JSON/stdout is not that protocol.

For a bug report include SDK version, launcher build, plugin ID/version, phase,
error code and correlation ID. Attach a minimal source example and redacted logs.
Do not include account tokens, encrypted content keys or private user files.
