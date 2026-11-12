using System.Collections.Immutable;
namespace Nexa.Plugin.Bootstrap.V1;

public sealed record PayloadDescriptor(string Path, long Size, string Sha256);
public sealed record ManagedEntry(string Assembly, string Type);
public sealed record PluginTarget(ImmutableArray<string> OperatingSystems, ImmutableArray<string> Architectures, string Runtime);
public sealed record PluginManifest(uint ManifestVersion, string PluginId, string PluginVersion, uint BootstrapVersion, ManagedEntry Entry, PluginTarget Target, ImmutableArray<uint> DeclaredAbiCandidates, ImmutableArray<PluginDependency> RequiredDependencies, ImmutableArray<PluginDependency> OptionalDependencies, ImmutableArray<PluginConflict> Conflicts, ImmutableArray<string> RequestedPermissions, ImmutableArray<PayloadDescriptor> Payloads)
{
    public string? WebAssemblyEntryPath { get; init; }
    public string? DeclarativeEntryPath { get; init; }
    public ImmutableArray<CapabilityRequirement> RequiredCapabilities { get; init; } = [];
    public ImmutableArray<CapabilityRequirement> OptionalCapabilities { get; init; } = [];
}
public sealed record LoadPermit(Guid PermitId, Guid SessionId, PluginIdentity Identity, string ContentDigest);
public sealed record DependencyAnchor(PluginIdentity Provider, string ContextDigest, bool Required);
public sealed record PrepareGroup(Guid OperationId, Guid SessionId, Guid LoadGroupId, ulong PlanGeneration, ulong CheckedRegistryRevision, ImmutableArray<PluginIdentity> Members, string ContextDigest, string RegistrationDigest, ImmutableArray<DependencyAnchor> Anchors);
public sealed record PreparedToken(Guid Value);
public sealed record CommitGroup(Guid OperationId, Guid SessionId, Guid LoadGroupId, PreparedToken Token);
public sealed record GroupDecision(Guid LoadGroupId, LoadState State, ulong RegistryRevision, AbiError? Error);
/// <summary>Host authority port. Implementations must enforce identity, idempotency and atomic visibility.</summary>
public interface IHostLoadingV1
{
    ValueTask<AbiReply<LoadPermit>> BeginLoad(PluginManifest manifest, PluginIdentity identity, InvocationOptions options);
    ValueTask<AbiReply<Unit>> Verified(LoadPermit permit, string contentDigest, InvocationOptions options);
    ValueTask<AbiReply<PreparedToken>> Prepare(PrepareGroup request, InvocationOptions options);
    ValueTask<AbiReply<GroupDecision>> Commit(CommitGroup request, InvocationOptions options);
    ValueTask<AbiReply<GroupDecision>> Query(Guid groupId, InvocationOptions options);
    ValueTask<AbiReply<Unit>> Abort(Guid groupId, AbiError rootCause, InvocationOptions options);
}
