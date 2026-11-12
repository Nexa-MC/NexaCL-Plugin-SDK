#include <nexa/guest.h>
static nx_u8 input[NX_MAX_BYTES];
NX_EXPORT("input") nx_u32 address(void) { return (nx_u32)(__UINTPTR_TYPE__)input; }
NX_EXPORT("scan") nx_u32 scan(nx_u32 size) {
    nx_require(size <= sizeof input);
    nx_reader reader = {input, size, 0, 0};
    nx_skip(&reader, 0); nx_require(reader.offset == size);
    return reader.nodes;
}
NX_EXPORT("missing_and_null") int missing_and_null(void) {
    nx_u8 map[] = {8,1,0,0,0,1,0,0,0,'a',0};
    nx_value value = {map, sizeof map};
    nx_value missing = nx_field(value, "b"), present = nx_field(value, "a");
    return nx_is_missing(missing) && !nx_is_null(missing)
        && !nx_is_missing(present) && nx_is_null(present);
}
