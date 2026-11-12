using System.Collections.Immutable;
using Nexa.Plugin.Bootstrap.V1;
using Nexa.Plugin.Sdk.Abi100;

internal static class ContextTests
{
    internal static async Task Run()
    {
        var host = new ContextPort();
        var options = new InvocationOptions(Guid.NewGuid(), TimeSpan.FromSeconds(8), default);
        var negotiator = new BootstrapPort(host);
        Guid experimentId = Guid.NewGuid();
        var experiment = await ((IAbiNegotiatorV1)negotiator).GetExperimentABI(experimentId, options);
        Check(experiment.Success && experiment.Value.Value == 37 && negotiator.LastExperiment == experimentId && ReferenceEquals(negotiator.LastOptions, options));
        using var runtime = host.AsAbi100();
        Error(await runtime.Events.Publish(new(1), new AbiValue.Null(), options), AbiErrors.CONTEXT_NOT_READY);
        Error(runtime.GetExperiment<Feature>(host.Experiment), AbiErrors.CONTEXT_NOT_READY);
        host.Ready = true;
        host.DeniedContract = Ui100.ContractId;
        Error(await runtime.UI.DeclareCommand(new("command", "title"), new(1), options), AbiErrors.ABI_CONTRACT_NOT_NEGOTIATED);
        host.DeniedContract = null;
        Error(runtime.GetExperiment<Feature>(host.Experiment), AbiErrors.EXP_NOT_NEGOTIATED);
        Error(host.GetAbility(Feature.ContractId), AbiErrors.EXP_NOT_NEGOTIATED);
        host.ExperimentConfirmed = true;
        var feature = runtime.GetExperiment<Feature>(host.Experiment);
        Check(feature.Success);
        Error(runtime.GetExperiment<WrongFeature>(host.Experiment), AbiErrors.ABI_CONTRACT_MISMATCH);
        Error(await feature.Value.WrongContract(options), AbiErrors.ABI_CONTRACT_MISMATCH);
        Check((await feature.Value.Call(options)).Success);
        host.ExperimentConfirmed = false;
        Error(await feature.Value.Call(options), AbiErrors.EXP_NOT_NEGOTIATED); // Cached proxy rechecks admission.

        var stage = Stage(host, LoadStage.Initialize);
        host.Stage = stage;
        using var initialized = host.ForStage100(stage);
        var retained = initialized.Plugins;
        Check((await retained.ExportService(new("service", "schema/1", 1, "digest", [], new AbiValue.Null()), new(ulong.MaxValue), options)).Success);
        Check(host.Last!.StageInvocationId == stage.StageInvocationId && host.Last.OperationId == options.OperationId);
        Check(host.Last.Budget > TimeSpan.Zero && host.Last.Budget <= stage.Budget);
        Error(await retained.Bind(new("provider", "service", 1, 1, true), options), AbiErrors.STAGE_INVALID);
        initialized.Dispose();
        int calls = host.Invocations;
        Error(await retained.ExportService(new("service", "schema/1", 1, "digest", [], new AbiValue.Null()), new(1), options), AbiErrors.STAGE_FROZEN);
        Check(calls == host.Invocations);
        host.Stage = Stage(host, LoadStage.PostInitialize);
        using (var post = host.ForStage100(host.Stage))
        {
            Check((await post.Plugins.Bind(new("provider", "service", 1, 1, true), options)).Success);
            Error(await post.Plugins.Probe(new(1), 1, new AbiValue.Null(), options), AbiErrors.STAGE_INVALID);
            Error(await post.Plugins.Bind(new("provider", "service", 1, 1, true), options with { StageInvocationId = stage.StageInvocationId }), AbiErrors.STAGE_INVALID);
        }
        // Recreating a view from saved StageContext does not authorize it: Host rejects the old ID.
        using (var stale = host.ForStage100(stage))
            Error(await stale.Plugins.ExportService(new("service", "schema/1", 1, "digest", [], new AbiValue.Null()), new(1), options), AbiErrors.STAGE_FROZEN);
        host.Stage = Stage(host, LoadStage.Checkup) with { CheckupInfo = new(Guid.NewGuid(), new AbiValue.Null(), new AbiValue.Null()) };
        using (var checkup = host.ForStage100(host.Stage))
        {
            Check((await checkup.Plugins.Probe(new(1), 1, new AbiValue.Null(), options)).Success);
            Check((await checkup.Diagnostics.QueryRegistrations(options)).Success);
            Error(await checkup.Plugins.Call(new(1), 1, new AbiValue.Null(), options), AbiErrors.STAGE_INVALID);
        }
        using (var zero = host.ForStage100(Stage(host, LoadStage.Finalize) with { Budget = TimeSpan.Zero }))
            Error(await zero.Diagnostics.Report(new Diagnostic("test", "test", "info"), options), AbiErrors.STAGE_TIMEOUT);
        using (var other = host.ForStage100(stage with { Identity = stage.Identity with { LoadInstanceId = Guid.NewGuid() } }))
            Error(await other.Diagnostics.QueryRegistrations(options), AbiErrors.HANDLE_OWNER_MISMATCH);
        using (var canceled = new CancellationTokenSource())
        {
            canceled.Cancel();
            using var view = host.ForStage100(stage with { Cancellation = canceled.Token });
            Error(await view.Diagnostics.Report(new Diagnostic("test", "test", "info"), options), AbiErrors.CANCELLED);
        }
        var elapsedStage = Stage(host, LoadStage.Checkup) with { Budget = TimeSpan.FromMilliseconds(1) };
        while (elapsedStage.RemainingBudget > TimeSpan.Zero) await Task.Delay(1);
        using (var lateView = host.ForStage100(elapsedStage))
            Error(await lateView.Diagnostics.QueryRegistrations(options), AbiErrors.STAGE_TIMEOUT);
        using (var stop = new CancellationTokenSource())
        {
            host.Stage = Stage(host, LoadStage.Checkup) with { Cancellation = stop.Token };
            host.Pause = true;
            using var pendingView = host.ForStage100(host.Stage);
            var pending = pendingView.Diagnostics.QueryRegistrations(options).AsTask();
            await host.Entered.Task.WaitAsync(TimeSpan.FromSeconds(3));
            stop.Cancel();
            try { await pending; throw new InvalidOperationException("Stage cancellation was not forwarded."); }
            catch (OperationCanceledException) { }
            host.Pause = false;
        }
        host.Stage = null;
        Check((await runtime.Plugins.Call(new(1), 1, new AbiValue.Null(), options)).Success);
        Check(host.Last == options); // No completed stage deadline or cancellation leaks into Active.
        Error(await runtime.Plugins.Call(new(1), 1, new AbiValue.Null(), options with { StageInvocationId = stage.StageInvocationId }), AbiErrors.STAGE_INVALID);
        host.Info = host.Info with { StableAbiVersion = 200 };
        Error(await runtime.Events.Publish(new(1), new AbiValue.Null(), options), AbiErrors.ABI_CONTRACT_MISMATCH);
        host.Info = host.Info with { StableAbiVersion = 100 };
        host.Retired = true;
        Error(await runtime.Events.Publish(new(1), new AbiValue.Null(), options), AbiErrors.HANDLE_EXPIRED);
        await SampleLifecycle();
        Console.WriteLine("PASS: unified lazy views, Draft/experiment errors, exact ABI, stage IDs, Host phase errors, stale scopes/proxies, cleanup of local views and runtime budgets.");
    }

