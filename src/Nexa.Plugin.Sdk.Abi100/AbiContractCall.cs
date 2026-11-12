using System.Collections.Immutable;
using Nexa.Plugin.Bootstrap.V1;
using Nexa.Plugin.Sdk.Abi100.Data;
namespace Nexa.Plugin.Sdk.Abi100;

internal static class AbiContractCall
{
    public static async ValueTask<AbiReply<TOutput>> Invoke<TInput, TOutput>(IAbilityV1 ability, string contract, uint method, TInput input, InvocationOptions options)
        where TInput : IAbiData<TInput> where TOutput : IAbiData<TOutput>
    {
        AbiValue arguments;
        try { arguments = TInput.Write(input); DataCodec.Validate(arguments); }
        catch (Exception e) when (e is FormatException or ArgumentException) { return Invalid<TOutput>(contract, options); }
        // Transport exceptions are not converted into retryable success or automatically retried.
        var result = await ability.Invoke(contract, method, arguments, options).ConfigureAwait(false);
        if (!result.Success) return AbiReply<TOutput>.Fail(result.Error!);
        try { DataCodec.Validate(result.Value); return AbiReply<TOutput>.Ok(TOutput.Read(result.Value)); }
        catch (Exception e) when (e is FormatException or ArgumentException) { return Invalid<TOutput>(contract, options); }
    }
    private static AbiReply<T> Invalid<T>(string contract, InvocationOptions options) => AbiReply<T>.Fail(new(
        AbiErrors.SCHEMA_INVALID, "ABI payload does not match the bounded schema.", "SDK", contract, "", Guid.Empty,
        options.CorrelationId, false, ImmutableDictionary<string, string>.Empty) { OperationId = options.OperationId });
}
