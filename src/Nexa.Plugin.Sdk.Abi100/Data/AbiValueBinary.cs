using System.Collections.Immutable;
using System.Text;
using Nexa.Plugin.Bootstrap.V1;
namespace Nexa.Plugin.Sdk.Abi100.Data;

/// <summary>Closed-value payload codec v1. This does not define a Host transport frame.</summary>
public static class AbiValueBinary
{
    private static readonly UTF8Encoding Utf8 = new(false, true);
    public static byte[] Encode(AbiValue value)
    {
        DataCodec.Validate(value);
        using var stream = new MemoryStream(); using var writer = new BinaryWriter(stream, Utf8, true);
        writer.Write(1u); Write(value); writer.Flush();
        if (stream.Length > DataCodec.MaximumBytes) throw new FormatException("ABI binary byte budget exceeded.");
        return stream.ToArray();
        void Text(string text) { byte[] bytes = Utf8.GetBytes(text); writer.Write(bytes.Length); writer.Write(bytes); }
        void Write(AbiValue item)
        {
            switch (item)
            {
                case AbiValue.Null: writer.Write((byte)0); break;
                case AbiValue.Bool b: writer.Write((byte)1); writer.Write(b.Value); break;
                case AbiValue.Int64 n: writer.Write((byte)2); writer.Write(n.Value); break;
                case AbiValue.UInt64 n: writer.Write((byte)3); writer.Write(n.Value); break;
                case AbiValue.Float64 n: writer.Write((byte)4); writer.Write(n.Value); break;
                case AbiValue.Utf8String s: writer.Write((byte)5); Text(s.Value); break;
                case AbiValue.Bytes b: writer.Write((byte)6); writer.Write(b.Value.Length); writer.Write(b.Value.AsSpan()); break;
                case AbiValue.Array a: writer.Write((byte)7); writer.Write(a.Value.Length); foreach (var child in a.Value) Write(child); break;
                case AbiValue.Map m: writer.Write((byte)8); writer.Write(m.Value.Count); foreach (var pair in m.Value.OrderBy(p => p.Key, StringComparer.Ordinal)) { Text(pair.Key); Write(pair.Value); } break;
                default: throw new FormatException("Unknown ABI value.");
            }
        }
    }
    public static AbiValue Decode(ReadOnlySpan<byte> bytes)
    {
        if (bytes.Length > DataCodec.MaximumBytes) throw new FormatException("ABI binary byte budget exceeded.");
        using var stream = new MemoryStream(bytes.ToArray(), false); using var reader = new BinaryReader(stream, Utf8);
        int nodes = 0;
        try
        {
            if (reader.ReadUInt32() != 1) throw Invalid();
            var result = Read(0);
            if (stream.Position != stream.Length) throw Invalid();
            DataCodec.Validate(result); return result;
        }
        catch (Exception e) when (e is EndOfStreamException or DecoderFallbackException or ArgumentException or OverflowException)
        { throw new FormatException("Malformed ABI binary value.", e); }
        FormatException Invalid() => new("Malformed ABI binary value.");
        byte[] Bytes()
        {
            int count = reader.ReadInt32();
            if (count < 0 || count > stream.Length - stream.Position) throw Invalid();
            return reader.ReadBytes(count);
        }
        string Text() => Utf8.GetString(Bytes());
        int Count() { int count = reader.ReadInt32(); if (count < 0 || count > DataCodec.MaximumItems - nodes) throw Invalid(); return count; }
        AbiValue Read(int depth)
        {
            DataCodec.CheckDepth(depth); if (++nodes > DataCodec.MaximumItems) throw Invalid();
            switch (reader.ReadByte())
            {
                case 0: return new AbiValue.Null();
                case 1: byte b = reader.ReadByte(); if (b > 1) throw Invalid(); return new AbiValue.Bool(b != 0);
                case 2: return new AbiValue.Int64(reader.ReadInt64());
                case 3: return new AbiValue.UInt64(reader.ReadUInt64());
                case 4: return new AbiValue.Float64(reader.ReadDouble());
                case 5: return DataCodec.WriteString(Text());
                case 6: return new AbiValue.Bytes(Bytes().ToImmutableArray());
                case 7:
                    var items = ImmutableArray.CreateBuilder<AbiValue>(Count());
                    int length = items.Capacity;
                    for (int i = 0; i < length; i++) items.Add(Read(depth + 1));
                    return new AbiValue.Array(items.MoveToImmutable());
                case 8:
                    int count = Count(); var fields = ImmutableDictionary.CreateBuilder<string, AbiValue>();
                    for (int i = 0; i < count; i++) { string key = Text(); if (fields.ContainsKey(key)) throw Invalid(); fields.Add(key, Read(depth + 1)); }
                    return new AbiValue.Map(fields.ToImmutable());
                default: throw Invalid();
            }
        }
    }
}
