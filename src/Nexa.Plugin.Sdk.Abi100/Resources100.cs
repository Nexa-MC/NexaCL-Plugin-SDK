using Nexa.Plugin.Bootstrap.V1;
using static Nexa.Plugin.Sdk.Abi100.Values;
namespace Nexa.Plugin.Sdk.Abi100;

public sealed partial class Resources100(IAbilityV1 ability)
{
    public const string ContractId = "nexa.resources/100";
    public ValueTask<AbiReply<AbiValue>> RegisterCleanup(CallbackHandle callback, InvocationOptions options) =>
        ability.Invoke(ContractId, 1, M(("callback", U(callback.Value))), options);
}
