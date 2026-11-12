#ifndef NEXA_GUEST_H
#define NEXA_GUEST_H
/* Freestanding C11 guest SDK. All offsets/lengths are bounded by guest memory.
 * Values are borrowed until the next nexa_resume call. No WASI or libc needed. */
typedef unsigned char nx_u8;
typedef unsigned int nx_u32;
typedef unsigned long long nx_u64;
typedef long long nx_i64;
typedef double nx_f64;
typedef struct { const nx_u8 *data; nx_u32 size; } nx_text;
typedef struct { const nx_u8 *data; nx_u32 size; } nx_value;
typedef struct { nx_u8 *data; nx_u32 size, capacity; } nx_writer;
typedef struct { const nx_u8 *data; nx_u32 size, offset, nodes; } nx_reader;
#define NX_EXPORT(name) __attribute__((export_name(name)))
#define NX_MAX_BYTES (4u * 1024u * 1024u)

static inline void nx_require(int ok) { if (!ok) __builtin_trap(); }
static inline nx_u32 nx_strlen(const char *s) { nx_u32 n = 0; while (s[n]) { nx_require(n < 65536); n++; } return n; }
static inline void nx_reserve(nx_writer *w, nx_u32 count) { nx_require(w->size <= w->capacity && count <= w->capacity - w->size && w->capacity <= NX_MAX_BYTES); }
static inline void nx_byte(nx_writer *w, nx_u8 n) { nx_reserve(w, 1); w->data[w->size++] = n; }
static inline void nx_word(nx_writer *w, nx_u32 n) { for (nx_u32 i = 0; i < 4; i++) nx_byte(w, (nx_u8)(n >> (8 * i))); }
static inline void nx_copy(nx_writer *w, const nx_u8 *data, nx_u32 size) { nx_reserve(w, size); for (nx_u32 i = 0; i < size; i++) w->data[w->size++] = data[i]; }
static inline void nx_key(nx_writer *w, const char *s) { nx_u32 size = nx_strlen(s); nx_word(w, size); nx_copy(w, (const nx_u8 *)s, size); }
static inline void nx_string(nx_writer *w, const char *s) { nx_byte(w, 5); nx_key(w, s); }
static inline void nx_null(nx_writer *w) { nx_byte(w, 0); }
static inline void nx_boolean(nx_writer *w, int value) { nx_byte(w, 1); nx_byte(w, value ? 1 : 0); }
static inline void nx_unsigned(nx_writer *w, nx_u64 value) { nx_byte(w, 3); for (nx_u32 i = 0; i < 8; i++) nx_byte(w, (nx_u8)(value >> (8 * i))); }
static inline void nx_array(nx_writer *w, nx_u32 count) { nx_require(count <= 16384); nx_byte(w, 7); nx_word(w, count); }
static inline void nx_map(nx_writer *w, nx_u32 count) { nx_require(count <= 16384); nx_byte(w, 8); nx_word(w, count); }
static inline void nx_start(nx_writer *w) { w->size = 0; nx_word(w, 1); }
static inline nx_u8 nx_take(nx_reader *r) { nx_require(r->offset < r->size); return r->data[r->offset++]; }
static inline nx_u32 nx_read_word(nx_reader *r) { nx_u32 n = 0; for (nx_u32 i = 0; i < 4; i++) n |= (nx_u32)nx_take(r) << (8 * i); return n; }
static inline void nx_advance(nx_reader *r, nx_u32 count) { nx_require(r->offset <= r->size && count <= r->size - r->offset); r->offset += count; }
static inline nx_u32 nx_utf8(const nx_u8 *data, nx_u32 size) {
    nx_u32 units=0;
    for(nx_u32 i=0;i<size;) {
        nx_u32 c=data[i++], minimum=0, extra=0;
        if(c<128) { units++; continue; }
        if(c>=194 && c<=223) { extra=1; minimum=128; c&=31; }
        else if(c>=224 && c<=239) { extra=2; minimum=2048; c&=15; }
        else if(c>=240 && c<=244) { extra=3; minimum=65536; c&=7; }
        else __builtin_trap();
        nx_require(extra<=size-i);
        for(nx_u32 j=0;j<extra;j++) { nx_u32 next=data[i++]; nx_require((next&192)==128); c=(c<<6)|(next&63); }
        nx_require(c>=minimum && c<=1114111 && !(c>=55296 && c<=57343)); units+=c>=65536?2:1;
    }
    nx_require(units<=65536); return units;
}
static inline void nx_qualified_id(nx_text text) {
    nx_require(text.size>=3 && text.size<=512); int colon=0;
    for(nx_u32 i=0;i<text.size;i++) { nx_u8 c=text.data[i];
        if(c==':') { nx_require(!colon && i>0 && i<text.size-1); colon=1; }
        else nx_require((c>='a' && c<='z') || (c>='0' && c<='9') || c=='_' || c=='.' || c=='-' || (colon && c=='/'));
    } nx_require(colon);
}
static inline void nx_guid(nx_text text) {
    nx_require(text.size==36); for(nx_u32 i=0;i<36;i++) { nx_u8 c=text.data[i];
        if(i==8 || i==13 || i==18 || i==23) nx_require(c=='-'); else nx_require((c>='0'&&c<='9')||(c>='a'&&c<='f')||(c>='A'&&c<='F'));
    }
}
static inline nx_u32 nx_decimal(const nx_u8 *text,nx_u32 count) { nx_u32 n=0; for(nx_u32 i=0;i<count;i++) { nx_require(text[i]>='0' && text[i]<='9'); n=n*10+text[i]-'0'; } return n; }
static inline void nx_timestamp(nx_text text) {
    nx_require(text.size==33); const nx_u8 *s=text.data;
    nx_require(s[4]=='-'&&s[7]=='-'&&s[10]=='T'&&s[13]==':'&&s[16]==':'&&s[19]=='.'&&(s[27]=='+'||s[27]=='-')&&s[30]==':');
    nx_u32 year=nx_decimal(s,4), month=nx_decimal(s+5,2), day=nx_decimal(s+8,2); nx_require(year>0&&month>=1&&month<=12);
    static const nx_u8 days[12]={31,28,31,30,31,30,31,31,30,31,30,31}; nx_u32 maximum=days[month-1];
    if(month==2 && year%4==0 && (year%100!=0 || year%400==0)) maximum++;
    nx_require(day>=1 && day<=maximum && nx_decimal(s+11,2)<24 && nx_decimal(s+14,2)<60 && nx_decimal(s+17,2)<60);
    (void)nx_decimal(s+20,7); nx_u32 hours=nx_decimal(s+28,2), minutes=nx_decimal(s+31,2); nx_require(hours<=14&&minutes<60&&(hours<14||minutes==0));
}
static inline void nx_uri(nx_text text) {
    nx_require(text.size>1 && nx_utf8(text.data,text.size)<=8192); nx_u32 i=0; nx_u8 c=text.data[0]; nx_require((c>='a'&&c<='z')||(c>='A'&&c<='Z'));
    for(i=1;i<text.size && text.data[i]!=':';i++) { c=text.data[i]; nx_require((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')||c=='+'||c=='-'||c=='.'); }
    nx_require(i<text.size);
}
/* Both strings have already passed nx_utf8. Compare in .NET UTF-16 ordinal
 * order: BMP below D800, supplementary scalars, then BMP E000..FFFF. */
static inline nx_u32 nx_ordinal_scalar(nx_text text, nx_u32 *offset)
{
    nx_require(*offset < text.size);
    nx_u32 c=text.data[(*offset)++], extra=0;
    if(c>=240) { c&=7; extra=3; }
    else if(c>=224) { c&=15; extra=2; }
    else if(c>=192) { c&=31; extra=1; }
    nx_require(extra<=text.size-*offset);
    for(nx_u32 i=0;i<extra;i++) c=(c<<6)|(text.data[(*offset)++]&63);
    return c>=0xe000 && c<=0xffff ? c+0x102000 : c;
}
static inline int nx_ordinal_less(nx_text left, nx_text right)
{
    nx_u32 a=0,b=0;
    while(a<left.size && b<right.size) {
        nx_u32 x=nx_ordinal_scalar(left,&a), y=nx_ordinal_scalar(right,&b);
        if(x!=y) return x<y;
    }
    return a==left.size && b<right.size;
}
static inline void nx_scan(nx_reader *r, nx_u32 depth, int check)
{
    nx_require(depth <= 32 && ++r->nodes <= 16384);
    nx_u8 tag = nx_take(r);
    switch (tag) {
    case 0: return;
    case 1: nx_require(nx_take(r) <= 1); return;
    case 2: case 3: nx_advance(r, 8); return;
    case 4: { nx_u64 bits=0; for(nx_u32 i=0;i<8;i++) bits|=(nx_u64)nx_take(r)<<(8*i); nx_require(((bits>>52)&2047)!=2047); return; }
    case 5: case 6: { nx_u32 n = nx_read_word(r), start=r->offset; nx_advance(r, n); if(check && tag==5) nx_utf8(r->data+start,n); return; }
    case 7: case 8: {
        nx_u32 n = nx_read_word(r); nx_require(n <= 16384 - r->nodes);
        nx_text previous={0,0};
        for (nx_u32 i = 0; i < n; i++) {
            if (tag == 8) {
                nx_u32 length=nx_read_word(r), start=r->offset; nx_advance(r,length);
                if(check) {
                    nx_text current={r->data+start,length};
                    nx_utf8(current.data,current.size);
                    if(i) nx_require(nx_ordinal_less(previous,current));
                    previous=current;
                }
            }
            nx_scan(r, depth + 1,check);
        }
        return;
    }
    default: __builtin_trap();
    }
}
static inline void nx_skip(nx_reader *r,nx_u32 depth) { nx_scan(r,depth,1); }
static inline nx_value nx_decode(const nx_u8 *data, nx_u32 size)
{
    nx_require(size <= NX_MAX_BYTES); nx_reader r = {data, size, 0, 0};
    nx_require(nx_read_word(&r) == 1); nx_skip(&r, 0); nx_require(r.offset == size);
    nx_value v = {data + 4, size - 4}; return v;
}
static inline int nx_bytes_equal(const nx_u8 *a, nx_u32 count, const char *b)
{
    if (count != nx_strlen(b)) return 0;
    for (nx_u32 i = 0; i < count; i++) if (a[i] != (nx_u8)b[i]) return 0;
    return 1;
}
static inline nx_value nx_field(nx_value map, const char *key)
{
    nx_reader r = {map.data, map.size, 0, 0}; nx_require(nx_take(&r) == 8);
    nx_u32 count = nx_read_word(&r); nx_require(count <= 16384);
    for (nx_u32 i = 0; i < count; i++) {
        nx_u32 size = nx_read_word(&r), offset = r.offset; nx_advance(&r, size);
        int match = nx_bytes_equal(r.data + offset, size, key); offset = r.offset;
        nx_skip(&r, 1);
        if (match) { nx_value v = {r.data + offset, r.offset - offset}; return v; }
    }
    nx_value missing = {0, 0}; return missing;
}
static inline int nx_is_string(nx_value value, const char *text)
{
    if (!value.size || value.data[0] != 5) return 0;
    nx_reader r = {value.data, value.size, 1, 0}; nx_u32 size = nx_read_word(&r);
    nx_u32 offset = r.offset; nx_advance(&r, size);
    return r.offset == r.size && nx_bytes_equal(r.data + offset, size, text);
}
static inline int nx_is_true(nx_value value) { return value.size == 2 && value.data[0] == 1 && value.data[1] == 1; }
static inline void nx_raw(nx_writer *w, nx_value value)
{
    nx_reader r = {value.data, value.size, 0, 0}; nx_skip(&r, 0); nx_require(r.offset == r.size);
    nx_copy(w, value.data, value.size);
}
static inline void nx_invoke(nx_writer *w, const char *contract, nx_u32 method, const char *idempotency_key, nx_value arguments)
{
    nx_start(w); nx_map(w, 5);
    nx_key(w, "arguments"); nx_raw(w, arguments);
    nx_key(w, "contract"); nx_string(w, contract);
    nx_key(w, "idempotencyKey"); if (idempotency_key) nx_string(w, idempotency_key); else nx_null(w);
    nx_key(w, "kind"); nx_string(w, "invoke");
    nx_key(w, "method"); nx_unsigned(w, method);
}
static inline void nx_complete(nx_writer *w, int success)
{
    nx_start(w); nx_map(w, 2);
    nx_key(w, "kind"); nx_string(w, "complete");
    nx_key(w, "value"); nx_map(w, 1); nx_key(w, "success"); nx_boolean(w, success);
}
static inline nx_u64 nx_result(nx_writer *w) { return ((nx_u64)(nx_u32)(__UINTPTR_TYPE__)w->data << 32) | w->size; }
/* Full closed-value readers/writers. Text is length-delimited, including embedded NUL. */
static inline nx_u64 nx_bits(nx_value v, nx_u8 tag) {
    nx_require(v.size == 9 && v.data[0] == tag); nx_u64 n = 0;
    for (nx_u32 i = 0; i < 8; i++) n |= (nx_u64)v.data[i + 1] << (8 * i); return n;
}
static inline nx_u64 nx_as_unsigned(nx_value v) { return nx_bits(v, 3); }
static inline nx_i64 nx_as_signed(nx_value v) { union { nx_u64 u; nx_i64 i; } n; n.u = nx_bits(v, 2); return n.i; }
static inline nx_f64 nx_as_float(nx_value v) { union { nx_u64 u; nx_f64 f; } n; n.u = nx_bits(v, 4); nx_require(((n.u >> 52) & 2047) != 2047); return n.f; }
static inline int nx_as_boolean(nx_value v) { nx_require(v.size == 2 && v.data[0] == 1 && v.data[1] <= 1); return v.data[1]; }
static inline int nx_is_missing(nx_value v) { return v.data == 0 && v.size == 0; }
static inline int nx_is_null(nx_value v) { return v.size == 1 && v.data[0] == 0; }
static inline nx_text nx_as_text(nx_value v) {
    nx_reader r = {v.data, v.size, 0, 0}; nx_require(nx_take(&r) == 5); nx_u32 size = nx_read_word(&r), start = r.offset;
    nx_advance(&r, size); nx_require(r.offset == r.size); nx_text text = {v.data + start, size}; return text;
}
static inline nx_text nx_as_bytes(nx_value v) {
    nx_reader r = {v.data, v.size, 0, 0}; nx_require(nx_take(&r) == 6); nx_u32 size = nx_read_word(&r), start = r.offset;
    nx_advance(&r, size); nx_require(r.offset == r.size); nx_text bytes = {v.data + start, size}; return bytes;
}
static inline nx_text nx_literal(const char *text) { nx_text v = {(const nx_u8 *)text, nx_strlen(text)}; return v; }
static inline void nx_text_write(nx_writer *w, nx_text text) { nx_utf8(text.data,text.size); nx_byte(w, 5); nx_word(w, text.size); nx_copy(w, text.data, text.size); }
static inline void nx_bytes(nx_writer *w, nx_text bytes) { nx_byte(w, 6); nx_word(w, bytes.size); nx_copy(w, bytes.data, bytes.size); }
static inline void nx_signed(nx_writer *w, nx_i64 value) { nx_byte(w, 2); nx_u64 n = (nx_u64)value; for (nx_u32 i=0;i<8;i++) nx_byte(w,(nx_u8)(n>>(8*i))); }
static inline void nx_float(nx_writer *w, nx_f64 value) { union { nx_u64 u; nx_f64 f; } n; n.f=value; nx_require(((n.u>>52)&2047)!=2047); nx_byte(w,4); for(nx_u32 i=0;i<8;i++) nx_byte(w,(nx_u8)(n.u>>(8*i))); }
static inline nx_u32 nx_count(nx_value array) { nx_reader r={array.data,array.size,0,0}; nx_require(nx_take(&r)==7); nx_u32 n=nx_read_word(&r); nx_require(n<=16384); return n; }
static inline nx_value nx_at(nx_value array, nx_u32 index) {
    nx_reader r={array.data,array.size,0,0}; nx_require(nx_take(&r)==7); nx_u32 n=nx_read_word(&r); nx_require(n<=16384 && index<n);
    for(nx_u32 i=0;i<index;i++) nx_skip(&r,1); nx_u32 start=r.offset; nx_skip(&r,1); nx_value v={r.data+start,r.offset-start}; return v;
}
static inline nx_value nx_written(nx_writer *w, nx_u32 start) { nx_require(start<=w->size); nx_value v={w->data+start,w->size-start}; return v; }
static inline int nx_reply_success(nx_value reply) { nx_require(nx_is_string(nx_field(reply,"kind"),"reply")); return nx_as_boolean(nx_field(reply,"success")); }
static inline nx_value nx_reply_error(nx_value reply) { nx_require(!nx_reply_success(reply)); return nx_field(reply,"error"); }
static inline void nx_complete_value(nx_writer *w, nx_value value) { nx_start(w); nx_map(w,2); nx_key(w,"kind"); nx_string(w,"complete"); nx_key(w,"value"); nx_raw(w,value); }
typedef struct { const char *operation_id, *idempotency_key, *expected_revision, *experiment_id; nx_u64 budget_milliseconds; } nx_call_options;
static inline void nx_invoke_options(nx_writer *w, const char *contract, nx_u32 method, nx_value arguments, const nx_call_options *options) {
    nx_start(w); nx_map(w, 5 + (options && options->budget_milliseconds ? 1:0) + (options && options->operation_id ? 1:0) + (options && options->experiment_id ? 1:0) + (options && options->expected_revision ? 1:0));
    nx_key(w,"arguments"); nx_raw(w,arguments); if(options && options->budget_milliseconds) { nx_require(options->budget_milliseconds<=300000); nx_key(w,"budgetMilliseconds"); nx_unsigned(w,options->budget_milliseconds); } nx_key(w,"contract"); nx_string(w,contract);
    if(options && options->expected_revision) { nx_key(w,"expectedRevision"); nx_string(w,options->expected_revision); }
    if(options && options->experiment_id) { nx_key(w,"experimentId"); nx_string(w,options->experiment_id); }
    nx_key(w,"idempotencyKey"); if(options && options->idempotency_key) nx_string(w,options->idempotency_key); else nx_null(w);
    nx_key(w,"kind"); nx_string(w,"invoke"); nx_key(w,"method"); nx_unsigned(w,method);
    if(options && options->operation_id) { nx_key(w,"operationId"); nx_string(w,options->operation_id); }
}
static inline void nx_invoke_text_options(nx_writer *w, const char *contract, nx_u32 method, nx_text arguments, const nx_call_options *options) {
    nx_start(w); nx_map(w, 5 + (options && options->budget_milliseconds ? 1:0) + (options && options->operation_id ? 1:0) + (options && options->experiment_id ? 1:0) + (options && options->expected_revision ? 1:0));
    nx_key(w,"arguments"); nx_text_write(w,arguments); if(options && options->budget_milliseconds) { nx_require(options->budget_milliseconds<=300000); nx_key(w,"budgetMilliseconds"); nx_unsigned(w,options->budget_milliseconds); } nx_key(w,"contract"); nx_string(w,contract);
    if(options && options->expected_revision) { nx_key(w,"expectedRevision"); nx_string(w,options->expected_revision); }
    if(options && options->experiment_id) { nx_key(w,"experimentId"); nx_string(w,options->experiment_id); }
    nx_key(w,"idempotencyKey"); if(options && options->idempotency_key) nx_string(w,options->idempotency_key); else nx_null(w);
    nx_key(w,"kind"); nx_string(w,"invoke"); nx_key(w,"method"); nx_unsigned(w,method);
    if(options && options->operation_id) { nx_key(w,"operationId"); nx_string(w,options->operation_id); }
}
static inline int nx_context_contains(nx_value invocation, const char *field, const char *id) {
    nx_value context=nx_field(invocation,"abi"); if(!context.size || nx_is_null(context)) return 0;
    nx_value items=nx_field(context,field); for(nx_u32 i=0;i<nx_count(items);i++) if(nx_is_string(nx_at(items,i),id)) return 1; return 0;
}
static inline int nx_has_capability(nx_value invocation,const char *id) { return nx_context_contains(invocation,"capabilities",id); }
static inline int nx_has_permission(nx_value invocation,const char *id) { return nx_context_contains(invocation,"permissions",id); }
static inline nx_u64 nx_handler_id(nx_value invocation) { nx_require(nx_is_string(nx_field(invocation,"kind"),"handler")); return nx_as_unsigned(nx_field(invocation,"handler")); }
static inline nx_value nx_handler_input(nx_value invocation) { (void)nx_handler_id(invocation); return nx_field(invocation,"input"); }
static inline void nx_handler_success(nx_writer *w,nx_value value) { nx_start(w); nx_map(w,2); nx_key(w,"kind"); nx_string(w,"complete"); nx_key(w,"value"); nx_map(w,2); nx_key(w,"success"); nx_boolean(w,1); nx_key(w,"value"); nx_raw(w,value); }
static inline void nx_handler_error(nx_writer *w,nx_value error) { nx_start(w); nx_map(w,2); nx_key(w,"kind"); nx_string(w,"complete"); nx_key(w,"value"); nx_map(w,2); nx_key(w,"error"); nx_raw(w,error); nx_key(w,"success"); nx_boolean(w,0); }
/* Lifecycle and handler failures share the same completion envelope. */
static inline void nx_complete_error(nx_writer *w,nx_value error) { nx_handler_error(w,error); }
static inline int nx_has_experiment(nx_value invocation,const char *id) { return nx_context_contains(invocation,"experiments",id); }
#endif
