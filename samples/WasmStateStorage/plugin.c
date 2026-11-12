#include <nexa/abi100.h>

/* The namespace and stored value are copied into owned buffers before yielding. */
static nx_u8 input[65536], output[65536], arguments[32768];
static nx_u8 namespace_bytes[2048], value_bytes[4096];
static nx_u32 namespace_size, value_size;
static int step;

NX_EXPORT("nexa_alloc") nx_u32 nexa_alloc(nx_u32 size)
{
    nx_require(size <= sizeof input);
    return (nx_u32)(__UINTPTR_TYPE__)input;
}
static nx_ScopedTarget scope(nx_writer *w)
{
    return nx_ScopedTarget_write(w, nx_literal("nexa:global"),
        nx_EntityIdOptional_none(w), nx_literal("example.state"));
}
static nx_StorageNamespace owned_namespace(void)
{
    nx_value value = {namespace_bytes, namespace_size};
    return nx_StorageNamespace_read(value);
}
static void read_state(nx_writer *reply, nx_writer *args)
{
    nx_call_options options = {0};
    step = 5;
    nx_State_Read(reply, nx_StateReadRequest_write(args,
        nx_literal("example.state:message"), scope(args)), &options);
}
NX_EXPORT("nexa_resume") nx_u64 nexa_resume(nx_u32 address, nx_u32 size)
{
    nx_require(address == (nx_u32)(__UINTPTR_TYPE__)input && size <= sizeof input);
    nx_value message = nx_decode(input, size);
    nx_writer reply = {output, 0, sizeof output};
    nx_writer args = {arguments, 0, sizeof arguments};
    nx_call_options options = {0};
    if (nx_is_string(nx_field(message, "kind"), "reply")) {
        if (!nx_reply_success(message)) {
            /* Only a genuinely absent entry is initialized. All other failures fail. */
            if (step == 3 && nx_is_string(nx_field(nx_reply_error(message), "code"), "NOT_FOUND")) {
                nx_TextResult initial = nx_TextResult_write(&args, nx_literal("Saved by the state tutorial"));
                nx_StorageWrite write = nx_StorageWrite_write(&args, owned_namespace(), nx_literal("message"),
                    initial.value, nx_schema_TextResult(&args), nx_RevisionOptional_none(&args));
                options.idempotency_key = "initialize-message";
                step = 4;
                nx_Storage_CompareExchange(&reply, write, &options);
            } else { step = 0; nx_handler_error(&reply, nx_reply_error(message)); }
        } else if (step == 1) {
            nx_StorageNamespace value;
            nx_require(nx_Storage_OpenNamespace_result(message, &value));
            nx_writer saved = {namespace_bytes, 0, sizeof namespace_bytes};
            nx_StorageNamespace_encode(&saved, value); namespace_size = saved.size;
            nx_StateDescriptor descriptor = nx_StateDescriptor_write(&args,
                nx_literal("example.state:message"), nx_schema_TextResult(&args), scope(&args));
            options.idempotency_key = "define-message"; step = 2;
            nx_State_DefineOwned(&reply, descriptor, &options);
        } else if (step == 2) { step = 0; nx_complete(&reply, 1); }
        else if (step == 3 || step == 4) {
            nx_StorageValue stored;
            if (step == 3) nx_require(nx_Storage_Read_result(message, &stored));
            else nx_require(nx_Storage_CompareExchange_result(message, &stored));
            nx_value value = nx_StorageValue_Value(stored);
            (void)nx_TextResult_read(value);
            nx_writer saved = {value_bytes, 0, sizeof value_bytes};
            nx_AbiValue_encode(&saved, value); value_size = saved.size;
            read_state(&reply, &args);
        } else if (step == 5) {
            nx_StateSnapshot current;
            nx_require(nx_State_Read_result(message, &current));
            nx_value value = {value_bytes, value_size};
            nx_StateUpdate update = nx_StateUpdate_write(&args,
                nx_literal("example.state:message"), scope(&args), value,
                nx_StateSnapshot_Revision(current));
            options.idempotency_key = "publish-message"; step = 6;
            nx_State_CompareExchangeOwned(&reply, update, &options);
        } else if (step == 6) {
            nx_StateSnapshot current;
            nx_require(nx_State_CompareExchangeOwned_result(message, &current));
            (void)nx_TextResult_read(nx_StateSnapshot_Value(current));
            step = 0; nx_complete(&reply, 1);
        } else nx_complete(&reply, 0);
    } else if (nx_is_string(nx_field(message, "phase"), "Initialize")) {
        step = 1;
        nx_Storage_OpenNamespace(&reply, nx_NamespaceRequest_write(&args,
            nx_literal("example.state:data"), 1), &options);
    } else if (nx_is_string(nx_field(message, "phase"), "Activated")) {
        step = 3;
        nx_Storage_Read(&reply, nx_StorageKey_write(&args, owned_namespace(),
            nx_literal("message")), &options);
    } else nx_complete(&reply, 1);
    return nx_result(&reply);
}
