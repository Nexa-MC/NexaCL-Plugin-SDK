#include <nexa/abi100.h>

/* Borrowed SDK views stay inside one invocation. Host continuations arrive in a
   new input buffer, so only this small continuation state survives a yield. */
static nx_u8 input[65536], output[65536], arguments[32768];
static int next_registration, awaiting_start;

NX_EXPORT("nexa_alloc") nx_u32 nexa_alloc(nx_u32 size)
{
    nx_require(size <= sizeof input);
    return (nx_u32)(__UINTPTR_TYPE__)input;
}

static void register_next(nx_writer *reply)
{
    nx_writer args = {arguments, 0, sizeof arguments};
    nx_call_options options = {0};
    nx_SchemaRef empty = nx_schema_Empty(&args);
    nx_SchemaRef text = nx_schema_TextResult(&args);
    if (next_registration == 1) {
        nx_stringArray strings = nx_stringArray_write(&args, 0, 0);
        nx_NamedValueArray values = nx_NamedValueArray_write(&args, 0, 0);
        nx_LocalizedText title = nx_LocalizedText_write(&args, nx_literal("example.workflow.action"), values);
        nx_QualifiedIdOptional none = nx_QualifiedIdOptional_none(&args);
        nx_ulongOptional handler = nx_ulongOptional_some(&args, 1);
        nx_ActionDescriptor action = nx_ActionDescriptor_write(&args, nx_literal("example.workflow:action"),
            empty, text, strings, strings, nx_IdempotencyMode_ReadOnly, 1, 0,
            nx_ConfirmationRequirement_None, none, title, handler);
        options.idempotency_key = "register-action";
        nx_Actions_Register(reply, action, &options);
    } else if (next_registration == 2) {
        nx_QualifiedIdOptional target = nx_QualifiedIdOptional_some(&args, nx_literal("example.workflow:action"));
        nx_WorkflowNodeArray children = nx_WorkflowNodeArray_write(&args, 0, 0);
        nx_stringArray errors = nx_stringArray_write(&args, 0, 0);
        nx_u32 start = args.size; nx_null(&args); nx_value previous = nx_written(&args, start);
        nx_WorkflowNode action = nx_WorkflowNode_write(&args, nx_literal("call"), nx_WorkflowNodeKind_Action,
            target, previous, children, 1, 1, 0, nx_ParallelCompletion_All, errors, empty, text);
        nx_WorkflowNodeArray nodes = nx_WorkflowNodeArray_write(&args, &action, 1);
        nx_WorkflowDefinition workflow = nx_WorkflowDefinition_write(&args, nx_literal("example.workflow:run"),
            empty, text, nodes, nx_literal("example-workflow-v1"), 1, nx_ConcurrencyPolicy_Queue, 8, 32);
        options.idempotency_key = "register-workflow";
        nx_Workflows_Register(reply, workflow, &options);
    } else if (next_registration == 3) {
        nx_DateTimeOffsetOptional at = nx_DateTimeOffsetOptional_none(&args);
        nx_longOptional interval = nx_longOptional_some(&args, 60000);
        nx_QualifiedIdOptional event = nx_QualifiedIdOptional_none(&args);
        nx_ScheduleDefinition schedule = nx_ScheduleDefinition_write(&args, nx_literal("example.workflow:timer"),
            nx_literal("example.workflow:run"), nx_ScheduleTrigger_Interval, nx_literal("UTC"), at,
            interval, event, nx_MissedSchedulePolicy_Coalesce, 1, 0);
        options.idempotency_key = "register-schedule";
        nx_Schedules_Register(reply, schedule, &options);
    } else if (next_registration == 4) {
        options.idempotency_key = "register-cleanup";
        nx_Resources_RegisterCleanup(reply, nx_CleanupRequest_write(&args, 2), &options);
    } else {
        next_registration = 0;
        nx_complete(reply, 1);
    }
}

NX_EXPORT("nexa_resume") nx_u64 nexa_resume(nx_u32 address, nx_u32 size)
{
    nx_require(address == (nx_u32)(__UINTPTR_TYPE__)input && size <= sizeof input);
    nx_value message = nx_decode(input, size);
    nx_writer reply = {output, 0, sizeof output};
    if (nx_is_string(nx_field(message, "kind"), "reply")) {
        if (!nx_reply_success(message)) {
            next_registration = 0; awaiting_start = 0;
            nx_complete(&reply, 0);
        } else if (awaiting_start) {
            nx_OperationRef operation;
            nx_require(nx_Workflows_Start_result(message, &operation));
            awaiting_start = 0;
            nx_complete(&reply, 1);
        } else {
            next_registration++;
            register_next(&reply);
        }
    } else if (nx_is_string(nx_field(message, "kind"), "handler")) {
        nx_writer args = {arguments, 0, sizeof arguments};
        if (nx_handler_id(message) == 1) {
            nx_ActionRequest request = nx_ActionRequest_read(nx_handler_input(message));
            (void)nx_Empty_read(nx_ActionRequest_Inputs(request));
            nx_TextResult result = nx_TextResult_write(&args, nx_literal("C callback completed"));
            nx_handler_success(&reply, result.value);
        } else {
            nx_require(nx_handler_id(message) == 2);
            nx_handler_success(&reply, nx_Empty_write(&args).value);
        }
    } else if (nx_is_string(nx_field(message, "phase"), "Initialize")) {
        next_registration = 1;
        register_next(&reply);
    } else if (nx_is_string(nx_field(message, "phase"), "Activated")) {
        nx_writer args = {arguments, 0, sizeof arguments};
        nx_Empty empty = nx_Empty_write(&args);
        nx_WorkflowRequest request = nx_WorkflowRequest_write(&args, nx_literal("example.workflow:run"),
            empty.value, nx_literal("example-workflow-v1"));
        nx_call_options options = {0}; options.idempotency_key = "activation-run";
        awaiting_start = 1;
        nx_Workflows_Start(&reply, request, &options);
    } else nx_complete(&reply, 1);
    return nx_result(&reply);
}
