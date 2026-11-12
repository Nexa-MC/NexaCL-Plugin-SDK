#include <nexa/guest.h>
static nx_u8 input[262144],output[262144];
NX_EXPORT("nexa_alloc") nx_u32 alloc(nx_u32 size) { nx_require(size<=sizeof input); return (nx_u32)(__UINTPTR_TYPE__)input; }
NX_EXPORT("nexa_resume") nx_u64 resume(nx_u32 address,nx_u32 size) {
    nx_require(address==(nx_u32)(__UINTPTR_TYPE__)input && size<=sizeof input);
    nx_text bytes=nx_as_bytes(nx_decode(input,size)); nx_value value=nx_decode(bytes.data,bytes.size);
    nx_writer writer={output,0,sizeof output}; nx_complete_value(&writer,value); return nx_result(&writer);
}
