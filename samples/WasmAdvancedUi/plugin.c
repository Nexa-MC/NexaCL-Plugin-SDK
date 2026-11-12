#include <nexa/abi100.h>
static nx_u8 input[65536], output[65536], arguments[32768];
static int step;
NX_EXPORT("nexa_alloc") nx_u32 nexa_alloc(nx_u32 size) { nx_require(size<=sizeof input); return (nx_u32)(__UINTPTR_TYPE__)input; }
NX_EXPORT("nexa_resume") nx_u64 nexa_resume(nx_u32 address,nx_u32 size) {
 nx_require(address==(nx_u32)(__UINTPTR_TYPE__)input && size<=sizeof input);
 nx_value message=nx_decode(input,size); nx_writer reply={output,0,sizeof output},args={arguments,0,sizeof arguments}; nx_call_options options={0};
 if(nx_is_string(nx_field(message,"kind"),"reply")) {
  if(!nx_reply_success(message)) {step=0;nx_complete_error(&reply,nx_reply_error(message));}
  else if(step==1) {
   nx_FileRef file;nx_require(nx_Files_OpenPackageFile_result(message,&file));
   nx_UIPage page=nx_UIPage_write(&args,nx_literal("example.advanced:home"),file,nx_schema_TextResult(&args),nx_QualifiedIdArray_write(&args,0,0));
   options.idempotency_key="page";step=2;nx_UI_RegisterPage(&reply,page,&options);
  } else if(step==2) {
   nx_stringArray strings=nx_stringArray_write(&args,0,0);
   nx_LocalizedText title=nx_LocalizedText_write(&args,nx_literal("Run sample action"),nx_NamedValueArray_write(&args,0,0));
   nx_ActionDescriptor action=nx_ActionDescriptor_write(&args,nx_literal("example.advanced:hello"),nx_schema_TextResult(&args),nx_schema_TextResult(&args),strings,strings,nx_IdempotencyMode_ReadOnly,1,0,nx_ConfirmationRequirement_UserConfirmation,nx_QualifiedIdOptional_none(&args),title,nx_ulongOptional_some(&args,1));
   options.idempotency_key="action";step=3;nx_Actions_Register(&reply,action,&options);
  } else if(step==3) {
   step=4;nx_Files_OpenPackageFile(&reply,nx_PackageFileRequest_write(&args,nx_literal("component.nxml")),&options);
  } else if(step==4) {
   nx_FileRef file;nx_require(nx_Files_OpenPackageFile_result(message,&file));
   options.idempotency_key="component";step=5;nx_UI_RegisterComponent(&reply,nx_UIComponent_write(&args,nx_literal("example.advanced:component"),file,nx_schema_Empty(&args)),&options);
  } else if(step==5) {
   options.idempotency_key="contribution";step=6;
   nx_UI_RegisterContribution(&reply,nx_UIContribution_write(&args,nx_literal("example.advanced:contribution"),nx_literal("nexa:plugins/content"),nx_literal("content"),nx_UIContributionMode_Append,nx_literal("example.advanced:component"),nx_QualifiedIdArray_write(&args,0,0),nx_QualifiedIdArray_write(&args,0,0)),&options);
  } else if(step==6) {
   nx_stringArray strings=nx_stringArray_write(&args,0,0);
   nx_LocalizedText title=nx_LocalizedText_write(&args,nx_literal("Run command"),nx_NamedValueArray_write(&args,0,0));
   nx_ActionDescriptor action=nx_ActionDescriptor_write(&args,nx_literal("example.advanced:ping"),nx_schema_Empty(&args),nx_schema_TextResult(&args),strings,strings,nx_IdempotencyMode_ReadOnly,1,0,nx_ConfirmationRequirement_UserConfirmation,nx_QualifiedIdOptional_none(&args),title,nx_ulongOptional_some(&args,3));
   options.idempotency_key="ping";step=60;nx_Actions_Register(&reply,action,&options);
  } else if(step==60) {
   options.idempotency_key="command";step=7;
   nx_UI_RegisterCommand(&reply,nx_UICommand_write(&args,nx_literal("example.advanced:command"),nx_literal("example.advanced:ping"),nx_LocalizedText_write(&args,nx_literal("Advanced command"),nx_NamedValueArray_write(&args,0,0))),&options);
  } else if(step==7) {
   options.idempotency_key="shortcut";step=8;
   nx_UI_RegisterShortcut(&reply,nx_UIShortcut_write(&args,nx_literal("example.advanced:shortcut"),nx_literal("example.advanced:command"),nx_literal("Ctrl+Alt+P"),nx_literal("example.advanced:home")),&options);
  } else {step=0;nx_complete(&reply,1);}
 } else if(nx_is_string(nx_field(message,"kind"),"handler")) {
  if(nx_handler_id(message)==2) {nx_handler_success(&reply,nx_Empty_write(&args).value);return nx_result(&reply);}
  if(nx_handler_id(message)==3) {nx_handler_success(&reply,nx_TextResult_write(&args,nx_literal("Command completed")).value);return nx_result(&reply);}
  nx_require(nx_handler_id(message)==1);nx_ActionRequest request=nx_ActionRequest_read(nx_handler_input(message));nx_handler_success(&reply,nx_ActionRequest_Inputs(request));
 } else if(nx_is_string(nx_field(message,"phase"),"Initialize")) {
  step=1;nx_Files_OpenPackageFile(&reply,nx_PackageFileRequest_write(&args,nx_literal("page.nxml")),&options);
 } else nx_complete(&reply,1);
 return nx_result(&reply);
}
