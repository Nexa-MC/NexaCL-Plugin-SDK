#include <nexa/guest.h>
#include <nexa/abi100.h>

static nx_u8 input[65536], output[65536], argument[4096];
static int awaiting_registration;
NX_EXPORT("nexa_alloc") nx_u32 nexa_alloc(nx_u32 size)
{
    nx_require(size <= sizeof input);
    return (nx_u32)(__UINTPTR_TYPE__)input;
}
NX_EXPORT("nexa_resume") nx_u64 nexa_resume(nx_u32 address, nx_u32 size)
{
    nx_require(address == (nx_u32)(__UINTPTR_TYPE__)input && size <= sizeof input);
    nx_value message = nx_decode(input, size);
    nx_writer reply = {output, 0, sizeof output};
    if (awaiting_registration) {
        nx_require(nx_is_string(nx_field(message, "kind"), "reply"));
        awaiting_registration = 0;
        if (nx_reply_success(message)) nx_complete(&reply, 1);
        else nx_handler_error(&reply, nx_reply_error(message));
    } else if (nx_is_string(nx_field(message, "phase"), "Initialize")) {
        nx_writer args = {argument, 0, sizeof argument};
        nx_SchemaRef schema = nx_SchemaRef_write(&args, nx_literal("example.wasm:message"), 1, nx_literal("example-string-v1"));
        nx_ReferenceArray references = nx_ReferenceArray_write(&args, 0, 0);
        nx_u32 body_start = args.size;
        nx_string(&args, "Hello from the C WebAssembly SDK");
        nx_value body = nx_written(&args, body_start);
        nx_Definition definition = nx_Definition_write(&args, nx_literal("example.wasm:hello"),
            nx_literal("example.wasm:messages"), schema, body, references);
        nx_call_options options = {0}; options.idempotency_key = "hello-definition";
        nx_Definitions_Register(&reply, definition, &options);
        awaiting_registration = 1;
    } else nx_complete(&reply, 1);
    return nx_result(&reply);
}
