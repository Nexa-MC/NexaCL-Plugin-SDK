using System.Collections.Immutable;
using Nexa.Plugin.Bootstrap.V1;
namespace Nexa.Plugin.Sdk.Abi100;

/// <summary>Local immutable draft assembly. Only Host Make can authorize the result.</summary>
public sealed class Abi100Draft
{
    private readonly ABIContext _draft;
    private readonly ImmutableArray<ExperimentRef> _experiments;
    private readonly ImmutableArray<CapabilityRequirement> _required, _optional;
    public Abi100Draft(ABIContext draft) : this(draft, [], [], []) { }
    private Abi100Draft(ABIContext draft, ImmutableArray<ExperimentRef> experiments, ImmutableArray<CapabilityRequirement> required, ImmutableArray<CapabilityRequirement> optional)
    {
        ArgumentNullException.ThrowIfNull(draft);
        if (draft.Info.StableAbiVersion != 100) throw new ArgumentException("ABI 100 requires an exact ABI 100 draft.", nameof(draft));
        _draft = draft; _experiments = experiments; _required = required; _optional = optional;
    }
    public Abi100Draft Include(ExperimentRef experiment)
    {
        if (experiment.Value == 0) throw new ArgumentException("An experiment must be obtained from Host.", nameof(experiment));
        return new(_draft, _experiments.Contains(experiment) ? _experiments : _experiments.Add(experiment), _required, _optional);
    }
    public Abi100Draft Require(string contractId, uint minimumVersion = 1) => WithCapability(contractId, minimumVersion, true);
    public Abi100Draft Optional(string contractId, uint minimumVersion = 1) => WithCapability(contractId, minimumVersion, false);
    private Abi100Draft WithCapability(string contract, uint version, bool required)
    {
        if (string.IsNullOrWhiteSpace(contract) || version == 0) throw new ArgumentException("A capability needs an ID and positive version.");
        if (_required.Any(c => c.ContractId == contract) || _optional.Any(c => c.ContractId == contract)) throw new ArgumentException("Duplicate capability requirement.");
        var item = new CapabilityRequirement(contract, version);
        return new(_draft, _experiments, required ? _required.Add(item) : _required, required ? _optional : _optional.Add(item));
    }
    /// <summary>Reuse the same operation ID only to query/retry the same Make inputs. No automatic fallback.</summary>
    public ValueTask<AbiReply<ABIContext>> Make(IAbiNegotiatorV1 negotiator, Guid operationId, ImmutableArray<string> permissions, CancellationToken cancellation) =>
        negotiator.MakeABIContext(_draft, _experiments, new(operationId, permissions) { RequiredCapabilities = _required, OptionalCapabilities = _optional }, cancellation);
}
