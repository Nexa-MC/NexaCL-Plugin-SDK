namespace Nexa.Plugin.Bootstrap.V1;

/// <summary>Source-compatible spelling without adding a required Bootstrap member.</summary>
public static class AbiNegotiatorExtensions
{
    public static ValueTask<AbiReply<ExperimentRef>> GetExperimentABI(this IAbiNegotiatorV1 negotiator, Guid expId, InvocationOptions options)
    {
        ArgumentNullException.ThrowIfNull(negotiator);
#pragma warning disable CS0618 // Forward to the frozen Bootstrap V1 slot.
        return negotiator.GetExpermentABI(expId, options);
#pragma warning restore CS0618
    }
}
