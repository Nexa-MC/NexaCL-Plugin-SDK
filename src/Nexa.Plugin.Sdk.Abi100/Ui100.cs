using Nexa.Plugin.Bootstrap.V1;
using static Nexa.Plugin.Sdk.Abi100.Values;
namespace Nexa.Plugin.Sdk.Abi100;

public sealed partial class Ui100(IAbilityV1 ability)
{
    public const string ContractId = "nexa.ui/100";
    public ValueTask<AbiReply<AbiValue>> DeclareSurface(SurfaceSpec value, InvocationOptions options) => ability.Invoke(ContractId, 1, M(("localId", S(value.LocalId)), ("nodes", value.Nodes), ("resourceIds", A(value.ResourceIds))), options);
    public ValueTask<AbiReply<AbiValue>> DeclareCommand(CommandSpec value, CallbackHandle callback, InvocationOptions options) => ability.Invoke(ContractId, 2, M(("localId", S(value.LocalId)), ("title", S(value.Title)), ("handler", U(callback.Value))), options);
    public ValueTask<AbiReply<AbiValue>> DeclarePlacement(PlacementSpec value, InvocationOptions options) => ability.Invoke(ContractId, 3, M(("localId", S(value.LocalId)), ("surfaceId", S(value.SurfaceId)), ("slotId", S(value.SlotId))), options);
    public ValueTask<AbiReply<AbiValue>> DeclareSettings(SettingsSpec value, InvocationOptions options) => ability.Invoke(ContractId, 4, M(("localId", S(value.LocalId)), ("schemaId", S(value.SchemaId)), ("schemaDigest", S(value.SchemaDigest)), ("layout", value.Layout)), options);
    public ValueTask<AbiReply<AbiValue>> PatchState(SurfaceHandle handle, ulong revision, AbiValue patch, InvocationOptions options) => ability.Invoke(ContractId, 5, M(("handle", U(handle.Value)), ("revision", U(revision)), ("patch", patch)), options);
    public ValueTask<AbiReply<AbiValue>> SetCommandState(CommandHandle handle, CommandState state, InvocationOptions options) => ability.Invoke(ContractId, 6, M(("handle", U(handle.Value)), ("enabled", B(state.Enabled)), ("visible", B(state.Visible))), options);
}