    private static async Task SampleLifecycle()
    {
        var host = new ContextPort(); var bootstrap = new BootstrapPort(host);
        var loaded = new HelloPlugin.Plugin();
        var negotiated = await loaded.OnPreInitialize(new(host.Info.Identity, 1, bootstrap, bootstrap, bootstrap, bootstrap, default, TimeSpan.FromSeconds(15)));
        Check(negotiated.Success && ReferenceEquals(host, negotiated.Value.FinalContext));
        var stages = new[] { LoadStage.Initialize, LoadStage.PostInitialize, LoadStage.Checkup, LoadStage.Finalize }.Select(stage => Stage(host, stage)).ToArray();
        Check(stages.Select(stage => stage.StageInvocationId).Distinct().Count() == 4);
        Check((await loaded.OnInitialize(negotiated.Value.FinalContext, stages[0])).Success);
        Check((await loaded.OnPostInitialize(negotiated.Value.FinalContext, stages[1])).Success);
        host.Stage = stages[2];
        Check((await loaded.OnCheckup(negotiated.Value.FinalContext, stages[2])).Success);
        Check(host.Last!.StageInvocationId == stages[2].StageInvocationId);
        Check((await loaded.OnFinalize(negotiated.Value.FinalContext, stages[3])).Success);
        Check((await loaded.OnActivated(negotiated.Value.FinalContext, new(host.Info.Identity, Guid.NewGuid(), Guid.NewGuid(), null, default, TimeSpan.FromSeconds(3)))).Success);
        Check((await loaded.OnStop(new(host.Info.Identity, host, "test.stop", default, StageBudgets.Cleanup))).Success);
        Console.WriteLine("PASS: standalone sample negotiates one final context across the revised lifecycle.");
    }

