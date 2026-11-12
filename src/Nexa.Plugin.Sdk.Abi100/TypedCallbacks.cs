using System.Collections.Immutable;
using Nexa.Plugin.Bootstrap.V1;
using Nexa.Plugin.Sdk.Abi100.Data;
namespace Nexa.Plugin.Sdk.Abi100;

/// <summary>A local typed callback lease. Registering it does not subscribe or publish a service.</summary>
public sealed class TypedCallbackRegistration : IDisposable
{
    private ICallbacksV1? _owner;
    public CallbackHandle Handle { get; }
    internal TypedCallbackRegistration(ICallbacksV1 owner, CallbackHandle handle) { _owner = owner; Handle = handle; }
    public void Dispose() => Interlocked.Exchange(ref _owner, null)?.Release(Handle);
}

public static class TypedCallbacks
{
    public static TypedCallbackRegistration Register<TInput, TOutput>(this ICallbacksV1 callbacks, string contract,
        Func<TInput, InvocationOptions, ValueTask<AbiReply<TOutput>>> handler)
        where TInput : IAbiData<TInput> where TOutput : IAbiData<TOutput>
    {
        ArgumentNullException.ThrowIfNull(callbacks); ArgumentNullException.ThrowIfNull(handler);
        ArgumentException.ThrowIfNullOrWhiteSpace(contract);
        var handle = callbacks.Register(contract, async (input, invocation) =>
        {
            TInput request;
            try { DataCodec.Validate(input); request = TInput.Read(input); }
            catch (FormatException) { return Invalid(invocation); }
            if (invocation.Cancellation.IsCancellationRequested) return Failure(AbiErrors.CANCELLED, invocation);
            var reply = await handler(request, invocation).ConfigureAwait(false);
            if (!reply.Success) return AbiReply<AbiValue>.Fail(reply.Error!);
            try { var value = TOutput.Write(reply.Value); DataCodec.Validate(value); return AbiReply<AbiValue>.Ok(value); }
            catch (FormatException) { return Invalid(invocation); }
        });
        if (handle.Value == 0) throw new InvalidOperationException(AbiErrors.HANDLE_INVALID);
        return new(callbacks, handle);

        AbiReply<AbiValue> Invalid(InvocationOptions options) => Failure(AbiErrors.SCHEMA_INVALID, options);
        AbiReply<AbiValue> Failure(string code, InvocationOptions options) => AbiReply<AbiValue>.Fail(new(code, code, "Callback", contract,
            "", Guid.Empty, options.CorrelationId, false, ImmutableDictionary<string, string>.Empty) { OperationId = options.OperationId });
    }
}
