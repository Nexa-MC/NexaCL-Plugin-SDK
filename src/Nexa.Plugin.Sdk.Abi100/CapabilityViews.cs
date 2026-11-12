using Nexa.Plugin.Bootstrap.V1;
namespace Nexa.Plugin.Sdk.Abi100;

public interface ICapabilityView<TSelf> where TSelf : ICapabilityView<TSelf>
{
    static abstract string CapabilityId { get; }
    static abstract TSelf Create(IAbilityV1 ability);
}

public sealed partial class Abi100Context
{
    /// <summary>Queries the negotiated local facade; does not negotiate or grant authority.</summary>
    public AbiReply<T> TryGet<T>() where T : ICapabilityView<T>
    {
        var resolved = Resolve(T.CapabilityId, null);
        return resolved.Success ? AbiReply<T>.Ok(T.Create(new ContextAbility(this, T.CapabilityId))) : AbiReply<T>.Fail(resolved.Error!);
    }
    public bool IsAvailable<T>() where T : ICapabilityView<T> => TryGet<T>().Success;
    public ExperimentViews Experiments => new(this);
}

public sealed class ExperimentViews
{
    private readonly Abi100Context _owner;
    internal ExperimentViews(Abi100Context owner) => _owner = owner;
    public AbiReply<T> TryGet<T>(Guid expId) where T : IExperimentView<T> => _owner.GetExperiment<T>(expId);
    public bool IsAvailable<T>(Guid expId) where T : IExperimentView<T> => TryGet<T>(expId).Success;
}