    private sealed class BootstrapPort(ContextPort host) : IAbiNegotiatorV1, IDiagnosticsV1, IResourcesV1, ICallbacksV1
    {
        public ValueTask<AbiReply<ABIContext>> GetABIContext(uint version, InvocationOptions options) => ValueTask.FromResult(AbiReply<ABIContext>.Ok(host));
        internal Guid LastExperiment;
        internal InvocationOptions? LastOptions;
        public ValueTask<AbiReply<ExperimentRef>> GetExpermentABI(Guid id, InvocationOptions options)
        { LastExperiment = id; LastOptions = options; return ValueTask.FromResult(AbiReply<ExperimentRef>.Ok(new(37))); }
        public ValueTask<AbiReply<ABIContext>> MakeABIContext(ABIContext draft, ImmutableArray<ExperimentRef> experiments, MakeOptions options, CancellationToken cancellation)
        { Check(ReferenceEquals(draft, host)); host.Ready = true; return ValueTask.FromResult(AbiReply<ABIContext>.Ok(host)); }
        public ValueTask<AbiReply<Unit>> ReportDiagnostic(Finding finding, InvocationOptions options) => ValueTask.FromResult(AbiReply<Unit>.Ok(new()));
        public ValueTask<AbiReply<RegistrationHandle>> RegisterCleanup(CallbackHandle callback, InvocationOptions options) => throw new NotSupportedException();
        public CallbackHandle Register(string contractId, Func<AbiValue, InvocationOptions, ValueTask<AbiReply<AbiValue>>> callback) => throw new NotSupportedException();
        public void Release(CallbackHandle callback) => throw new NotSupportedException();
    }

    private static StageContext Stage(ContextPort host, LoadStage stage) => new(host.Info.Identity, stage, Guid.NewGuid(), Guid.NewGuid(), default, TimeSpan.FromSeconds(3));
    private static void Check(bool value) { if (!value) throw new InvalidOperationException("Context assertion failed."); }
    private static void Error<T>(AbiReply<T> reply, string code) => Check(!reply.Success && reply.Error?.Code == code);
    private sealed class Feature(IAbilityV1 ability) : IExperimentView<Feature>
    {
        public static string ContractId => "test.feature/1";
        public static Feature Create(IAbilityV1 ability) => new(ability);
        internal ValueTask<AbiReply<AbiValue>> Call(InvocationOptions options) => ability.Invoke(ContractId, 1, new AbiValue.Null(), options);
        internal ValueTask<AbiReply<AbiValue>> WrongContract(InvocationOptions options) => ability.Invoke("wrong/1", 1, new AbiValue.Null(), options);
    }
    private sealed class WrongFeature : IExperimentView<WrongFeature>
    {
        public static string ContractId => "wrong/1";
        public static WrongFeature Create(IAbilityV1 ability) => new();
    }

