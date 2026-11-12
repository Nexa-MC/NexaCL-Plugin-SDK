# Packaging and distribution

A plugin ZIP contains `plugin.json`, its declared entry and verified assets.
The manifest binds plugin ID/version, Bootstrap version, target profile, ABI
candidates, dependency/conflict declarations, requested permissions and required/
optional capabilities. Every payload has a normalized relative path, exact byte
length and SHA-256. Never include paths outside the package, duplicate entries,
symlinks or an undeclared replacement for a hashed asset.

The sample build script is the executable manifest example. Keep build inputs
under version control, run the generator consistency check, compile the guest,
then compute manifest hashes from the actual output bytes. The ZIP uses stable
entry order and timestamps. A changed asset requires a fresh package digest.

SDK releases contain two NuGet packages, C/Wasm headers, contracts, samples and
documentation. `SHA256.json` records every bundle member. Consumers pin both the
release and bundle digest; they must not silently download a mutable `main` branch.
Checksums verify integrity, not publisher authenticity. Host/Market trust and
entitlement verification are separate from an authoring SDK archive.

Use GitHub Releases as a download distribution, then add the extracted `packages/`
as a local NuGet source. Package IDs and exact versions remain explicit in the
consumer project. No private GitHub access or checkout of PluginSidecar should be
required to compile an SDK-only project.

Local developer admission and production Market delivery are distinct. The SDK
cannot issue production entitlements, forge a verification result, or embed Market
private keys. The Host can preserve approved encrypted packages for offline use;
plugin code must still tolerate revoked permissions and missing optional services.
