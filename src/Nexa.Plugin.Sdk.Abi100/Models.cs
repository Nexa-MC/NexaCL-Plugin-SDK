using System.Collections.Immutable;
using Nexa.Plugin.Bootstrap.V1;
namespace Nexa.Plugin.Sdk.Abi100;

public sealed record EventDeclaration(string Name, string PayloadSchemaId, string PayloadSchemaDigest, int MaxPayloadBytes, int QueueLimit);
public sealed record EventSubscription(string SourcePluginId, string EventName, string SchemaId, CallbackHandle Handler, bool Required, int Concurrency, int QueueLimit);
public sealed record ServiceDeclaration(string ServiceId, string ContractId, uint ContractVersion, string SchemaDigest, ImmutableArray<AbiValue> Methods, AbiValue HealthProbe);
public sealed record SurfaceSpec(string LocalId, AbiValue Nodes, ImmutableArray<string> ResourceIds);
public sealed record CommandSpec(string LocalId, string Title);
public sealed record PlacementSpec(string LocalId, string SurfaceId, string SlotId);
public sealed record SettingsSpec(string LocalId, string SchemaId, string SchemaDigest, AbiValue Layout);
public sealed record CommandState(bool Enabled, bool Visible);
public sealed record ServiceQuery(string ProviderPluginId, string ServiceId);
public sealed record ServiceRequirement(string ProviderPluginId, string ServiceId, uint MinimumContractVersion, uint MaximumContractVersion, bool Required);
internal static class Values
{
    internal static AbiValue S(string v) => new AbiValue.Utf8String(v);
    internal static AbiValue U(ulong v) => new AbiValue.UInt64(v);
    internal static AbiValue I(int v) => new AbiValue.Int64(v);
    internal static AbiValue B(bool v) => new AbiValue.Bool(v);
    internal static AbiValue A(IEnumerable<string> v) => new AbiValue.Array(v.Select(S).ToImmutableArray());
    internal static AbiValue M(params (string Key, AbiValue Value)[] fields) => new AbiValue.Map(fields.ToImmutableDictionary(x => x.Key, x => x.Value, StringComparer.Ordinal));
}
