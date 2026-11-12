using System.Collections.Immutable;
namespace Nexa.Plugin.Bootstrap.V1;

public interface IAbiNegotiatorV1
{
    ValueTask<AbiReply<ABIContext>> GetABIContext(uint version, InvocationOptions options);
    ValueTask<AbiReply<ExperimentRef>> GetExpermentABI(Guid expId, InvocationOptions options);
    ValueTask<AbiReply<ABIContext>> MakeABIContext(ABIContext draft, ImmutableArray<ExperimentRef> experiments, MakeOptions options, CancellationToken cancellation);
}
/// <summary>Local facade; only Info.Handle and explicit data may cross the existing Host ABI.</summary>
public interface ABIContext
{
    AbiContextInfo Info { get; }
    AbiReply<IAbilityV1> GetAbility(string contractId);
    AbiReply<IAbilityV1> GetExperiment(Guid expId, string contractId);
}
public interface IAbilityV1
{
    AbiContextHandle Context { get; }
    ValueTask<AbiReply<AbiValue>> Invoke(string contractId, uint methodId, AbiValue arguments, InvocationOptions options);
}
public interface EventAbility : IAbilityV1 { }
public interface UiAbility : IAbilityV1 { }
public interface InterPluginAbility : IAbilityV1 { }
public interface IDiagnosticsV1 { ValueTask<AbiReply<Unit>> ReportDiagnostic(Finding finding, InvocationOptions options); }
public interface IResourcesV1 { ValueTask<AbiReply<RegistrationHandle>> RegisterCleanup(CallbackHandle callback, InvocationOptions options); }
public interface ICallbacksV1
{
    CallbackHandle Register(string contractId, Func<AbiValue, InvocationOptions, ValueTask<AbiReply<AbiValue>>> callback);
    void Release(CallbackHandle callback);
}
public sealed record PreInitContext(PluginIdentity Identity, uint BootstrapVersion, IAbiNegotiatorV1 Negotiator, IDiagnosticsV1 Diagnostics, IResourcesV1 Resources, ICallbacksV1 Callbacks, CancellationToken Cancellation, TimeSpan Budget);
public sealed record CheckupInfo(Guid BatchId, AbiValue Inputs, AbiValue PolicySnapshot);
public sealed record StageContext(PluginIdentity Identity, LoadStage Stage, Guid StageInvocationId, Guid LoadGroupId, CancellationToken Cancellation, TimeSpan Budget, CheckupInfo? CheckupInfo = null)
{
    private readonly long _started = System.Diagnostics.Stopwatch.GetTimestamp();
    // Local callback lifetime. Creating another SDK view cannot reset this deadline.
    public TimeSpan RemainingBudget => Budget - System.Diagnostics.Stopwatch.GetElapsedTime(_started);
}
public sealed record PreInitResult(ABIContext FinalContext, ImmutableArray<PluginDependency> RequiredDependencies, ImmutableArray<PluginDependency> OptionalDependencies, ImmutableArray<PluginConflict> Conflicts, ImmutableArray<string> DeclaredDegradationModes);
public sealed record CheckupResult(CheckupStatus Status, ImmutableArray<Finding> Findings, ImmutableArray<string> EnabledDegradationModes);
public sealed record AbortContext(PluginIdentity Identity, LoadStage FailedStage, AbiError RootCause, ImmutableArray<LoadStage> CompletedStages, AbiValue Resources, CancellationToken Cancellation, TimeSpan Budget, ABIContext? ABI = null);
public sealed record StopContext(PluginIdentity Identity, ABIContext ABI, string ReasonCode, CancellationToken Cancellation, TimeSpan Budget);
public sealed record InvocationContext(PluginIdentity Identity, Guid InvocationId, Guid CorrelationId, Guid? CausationId, CancellationToken Cancellation, TimeSpan Budget);
/// <summary>Local execution adapter port. The trusted dispatcher supplies identity and the admitted ABI context.</summary>
public interface IPluginInvocationV1
{
    ValueTask<AbiReply<AbiValue>> InvokeHandler(ABIContext abi, ulong handler, AbiValue input, InvocationContext invocation);
}
public interface IPluginBootstrapV1
{
    ValueTask<AbiReply<PreInitResult>> OnPreInitialize(PreInitContext context);
    ValueTask<AbiReply<Unit>> OnInitialize(ABIContext abi, StageContext stage);
    ValueTask<AbiReply<Unit>> OnPostInitialize(ABIContext abi, StageContext stage);
    ValueTask<AbiReply<CheckupResult>> OnCheckup(ABIContext abi, StageContext stage);
    ValueTask<AbiReply<Unit>> OnFinalize(ABIContext abi, StageContext stage);
    ValueTask<AbiReply<Unit>> OnActivated(ABIContext abi, InvocationContext invocation);
    ValueTask<AbiReply<Unit>> OnAbort(AbortContext context);
    ValueTask<AbiReply<Unit>> OnStop(StopContext context);
}
public static class StageBudgets
{
    public static TimeSpan For(LoadStage stage) => TimeSpan.FromSeconds(stage switch
    {
        LoadStage.PreInitialize => 15,
        LoadStage.Initialize => 30,
        LoadStage.PostInitialize => 15,
        LoadStage.Checkup => 15,
        LoadStage.Finalize => 10,
        _ => throw new ArgumentOutOfRangeException(nameof(stage))
    });
    public static TimeSpan Cleanup => TimeSpan.FromSeconds(5);
}

/// <summary>Optional local execution adapter for bounded cleanup after business
/// dispatch has been sealed. Only the trusted lifecycle coordinator invokes it.</summary>
public interface IPluginCleanupInvocationV1
{
    ValueTask<AbiReply<AbiValue>> InvokeCleanup(ABIContext abi, ulong handler, string phase, InvocationOptions options);
}

/// <summary>Optional local adapter for a bounded Checkup handler. The Host must
/// enforce query-only capability access for the entire invocation lifetime.</summary>
public interface IPluginProbeInvocationV1
{
    ValueTask<AbiReply<AbiValue>> InvokeProbe(ABIContext abi, ulong handler, AbiValue input, InvocationContext invocation);
}
