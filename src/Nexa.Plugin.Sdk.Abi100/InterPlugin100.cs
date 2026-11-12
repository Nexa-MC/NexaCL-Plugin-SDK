using Nexa.Plugin.Bootstrap.V1;
using static Nexa.Plugin.Sdk.Abi100.Values;
namespace Nexa.Plugin.Sdk.Abi100;

public sealed partial class InterPlugin100(IAbilityV1 ability)
{
    public const string ContractId = "nexa.interplugin/100";
    public ValueTask<AbiReply<AbiValue>> Describe(ServiceQuery value, InvocationOptions options) => ability.Invoke(ContractId, 1, M(("providerPluginId", S(value.ProviderPluginId)), ("serviceId", S(value.ServiceId))), options);
    public ValueTask<AbiReply<AbiValue>> Bind(ServiceRequirement value, InvocationOptions options) => ability.Invoke(ContractId, 2, Requirement(value), options);
    public ValueTask<AbiReply<AbiValue>> Call(ServiceHandle handle, uint methodId, AbiValue payload, InvocationOptions options) => ability.Invoke(ContractId, 3, M(("handle", U(handle.Value)), ("methodId", U(methodId)), ("payload", payload)), options);
    public ValueTask<AbiReply<AbiValue>> Release(ServiceHandle handle, InvocationOptions options) => ability.Invoke(ContractId, 4, M(("handle", U(handle.Value))), options);
    public ValueTask<AbiReply<AbiValue>> RebindOptional(ServiceRequirement value, InvocationOptions options) => ability.Invoke(ContractId, 5, Requirement(value), options);
    public ValueTask<AbiReply<AbiValue>> ExportService(ServiceDeclaration value, CallbackHandle callback, InvocationOptions options) => ability.Invoke(ContractId, 6, M(("serviceId", S(value.ServiceId)), ("contractId", S(value.ContractId)), ("contractVersion", U(value.ContractVersion)), ("schemaDigest", S(value.SchemaDigest)), ("methods", new AbiValue.Array(value.Methods)), ("healthProbe", value.HealthProbe), ("handler", U(callback.Value))), options);
    public ValueTask<AbiReply<AbiValue>> Probe(ServiceHandle handle, uint probeId, AbiValue payload, InvocationOptions options) => ability.Invoke(ContractId, 7, M(("handle", U(handle.Value)), ("probeId", U(probeId)), ("payload", payload)), options);
    private static AbiValue Requirement(ServiceRequirement value) => M(("providerPluginId", S(value.ProviderPluginId)), ("serviceId", S(value.ServiceId)), ("minimumContractVersion", U(value.MinimumContractVersion)), ("maximumContractVersion", U(value.MaximumContractVersion)), ("required", B(value.Required)));
}
