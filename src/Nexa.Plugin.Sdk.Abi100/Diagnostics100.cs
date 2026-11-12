using Nexa.Plugin.Bootstrap.V1;
using static Nexa.Plugin.Sdk.Abi100.Values;
namespace Nexa.Plugin.Sdk.Abi100;

public sealed record Diagnostic(string Code, string Message, string Severity);
public sealed partial class Diagnostics100(IAbilityV1 ability)
{
    public const string ContractId = "nexa.diagnostics/100";
    public ValueTask<AbiReply<AbiValue>> Report(Diagnostic value, InvocationOptions options) => ability.Invoke(ContractId, 1,
        M(("code", S(value.Code)), ("message", S(value.Message)), ("severity", S(value.Severity))), options);
    public ValueTask<AbiReply<AbiValue>> ReportFinding(Finding value, InvocationOptions options) => ability.Invoke(ContractId, 2,
        M(("code", S(value.Code)), ("message", S(value.Message)), ("fatal", B(value.Fatal))), options);
    public ValueTask<AbiReply<AbiValue>> QueryRegistrations(InvocationOptions options) => ability.Invoke(ContractId, 3, M(), options);
    public ValueTask<AbiReply<AbiValue>> QueryBindingStatus(InvocationOptions options) => ability.Invoke(ContractId, 4, M(), options);
}