    // Test authority port, not a production Host implementation or local Make fallback.
    private sealed class ContextPort : ABIContext, IAbilityV1
    {
        public bool Ready, Retired, ExperimentConfirmed, Pause;
        public string? DeniedContract;
        public TaskCompletionSource Entered { get; } = new(TaskCreationOptions.RunContinuationsAsynchronously);
        public Guid Experiment { get; } = Guid.NewGuid();
        public AbiContextInfo Info { get; set; } = new(new(42), Guid.NewGuid(), new("test.plugin", "1.0.0", Guid.NewGuid()), 100, [], [], Guid.NewGuid(), "digest", "fixture", []);
        public AbiContextHandle Context => Info.Handle;
        public StageContext? Stage;
        public InvocationOptions? Last;
        public int Invocations;
        public AbiReply<IAbilityV1> GetAbility(string contractId)
        {
            if (!Ready) return Fail<IAbilityV1>(AbiErrors.CONTEXT_NOT_READY);
            if (Retired) return Fail<IAbilityV1>(AbiErrors.HANDLE_EXPIRED);
            if (contractId == DeniedContract) return Fail<IAbilityV1>(AbiErrors.ABI_CONTRACT_NOT_NEGOTIATED);
            if (contractId == Feature.ContractId) return GetExperiment(Experiment, contractId);
            return contractId is Events100.ContractId or Ui100.ContractId or InterPlugin100.ContractId or Diagnostics100.ContractId or Resources100.ContractId
                ? AbiReply<IAbilityV1>.Ok(this) : Fail<IAbilityV1>(AbiErrors.ABI_CONTRACT_NOT_NEGOTIATED);
        }
        public AbiReply<IAbilityV1> GetExperiment(Guid expId, string contractId)
        {
            if (!Ready) return Fail<IAbilityV1>(AbiErrors.CONTEXT_NOT_READY);
            if (Retired) return Fail<IAbilityV1>(AbiErrors.HANDLE_EXPIRED);
            if (!ExperimentConfirmed || expId != Experiment) return Fail<IAbilityV1>(AbiErrors.EXP_NOT_NEGOTIATED);
            return contractId == Feature.ContractId ? AbiReply<IAbilityV1>.Ok(this) : Fail<IAbilityV1>(AbiErrors.ABI_CONTRACT_MISMATCH);
        }
        public ValueTask<AbiReply<AbiValue>> Invoke(string contractId, uint methodId, AbiValue arguments, InvocationOptions options)
        {
            Invocations++; Last = options;
            if (Pause) { Entered.TrySetResult(); return Wait(options.Cancellation); }
            if (Stage is not null && options.StageInvocationId != Stage.StageInvocationId) return ValueTask.FromResult(Fail<AbiValue>(AbiErrors.STAGE_FROZEN));
            if (contractId == InterPlugin100.ContractId)
            {
                bool allowed = methodId switch { 6 => Stage?.Stage == LoadStage.Initialize, 2 => Stage?.Stage == LoadStage.PostInitialize, 7 => Stage?.Stage == LoadStage.Checkup, 3 => Stage is null, _ => true };
                if (!allowed) return ValueTask.FromResult(Fail<AbiValue>(AbiErrors.STAGE_INVALID));
            }
            return ValueTask.FromResult(AbiReply<AbiValue>.Ok(new AbiValue.Null()));
        }
        private static async ValueTask<AbiReply<AbiValue>> Wait(CancellationToken token)
        { await Task.Delay(Timeout.Infinite, token); return AbiReply<AbiValue>.Ok(new AbiValue.Null()); }
        private AbiReply<T> Fail<T>(string code) => AbiReply<T>.Fail(new(code, code, "Test", "test", Info.Identity.PluginId, Info.Identity.LoadInstanceId, Guid.NewGuid(), false, ImmutableDictionary<string, string>.Empty));
    }
}
