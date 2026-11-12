using System.Collections.Immutable;
using Nexa.Plugin.Bootstrap.V1;
namespace Nexa.Plugin.Sdk.Abi100.Data;

public sealed record QualifiedId : IAbiData<QualifiedId>
{
    public string Value { get; }
    public QualifiedId(string value)
    {
        if (string.IsNullOrEmpty(value) || value.Length > 512) throw new FormatException("Expected namespace:path.");
        var colon = value.IndexOf(':');
        if (colon < 1 || colon == value.Length - 1 || value.LastIndexOf(':') != colon ||
            !value[..colon].All(c => char.IsAsciiLetterLower(c) || char.IsAsciiDigit(c) || c is '_' or '.' or '-') ||
            !value[(colon + 1)..].All(c => char.IsAsciiLetterLower(c) || char.IsAsciiDigit(c) || c is '_' or '.' or '-' or '/'))
            throw new FormatException("Expected namespace:path.");
        Value = value;
    }
    public bool IsHostNamespace => Value.StartsWith("nexa:", StringComparison.Ordinal);
    public override string ToString() => Value;
    public static AbiValue Write(QualifiedId value, int depth = 0) => DataCodec.WriteString((value ?? throw new ArgumentNullException(nameof(value))).Value);
    public static QualifiedId Read(AbiValue value, int depth = 0) => new(DataCodec.ReadString(value));
}

public sealed record EntityId : IAbiData<EntityId>
{
    public string Value { get; }
    public EntityId(string value) { if (string.IsNullOrWhiteSpace(value) || value.Length > 1024) throw new FormatException("Invalid entity ID."); Value = value; }
    public static AbiValue Write(EntityId value, int depth = 0) => DataCodec.WriteString((value ?? throw new ArgumentNullException(nameof(value))).Value);
    public static EntityId Read(AbiValue value, int depth = 0) => new(DataCodec.ReadString(value));
}

/// <summary>Opaque equality token, never an incrementable sequence number.</summary>
public sealed record Revision : IAbiData<Revision>
{
    public string Value { get; }
    public Revision(string value) { if (string.IsNullOrWhiteSpace(value) || value.Length > 1024) throw new FormatException("Invalid revision."); Value = value; }
    public static AbiValue Write(Revision value, int depth = 0) => DataCodec.WriteString((value ?? throw new ArgumentNullException(nameof(value))).Value);
    public static Revision Read(AbiValue value, int depth = 0) => new(DataCodec.ReadString(value));
}

/// <summary>An address, not an authority grant. Host applies scheme and network policy.</summary>
public sealed record UriRef : IAbiData<UriRef>
{
    public string Value { get; }
    public UriRef(string value) { if (value is null || value.Length > 8192 || !Uri.TryCreate(value, UriKind.Absolute, out _)) throw new FormatException("Expected absolute URI."); Value = value; }
    public static AbiValue Write(UriRef value, int depth = 0) => DataCodec.WriteString((value ?? throw new ArgumentNullException(nameof(value))).Value);
    public static UriRef Read(AbiValue value, int depth = 0) => new(DataCodec.ReadString(value));
}

public sealed record Page<T>(ImmutableArray<T> Items, string? NextCursor, Revision Revision) : IAbiData<Page<T>> where T : IAbiData<T>
{
    public static AbiValue Write(Page<T> value, int depth = 0)
    {
        using var scope = DataCodec.Enter(depth);
        return DataCodec.Map(("items", DataCodec.WriteArray(value.Items, T.Write, depth + 1)), ("nextCursor", value.NextCursor is null ? new AbiValue.Null() : DataCodec.WriteString(value.NextCursor)), ("revision", Revision.Write(value.Revision)));
    }
    public static Page<T> Read(AbiValue value, int depth = 0)
    {
        using var scope = DataCodec.Enter(depth); var map = DataCodec.ReadMap(value); var cursor = DataCodec.Field(map, "nextCursor");
        return new(DataCodec.ReadArray(DataCodec.Field(map, "items"), T.Read, depth + 1), cursor is AbiValue.Null ? null : DataCodec.ReadString(cursor), Revision.Read(DataCodec.Field(map, "revision")));
    }
}
public sealed record Snapshot<T>(T Value, Revision Revision, ulong SchemaVersion, DateTimeOffset ObservedAt) : IAbiData<Snapshot<T>> where T : IAbiData<T>
{
    public static AbiValue Write(Snapshot<T> value, int depth = 0)
    { using var scope = DataCodec.Enter(depth); return DataCodec.Map(("value", T.Write(value.Value, depth + 1)), ("revision", Revision.Write(value.Revision)), ("schemaVersion", DataCodec.WriteUInt64(value.SchemaVersion)), ("observedAt", DataCodec.WriteTimestamp(value.ObservedAt))); }
    public static Snapshot<T> Read(AbiValue value, int depth = 0)
    { using var scope = DataCodec.Enter(depth); var map = DataCodec.ReadMap(value); return new(T.Read(DataCodec.Field(map, "value"), depth + 1), Revision.Read(DataCodec.Field(map, "revision")), DataCodec.ReadUInt64(DataCodec.Field(map, "schemaVersion")), DataCodec.ReadTimestamp(DataCodec.Field(map, "observedAt"))); }
}
