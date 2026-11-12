using System.Collections.Immutable;
namespace Nexa.Plugin.Bootstrap.V1;

public readonly record struct Unit;
public readonly record struct AbiContextHandle(ulong Value);
public readonly record struct ExperimentRef(ulong Value);
public readonly record struct CallbackHandle(ulong Value);
public readonly record struct RegistrationHandle(ulong Value);
public readonly record struct ServiceHandle(ulong Value);
public readonly record struct EventHandle(ulong Value);
public readonly record struct SurfaceHandle(ulong Value);
public readonly record struct CommandHandle(ulong Value);
public sealed record PluginIdentity(string PluginId, string PluginVersion, Guid LoadInstanceId);
public enum LoadStage { Checksum, PreInitialize, Initialize, PostInitialize, Checkup, Finalize }
public enum LoadState { Discovered, Verifying, Verified, PreInitializing, Negotiated, Planned, Initializing, Initialized, PostInitializing, Bound, Checking, Checked, Finalizing, Prepared, Active, Aborting, Failed, BlockedConflict, Quiescing, Stopping, Unloaded, SessionLost }
public enum CheckupStatus { Passed, Degraded, Failed }
public sealed record AbiError(string Code, string Message, string Stage, string Operation, string PluginId, Guid LoadInstanceId, Guid CorrelationId, bool Retryable, ImmutableDictionary<string, string> Details)
{
    public string MessageKey { get; init; } = Code;
    public ImmutableDictionary<string, string> Parameters { get; init; } = ImmutableDictionary<string, string>.Empty;
    public Guid OperationId { get; init; }
}
public sealed class AbiReply<T>
{
    private AbiReply(T value, AbiError? error) { Value = value; Error = error; }
    public T Value { get; }
    public AbiError? Error { get; }
    public bool Success => Error is null;
    public static AbiReply<T> Ok(T value) => new(value, null);
    public static AbiReply<T> Fail(AbiError error) => new(default!, error ?? throw new ArgumentNullException(nameof(error)));
}
// Closed data union: no arbitrary CLR objects, delegates or type names.
public abstract record AbiValue
{
    private AbiValue() { }
    public sealed record Null : AbiValue;
    public sealed record Bool(bool Value) : AbiValue;
    public sealed record Int64(long Value) : AbiValue;
    public sealed record UInt64(ulong Value) : AbiValue;
    public sealed record Float64 : AbiValue
    {
        public double Value { get; }
        public Float64(double value) { if (!double.IsFinite(value)) throw new ArgumentOutOfRangeException(nameof(value)); Value = value; }
    }
    public sealed record Utf8String(string Value) : AbiValue;
    public sealed record Bytes(ImmutableArray<byte> Value) : AbiValue;
    public sealed record Array(ImmutableArray<AbiValue> Value) : AbiValue;
    public sealed record Map(ImmutableDictionary<string, AbiValue> Value) : AbiValue;
}
public sealed record InvocationOptions(Guid OperationId, TimeSpan Budget, CancellationToken Cancellation)
{
    // Empty for runtime calls; a Host-issued identity for phase-limited operations.
    public Guid StageInvocationId { get; init; }
    public Guid CorrelationId { get; init; }
    public Guid? CausationId { get; init; }
    public string? ExpectedRevision { get; init; }
    public string? IdempotencyKey { get; init; }
}
public sealed record VersionRange(string? Minimum, bool MinimumInclusive, string? Maximum, bool MaximumInclusive);
public sealed record PluginDependency(string PluginId, VersionRange Version);
public sealed record PluginConflict(string PluginId, VersionRange Version, string? ReasonCode);
public sealed record Finding(string Code, string Message, bool Fatal);
public sealed record CapabilityRequirement(string ContractId, uint MinimumVersion);
public sealed record MakeOptions(Guid OperationId, ImmutableArray<string> RequestedPermissions)
{
    public ImmutableArray<CapabilityRequirement> RequiredCapabilities { get; init; } = [];
    public ImmutableArray<CapabilityRequirement> OptionalCapabilities { get; init; } = [];
}
public sealed record ExperimentDescriptor(Guid ExpId, string ContractDigest, ImmutableArray<uint> SupportedBaseAbis, ImmutableArray<Guid> RequiredExperiments, ImmutableArray<Guid> ConflictingExperiments, ImmutableArray<string> RequiredPermissions, ImmutableArray<string> SupportedPlatforms, uint? PromotedStableAbi);
public sealed record CapabilityDescriptor(string ContractId, Guid? ExperimentId = null);
public sealed record AbiContextInfo(AbiContextHandle Handle, Guid SessionId, PluginIdentity Identity, uint StableAbiVersion, ImmutableArray<ExperimentDescriptor> Experiments, ImmutableArray<string> Permissions, Guid LoadPermitId, string ProtocolDigest, string AdapterId, ImmutableArray<CapabilityDescriptor> Capabilities);
public static class AbiVersions
{
    public const uint Bootstrap = 1;
    public const uint Stable100 = 100;
    public static bool IsStable(uint version) => version > 0 && version % 100 == 0;
}
