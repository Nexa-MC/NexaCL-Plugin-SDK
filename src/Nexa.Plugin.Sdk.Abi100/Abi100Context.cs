using System.Collections.Immutable;
using Nexa.Plugin.Bootstrap.V1;
namespace Nexa.Plugin.Sdk.Abi100;

/// <summary>A statically mapped experimental view; no reflection or negotiation on access.</summary>
public interface IExperimentView<TSelf> where TSelf : IExperimentView<TSelf>
{
    static abstract string ContractId { get; }
    static abstract TSelf Create(IAbilityV1 ability);
}

public static class Abi100Extensions
{
    public static Abi100Context AsAbi100(this ABIContext context) => new(context);
    public static Abi100Context ForStage100(this ABIContext context, StageContext stage) => new(context, stage);
    public static AbiReply<T> GetExperiment<T>(this ABIContext context, Guid expId) where T : IExperimentView<T> =>
        context.AsAbi100().GetExperiment<T>(expId);
}

/// <summary>Local typed view. Host still authorizes every call, even for already acquired proxies.</summary>
public sealed partial class Abi100Context : IDisposable
{
    private readonly ABIContext _context;
    private readonly StageContext? _stage;
    private int _closed;
    public AbiContextInfo Info => _context.Info;
    public Events100 Events { get; }
    public Ui100 UI { get; }
    public InterPlugin100 Plugins { get; }
    public Diagnostics100 Diagnostics { get; }
    public Resources100 Resources { get; }

    internal Abi100Context(ABIContext context, StageContext? stage = null)
    {
        _context = context ?? throw new ArgumentNullException(nameof(context)); _stage = stage;
        InitializePublicGroups();
        Events = new(new ContextAbility(this, Events100.ContractId));
        UI = new(new ContextAbility(this, Ui100.ContractId));
        Plugins = new(new ContextAbility(this, InterPlugin100.ContractId));
        Diagnostics = new(new ContextAbility(this, Diagnostics100.ContractId));
        Resources = new(new ContextAbility(this, Resources100.ContractId));
    }

    public AbiReply<T> GetExperiment<T>(Guid expId) where T : IExperimentView<T>
    {
        var ability = Resolve(T.ContractId, expId);
        return ability.Success ? AbiReply<T>.Ok(T.Create(new ContextAbility(this, T.ContractId, expId))) : AbiReply<T>.Fail(ability.Error!);
    }

    // Disposes this view only, never the shared final ABIContext.
    public void Dispose() => Interlocked.Exchange(ref _closed, 1);

    private AbiReply<IAbilityV1> Resolve(string contract, Guid? experiment)
    {
        if (Volatile.Read(ref _closed) != 0) return Fail<IAbilityV1>(_stage is null ? AbiErrors.HANDLE_EXPIRED : AbiErrors.STAGE_FROZEN);
        if (Info.StableAbiVersion != AbiVersions.Stable100 || string.IsNullOrWhiteSpace(contract)) return Fail<IAbilityV1>(AbiErrors.ABI_CONTRACT_MISMATCH);
        if (_stage is not null && (_stage.Identity != Info.Identity || _stage.StageInvocationId == Guid.Empty)) return Fail<IAbilityV1>(AbiErrors.HANDLE_OWNER_MISMATCH);
        // Access never calls GetABIContext, GetExpermentABI or MakeABIContext.
        var result = experiment is { } id ? _context.GetExperiment(id, contract) : _context.GetAbility(contract);
        if (!result.Success) return result;
        return result.Value is null || result.Value.Context != Info.Handle || Info.Handle.Value == 0
            ? Fail<IAbilityV1>(AbiErrors.HANDLE_OWNER_MISMATCH) : result;
    }

    private AbiReply<T> Fail<T>(string code) => AbiReply<T>.Fail(new(code, code, _stage?.Stage.ToString() ?? "Runtime", "abi.invoke",
        Info.Identity.PluginId, Info.Identity.LoadInstanceId, Guid.NewGuid(), false, ImmutableDictionary<string, string>.Empty));

    private async ValueTask<AbiReply<AbiValue>> Invoke(string contract, Guid? experiment, uint method, AbiValue value, InvocationOptions options)
    {
        var resolved = Resolve(contract, experiment);
        if (!resolved.Success) return AbiReply<AbiValue>.Fail(resolved.Error!);
        if (_stage is null)
        {
            // Runtime calls cannot reuse the identity or deadline of an ended load callback.
            if (options.StageInvocationId != Guid.Empty) return Fail<AbiValue>(AbiErrors.STAGE_INVALID);
            return await resolved.Value.Invoke(contract, method, value, options).ConfigureAwait(false);
        }
        if (options.StageInvocationId != Guid.Empty && options.StageInvocationId != _stage.StageInvocationId)
            return Fail<AbiValue>(AbiErrors.STAGE_INVALID);
        if (_stage.Cancellation.IsCancellationRequested || options.Cancellation.IsCancellationRequested) return Fail<AbiValue>(AbiErrors.CANCELLED);
        var remaining = _stage.RemainingBudget;
        if (remaining <= TimeSpan.Zero || options.Budget <= TimeSpan.Zero) return Fail<AbiValue>(AbiErrors.STAGE_TIMEOUT);
        using var cancellation = CancellationTokenSource.CreateLinkedTokenSource(_stage.Cancellation, options.Cancellation);
        return await resolved.Value.Invoke(contract, method, value, options with
        {
            StageInvocationId = _stage.StageInvocationId,
            Budget = options.Budget < remaining ? options.Budget : remaining,
            Cancellation = cancellation.Token
        }).ConfigureAwait(false);
    }

    private sealed class ContextAbility(Abi100Context owner, string contract, Guid? experiment = null) : IAbilityV1
    {
        public AbiContextHandle Context => owner.Info.Handle;
        public ValueTask<AbiReply<AbiValue>> Invoke(string contractId, uint methodId, AbiValue arguments, InvocationOptions options) =>
            contractId != contract ? ValueTask.FromResult(owner.Fail<AbiValue>(AbiErrors.ABI_CONTRACT_MISMATCH))
            : owner.Invoke(contract, experiment, methodId, arguments, options);
    }
}
