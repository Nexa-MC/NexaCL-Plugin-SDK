using System.Collections.Immutable;
using System.Globalization;
using Nexa.Plugin.Bootstrap.V1;

namespace Nexa.Plugin.Sdk.Abi100.Data;

public interface IAbiData<TSelf> where TSelf : IAbiData<TSelf>
{
    static abstract AbiValue Write(TSelf value, int depth = 0);
    static abstract TSelf Read(AbiValue value, int depth = 0);
}

/// <summary>Bounded closed-value codecs. These SDK limits do not replace Host quotas.</summary>
public static class DataCodec
{
    private static readonly System.Text.UTF8Encoding StrictUtf8 = new(false, true);
    private static int StringBytes(string value)
    {
        try { return StrictUtf8.GetByteCount(value); }
        catch (System.Text.EncoderFallbackException) { throw Invalid(); }
    }
    [ThreadStatic] private static CodecBudget? _budget;
    private sealed class CodecBudget { internal int Users, Nodes, Bytes; }
    private sealed class BudgetScope(CodecBudget budget) : IDisposable
    {
        public void Dispose() { if (--budget.Users == 0) _budget = null; }
    }
    public static IDisposable Enter(int depth)
    {
        CheckDepth(depth);
        var budget = _budget ??= new();
        if (++budget.Nodes > MaximumItems) { if (budget.Users == 0) _budget = null; throw Invalid(); }
        budget.Users++; return new BudgetScope(budget);
    }
    private static void Charge(int nodes, int bytes = 0)
    {
        if (_budget is not { } budget) return;
        budget.Nodes += nodes; budget.Bytes += bytes;
        if (budget.Nodes > MaximumItems || budget.Bytes > MaximumBytes) throw Invalid();
    }
    public const int MaximumDepth = 32;
    public const int MaximumItems = 16384;
    public const int MaximumStringLength = 65536;
    public const int MaximumBytes = 4 * 1024 * 1024;
    public static void CheckDepth(int depth) { if (depth > MaximumDepth) throw new FormatException("ABI value nesting limit exceeded."); }
    public static AbiValue WriteString(string value)
    {
        if (value is null || value.Length > MaximumStringLength) throw new FormatException("Invalid ABI string.");
        Charge(0, StringBytes(value));
        return new AbiValue.Utf8String(value);
    }
    public static string ReadString(AbiValue value)
    {
        if (value is not AbiValue.Utf8String s || s.Value is null || s.Value.Length > MaximumStringLength) throw Invalid();
        Charge(0, StringBytes(s.Value)); return s.Value;
    }
    public static AbiValue WriteBoolean(bool value) => new AbiValue.Bool(value);
    public static bool ReadBoolean(AbiValue value) => value is AbiValue.Bool b ? b.Value : throw Invalid();
    public static AbiValue WriteInt64(long value) => new AbiValue.Int64(value);
    public static long ReadInt64(AbiValue value) => value is AbiValue.Int64 n ? n.Value : throw Invalid();
    public static AbiValue WriteUInt64(ulong value) => new AbiValue.UInt64(value);
    public static ulong ReadUInt64(AbiValue value) => value is AbiValue.UInt64 n ? n.Value : throw Invalid();
    public static AbiValue WriteFloat64(double value) => new AbiValue.Float64(value);
    public static double ReadFloat64(AbiValue value) => value is AbiValue.Float64 n ? n.Value : throw Invalid();
    public static AbiValue WriteGuid(Guid value) => WriteString(value.ToString("D"));
    public static Guid ReadGuid(AbiValue value) => Guid.TryParseExact(ReadString(value), "D", out var id) ? id : throw Invalid();
    public static AbiValue WriteTimestamp(DateTimeOffset value) => WriteString(value.ToString("O", CultureInfo.InvariantCulture));
    public static DateTimeOffset ReadTimestamp(AbiValue value) => DateTimeOffset.TryParseExact(ReadString(value), "O", CultureInfo.InvariantCulture, DateTimeStyles.None, out var time) ? time : throw Invalid();
    public static AbiValue WriteEnum<T>(T value) where T : struct, Enum => Enum.IsDefined(value) ? WriteString(value.ToString()) : throw Invalid();
    public static T ReadEnum<T>(AbiValue value) where T : struct, Enum => Enum.TryParse<T>(ReadString(value), false, out var result) && Enum.IsDefined(result) && result.ToString() == ReadString(value) ? result : throw Invalid();
    public static AbiValue WriteValue(AbiValue value) { Validate(value); return value; }
    public static AbiValue ReadValue(AbiValue value) { Validate(value); return value; }
    public static AbiValue Map(params (string Key, AbiValue Value)[] fields) => new AbiValue.Map(fields.ToImmutableDictionary(f => f.Key, f => f.Value));
    public static ImmutableDictionary<string, AbiValue> ReadMap(AbiValue value) => value is AbiValue.Map m && m.Value is not null && m.Value.Count <= MaximumItems ? m.Value : throw Invalid();
    public static AbiValue Field(ImmutableDictionary<string, AbiValue> map, string name) => map.TryGetValue(name, out var value) ? value : throw new FormatException($"Missing ABI field: {name}.");
    public static AbiValue WriteArray<T>(ImmutableArray<T> values, Func<T, int, AbiValue> encode, int depth)
    {
        using var scope = Enter(depth);
        if (values.IsDefault || values.Length > MaximumItems) throw Invalid();
        Charge(values.Length);
        return new AbiValue.Array(values.Select(v => encode(v, depth + 1)).ToImmutableArray());
    }
    public static ImmutableArray<T> ReadArray<T>(AbiValue value, Func<AbiValue, int, T> decode, int depth)
    {
        using var scope = Enter(depth);
        if (value is not AbiValue.Array a || a.Value.IsDefault || a.Value.Length > MaximumItems) throw Invalid();
        Charge(a.Value.Length);
        return a.Value.Select(v => decode(v, depth + 1)).ToImmutableArray();
    }
    public static void Validate(AbiValue value)
    {
        int nodes = 0, bytes = 0;
        Visit(value, 0);
        void Visit(AbiValue v, int depth)
        {
            CheckDepth(depth);
            Charge(1);
            if (++nodes > MaximumItems) throw Invalid();
            switch (v)
            {
                case AbiValue.Null or AbiValue.Bool or AbiValue.Int64 or AbiValue.UInt64 or AbiValue.Float64: break;
                case AbiValue.Utf8String s: bytes += System.Text.Encoding.UTF8.GetByteCount(ReadString(s)); break;
                case AbiValue.Bytes b when !b.Value.IsDefault: bytes += b.Value.Length; break;
                case AbiValue.Array a when !a.Value.IsDefault && a.Value.Length <= MaximumItems:
                    foreach (var child in a.Value) Visit(child, depth + 1);
                    break;
                case AbiValue.Map m when m.Value is not null && m.Value.Count <= MaximumItems:
                    foreach (var (key, child) in m.Value) { bytes += System.Text.Encoding.UTF8.GetByteCount(ReadString(WriteString(key))); Visit(child, depth + 1); }
                    break;
                default: throw Invalid();
            }
            if (bytes > MaximumBytes) throw Invalid();
        }
    }
    private static FormatException Invalid() => new("Invalid or oversized ABI value.");
}
