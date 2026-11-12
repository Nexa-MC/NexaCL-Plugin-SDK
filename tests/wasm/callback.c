#include <nexa/abi100.h>
static nx_u8 input[65536],output[65536];
static int pending;
NX_EXPORT("nexa_alloc") nx_u32 alloc(nx_u32 size) { nx_require(size<=sizeof input); return (nx_u32)(__UINTPTR_TYPE__)input; }
NX_EXPORT("nexa_resume") nx_u64 resume(nx_u32 address,nx_u32 size) {
    nx_require(address==(nx_u32)(__UINTPTR_TYPE__)input && size<=sizeof input);
    nx_value message=nx_decode(input,size); nx_writer writer={output,0,sizeof output};
    if(pending) { pending=0; if(nx_reply_success(message)) nx_handler_success(&writer,nx_field(message,"value")); else nx_handler_error(&writer,nx_reply_error(message)); }
    else if(nx_is_string(nx_field(message,"kind"),"handler")) {
        nx_u64 handler=nx_handler_id(message);
        if(handler==1) nx_handler_success(&writer,nx_handler_input(message));
        else if(handler==2 || handler==4) {
            nx_require(nx_has_capability(message,"nexa.platform/100"));
            nx_call_options options={"12345678-1234-1234-1234-123456789abc",0,0,handler==4?"12345678-1234-1234-1234-123456789def":0,1000};
            nx_Platform_Describe(&writer,nx_Empty_read(nx_handler_input(message)),&options); pending=1;
        } else if(handler==5) {
            nx_require(nx_is_string(nx_field(message,"phase"),"Checkup"));
            nx_PredicateRequest request=nx_PredicateRequest_read(nx_handler_input(message));
            nx_u8 arguments[4096]; nx_writer args={arguments,0,sizeof arguments};
            nx_ValidationIssueArray issues=nx_ValidationIssueArray_write(&args,0,0);
            nx_PredicateResult result=nx_PredicateResult_write(&args,nx_PredicateOutcome_True,nx_PredicateRequest_Consistency(request),issues);
            nx_handler_success(&writer,result.value);
        } else if(handler==3) nx_handler_error(&writer,nx_handler_input(message)); else __builtin_trap();
    } else nx_complete(&writer,1);
    return nx_result(&writer);
}
