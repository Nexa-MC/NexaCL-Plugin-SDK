using System.Collections.Immutable;
using System.Reflection;
using System.Text.Json;
using Nexa.Plugin.Bootstrap.V1;
using Nexa.Plugin.Sdk.Abi100;
using Nexa.Plugin.Sdk.Abi100.Data;

internal static class SurfaceTests
{
    internal static async Task Run()
    {
        using var json = JsonDocument.Parse(File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "fixtures", "abi100.json")));
        var spec = json.RootElement;
        var port = new Port();
        using var api = port.AsAbi100();
        var options = new InvocationOptions(Guid.NewGuid(), TimeSpan.FromSeconds(5), default)
        { CorrelationId = Guid.NewGuid(), CausationId = Guid.NewGuid(), ExpectedRevision = "opaque:r7", IdempotencyKey = "save-123" };
        var descriptors = Abi100Catalog.Operations;
        Check(descriptors.Length == 346 && descriptors.Select(x => (x.ContractId, x.MethodId)).Distinct().Count() == 346);
        Check(descriptors.All(x => x.HostBinding == "HostMappingPending" && x.Phases.Length > 0));
        foreach (var group in spec.GetProperty("groups").EnumerateArray())
        {
            object wrapper = api;
            foreach (var path in group.GetProperty("name").GetString()!.Split('.')) wrapper = wrapper.GetType().GetProperty(path)!.GetValue(wrapper)!;
            foreach (var operation in group.GetProperty("operations").EnumerateArray())
            {
                string input = operation.GetProperty("input").GetString()!, output = operation.GetProperty("output").GetString()!;
                var inputType = typeof(QualifiedId).Assembly.GetType("Nexa.Plugin.Sdk.Abi100.Data." + input)!;
                var request = inputType.GetMethod("Read")!.Invoke(null, [Fixture(input), 0]);
                port.Response = Fixture(output); port.Last = null;
                var method = wrapper.GetType().GetMethod(operation.GetProperty("name").GetString()!, [inputType, typeof(InvocationOptions)])!;
                var pending = method.Invoke(wrapper, [request, options])!;
                var task = (Task)pending.GetType().GetMethod("AsTask")!.Invoke(pending, null)!;
                await task;
                var reply = task.GetType().GetProperty("Result")!.GetValue(task)!;
                Check((bool)reply.GetType().GetProperty("Success")!.GetValue(reply)!, $"Invalid output mapping: {group.GetProperty("name")}.{method.Name}");
                Check(port.Last == options && port.Contract == group.GetProperty("contractId").GetString() && port.Method == operation.GetProperty("methodId").GetUInt32());
                // Public wrapper must encode the same typed request shape; arrays and opaque 64-bit values survive.
                Check(Equal(port.Arguments!, Fixture(input)));
            }
        }
        Check(api.IsAvailable<Network100>() && api.TryGet<Ui100>().Success);
        var retained = api.TryGet<Network100>().Value;
        port.Denied = Network100.ContractId;
        var denied = api.TryGet<Network100>();
        Check(!api.IsAvailable<Network100>() && !denied.Success && ReferenceEquals(denied.Error, port.Error));
        Check(ReferenceEquals((await retained.Close(new(new("connection"), new("example:stream"), "scope", Guid.NewGuid()), options)).Error, port.Error));
        port.Denied = null;
        port.Failure = true;
        Check(ReferenceEquals((await api.Minecraft.Instances.List(new(null, new(null, 25)), options)).Error, port.Error));
        port.Failure = false;
        port.Response = new AbiValue.Null();
        var malformed = await api.Minecraft.Instances.List(new(null, new(null, 25)), options);
        Check(!malformed.Success && malformed.Error!.Code == AbiErrors.SCHEMA_INVALID && malformed.Error.OperationId == options.OperationId);
        int before = port.Calls;
        var invalid = await api.Minecraft.Instances.Read(new(null!), options);
        Check(!invalid.Success && invalid.Error!.Code == AbiErrors.SCHEMA_INVALID && before == port.Calls);
        var oversized = await api.Minecraft.Instances.List(new(null, new(new string('x', DataCodec.MaximumStringLength + 1), 25)), options);
        Check(!oversized.Success && before == port.Calls);
        Invalid(() => QualifiedId.Read(new AbiValue.Utf8String("../../host")));
        Invalid(() => DataCodec.ReadEnum<OperationState>(new AbiValue.Utf8String("0")));
        Invalid(() => DataCodec.WriteString("\ud800"));
        Invalid(() => DataCodec.ReadString(new AbiValue.Utf8String("\udfff")));
        Invalid(() => DataCodec.Validate(new AbiValue.Bytes(new byte[DataCodec.MaximumBytes + 1].ToImmutableArray())));
        AbiValue nested = new AbiValue.Null();
        for (int i = 0; i < DataCodec.MaximumDepth + 1; i++) nested = new AbiValue.Array([nested]);
        Invalid(() => DataCodec.Validate(nested));
        var snap = new Snapshot<EntityRequest>(new(new("stable-instance-id")), new("opaque:revision"), 3, DateTimeOffset.Parse("2026-11-11T01:00:00+08:00"));
        Check(Snapshot<EntityRequest>.Read(Snapshot<EntityRequest>.Write(snap)) == snap);
        Check(Abi100Schemas.Validate(Abi100Schemas.PageOfCatalogProject, Fixture("Page<CatalogProject>")));
        Check(!Abi100Schemas.Validate(Abi100Schemas.PageOfCatalogProject, Fixture("Page<CatalogVersion>")));
        Check(!Abi100Schemas.Validate(Abi100Schemas.PageOfCatalogProject with { Digest = "wrong" }, Fixture("Page<CatalogProject>")));
        var scope = new FileRef(Guid.NewGuid(), Guid.NewGuid(), "chosen-directory");
        Check(FileRef.Read(FileRef.Write(scope)) == scope);
        var u64 = new RegistrationRef(ulong.MaxValue, "plugin", Guid.NewGuid(), new("example:entry"), RegistrationState.Staged);
        Check(RegistrationRef.Read(RegistrationRef.Write(u64)) == u64);
        var make = new Negotiator(port);
        var draft = new Abi100Draft(port).Require("nexa.minecraft.launch", 1).Optional("nexa.catalog", 1).Include(new(8));
        var result = await draft.Make(make, options.OperationId, ["nexa.minecraft.launch.read"], default);
        Check(!result.Success && ReferenceEquals(result.Error, port.Error));
        Check(make.Options!.OperationId == options.OperationId && make.Options.RequiredCapabilities.Single().ContractId == "nexa.minecraft.launch" && make.Options.OptionalCapabilities.Single().ContractId == "nexa.catalog" && make.Experiments.Single().Value == 8);
        Check(descriptors.Single(x => x.Group == "Network" && x.Name == "Receive").Phases.SequenceEqual(["Active"]));
        api.Dispose();
        Check(!api.TryGet<Network100>().Success);
        Console.WriteLine("PASS: 346 typed draft operations, nested groups, DTO codecs, opaque identifiers, capability revocation, malformed data bounds, exact Make requirements and Host failure preservation.");

        AbiValue Fixture(string type)
        {
            if (type.EndsWith('?')) return new AbiValue.Null();
            if (type.EndsWith("[]")) return new AbiValue.Array([]);
            if (type.StartsWith("Page<")) return DataCodec.Map(("items", new AbiValue.Array([Fixture(type[5..^1])])), ("nextCursor", new AbiValue.Null()), ("revision", new AbiValue.Utf8String("revision")));
            if (type.StartsWith("Snapshot<")) return DataCodec.Map(("value", Fixture(type[9..^1])), ("revision", new AbiValue.Utf8String("revision")), ("schemaVersion", new AbiValue.UInt64(1)), ("observedAt", DataCodec.WriteTimestamp(DateTimeOffset.UnixEpoch)));
            if (spec.GetProperty("enums").TryGetProperty(type, out var enumeration)) return new AbiValue.Utf8String(enumeration[0].GetString()!);
            if (spec.GetProperty("models").TryGetProperty(type, out var model))
                return new AbiValue.Map(model.EnumerateArray().ToImmutableDictionary(field => { var name = field.GetProperty("name").GetString()!; return char.ToLowerInvariant(name[0]) + name[1..]; }, field => Fixture(field.GetProperty("type").GetString()!)));
            return type switch
            {
                "string" => new AbiValue.Utf8String("fixture"), "QualifiedId" => new AbiValue.Utf8String("example:fixture"),
                "EntityId" or "Revision" => new AbiValue.Utf8String("opaque"), "UriRef" => new AbiValue.Utf8String("https://example.invalid/"),
                "Guid" => DataCodec.WriteGuid(Guid.Empty), "DateTimeOffset" => DataCodec.WriteTimestamp(DateTimeOffset.UnixEpoch),
                "bool" => new AbiValue.Bool(true), "long" => new AbiValue.Int64(1), "ulong" => new AbiValue.UInt64(ulong.MaxValue),
                "double" => new AbiValue.Float64(0.5), "AbiValue" => new AbiValue.Null(), _ => throw new InvalidOperationException(type)
            };
        }
    }
    private static bool Equal(AbiValue a, AbiValue b) => (a, b) switch
    {
        (AbiValue.Map x, AbiValue.Map y) => x.Value.Count == y.Value.Count && x.Value.All(kv => y.Value.TryGetValue(kv.Key, out var v) && Equal(kv.Value, v)),
        (AbiValue.Array x, AbiValue.Array y) => x.Value.Length == y.Value.Length && x.Value.Zip(y.Value).All(pair => Equal(pair.First, pair.Second)),
        (AbiValue.Bytes x, AbiValue.Bytes y) => x.Value.SequenceEqual(y.Value),
        _ => a == b
    };
    private static void Check(bool value, string message = "ABI v0.2 assertion failed.") { if (!value) throw new InvalidOperationException(message); }
    private static void Invalid(Action action) { try { action(); } catch (FormatException) { return; } throw new InvalidOperationException("Malformed value was accepted."); }
    private sealed class Port : ABIContext, IAbilityV1
    {
        public AbiContextInfo Info { get; } = new(new(1), Guid.NewGuid(), new("fixture", "1", Guid.NewGuid()), 100, [], [], Guid.NewGuid(), "digest", "fixture", []);
        public AbiContextHandle Context => Info.Handle;
        public AbiError Error { get; } = new(AbiErrors.CAPABILITY_UNAVAILABLE, "missing", "Test", "fixture", "fixture", Guid.NewGuid(), Guid.NewGuid(), false, ImmutableDictionary<string, string>.Empty);
        public string? Denied, Contract;
        public uint Method;
        public int Calls;
        public bool Failure;
        public InvocationOptions? Last;
        public AbiValue? Arguments;
        public AbiValue Response = new AbiValue.Null();
        public AbiReply<IAbilityV1> GetAbility(string contractId) => contractId == Denied ? AbiReply<IAbilityV1>.Fail(Error) : AbiReply<IAbilityV1>.Ok(this);
        public AbiReply<IAbilityV1> GetExperiment(Guid id, string contractId) => AbiReply<IAbilityV1>.Fail(Error);
        public ValueTask<AbiReply<AbiValue>> Invoke(string contractId, uint methodId, AbiValue arguments, InvocationOptions options)
        { Calls++; Contract = contractId; Method = methodId; Arguments = arguments; Last = options; return ValueTask.FromResult(Failure ? AbiReply<AbiValue>.Fail(Error) : AbiReply<AbiValue>.Ok(Response)); }
    }
    private sealed class Negotiator(Port port) : IAbiNegotiatorV1
    {
        public MakeOptions? Options;
        public ImmutableArray<ExperimentRef> Experiments;
        public ValueTask<AbiReply<ABIContext>> GetABIContext(uint version, InvocationOptions options) => throw new NotSupportedException();
        public ValueTask<AbiReply<ExperimentRef>> GetExpermentABI(Guid expId, InvocationOptions options) => throw new NotSupportedException();
        public ValueTask<AbiReply<ABIContext>> MakeABIContext(ABIContext draft, ImmutableArray<ExperimentRef> experiments, MakeOptions options, CancellationToken cancellation)
        { Options = options; Experiments = experiments; return ValueTask.FromResult(AbiReply<ABIContext>.Fail(port.Error)); }
    }
}
