/* Generated cross-language conformance guest. */
#include <nexa/abi100.h>
static nx_u8 input[262144],output[262144],scratch[262144];
static nx_u32 operation; static int waiting;
NX_EXPORT("nexa_alloc") nx_u32 alloc(nx_u32 size) { nx_require(size<=sizeof input); return (nx_u32)(__UINTPTR_TYPE__)input; }
NX_EXPORT("nexa_resume") nx_u64 resume(nx_u32 address,nx_u32 size) { nx_require(address==(nx_u32)(__UINTPTR_TYPE__)input && size<=sizeof input); nx_value value=nx_decode(input,size); nx_writer writer={output,0,sizeof output}; nx_writer *w=&writer;
if(!waiting) { operation=(nx_u32)nx_as_unsigned(nx_field(value,"index")); nx_value args=nx_field(value,"arguments");
if(operation>=368) { nx_writer constructed={scratch,0,sizeof scratch}; switch(operation) {
case 368: { nx_AccountPublic model=nx_AccountPublic_read(args); (void)model; nx_AccountPublic copy=nx_AccountPublic_write(&constructed, nx_AccountPublic_Id(model), nx_AccountPublic_Provider(model), nx_AccountPublic_DisplayName(model), nx_AccountPublic_Avatar(model), nx_AccountPublic_Revision(model)); nx_complete_value(w,copy.value); break; }
case 369: { nx_ActionDescriptor model=nx_ActionDescriptor_read(args); (void)model; nx_ActionDescriptor copy=nx_ActionDescriptor_write(&constructed, nx_ActionDescriptor_Id(model), nx_ActionDescriptor_Input(model), nx_ActionDescriptor_Output(model), nx_ActionDescriptor_RequiredCapabilities(model), nx_ActionDescriptor_Scopes(model), nx_ActionDescriptor_Idempotency(model), nx_ActionDescriptor_Cancellable(model), nx_ActionDescriptor_SupportsPreview(model), nx_ActionDescriptor_Confirmation(model), nx_ActionDescriptor_Compensation(model), nx_ActionDescriptor_Title(model), nx_ActionDescriptor_Handler(model)); nx_complete_value(w,copy.value); break; }
case 370: { nx_ActionRequest model=nx_ActionRequest_read(args); (void)model; nx_ActionRequest copy=nx_ActionRequest_write(&constructed, nx_ActionRequest_Action(model), nx_ActionRequest_Target(model), nx_ActionRequest_Inputs(model), nx_ActionRequest_ExpectedRevision(model), nx_ActionRequest_IdempotencyKey(model)); nx_complete_value(w,copy.value); break; }
case 371: { nx_ArchitectureInfo model=nx_ArchitectureInfo_read(args); (void)model; nx_ArchitectureInfo copy=nx_ArchitectureInfo_write(&constructed, nx_ArchitectureInfo_OperatingSystem(model), nx_ArchitectureInfo_Architecture(model)); nx_complete_value(w,copy.value); break; }
case 372: { nx_BackupCapture model=nx_BackupCapture_read(args); (void)model; nx_BackupCapture copy=nx_BackupCapture_write(&constructed, nx_BackupCapture_Instance(model), nx_BackupCapture_Target(model), nx_BackupCapture_Include(model), nx_BackupCapture_Exclude(model)); nx_complete_value(w,copy.value); break; }
case 373: { nx_BackupPrune model=nx_BackupPrune_read(args); (void)model; nx_BackupPrune copy=nx_BackupPrune_write(&constructed, nx_BackupPrune_Instance(model), nx_BackupPrune_Retention(model), nx_BackupPrune_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 374: { nx_BackupRestore model=nx_BackupRestore_read(args); (void)model; nx_BackupRestore copy=nx_BackupRestore_write(&constructed, nx_BackupRestore_Backup(model), nx_BackupRestore_Destination(model), nx_BackupRestore_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 375: { nx_BackupRetention model=nx_BackupRetention_read(args); (void)model; nx_BackupRetention copy=nx_BackupRetention_write(&constructed, nx_BackupRetention_Instance(model), nx_BackupRetention_Policy(model), nx_BackupRetention_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 376: { nx_BackupStatistics model=nx_BackupStatistics_read(args); (void)model; nx_BackupStatistics copy=nx_BackupStatistics_write(&constructed, nx_BackupStatistics_Instance(model), nx_BackupStatistics_Count(model), nx_BackupStatistics_Bytes(model)); nx_complete_value(w,copy.value); break; }
case 377: { nx_BackupSummary model=nx_BackupSummary_read(args); (void)model; nx_BackupSummary copy=nx_BackupSummary_write(&constructed, nx_BackupSummary_Id(model), nx_BackupSummary_Instance(model), nx_BackupSummary_CreatedAt(model), nx_BackupSummary_Size(model), nx_BackupSummary_Revision(model)); nx_complete_value(w,copy.value); break; }
case 378: { nx_BackupTransfer model=nx_BackupTransfer_read(args); (void)model; nx_BackupTransfer copy=nx_BackupTransfer_write(&constructed, nx_BackupTransfer_Backup(model), nx_BackupTransfer_File(model)); nx_complete_value(w,copy.value); break; }
case 379: { nx_BlobRef model=nx_BlobRef_read(args); (void)model; nx_BlobRef copy=nx_BlobRef_write(&constructed, nx_BlobRef_Token(model), nx_BlobRef_LoadInstanceId(model), nx_BlobRef_Size(model), nx_BlobRef_Sha256(model)); nx_complete_value(w,copy.value); break; }
case 380: { nx_BooleanResult model=nx_BooleanResult_read(args); (void)model; nx_BooleanResult copy=nx_BooleanResult_write(&constructed, nx_BooleanResult_Value(model)); nx_complete_value(w,copy.value); break; }
case 381: { nx_BusinessProviderCall model=nx_BusinessProviderCall_read(args); (void)model; nx_BusinessProviderCall copy=nx_BusinessProviderCall_write(&constructed, nx_BusinessProviderCall_Provider(model), nx_BusinessProviderCall_Kind(model), nx_BusinessProviderCall_Method(model), nx_BusinessProviderCall_InputSchema(model), nx_BusinessProviderCall_OutputSchema(model), nx_BusinessProviderCall_Inputs(model)); nx_complete_value(w,copy.value); break; }
case 382: { nx_CapabilityDescription model=nx_CapabilityDescription_read(args); (void)model; nx_CapabilityDescription copy=nx_CapabilityDescription_write(&constructed, nx_CapabilityDescription_Id(model), nx_CapabilityDescription_Version(model), nx_CapabilityDescription_Availability(model), nx_CapabilityDescription_Scopes(model), nx_CapabilityDescription_Quotas(model)); nx_complete_value(w,copy.value); break; }
case 383: { nx_Cape model=nx_Cape_read(args); (void)model; nx_Cape copy=nx_Cape_write(&constructed, nx_Cape_Id(model), nx_Cape_Title(model), nx_Cape_Image(model)); nx_complete_value(w,copy.value); break; }
case 384: { nx_CapeSelection model=nx_CapeSelection_read(args); (void)model; nx_CapeSelection copy=nx_CapeSelection_write(&constructed, nx_CapeSelection_Account(model), nx_CapeSelection_CapeId(model)); nx_complete_value(w,copy.value); break; }
case 385: { nx_CatalogDependency model=nx_CatalogDependency_read(args); (void)model; nx_CatalogDependency copy=nx_CatalogDependency_write(&constructed, nx_CatalogDependency_Version(model), nx_CatalogDependency_Required(model), nx_CatalogDependency_Conflict(model)); nx_complete_value(w,copy.value); break; }
case 386: { nx_CatalogFile model=nx_CatalogFile_read(args); (void)model; nx_CatalogFile copy=nx_CatalogFile_write(&constructed, nx_CatalogFile_Name(model), nx_CatalogFile_Source(model), nx_CatalogFile_Size(model), nx_CatalogFile_Sha256(model)); nx_complete_value(w,copy.value); break; }
case 387: { nx_CatalogInstallRequest model=nx_CatalogInstallRequest_read(args); (void)model; nx_CatalogInstallRequest copy=nx_CatalogInstallRequest_write(&constructed, nx_CatalogInstallRequest_Instance(model), nx_CatalogInstallRequest_Versions(model), nx_CatalogInstallRequest_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 388: { nx_CatalogProject model=nx_CatalogProject_read(args); (void)model; nx_CatalogProject copy=nx_CatalogProject_write(&constructed, nx_CatalogProject_Resource(model), nx_CatalogProject_Name(model), nx_CatalogProject_Summary(model), nx_CatalogProject_Kind(model), nx_CatalogProject_Categories(model)); nx_complete_value(w,copy.value); break; }
case 389: { nx_CatalogSearch model=nx_CatalogSearch_read(args); (void)model; nx_CatalogSearch copy=nx_CatalogSearch_write(&constructed, nx_CatalogSearch_Providers(model), nx_CatalogSearch_Query(model), nx_CatalogSearch_Kind(model), nx_CatalogSearch_GameVersion(model), nx_CatalogSearch_Loader(model), nx_CatalogSearch_Page(model)); nx_complete_value(w,copy.value); break; }
case 390: { nx_CatalogVersion model=nx_CatalogVersion_read(args); (void)model; nx_CatalogVersion copy=nx_CatalogVersion_write(&constructed, nx_CatalogVersion_Version(model), nx_CatalogVersion_Name(model), nx_CatalogVersion_GameVersions(model), nx_CatalogVersion_Loaders(model), nx_CatalogVersion_Files(model)); nx_complete_value(w,copy.value); break; }
case 391: { nx_CatalogVersionQuery model=nx_CatalogVersionQuery_read(args); (void)model; nx_CatalogVersionQuery copy=nx_CatalogVersionQuery_write(&constructed, nx_CatalogVersionQuery_Resource(model), nx_CatalogVersionQuery_GameVersion(model), nx_CatalogVersionQuery_Page(model)); nx_complete_value(w,copy.value); break; }
case 392: { nx_CleanupRequest model=nx_CleanupRequest_read(args); (void)model; nx_CleanupRequest copy=nx_CleanupRequest_write(&constructed, nx_CleanupRequest_Callback(model)); nx_complete_value(w,copy.value); break; }
case 393: { nx_ClipboardContent model=nx_ClipboardContent_read(args); (void)model; nx_ClipboardContent copy=nx_ClipboardContent_write(&constructed, nx_ClipboardContent_Text(model), nx_ClipboardContent_Image(model)); nx_complete_value(w,copy.value); break; }
case 394: { nx_CompatibilityRequest model=nx_CompatibilityRequest_read(args); (void)model; nx_CompatibilityRequest copy=nx_CompatibilityRequest_write(&constructed, nx_CompatibilityRequest_Contract(model), nx_CompatibilityRequest_Version(model), nx_CompatibilityRequest_SchemaDigest(model)); nx_complete_value(w,copy.value); break; }
case 395: { nx_ConsumerDefinition model=nx_ConsumerDefinition_read(args); (void)model; nx_ConsumerDefinition copy=nx_ConsumerDefinition_write(&constructed, nx_ConsumerDefinition_Id(model), nx_ConsumerDefinition_Contract(model), nx_ConsumerDefinition_Version(model), nx_ConsumerDefinition_Handler(model)); nx_complete_value(w,copy.value); break; }
case 396: { nx_ContentChangeRequest model=nx_ContentChangeRequest_read(args); (void)model; nx_ContentChangeRequest copy=nx_ContentChangeRequest_write(&constructed, nx_ContentChangeRequest_Instance(model), nx_ContentChangeRequest_Items(model), nx_ContentChangeRequest_Versions(model), nx_ContentChangeRequest_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 397: { nx_ContentDependency model=nx_ContentDependency_read(args); (void)model; nx_ContentDependency copy=nx_ContentDependency_write(&constructed, nx_ContentDependency_From(model), nx_ContentDependency_To(model), nx_ContentDependency_Required(model), nx_ContentDependency_Conflict(model)); nx_complete_value(w,copy.value); break; }
case 398: { nx_ContentDependencyGraph model=nx_ContentDependencyGraph_read(args); (void)model; nx_ContentDependencyGraph copy=nx_ContentDependencyGraph_write(&constructed, nx_ContentDependencyGraph_Instance(model), nx_ContentDependencyGraph_Nodes(model), nx_ContentDependencyGraph_Edges(model), nx_ContentDependencyGraph_Revision(model)); nx_complete_value(w,copy.value); break; }
case 399: { nx_ContentItem model=nx_ContentItem_read(args); (void)model; nx_ContentItem copy=nx_ContentItem_write(&constructed, nx_ContentItem_Id(model), nx_ContentItem_Instance(model), nx_ContentItem_Kind(model), nx_ContentItem_Name(model), nx_ContentItem_Version(model), nx_ContentItem_Enabled(model), nx_ContentItem_Revision(model)); nx_complete_value(w,copy.value); break; }
case 400: { nx_ContentPlan model=nx_ContentPlan_read(args); (void)model; nx_ContentPlan copy=nx_ContentPlan_write(&constructed, nx_ContentPlan_Plan(model), nx_ContentPlan_Changes(model), nx_ContentPlan_Issues(model)); nx_complete_value(w,copy.value); break; }
case 401: { nx_ContentQuery model=nx_ContentQuery_read(args); (void)model; nx_ContentQuery copy=nx_ContentQuery_write(&constructed, nx_ContentQuery_Instance(model), nx_ContentQuery_Kind(model), nx_ContentQuery_Page(model)); nx_complete_value(w,copy.value); break; }
case 402: { nx_ContentTransaction model=nx_ContentTransaction_read(args); (void)model; nx_ContentTransaction copy=nx_ContentTransaction_write(&constructed, nx_ContentTransaction_Id(model), nx_ContentTransaction_Instance(model), nx_ContentTransaction_State(model), nx_ContentTransaction_Plan(model), nx_ContentTransaction_Revision(model)); nx_complete_value(w,copy.value); break; }
case 403: { nx_ContentTransfer model=nx_ContentTransfer_read(args); (void)model; nx_ContentTransfer copy=nx_ContentTransfer_write(&constructed, nx_ContentTransfer_Instance(model), nx_ContentTransfer_File(model), nx_ContentTransfer_Format(model), nx_ContentTransfer_Selection(model)); nx_complete_value(w,copy.value); break; }
case 404: { nx_ContractQuery model=nx_ContractQuery_read(args); (void)model; nx_ContractQuery copy=nx_ContractQuery_write(&constructed, nx_ContractQuery_Id(model), nx_ContractQuery_Version(model)); nx_complete_value(w,copy.value); break; }
case 405: { nx_CredentialRef model=nx_CredentialRef_read(args); (void)model; nx_CredentialRef copy=nx_CredentialRef_write(&constructed, nx_CredentialRef_Token(model), nx_CredentialRef_LoadInstanceId(model), nx_CredentialRef_Provider(model)); nx_complete_value(w,copy.value); break; }
case 406: { nx_DataPackSelection model=nx_DataPackSelection_read(args); (void)model; nx_DataPackSelection copy=nx_DataPackSelection_write(&constructed, nx_DataPackSelection_World(model), nx_DataPackSelection_Packs(model), nx_DataPackSelection_EnabledOrder(model), nx_DataPackSelection_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 407: { nx_DeclarativeContentPack model=nx_DeclarativeContentPack_read(args); (void)model; nx_DeclarativeContentPack copy=nx_DeclarativeContentPack_write(&constructed, nx_DeclarativeContentPack_Id(model), nx_DeclarativeContentPack_Schema(model), nx_DeclarativeContentPack_Definitions(model)); nx_complete_value(w,copy.value); break; }
case 408: { nx_Definition model=nx_Definition_read(args); (void)model; nx_Definition copy=nx_Definition_write(&constructed, nx_Definition_Id(model), nx_Definition_Registry(model), nx_Definition_Schema(model), nx_Definition_Body(model), nx_Definition_References(model)); nx_complete_value(w,copy.value); break; }
case 409: { nx_DefinitionBatch model=nx_DefinitionBatch_read(args); (void)model; nx_DefinitionBatch copy=nx_DefinitionBatch_write(&constructed, nx_DefinitionBatch_Definitions(model)); nx_complete_value(w,copy.value); break; }
case 410: { nx_DefinitionQuery model=nx_DefinitionQuery_read(args); (void)model; nx_DefinitionQuery copy=nx_DefinitionQuery_write(&constructed, nx_DefinitionQuery_Registry(model), nx_DefinitionQuery_Id(model)); nx_complete_value(w,copy.value); break; }
case 411: { nx_DefinitionRemove model=nx_DefinitionRemove_read(args); (void)model; nx_DefinitionRemove copy=nx_DefinitionRemove_write(&constructed, nx_DefinitionRemove_Registry(model), nx_DefinitionRemove_Id(model), nx_DefinitionRemove_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 412: { nx_DefinitionSearch model=nx_DefinitionSearch_read(args); (void)model; nx_DefinitionSearch copy=nx_DefinitionSearch_write(&constructed, nx_DefinitionSearch_Registry(model), nx_DefinitionSearch_Tags(model), nx_DefinitionSearch_Page(model)); nx_complete_value(w,copy.value); break; }
case 413: { nx_DefinitionUpdate model=nx_DefinitionUpdate_read(args); (void)model; nx_DefinitionUpdate copy=nx_DefinitionUpdate_write(&constructed, nx_DefinitionUpdate_Definition(model), nx_DefinitionUpdate_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 414: { nx_DiagnosticAnalysis model=nx_DiagnosticAnalysis_read(args); (void)model; nx_DiagnosticAnalysis copy=nx_DiagnosticAnalysis_write(&constructed, nx_DiagnosticAnalysis_Instance(model), nx_DiagnosticAnalysis_Reports(model), nx_DiagnosticAnalysis_Issues(model)); nx_complete_value(w,copy.value); break; }
case 415: { nx_DiagnosticReport model=nx_DiagnosticReport_read(args); (void)model; nx_DiagnosticReport copy=nx_DiagnosticReport_write(&constructed, nx_DiagnosticReport_Code(model), nx_DiagnosticReport_Message(model), nx_DiagnosticReport_Severity(model), nx_DiagnosticReport_CorrelationId(model), nx_DiagnosticReport_OperationId(model)); nx_complete_value(w,copy.value); break; }
case 416: { nx_DiagnosticSpan model=nx_DiagnosticSpan_read(args); (void)model; nx_DiagnosticSpan copy=nx_DiagnosticSpan_write(&constructed, nx_DiagnosticSpan_Name(model), nx_DiagnosticSpan_CorrelationId(model), nx_DiagnosticSpan_Parent(model), nx_DiagnosticSpan_Attributes(model)); nx_complete_value(w,copy.value); break; }
case 417: { nx_DisplayInfo model=nx_DisplayInfo_read(args); (void)model; nx_DisplayInfo copy=nx_DisplayInfo_write(&constructed, nx_DisplayInfo_Id(model), nx_DisplayInfo_Width(model), nx_DisplayInfo_Height(model), nx_DisplayInfo_Scale(model)); nx_complete_value(w,copy.value); break; }
case 418: { nx_DownloadPlan model=nx_DownloadPlan_read(args); (void)model; nx_DownloadPlan copy=nx_DownloadPlan_write(&constructed, nx_DownloadPlan_Sources(model), nx_DownloadPlan_Target(model), nx_DownloadPlan_Size(model), nx_DownloadPlan_Sha256(model)); nx_complete_value(w,copy.value); break; }
case 419: { nx_DownloadSource model=nx_DownloadSource_read(args); (void)model; nx_DownloadSource copy=nx_DownloadSource_write(&constructed, nx_DownloadSource_Uri(model), nx_DownloadSource_Provider(model), nx_DownloadSource_Credential(model)); nx_complete_value(w,copy.value); break; }
case 420: { nx_DownloadState model=nx_DownloadState_read(args); (void)model; nx_DownloadState copy=nx_DownloadState_write(&constructed, nx_DownloadState_Id(model), nx_DownloadState_State(model), nx_DownloadState_BytesReceived(model), nx_DownloadState_TotalBytes(model), nx_DownloadState_Failures(model), nx_DownloadState_Revision(model)); nx_complete_value(w,copy.value); break; }
case 421: { nx_DrawCommand model=nx_DrawCommand_read(args); (void)model; nx_DrawCommand copy=nx_DrawCommand_write(&constructed, nx_DrawCommand_Kind(model), nx_DrawCommand_Coordinates(model), nx_DrawCommand_Color(model), nx_DrawCommand_Text(model), nx_DrawCommand_Image(model)); nx_complete_value(w,copy.value); break; }
case 422: { nx_DrawSubmission model=nx_DrawSubmission_read(args); (void)model; nx_DrawSubmission copy=nx_DrawSubmission_write(&constructed, nx_DrawSubmission_Surface(model), nx_DrawSubmission_Commands(model), nx_DrawSubmission_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 423: { nx_DrawingSurfaceRef model=nx_DrawingSurfaceRef_read(args); (void)model; nx_DrawingSurfaceRef copy=nx_DrawingSurfaceRef_write(&constructed, nx_DrawingSurfaceRef_Id(model), nx_DrawingSurfaceRef_ViewScope(model), nx_DrawingSurfaceRef_Revision(model)); nx_complete_value(w,copy.value); break; }
case 424: { nx_DrawingSurfaceRequest model=nx_DrawingSurfaceRequest_read(args); (void)model; nx_DrawingSurfaceRequest copy=nx_DrawingSurfaceRequest_write(&constructed, nx_DrawingSurfaceRequest_Id(model), nx_DrawingSurfaceRequest_Width(model), nx_DrawingSurfaceRequest_Height(model), nx_DrawingSurfaceRequest_ViewScope(model)); nx_complete_value(w,copy.value); break; }
case 425: { nx_EffectiveSetting model=nx_EffectiveSetting_read(args); (void)model; nx_EffectiveSetting copy=nx_EffectiveSetting_write(&constructed, nx_EffectiveSetting_Id(model), nx_EffectiveSetting_Value(model), nx_EffectiveSetting_Source(model), nx_EffectiveSetting_Revision(model)); nx_complete_value(w,copy.value); break; }
case 426: { nx_Empty model=nx_Empty_read(args); (void)model; nx_Empty copy=nx_Empty_write(&constructed); nx_complete_value(w,copy.value); break; }
case 427: { nx_EntityRequest model=nx_EntityRequest_read(args); (void)model; nx_EntityRequest copy=nx_EntityRequest_write(&constructed, nx_EntityRequest_Id(model)); nx_complete_value(w,copy.value); break; }
case 428: { nx_EventDescriptor model=nx_EventDescriptor_read(args); (void)model; nx_EventDescriptor copy=nx_EventDescriptor_write(&constructed, nx_EventDescriptor_Id(model), nx_EventDescriptor_Schema(model), nx_EventDescriptor_OrderingPartition(model), nx_EventDescriptor_Delivery(model), nx_EventDescriptor_Durable(model), nx_EventDescriptor_QueueLimit(model)); nx_complete_value(w,copy.value); break; }
case 429: { nx_EventEnvelope model=nx_EventEnvelope_read(args); (void)model; nx_EventEnvelope copy=nx_EventEnvelope_write(&constructed, nx_EventEnvelope_EventId(model), nx_EventEnvelope_Event(model), nx_EventEnvelope_Schema(model), nx_EventEnvelope_Entity(model), nx_EventEnvelope_Revision(model), nx_EventEnvelope_OccurredAt(model), nx_EventEnvelope_CorrelationId(model), nx_EventEnvelope_CausationId(model), nx_EventEnvelope_Origin(model), nx_EventEnvelope_Scope(model), nx_EventEnvelope_Payload(model)); nx_complete_value(w,copy.value); break; }
case 430: { nx_EventSubscribeRequest model=nx_EventSubscribeRequest_read(args); (void)model; nx_EventSubscribeRequest copy=nx_EventSubscribeRequest_write(&constructed, nx_EventSubscribeRequest_Event(model), nx_EventSubscribeRequest_Schema(model), nx_EventSubscribeRequest_Cursor(model), nx_EventSubscribeRequest_Handler(model), nx_EventSubscribeRequest_IgnoreSelf(model), nx_EventSubscribeRequest_Deduplicate(model), nx_EventSubscribeRequest_Scope(model), nx_EventSubscribeRequest_Lifetime(model), nx_EventSubscribeRequest_Reentry(model), nx_EventSubscribeRequest_QueueLimit(model)); nx_complete_value(w,copy.value); break; }
case 431: { nx_EventSubscriptionRegistration model=nx_EventSubscriptionRegistration_read(args); (void)model; nx_EventSubscriptionRegistration copy=nx_EventSubscriptionRegistration_write(&constructed, nx_EventSubscriptionRegistration_Registration(model), nx_EventSubscriptionRegistration_Subscription(model)); nx_complete_value(w,copy.value); break; }
case 432: { nx_ExtensionPointDefinition model=nx_ExtensionPointDefinition_read(args); (void)model; nx_ExtensionPointDefinition copy=nx_ExtensionPointDefinition_write(&constructed, nx_ExtensionPointDefinition_Id(model), nx_ExtensionPointDefinition_Input(model), nx_ExtensionPointDefinition_Output(model), nx_ExtensionPointDefinition_Mode(model), nx_ExtensionPointDefinition_DeadlineMilliseconds(model), nx_ExtensionPointDefinition_MergePolicy(model), nx_ExtensionPointDefinition_Ordering(model), nx_ExtensionPointDefinition_Reentry(model), nx_ExtensionPointDefinition_AllowedFields(model), nx_ExtensionPointDefinition_FailurePolicy(model)); nx_complete_value(w,copy.value); break; }
case 433: { nx_FavoriteChange model=nx_FavoriteChange_read(args); (void)model; nx_FavoriteChange copy=nx_FavoriteChange_write(&constructed, nx_FavoriteChange_Resource(model), nx_FavoriteChange_Favorite(model), nx_FavoriteChange_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 434: { nx_FileDelete model=nx_FileDelete_read(args); (void)model; nx_FileDelete copy=nx_FileDelete_write(&constructed, nx_FileDelete_File(model), nx_FileDelete_ExpectedRevision(model), nx_FileDelete_Recursive(model)); nx_complete_value(w,copy.value); break; }
case 435: { nx_FileMove model=nx_FileMove_read(args); (void)model; nx_FileMove copy=nx_FileMove_write(&constructed, nx_FileMove_File(model), nx_FileMove_Destination(model), nx_FileMove_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 436: { nx_FilePick model=nx_FilePick_read(args); (void)model; nx_FilePick copy=nx_FilePick_write(&constructed, nx_FilePick_Title(model), nx_FilePick_Kind(model), nx_FilePick_Extensions(model)); nx_complete_value(w,copy.value); break; }
case 437: { nx_FileQuery model=nx_FileQuery_read(args); (void)model; nx_FileQuery copy=nx_FileQuery_write(&constructed, nx_FileQuery_Directory(model), nx_FileQuery_Page(model)); nx_complete_value(w,copy.value); break; }
case 438: { nx_FileRead model=nx_FileRead_read(args); (void)model; nx_FileRead copy=nx_FileRead_write(&constructed, nx_FileRead_File(model), nx_FileRead_Offset(model), nx_FileRead_Length(model)); nx_complete_value(w,copy.value); break; }
case 439: { nx_FileRef model=nx_FileRef_read(args); (void)model; nx_FileRef copy=nx_FileRef_write(&constructed, nx_FileRef_Token(model), nx_FileRef_LoadInstanceId(model), nx_FileRef_Scope(model)); nx_complete_value(w,copy.value); break; }
case 440: { nx_FileStat model=nx_FileStat_read(args); (void)model; nx_FileStat copy=nx_FileStat_write(&constructed, nx_FileStat_File(model), nx_FileStat_Name(model), nx_FileStat_IsDirectory(model), nx_FileStat_Size(model), nx_FileStat_ModifiedAt(model), nx_FileStat_Revision(model)); nx_complete_value(w,copy.value); break; }
case 441: { nx_FileWrite model=nx_FileWrite_read(args); (void)model; nx_FileWrite copy=nx_FileWrite_write(&constructed, nx_FileWrite_File(model), nx_FileWrite_Data(model), nx_FileWrite_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 442: { nx_GameSession model=nx_GameSession_read(args); (void)model; nx_GameSession copy=nx_GameSession_write(&constructed, nx_GameSession_Id(model), nx_GameSession_Instance(model), nx_GameSession_StartedAt(model), nx_GameSession_Running(model)); nx_complete_value(w,copy.value); break; }
case 443: { nx_GameVersion model=nx_GameVersion_read(args); (void)model; nx_GameVersion copy=nx_GameVersion_write(&constructed, nx_GameVersion_Id(model), nx_GameVersion_Kind(model), nx_GameVersion_ReleasedAt(model)); nx_complete_value(w,copy.value); break; }
case 444: { nx_GrantRequest model=nx_GrantRequest_read(args); (void)model; nx_GrantRequest copy=nx_GrantRequest_write(&constructed, nx_GrantRequest_Account(model), nx_GrantRequest_Instance(model)); nx_complete_value(w,copy.value); break; }
case 445: { nx_InputSubscription model=nx_InputSubscription_read(args); (void)model; nx_InputSubscription copy=nx_InputSubscription_write(&constructed, nx_InputSubscription_Surface(model), nx_InputSubscription_Events(model), nx_InputSubscription_Handler(model)); nx_complete_value(w,copy.value); break; }
case 446: { nx_InstallDraft model=nx_InstallDraft_read(args); (void)model; nx_InstallDraft copy=nx_InstallDraft_write(&constructed, nx_InstallDraft_Id(model), nx_InstallDraft_Instance(model), nx_InstallDraft_GameVersion(model), nx_InstallDraft_Loaders(model), nx_InstallDraft_OptionalFiles(model), nx_InstallDraft_Revision(model)); nx_complete_value(w,copy.value); break; }
case 447: { nx_InstallDraftUpdate model=nx_InstallDraftUpdate_read(args); (void)model; nx_InstallDraftUpdate copy=nx_InstallDraftUpdate_write(&constructed, nx_InstallDraftUpdate_Draft(model), nx_InstallDraftUpdate_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 448: { nx_InstallPlan model=nx_InstallPlan_read(args); (void)model; nx_InstallPlan copy=nx_InstallPlan_write(&constructed, nx_InstallPlan_Plan(model), nx_InstallPlan_Instance(model), nx_InstallPlan_Steps(model)); nx_complete_value(w,copy.value); break; }
case 449: { nx_InstallStep model=nx_InstallStep_read(args); (void)model; nx_InstallStep copy=nx_InstallStep_write(&constructed, nx_InstallStep_Action(model), nx_InstallStep_Inputs(model), nx_InstallStep_Effects(model), nx_InstallStep_Reversible(model)); nx_complete_value(w,copy.value); break; }
case 450: { nx_InstallTemplate model=nx_InstallTemplate_read(args); (void)model; nx_InstallTemplate copy=nx_InstallTemplate_write(&constructed, nx_InstallTemplate_Id(model), nx_InstallTemplate_GameVersion(model), nx_InstallTemplate_Loaders(model), nx_InstallTemplate_Content(model), nx_InstallTemplate_Workflow(model)); nx_complete_value(w,copy.value); break; }
case 451: { nx_InstallerInspection model=nx_InstallerInspection_read(args); (void)model; nx_InstallerInspection copy=nx_InstallerInspection_write(&constructed, nx_InstallerInspection_File(model), nx_InstallerInspection_Loader(model), nx_InstallerInspection_Version(model), nx_InstallerInspection_Issues(model)); nx_complete_value(w,copy.value); break; }
case 452: { nx_InstanceCloneRequest model=nx_InstanceCloneRequest_read(args); (void)model; nx_InstanceCloneRequest copy=nx_InstanceCloneRequest_write(&constructed, nx_InstanceCloneRequest_Source(model), nx_InstanceCloneRequest_Name(model), nx_InstanceCloneRequest_Destination(model), nx_InstanceCloneRequest_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 453: { nx_InstanceCreateRequest model=nx_InstanceCreateRequest_read(args); (void)model; nx_InstanceCreateRequest copy=nx_InstanceCreateRequest_write(&constructed, nx_InstanceCreateRequest_Template(model), nx_InstanceCreateRequest_Name(model), nx_InstanceCreateRequest_Root(model), nx_InstanceCreateRequest_GameVersion(model), nx_InstanceCreateRequest_Loader(model)); nx_complete_value(w,copy.value); break; }
case 454: { nx_InstanceDeleteRequest model=nx_InstanceDeleteRequest_read(args); (void)model; nx_InstanceDeleteRequest copy=nx_InstanceDeleteRequest_write(&constructed, nx_InstanceDeleteRequest_Instance(model), nx_InstanceDeleteRequest_ExpectedRevision(model), nx_InstanceDeleteRequest_RetainUserData(model)); nx_complete_value(w,copy.value); break; }
case 455: { nx_InstanceDetails model=nx_InstanceDetails_read(args); (void)model; nx_InstanceDetails copy=nx_InstanceDetails_write(&constructed, nx_InstanceDetails_Summary(model), nx_InstanceDetails_Directory(model), nx_InstanceDetails_Running(model), nx_InstanceDetails_Tags(model)); nx_complete_value(w,copy.value); break; }
case 456: { nx_InstanceListRequest model=nx_InstanceListRequest_read(args); (void)model; nx_InstanceListRequest copy=nx_InstanceListRequest_write(&constructed, nx_InstanceListRequest_Root(model), nx_InstanceListRequest_Page(model)); nx_complete_value(w,copy.value); break; }
case 457: { nx_InstanceRenameRequest model=nx_InstanceRenameRequest_read(args); (void)model; nx_InstanceRenameRequest copy=nx_InstanceRenameRequest_write(&constructed, nx_InstanceRenameRequest_Instance(model), nx_InstanceRenameRequest_Name(model), nx_InstanceRenameRequest_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 458: { nx_InstanceSummary model=nx_InstanceSummary_read(args); (void)model; nx_InstanceSummary copy=nx_InstanceSummary_write(&constructed, nx_InstanceSummary_Id(model), nx_InstanceSummary_Name(model), nx_InstanceSummary_GameVersion(model), nx_InstanceSummary_Loader(model), nx_InstanceSummary_Root(model), nx_InstanceSummary_Revision(model)); nx_complete_value(w,copy.value); break; }
case 459: { nx_IntegrityReport model=nx_IntegrityReport_read(args); (void)model; nx_IntegrityReport copy=nx_IntegrityReport_write(&constructed, nx_IntegrityReport_Target(model), nx_IntegrityReport_Valid(model), nx_IntegrityReport_Issues(model), nx_IntegrityReport_Revision(model)); nx_complete_value(w,copy.value); break; }
case 460: { nx_JavaDistribution model=nx_JavaDistribution_read(args); (void)model; nx_JavaDistribution copy=nx_JavaDistribution_write(&constructed, nx_JavaDistribution_Provider(model), nx_JavaDistribution_Version(model), nx_JavaDistribution_Architecture(model), nx_JavaDistribution_OperatingSystem(model), nx_JavaDistribution_Download(model)); nx_complete_value(w,copy.value); break; }
case 461: { nx_JavaInstallRequest model=nx_JavaInstallRequest_read(args); (void)model; nx_JavaInstallRequest copy=nx_JavaInstallRequest_write(&constructed, nx_JavaInstallRequest_Distribution(model), nx_JavaInstallRequest_Target(model)); nx_complete_value(w,copy.value); break; }
case 462: { nx_JavaRequirements model=nx_JavaRequirements_read(args); (void)model; nx_JavaRequirements copy=nx_JavaRequirements_write(&constructed, nx_JavaRequirements_Instance(model), nx_JavaRequirements_MinimumMajor(model), nx_JavaRequirements_MaximumMajor(model), nx_JavaRequirements_Architecture(model)); nx_complete_value(w,copy.value); break; }
case 463: { nx_JavaRuntime model=nx_JavaRuntime_read(args); (void)model; nx_JavaRuntime copy=nx_JavaRuntime_write(&constructed, nx_JavaRuntime_Id(model), nx_JavaRuntime_Version(model), nx_JavaRuntime_Architecture(model), nx_JavaRuntime_Vendor(model), nx_JavaRuntime_File(model), nx_JavaRuntime_Managed(model)); nx_complete_value(w,copy.value); break; }
case 464: { nx_JavaSelection model=nx_JavaSelection_read(args); (void)model; nx_JavaSelection copy=nx_JavaSelection_write(&constructed, nx_JavaSelection_Instance(model), nx_JavaSelection_Runtime(model), nx_JavaSelection_VersionLocal(model), nx_JavaSelection_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 465: { nx_LaunchArgument model=nx_LaunchArgument_read(args); (void)model; nx_LaunchArgument copy=nx_LaunchArgument_write(&constructed, nx_LaunchArgument_Id(model), nx_LaunchArgument_Value(model), nx_LaunchArgument_Scope(model)); nx_complete_value(w,copy.value); break; }
case 466: { nx_LaunchAttempt model=nx_LaunchAttempt_read(args); (void)model; nx_LaunchAttempt copy=nx_LaunchAttempt_write(&constructed, nx_LaunchAttempt_Id(model), nx_LaunchAttempt_Instance(model), nx_LaunchAttempt_State(model), nx_LaunchAttempt_Session(model), nx_LaunchAttempt_Issues(model), nx_LaunchAttempt_Revision(model)); nx_complete_value(w,copy.value); break; }
case 467: { nx_LaunchContributionRegistration model=nx_LaunchContributionRegistration_read(args); (void)model; nx_LaunchContributionRegistration copy=nx_LaunchContributionRegistration_write(&constructed, nx_LaunchContributionRegistration_Id(model), nx_LaunchContributionRegistration_Fields(model), nx_LaunchContributionRegistration_Handler(model), nx_LaunchContributionRegistration_Required(model)); nx_complete_value(w,copy.value); break; }
case 468: { nx_LaunchContributionReport model=nx_LaunchContributionReport_read(args); (void)model; nx_LaunchContributionReport copy=nx_LaunchContributionReport_write(&constructed, nx_LaunchContributionReport_Attempt(model), nx_LaunchContributionReport_Accepted(model), nx_LaunchContributionReport_Suppressed(model)); nx_complete_value(w,copy.value); break; }
case 469: { nx_LaunchEligibility model=nx_LaunchEligibility_read(args); (void)model; nx_LaunchEligibility copy=nx_LaunchEligibility_write(&constructed, nx_LaunchEligibility_Account(model), nx_LaunchEligibility_Allowed(model), nx_LaunchEligibility_Reasons(model)); nx_complete_value(w,copy.value); break; }
case 470: { nx_LaunchGrant model=nx_LaunchGrant_read(args); (void)model; nx_LaunchGrant copy=nx_LaunchGrant_write(&constructed, nx_LaunchGrant_Token(model), nx_LaunchGrant_LoadInstanceId(model), nx_LaunchGrant_Account(model)); nx_complete_value(w,copy.value); break; }
case 471: { nx_LaunchIntent model=nx_LaunchIntent_read(args); (void)model; nx_LaunchIntent copy=nx_LaunchIntent_write(&constructed, nx_LaunchIntent_Instance(model), nx_LaunchIntent_Grant(model), nx_LaunchIntent_Profile(model), nx_LaunchIntent_Target(model)); nx_complete_value(w,copy.value); break; }
case 472: { nx_LaunchPlan model=nx_LaunchPlan_read(args); (void)model; nx_LaunchPlan copy=nx_LaunchPlan_write(&constructed, nx_LaunchPlan_Plan(model), nx_LaunchPlan_Instance(model), nx_LaunchPlan_Profile(model), nx_LaunchPlan_ProviderVersions(model), nx_LaunchPlan_Suppressed(model)); nx_complete_value(w,copy.value); break; }
case 473: { nx_LaunchProfile model=nx_LaunchProfile_read(args); (void)model; nx_LaunchProfile copy=nx_LaunchProfile_write(&constructed, nx_LaunchProfile_Id(model), nx_LaunchProfile_Name(model), nx_LaunchProfile_MemoryMiB(model), nx_LaunchProfile_Java(model), nx_LaunchProfile_Width(model), nx_LaunchProfile_Height(model), nx_LaunchProfile_Arguments(model), nx_LaunchProfile_Environment(model), nx_LaunchProfile_Revision(model)); nx_complete_value(w,copy.value); break; }
case 474: { nx_LaunchProfileSelection model=nx_LaunchProfileSelection_read(args); (void)model; nx_LaunchProfileSelection copy=nx_LaunchProfileSelection_write(&constructed, nx_LaunchProfileSelection_Instance(model), nx_LaunchProfileSelection_Profile(model), nx_LaunchProfileSelection_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 475: { nx_LaunchProfileWrite model=nx_LaunchProfileWrite_read(args); (void)model; nx_LaunchProfileWrite copy=nx_LaunchProfileWrite_write(&constructed, nx_LaunchProfileWrite_Instance(model), nx_LaunchProfileWrite_Profile(model), nx_LaunchProfileWrite_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 476: { nx_LaunchTarget model=nx_LaunchTarget_read(args); (void)model; nx_LaunchTarget copy=nx_LaunchTarget_write(&constructed, nx_LaunchTarget_Server(model), nx_LaunchTarget_World(model)); nx_complete_value(w,copy.value); break; }
case 477: { nx_LegacyCleanup model=nx_LegacyCleanup_read(args); (void)model; nx_LegacyCleanup copy=nx_LegacyCleanup_write(&constructed, nx_LegacyCleanup_Callback(model)); nx_complete_value(w,copy.value); break; }
case 478: { nx_LegacyCommand model=nx_LegacyCommand_read(args); (void)model; nx_LegacyCommand copy=nx_LegacyCommand_write(&constructed, nx_LegacyCommand_LocalId(model), nx_LegacyCommand_Title(model), nx_LegacyCommand_Handler(model)); nx_complete_value(w,copy.value); break; }
case 479: { nx_LegacyCommandState model=nx_LegacyCommandState_read(args); (void)model; nx_LegacyCommandState copy=nx_LegacyCommandState_write(&constructed, nx_LegacyCommandState_Handle(model), nx_LegacyCommandState_Enabled(model), nx_LegacyCommandState_Visible(model)); nx_complete_value(w,copy.value); break; }
case 480: { nx_LegacyDiagnostic model=nx_LegacyDiagnostic_read(args); (void)model; nx_LegacyDiagnostic copy=nx_LegacyDiagnostic_write(&constructed, nx_LegacyDiagnostic_Code(model), nx_LegacyDiagnostic_Message(model), nx_LegacyDiagnostic_Severity(model)); nx_complete_value(w,copy.value); break; }
case 481: { nx_LegacyEventDeclaration model=nx_LegacyEventDeclaration_read(args); (void)model; nx_LegacyEventDeclaration copy=nx_LegacyEventDeclaration_write(&constructed, nx_LegacyEventDeclaration_Name(model), nx_LegacyEventDeclaration_PayloadSchemaId(model), nx_LegacyEventDeclaration_PayloadSchemaDigest(model), nx_LegacyEventDeclaration_Delivery(model), nx_LegacyEventDeclaration_MaxPayloadBytes(model), nx_LegacyEventDeclaration_QueueLimit(model)); nx_complete_value(w,copy.value); break; }
case 482: { nx_LegacyEventPublish model=nx_LegacyEventPublish_read(args); (void)model; nx_LegacyEventPublish copy=nx_LegacyEventPublish_write(&constructed, nx_LegacyEventPublish_Handle(model), nx_LegacyEventPublish_Payload(model)); nx_complete_value(w,copy.value); break; }
case 483: { nx_LegacyEventSubscription model=nx_LegacyEventSubscription_read(args); (void)model; nx_LegacyEventSubscription copy=nx_LegacyEventSubscription_write(&constructed, nx_LegacyEventSubscription_SourcePluginId(model), nx_LegacyEventSubscription_EventName(model), nx_LegacyEventSubscription_SchemaId(model), nx_LegacyEventSubscription_Handler(model), nx_LegacyEventSubscription_Required(model), nx_LegacyEventSubscription_Concurrency(model), nx_LegacyEventSubscription_QueueLimit(model)); nx_complete_value(w,copy.value); break; }
case 484: { nx_LegacyFinding model=nx_LegacyFinding_read(args); (void)model; nx_LegacyFinding copy=nx_LegacyFinding_write(&constructed, nx_LegacyFinding_Code(model), nx_LegacyFinding_Message(model), nx_LegacyFinding_Fatal(model)); nx_complete_value(w,copy.value); break; }
case 485: { nx_LegacyHandle model=nx_LegacyHandle_read(args); (void)model; nx_LegacyHandle copy=nx_LegacyHandle_write(&constructed, nx_LegacyHandle_Handle(model)); nx_complete_value(w,copy.value); break; }
case 486: { nx_LegacyPatch model=nx_LegacyPatch_read(args); (void)model; nx_LegacyPatch copy=nx_LegacyPatch_write(&constructed, nx_LegacyPatch_Handle(model), nx_LegacyPatch_Revision(model), nx_LegacyPatch_Patch(model)); nx_complete_value(w,copy.value); break; }
case 487: { nx_LegacyPlacement model=nx_LegacyPlacement_read(args); (void)model; nx_LegacyPlacement copy=nx_LegacyPlacement_write(&constructed, nx_LegacyPlacement_LocalId(model), nx_LegacyPlacement_SurfaceId(model), nx_LegacyPlacement_SlotId(model)); nx_complete_value(w,copy.value); break; }
case 488: { nx_LegacyServiceCall model=nx_LegacyServiceCall_read(args); (void)model; nx_LegacyServiceCall copy=nx_LegacyServiceCall_write(&constructed, nx_LegacyServiceCall_Handle(model), nx_LegacyServiceCall_MethodId(model), nx_LegacyServiceCall_Payload(model)); nx_complete_value(w,copy.value); break; }
case 489: { nx_LegacyServiceDeclaration model=nx_LegacyServiceDeclaration_read(args); (void)model; nx_LegacyServiceDeclaration copy=nx_LegacyServiceDeclaration_write(&constructed, nx_LegacyServiceDeclaration_ServiceId(model), nx_LegacyServiceDeclaration_ContractId(model), nx_LegacyServiceDeclaration_ContractVersion(model), nx_LegacyServiceDeclaration_SchemaDigest(model), nx_LegacyServiceDeclaration_Methods(model), nx_LegacyServiceDeclaration_HealthProbe(model), nx_LegacyServiceDeclaration_Handler(model)); nx_complete_value(w,copy.value); break; }
case 490: { nx_LegacyServiceProbe model=nx_LegacyServiceProbe_read(args); (void)model; nx_LegacyServiceProbe copy=nx_LegacyServiceProbe_write(&constructed, nx_LegacyServiceProbe_Handle(model), nx_LegacyServiceProbe_ProbeId(model), nx_LegacyServiceProbe_Payload(model)); nx_complete_value(w,copy.value); break; }
case 491: { nx_LegacyServiceQuery model=nx_LegacyServiceQuery_read(args); (void)model; nx_LegacyServiceQuery copy=nx_LegacyServiceQuery_write(&constructed, nx_LegacyServiceQuery_ProviderPluginId(model), nx_LegacyServiceQuery_ServiceId(model)); nx_complete_value(w,copy.value); break; }
case 492: { nx_LegacyServiceRequirement model=nx_LegacyServiceRequirement_read(args); (void)model; nx_LegacyServiceRequirement copy=nx_LegacyServiceRequirement_write(&constructed, nx_LegacyServiceRequirement_ProviderPluginId(model), nx_LegacyServiceRequirement_ServiceId(model), nx_LegacyServiceRequirement_MinimumContractVersion(model), nx_LegacyServiceRequirement_MaximumContractVersion(model), nx_LegacyServiceRequirement_Required(model)); nx_complete_value(w,copy.value); break; }
case 493: { nx_LegacySettings model=nx_LegacySettings_read(args); (void)model; nx_LegacySettings copy=nx_LegacySettings_write(&constructed, nx_LegacySettings_LocalId(model), nx_LegacySettings_SchemaId(model), nx_LegacySettings_SchemaDigest(model), nx_LegacySettings_Layout(model)); nx_complete_value(w,copy.value); break; }
case 494: { nx_LegacySurface model=nx_LegacySurface_read(args); (void)model; nx_LegacySurface copy=nx_LegacySurface_write(&constructed, nx_LegacySurface_LocalId(model), nx_LegacySurface_Nodes(model), nx_LegacySurface_ResourceIds(model)); nx_complete_value(w,copy.value); break; }
case 495: { nx_LoadReport model=nx_LoadReport_read(args); (void)model; nx_LoadReport copy=nx_LoadReport_write(&constructed, nx_LoadReport_Plugin(model), nx_LoadReport_LoadInstance(model), nx_LoadReport_State(model), nx_LoadReport_Findings(model), nx_LoadReport_DependencyChain(model)); nx_complete_value(w,copy.value); break; }
case 496: { nx_LoaderVersion model=nx_LoaderVersion_read(args); (void)model; nx_LoaderVersion copy=nx_LoaderVersion_write(&constructed, nx_LoaderVersion_Loader(model), nx_LoaderVersion_Version(model), nx_LoaderVersion_GameVersion(model), nx_LoaderVersion_Stable(model)); nx_complete_value(w,copy.value); break; }
case 497: { nx_LoaderVersionRequest model=nx_LoaderVersionRequest_read(args); (void)model; nx_LoaderVersionRequest copy=nx_LoaderVersionRequest_write(&constructed, nx_LoaderVersionRequest_Loader(model), nx_LoaderVersionRequest_GameVersion(model), nx_LoaderVersionRequest_Page(model)); nx_complete_value(w,copy.value); break; }
case 498: { nx_LocalizedText model=nx_LocalizedText_read(args); (void)model; nx_LocalizedText copy=nx_LocalizedText_write(&constructed, nx_LocalizedText_MessageKey(model), nx_LocalizedText_Arguments(model)); nx_complete_value(w,copy.value); break; }
case 499: { nx_LogChunk model=nx_LogChunk_read(args); (void)model; nx_LogChunk copy=nx_LogChunk_write(&constructed, nx_LogChunk_Session(model), nx_LogChunk_Lines(model), nx_LogChunk_NextCursor(model), nx_LogChunk_Gap(model)); nx_complete_value(w,copy.value); break; }
case 500: { nx_LogRangeRequest model=nx_LogRangeRequest_read(args); (void)model; nx_LogRangeRequest copy=nx_LogRangeRequest_write(&constructed, nx_LogRangeRequest_Session(model), nx_LogRangeRequest_Cursor(model), nx_LogRangeRequest_Limit(model)); nx_complete_value(w,copy.value); break; }
case 501: { nx_ManagedJavaInstallRequest model=nx_ManagedJavaInstallRequest_read(args); (void)model; nx_ManagedJavaInstallRequest copy=nx_ManagedJavaInstallRequest_write(&constructed, nx_ManagedJavaInstallRequest_Offer(model), nx_ManagedJavaInstallRequest_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 502: { nx_ManagedJavaOffer model=nx_ManagedJavaOffer_read(args); (void)model; nx_ManagedJavaOffer copy=nx_ManagedJavaOffer_write(&constructed, nx_ManagedJavaOffer_Id(model), nx_ManagedJavaOffer_Provider(model), nx_ManagedJavaOffer_Version(model), nx_ManagedJavaOffer_Platform(model), nx_ManagedJavaOffer_Files(model), nx_ManagedJavaOffer_Bytes(model), nx_ManagedJavaOffer_Licenses(model), nx_ManagedJavaOffer_ExpiresAt(model), nx_ManagedJavaOffer_Revision(model)); nx_complete_value(w,copy.value); break; }
case 503: { nx_MutationPlan model=nx_MutationPlan_read(args); (void)model; nx_MutationPlan copy=nx_MutationPlan_write(&constructed, nx_MutationPlan_Id(model), nx_MutationPlan_Revision(model), nx_MutationPlan_InputsHash(model), nx_MutationPlan_Summary(model), nx_MutationPlan_Confirmation(model), nx_MutationPlan_Constraints(model)); nx_complete_value(w,copy.value); break; }
case 504: { nx_NamedValue model=nx_NamedValue_read(args); (void)model; nx_NamedValue copy=nx_NamedValue_write(&constructed, nx_NamedValue_Name(model), nx_NamedValue_Value(model)); nx_complete_value(w,copy.value); break; }
case 505: { nx_NamespaceRequest model=nx_NamespaceRequest_read(args); (void)model; nx_NamespaceRequest copy=nx_NamespaceRequest_write(&constructed, nx_NamespaceRequest_Namespace(model), nx_NamespaceRequest_SchemaVersion(model)); nx_complete_value(w,copy.value); break; }
case 506: { nx_NetworkConnection model=nx_NetworkConnection_read(args); (void)model; nx_NetworkConnection copy=nx_NetworkConnection_write(&constructed, nx_NetworkConnection_Id(model), nx_NetworkConnection_Protocol(model), nx_NetworkConnection_Scope(model), nx_NetworkConnection_LoadInstanceId(model)); nx_complete_value(w,copy.value); break; }
case 507: { nx_NetworkConnectionRequest model=nx_NetworkConnectionRequest_read(args); (void)model; nx_NetworkConnectionRequest copy=nx_NetworkConnectionRequest_write(&constructed, nx_NetworkConnectionRequest_Protocol(model), nx_NetworkConnectionRequest_Address(model), nx_NetworkConnectionRequest_Port(model), nx_NetworkConnectionRequest_Scope(model)); nx_complete_value(w,copy.value); break; }
case 508: { nx_NetworkPacket model=nx_NetworkPacket_read(args); (void)model; nx_NetworkPacket copy=nx_NetworkPacket_write(&constructed, nx_NetworkPacket_Data(model), nx_NetworkPacket_Source(model), nx_NetworkPacket_EndOfStream(model)); nx_complete_value(w,copy.value); break; }
case 509: { nx_NetworkReceive model=nx_NetworkReceive_read(args); (void)model; nx_NetworkReceive copy=nx_NetworkReceive_write(&constructed, nx_NetworkReceive_Connection(model), nx_NetworkReceive_MaximumBytes(model)); nx_complete_value(w,copy.value); break; }
case 510: { nx_NetworkRequest model=nx_NetworkRequest_read(args); (void)model; nx_NetworkRequest copy=nx_NetworkRequest_write(&constructed, nx_NetworkRequest_Uri(model), nx_NetworkRequest_Method(model), nx_NetworkRequest_Headers(model), nx_NetworkRequest_Body(model), nx_NetworkRequest_Credential(model)); nx_complete_value(w,copy.value); break; }
case 511: { nx_NetworkResponse model=nx_NetworkResponse_read(args); (void)model; nx_NetworkResponse copy=nx_NetworkResponse_write(&constructed, nx_NetworkResponse_Id(model), nx_NetworkResponse_StatusCode(model), nx_NetworkResponse_Headers(model), nx_NetworkResponse_Body(model)); nx_complete_value(w,copy.value); break; }
case 512: { nx_NetworkSend model=nx_NetworkSend_read(args); (void)model; nx_NetworkSend copy=nx_NetworkSend_write(&constructed, nx_NetworkSend_Connection(model), nx_NetworkSend_Data(model), nx_NetworkSend_Destination(model)); nx_complete_value(w,copy.value); break; }
case 513: { nx_OperationFailure model=nx_OperationFailure_read(args); (void)model; nx_OperationFailure copy=nx_OperationFailure_write(&constructed, nx_OperationFailure_Code(model), nx_OperationFailure_Message(model), nx_OperationFailure_CorrelationId(model), nx_OperationFailure_Retryable(model), nx_OperationFailure_Details(model)); nx_complete_value(w,copy.value); break; }
case 514: { nx_OperationRecord model=nx_OperationRecord_read(args); (void)model; nx_OperationRecord copy=nx_OperationRecord_write(&constructed, nx_OperationRecord_Id(model), nx_OperationRecord_State(model), nx_OperationRecord_Progress(model), nx_OperationRecord_Stage(model), nx_OperationRecord_ResultSchema(model), nx_OperationRecord_Result(model), nx_OperationRecord_Failure(model), nx_OperationRecord_Revision(model)); nx_complete_value(w,copy.value); break; }
case 515: { nx_OperationRef model=nx_OperationRef_read(args); (void)model; nx_OperationRef copy=nx_OperationRef_write(&constructed, nx_OperationRef_Id(model), nx_OperationRef_State(model)); nx_complete_value(w,copy.value); break; }
case 516: { nx_OperationRequest model=nx_OperationRequest_read(args); (void)model; nx_OperationRequest copy=nx_OperationRequest_write(&constructed, nx_OperationRequest_Operation(model)); nx_complete_value(w,copy.value); break; }
case 517: { nx_OverlayDefinition model=nx_OverlayDefinition_read(args); (void)model; nx_OverlayDefinition copy=nx_OverlayDefinition_write(&constructed, nx_OverlayDefinition_Id(model), nx_OverlayDefinition_Target(model), nx_OverlayDefinition_Mode(model), nx_OverlayDefinition_Schema(model), nx_OverlayDefinition_Patch(model), nx_OverlayDefinition_Before(model), nx_OverlayDefinition_After(model)); nx_complete_value(w,copy.value); break; }
case 518: { nx_PackageFileRequest model=nx_PackageFileRequest_read(args); (void)model; nx_PackageFileRequest copy=nx_PackageFileRequest_write(&constructed, nx_PackageFileRequest_Path(model)); nx_complete_value(w,copy.value); break; }
case 519: { nx_Page_AccountPublic model=nx_Page_AccountPublic_read(args); (void)model; nx_Page_AccountPublic copy=nx_Page_AccountPublic_write(&constructed, nx_Page_AccountPublic_Items(model), nx_Page_AccountPublic_NextCursor(model), nx_Page_AccountPublic_Revision(model)); nx_complete_value(w,copy.value); break; }
case 520: { nx_Page_ActionDescriptor model=nx_Page_ActionDescriptor_read(args); (void)model; nx_Page_ActionDescriptor copy=nx_Page_ActionDescriptor_write(&constructed, nx_Page_ActionDescriptor_Items(model), nx_Page_ActionDescriptor_NextCursor(model), nx_Page_ActionDescriptor_Revision(model)); nx_complete_value(w,copy.value); break; }
case 521: { nx_Page_BackupSummary model=nx_Page_BackupSummary_read(args); (void)model; nx_Page_BackupSummary copy=nx_Page_BackupSummary_write(&constructed, nx_Page_BackupSummary_Items(model), nx_Page_BackupSummary_NextCursor(model), nx_Page_BackupSummary_Revision(model)); nx_complete_value(w,copy.value); break; }
case 522: { nx_Page_CatalogDependency model=nx_Page_CatalogDependency_read(args); (void)model; nx_Page_CatalogDependency copy=nx_Page_CatalogDependency_write(&constructed, nx_Page_CatalogDependency_Items(model), nx_Page_CatalogDependency_NextCursor(model), nx_Page_CatalogDependency_Revision(model)); nx_complete_value(w,copy.value); break; }
case 523: { nx_Page_CatalogFile model=nx_Page_CatalogFile_read(args); (void)model; nx_Page_CatalogFile copy=nx_Page_CatalogFile_write(&constructed, nx_Page_CatalogFile_Items(model), nx_Page_CatalogFile_NextCursor(model), nx_Page_CatalogFile_Revision(model)); nx_complete_value(w,copy.value); break; }
case 524: { nx_Page_CatalogProject model=nx_Page_CatalogProject_read(args); (void)model; nx_Page_CatalogProject copy=nx_Page_CatalogProject_write(&constructed, nx_Page_CatalogProject_Items(model), nx_Page_CatalogProject_NextCursor(model), nx_Page_CatalogProject_Revision(model)); nx_complete_value(w,copy.value); break; }
case 525: { nx_Page_CatalogVersion model=nx_Page_CatalogVersion_read(args); (void)model; nx_Page_CatalogVersion copy=nx_Page_CatalogVersion_write(&constructed, nx_Page_CatalogVersion_Items(model), nx_Page_CatalogVersion_NextCursor(model), nx_Page_CatalogVersion_Revision(model)); nx_complete_value(w,copy.value); break; }
case 526: { nx_Page_ContentItem model=nx_Page_ContentItem_read(args); (void)model; nx_Page_ContentItem copy=nx_Page_ContentItem_write(&constructed, nx_Page_ContentItem_Items(model), nx_Page_ContentItem_NextCursor(model), nx_Page_ContentItem_Revision(model)); nx_complete_value(w,copy.value); break; }
case 527: { nx_Page_ContentTransaction model=nx_Page_ContentTransaction_read(args); (void)model; nx_Page_ContentTransaction copy=nx_Page_ContentTransaction_write(&constructed, nx_Page_ContentTransaction_Items(model), nx_Page_ContentTransaction_NextCursor(model), nx_Page_ContentTransaction_Revision(model)); nx_complete_value(w,copy.value); break; }
case 528: { nx_Page_Definition model=nx_Page_Definition_read(args); (void)model; nx_Page_Definition copy=nx_Page_Definition_write(&constructed, nx_Page_Definition_Items(model), nx_Page_Definition_NextCursor(model), nx_Page_Definition_Revision(model)); nx_complete_value(w,copy.value); break; }
case 529: { nx_Page_DiagnosticReport model=nx_Page_DiagnosticReport_read(args); (void)model; nx_Page_DiagnosticReport copy=nx_Page_DiagnosticReport_write(&constructed, nx_Page_DiagnosticReport_Items(model), nx_Page_DiagnosticReport_NextCursor(model), nx_Page_DiagnosticReport_Revision(model)); nx_complete_value(w,copy.value); break; }
case 530: { nx_Page_DisplayInfo model=nx_Page_DisplayInfo_read(args); (void)model; nx_Page_DisplayInfo copy=nx_Page_DisplayInfo_write(&constructed, nx_Page_DisplayInfo_Items(model), nx_Page_DisplayInfo_NextCursor(model), nx_Page_DisplayInfo_Revision(model)); nx_complete_value(w,copy.value); break; }
case 531: { nx_Page_EffectiveSetting model=nx_Page_EffectiveSetting_read(args); (void)model; nx_Page_EffectiveSetting copy=nx_Page_EffectiveSetting_write(&constructed, nx_Page_EffectiveSetting_Items(model), nx_Page_EffectiveSetting_NextCursor(model), nx_Page_EffectiveSetting_Revision(model)); nx_complete_value(w,copy.value); break; }
case 532: { nx_Page_FileStat model=nx_Page_FileStat_read(args); (void)model; nx_Page_FileStat copy=nx_Page_FileStat_write(&constructed, nx_Page_FileStat_Items(model), nx_Page_FileStat_NextCursor(model), nx_Page_FileStat_Revision(model)); nx_complete_value(w,copy.value); break; }
case 533: { nx_Page_GameSession model=nx_Page_GameSession_read(args); (void)model; nx_Page_GameSession copy=nx_Page_GameSession_write(&constructed, nx_Page_GameSession_Items(model), nx_Page_GameSession_NextCursor(model), nx_Page_GameSession_Revision(model)); nx_complete_value(w,copy.value); break; }
case 534: { nx_Page_GameVersion model=nx_Page_GameVersion_read(args); (void)model; nx_Page_GameVersion copy=nx_Page_GameVersion_write(&constructed, nx_Page_GameVersion_Items(model), nx_Page_GameVersion_NextCursor(model), nx_Page_GameVersion_Revision(model)); nx_complete_value(w,copy.value); break; }
case 535: { nx_Page_InstanceSummary model=nx_Page_InstanceSummary_read(args); (void)model; nx_Page_InstanceSummary copy=nx_Page_InstanceSummary_write(&constructed, nx_Page_InstanceSummary_Items(model), nx_Page_InstanceSummary_NextCursor(model), nx_Page_InstanceSummary_Revision(model)); nx_complete_value(w,copy.value); break; }
case 536: { nx_Page_JavaDistribution model=nx_Page_JavaDistribution_read(args); (void)model; nx_Page_JavaDistribution copy=nx_Page_JavaDistribution_write(&constructed, nx_Page_JavaDistribution_Items(model), nx_Page_JavaDistribution_NextCursor(model), nx_Page_JavaDistribution_Revision(model)); nx_complete_value(w,copy.value); break; }
case 537: { nx_Page_JavaRuntime model=nx_Page_JavaRuntime_read(args); (void)model; nx_Page_JavaRuntime copy=nx_Page_JavaRuntime_write(&constructed, nx_Page_JavaRuntime_Items(model), nx_Page_JavaRuntime_NextCursor(model), nx_Page_JavaRuntime_Revision(model)); nx_complete_value(w,copy.value); break; }
case 538: { nx_Page_LaunchProfile model=nx_Page_LaunchProfile_read(args); (void)model; nx_Page_LaunchProfile copy=nx_Page_LaunchProfile_write(&constructed, nx_Page_LaunchProfile_Items(model), nx_Page_LaunchProfile_NextCursor(model), nx_Page_LaunchProfile_Revision(model)); nx_complete_value(w,copy.value); break; }
case 539: { nx_Page_LoaderVersion model=nx_Page_LoaderVersion_read(args); (void)model; nx_Page_LoaderVersion copy=nx_Page_LoaderVersion_write(&constructed, nx_Page_LoaderVersion_Items(model), nx_Page_LoaderVersion_NextCursor(model), nx_Page_LoaderVersion_Revision(model)); nx_complete_value(w,copy.value); break; }
case 540: { nx_Page_ManagedJavaOffer model=nx_Page_ManagedJavaOffer_read(args); (void)model; nx_Page_ManagedJavaOffer copy=nx_Page_ManagedJavaOffer_write(&constructed, nx_Page_ManagedJavaOffer_Items(model), nx_Page_ManagedJavaOffer_NextCursor(model), nx_Page_ManagedJavaOffer_Revision(model)); nx_complete_value(w,copy.value); break; }
case 541: { nx_Page_OperationRecord model=nx_Page_OperationRecord_read(args); (void)model; nx_Page_OperationRecord copy=nx_Page_OperationRecord_write(&constructed, nx_Page_OperationRecord_Items(model), nx_Page_OperationRecord_NextCursor(model), nx_Page_OperationRecord_Revision(model)); nx_complete_value(w,copy.value); break; }
case 542: { nx_Page_ProviderDescriptor model=nx_Page_ProviderDescriptor_read(args); (void)model; nx_Page_ProviderDescriptor copy=nx_Page_ProviderDescriptor_write(&constructed, nx_Page_ProviderDescriptor_Items(model), nx_Page_ProviderDescriptor_NextCursor(model), nx_Page_ProviderDescriptor_Revision(model)); nx_complete_value(w,copy.value); break; }
case 543: { nx_Page_PublicContract model=nx_Page_PublicContract_read(args); (void)model; nx_Page_PublicContract copy=nx_Page_PublicContract_write(&constructed, nx_Page_PublicContract_Items(model), nx_Page_PublicContract_NextCursor(model), nx_Page_PublicContract_Revision(model)); nx_complete_value(w,copy.value); break; }
case 544: { nx_Page_RecoveryRecord model=nx_Page_RecoveryRecord_read(args); (void)model; nx_Page_RecoveryRecord copy=nx_Page_RecoveryRecord_write(&constructed, nx_Page_RecoveryRecord_Items(model), nx_Page_RecoveryRecord_NextCursor(model), nx_Page_RecoveryRecord_Revision(model)); nx_complete_value(w,copy.value); break; }
case 545: { nx_Page_RegistrationRef model=nx_Page_RegistrationRef_read(args); (void)model; nx_Page_RegistrationRef copy=nx_Page_RegistrationRef_write(&constructed, nx_Page_RegistrationRef_Items(model), nx_Page_RegistrationRef_NextCursor(model), nx_Page_RegistrationRef_Revision(model)); nx_complete_value(w,copy.value); break; }
case 546: { nx_Page_RegistryDescriptor model=nx_Page_RegistryDescriptor_read(args); (void)model; nx_Page_RegistryDescriptor copy=nx_Page_RegistryDescriptor_write(&constructed, nx_Page_RegistryDescriptor_Items(model), nx_Page_RegistryDescriptor_NextCursor(model), nx_Page_RegistryDescriptor_Revision(model)); nx_complete_value(w,copy.value); break; }
case 547: { nx_Page_RootRegistration model=nx_Page_RootRegistration_read(args); (void)model; nx_Page_RootRegistration copy=nx_Page_RootRegistration_write(&constructed, nx_Page_RootRegistration_Items(model), nx_Page_RootRegistration_NextCursor(model), nx_Page_RootRegistration_Revision(model)); nx_complete_value(w,copy.value); break; }
case 548: { nx_Page_ScheduleState model=nx_Page_ScheduleState_read(args); (void)model; nx_Page_ScheduleState copy=nx_Page_ScheduleState_write(&constructed, nx_Page_ScheduleState_Items(model), nx_Page_ScheduleState_NextCursor(model), nx_Page_ScheduleState_Revision(model)); nx_complete_value(w,copy.value); break; }
case 549: { nx_Page_SettingsProfile model=nx_Page_SettingsProfile_read(args); (void)model; nx_Page_SettingsProfile copy=nx_Page_SettingsProfile_write(&constructed, nx_Page_SettingsProfile_Items(model), nx_Page_SettingsProfile_NextCursor(model), nx_Page_SettingsProfile_Revision(model)); nx_complete_value(w,copy.value); break; }
case 550: { nx_Page_StorageEntry model=nx_Page_StorageEntry_read(args); (void)model; nx_Page_StorageEntry copy=nx_Page_StorageEntry_write(&constructed, nx_Page_StorageEntry_Items(model), nx_Page_StorageEntry_NextCursor(model), nx_Page_StorageEntry_Revision(model)); nx_complete_value(w,copy.value); break; }
case 551: { nx_Page_ThemeResource model=nx_Page_ThemeResource_read(args); (void)model; nx_Page_ThemeResource copy=nx_Page_ThemeResource_write(&constructed, nx_Page_ThemeResource_Items(model), nx_Page_ThemeResource_NextCursor(model), nx_Page_ThemeResource_Revision(model)); nx_complete_value(w,copy.value); break; }
case 552: { nx_Page_ThemeSummary model=nx_Page_ThemeSummary_read(args); (void)model; nx_Page_ThemeSummary copy=nx_Page_ThemeSummary_write(&constructed, nx_Page_ThemeSummary_Items(model), nx_Page_ThemeSummary_NextCursor(model), nx_Page_ThemeSummary_Revision(model)); nx_complete_value(w,copy.value); break; }
case 553: { nx_Page_UIViewContract model=nx_Page_UIViewContract_read(args); (void)model; nx_Page_UIViewContract copy=nx_Page_UIViewContract_write(&constructed, nx_Page_UIViewContract_Items(model), nx_Page_UIViewContract_NextCursor(model), nx_Page_UIViewContract_Revision(model)); nx_complete_value(w,copy.value); break; }
case 554: { nx_Page_WorldSummary model=nx_Page_WorldSummary_read(args); (void)model; nx_Page_WorldSummary copy=nx_Page_WorldSummary_write(&constructed, nx_Page_WorldSummary_Items(model), nx_Page_WorldSummary_NextCursor(model), nx_Page_WorldSummary_Revision(model)); nx_complete_value(w,copy.value); break; }
case 555: { nx_PageRequest model=nx_PageRequest_read(args); (void)model; nx_PageRequest copy=nx_PageRequest_write(&constructed, nx_PageRequest_Cursor(model), nx_PageRequest_Limit(model)); nx_complete_value(w,copy.value); break; }
case 556: { nx_PlanRequest model=nx_PlanRequest_read(args); (void)model; nx_PlanRequest copy=nx_PlanRequest_write(&constructed, nx_PlanRequest_Plan(model), nx_PlanRequest_ExpectedRevision(model), nx_PlanRequest_ConfirmationToken(model)); nx_complete_value(w,copy.value); break; }
case 557: { nx_PlatformDescription model=nx_PlatformDescription_read(args); (void)model; nx_PlatformDescription copy=nx_PlatformDescription_write(&constructed, nx_PlatformDescription_Capabilities(model)); nx_complete_value(w,copy.value); break; }
case 558: { nx_PowerState model=nx_PowerState_read(args); (void)model; nx_PowerState copy=nx_PowerState_write(&constructed, nx_PowerState_OnBattery(model), nx_PowerState_ChargePercent(model), nx_PowerState_Saving(model)); nx_complete_value(w,copy.value); break; }
case 559: { nx_PredicateDefinition model=nx_PredicateDefinition_read(args); (void)model; nx_PredicateDefinition copy=nx_PredicateDefinition_write(&constructed, nx_PredicateDefinition_Id(model), nx_PredicateDefinition_Input(model), nx_PredicateDefinition_Handler(model), nx_PredicateDefinition_Expression(model)); nx_complete_value(w,copy.value); break; }
case 560: { nx_PredicateRequest model=nx_PredicateRequest_read(args); (void)model; nx_PredicateRequest copy=nx_PredicateRequest_write(&constructed, nx_PredicateRequest_Id(model), nx_PredicateRequest_Inputs(model), nx_PredicateRequest_Consistency(model)); nx_complete_value(w,copy.value); break; }
case 561: { nx_PredicateResult model=nx_PredicateResult_read(args); (void)model; nx_PredicateResult copy=nx_PredicateResult_write(&constructed, nx_PredicateResult_Outcome(model), nx_PredicateResult_InputRevision(model), nx_PredicateResult_Issues(model)); nx_complete_value(w,copy.value); break; }
case 562: { nx_ProviderDescriptor model=nx_ProviderDescriptor_read(args); (void)model; nx_ProviderDescriptor copy=nx_ProviderDescriptor_write(&constructed, nx_ProviderDescriptor_Id(model), nx_ProviderDescriptor_Kind(model), nx_ProviderDescriptor_ContractVersion(model), nx_ProviderDescriptor_SchemaHash(model), nx_ProviderDescriptor_DisplayName(model), nx_ProviderDescriptor_Capabilities(model), nx_ProviderDescriptor_SupportedScopes(model), nx_ProviderDescriptor_Selection(model), nx_ProviderDescriptor_Concurrency(model), nx_ProviderDescriptor_DeadlineMilliseconds(model), nx_ProviderDescriptor_FailurePolicy(model), nx_ProviderDescriptor_Configuration(model), nx_ProviderDescriptor_Handler(model)); nx_complete_value(w,copy.value); break; }
case 563: { nx_ProviderKindDefinition model=nx_ProviderKindDefinition_read(args); (void)model; nx_ProviderKindDefinition copy=nx_ProviderKindDefinition_write(&constructed, nx_ProviderKindDefinition_Id(model), nx_ProviderKindDefinition_Contract(model), nx_ProviderKindDefinition_Selection(model)); nx_complete_value(w,copy.value); break; }
case 564: { nx_PublicContract model=nx_PublicContract_read(args); (void)model; nx_PublicContract copy=nx_PublicContract_write(&constructed, nx_PublicContract_Id(model), nx_PublicContract_Version(model), nx_PublicContract_Schema(model), nx_PublicContract_Methods(model)); nx_complete_value(w,copy.value); break; }
case 565: { nx_QualifiedRequest model=nx_QualifiedRequest_read(args); (void)model; nx_QualifiedRequest copy=nx_QualifiedRequest_write(&constructed, nx_QualifiedRequest_Id(model)); nx_complete_value(w,copy.value); break; }
case 566: { nx_RecoveryRecord model=nx_RecoveryRecord_read(args); (void)model; nx_RecoveryRecord copy=nx_RecoveryRecord_write(&constructed, nx_RecoveryRecord_Id(model), nx_RecoveryRecord_Operation(model), nx_RecoveryRecord_Summary(model), nx_RecoveryRecord_Revision(model)); nx_complete_value(w,copy.value); break; }
case 567: { nx_Reference model=nx_Reference_read(args); (void)model; nx_Reference copy=nx_Reference_write(&constructed, nx_Reference_Id(model), nx_Reference_Required(model)); nx_complete_value(w,copy.value); break; }
case 568: { nx_RegistrationRef model=nx_RegistrationRef_read(args); (void)model; nx_RegistrationRef copy=nx_RegistrationRef_write(&constructed, nx_RegistrationRef_Handle(model), nx_RegistrationRef_Owner(model), nx_RegistrationRef_LoadInstanceId(model), nx_RegistrationRef_DefinitionId(model), nx_RegistrationRef_State(model)); nx_complete_value(w,copy.value); break; }
case 569: { nx_RegistrationRequest model=nx_RegistrationRequest_read(args); (void)model; nx_RegistrationRequest copy=nx_RegistrationRequest_write(&constructed, nx_RegistrationRequest_Registration(model)); nx_complete_value(w,copy.value); break; }
case 570: { nx_RegistryDescriptor model=nx_RegistryDescriptor_read(args); (void)model; nx_RegistryDescriptor copy=nx_RegistryDescriptor_write(&constructed, nx_RegistryDescriptor_Id(model), nx_RegistryDescriptor_Schema(model), nx_RegistryDescriptor_EntryIdentity(model), nx_RegistryDescriptor_ReferenceTypes(model), nx_RegistryDescriptor_MergePolicy(model), nx_RegistryDescriptor_OrderingPolicy(model), nx_RegistryDescriptor_Activation(model), nx_RegistryDescriptor_Ownership(model), nx_RegistryDescriptor_SupportedOperations(model), nx_RegistryDescriptor_ValidationRules(model), nx_RegistryDescriptor_Consumer(model), nx_RegistryDescriptor_Deletion(model), nx_RegistryDescriptor_MergeContract(model)); nx_complete_value(w,copy.value); break; }
case 571: { nx_RepairRequest model=nx_RepairRequest_read(args); (void)model; nx_RepairRequest copy=nx_RepairRequest_write(&constructed, nx_RepairRequest_Instance(model), nx_RepairRequest_Findings(model), nx_RepairRequest_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 572: { nx_ResolutionReport model=nx_ResolutionReport_read(args); (void)model; nx_ResolutionReport copy=nx_ResolutionReport_write(&constructed, nx_ResolutionReport_Target(model), nx_ResolutionReport_Active(model), nx_ResolutionReport_Contributions(model), nx_ResolutionReport_Issues(model), nx_ResolutionReport_Revision(model)); nx_complete_value(w,copy.value); break; }
case 573: { nx_ResourceCollection model=nx_ResourceCollection_read(args); (void)model; nx_ResourceCollection copy=nx_ResourceCollection_write(&constructed, nx_ResourceCollection_Id(model), nx_ResourceCollection_Resources(model), nx_ResourceCollection_Tags(model)); nx_complete_value(w,copy.value); break; }
case 574: { nx_ResourceRef model=nx_ResourceRef_read(args); (void)model; nx_ResourceRef copy=nx_ResourceRef_write(&constructed, nx_ResourceRef_Provider(model), nx_ResourceRef_ProjectId(model)); nx_complete_value(w,copy.value); break; }
case 575: { nx_ResourceVersionRef model=nx_ResourceVersionRef_read(args); (void)model; nx_ResourceVersionRef copy=nx_ResourceVersionRef_write(&constructed, nx_ResourceVersionRef_Resource(model), nx_ResourceVersionRef_VersionId(model)); nx_complete_value(w,copy.value); break; }
case 576: { nx_RetentionPolicy model=nx_RetentionPolicy_read(args); (void)model; nx_RetentionPolicy copy=nx_RetentionPolicy_write(&constructed, nx_RetentionPolicy_KeepCount(model), nx_RetentionPolicy_KeepDays(model), nx_RetentionPolicy_MaximumBytes(model)); nx_complete_value(w,copy.value); break; }
case 577: { nx_RootRef model=nx_RootRef_read(args); (void)model; nx_RootRef copy=nx_RootRef_write(&constructed, nx_RootRef_Token(model), nx_RootRef_LoadInstanceId(model)); nx_complete_value(w,copy.value); break; }
case 578: { nx_RootRegistration model=nx_RootRegistration_read(args); (void)model; nx_RootRegistration copy=nx_RootRegistration_write(&constructed, nx_RootRegistration_Root(model), nx_RootRegistration_DisplayName(model)); nx_complete_value(w,copy.value); break; }
case 579: { nx_RootRequest model=nx_RootRequest_read(args); (void)model; nx_RootRequest copy=nx_RootRequest_write(&constructed, nx_RootRequest_Root(model)); nx_complete_value(w,copy.value); break; }
case 580: { nx_ScheduleDefinition model=nx_ScheduleDefinition_read(args); (void)model; nx_ScheduleDefinition copy=nx_ScheduleDefinition_write(&constructed, nx_ScheduleDefinition_Id(model), nx_ScheduleDefinition_Workflow(model), nx_ScheduleDefinition_Trigger(model), nx_ScheduleDefinition_TimeZone(model), nx_ScheduleDefinition_At(model), nx_ScheduleDefinition_IntervalMilliseconds(model), nx_ScheduleDefinition_Event(model), nx_ScheduleDefinition_Missed(model), nx_ScheduleDefinition_ReplayLimit(model), nx_ScheduleDefinition_DebounceMilliseconds(model)); nx_complete_value(w,copy.value); break; }
case 581: { nx_ScheduleState model=nx_ScheduleState_read(args); (void)model; nx_ScheduleState copy=nx_ScheduleState_write(&constructed, nx_ScheduleState_Id(model), nx_ScheduleState_Enabled(model), nx_ScheduleState_NextRun(model), nx_ScheduleState_Revision(model)); nx_complete_value(w,copy.value); break; }
case 582: { nx_SchemaRef model=nx_SchemaRef_read(args); (void)model; nx_SchemaRef copy=nx_SchemaRef_write(&constructed, nx_SchemaRef_Id(model), nx_SchemaRef_Version(model), nx_SchemaRef_Digest(model)); nx_complete_value(w,copy.value); break; }
case 583: { nx_SchemaValidationRequest model=nx_SchemaValidationRequest_read(args); (void)model; nx_SchemaValidationRequest copy=nx_SchemaValidationRequest_write(&constructed, nx_SchemaValidationRequest_Schema(model), nx_SchemaValidationRequest_Value(model)); nx_complete_value(w,copy.value); break; }
case 584: { nx_ScopedTarget model=nx_ScopedTarget_read(args); (void)model; nx_ScopedTarget copy=nx_ScopedTarget_write(&constructed, nx_ScopedTarget_Kind(model), nx_ScopedTarget_Entity(model), nx_ScopedTarget_Scope(model)); nx_complete_value(w,copy.value); break; }
case 585: { nx_ServerJoinRequest model=nx_ServerJoinRequest_read(args); (void)model; nx_ServerJoinRequest copy=nx_ServerJoinRequest_write(&constructed, nx_ServerJoinRequest_Server(model), nx_ServerJoinRequest_Intent(model)); nx_complete_value(w,copy.value); break; }
case 586: { nx_ServerList model=nx_ServerList_read(args); (void)model; nx_ServerList copy=nx_ServerList_write(&constructed, nx_ServerList_Servers(model), nx_ServerList_Revision(model)); nx_complete_value(w,copy.value); break; }
case 587: { nx_ServerRecord model=nx_ServerRecord_read(args); (void)model; nx_ServerRecord copy=nx_ServerRecord_write(&constructed, nx_ServerRecord_Id(model), nx_ServerRecord_Name(model), nx_ServerRecord_Address(model), nx_ServerRecord_Port(model)); nx_complete_value(w,copy.value); break; }
case 588: { nx_ServerStatus model=nx_ServerStatus_read(args); (void)model; nx_ServerStatus copy=nx_ServerStatus_write(&constructed, nx_ServerStatus_Server(model), nx_ServerStatus_Reachable(model), nx_ServerStatus_Description(model), nx_ServerStatus_PlayersOnline(model), nx_ServerStatus_PlayersMaximum(model), nx_ServerStatus_Protocol(model)); nx_complete_value(w,copy.value); break; }
case 589: { nx_ServiceBinding model=nx_ServiceBinding_read(args); (void)model; nx_ServiceBinding copy=nx_ServiceBinding_write(&constructed, nx_ServiceBinding_Handle(model), nx_ServiceBinding_Provider(model), nx_ServiceBinding_ProviderLoadInstance(model), nx_ServiceBinding_Contract(model), nx_ServiceBinding_Version(model)); nx_complete_value(w,copy.value); break; }
case 590: { nx_ServiceCall model=nx_ServiceCall_read(args); (void)model; nx_ServiceCall copy=nx_ServiceCall_write(&constructed, nx_ServiceCall_Binding(model), nx_ServiceCall_Method(model), nx_ServiceCall_Input(model), nx_ServiceCall_CallChain(model), nx_ServiceCall_Delegation(model)); nx_complete_value(w,copy.value); break; }
case 591: { nx_ServiceDefinition model=nx_ServiceDefinition_read(args); (void)model; nx_ServiceDefinition copy=nx_ServiceDefinition_write(&constructed, nx_ServiceDefinition_Id(model), nx_ServiceDefinition_Contract(model), nx_ServiceDefinition_Handler(model), nx_ServiceDefinition_Probe(model)); nx_complete_value(w,copy.value); break; }
case 592: { nx_ServiceLookup model=nx_ServiceLookup_read(args); (void)model; nx_ServiceLookup copy=nx_ServiceLookup_write(&constructed, nx_ServiceLookup_Provider(model), nx_ServiceLookup_Service(model), nx_ServiceLookup_MinimumVersion(model), nx_ServiceLookup_MaximumVersion(model), nx_ServiceLookup_Required(model)); nx_complete_value(w,copy.value); break; }
case 593: { nx_ServiceMethod model=nx_ServiceMethod_read(args); (void)model; nx_ServiceMethod copy=nx_ServiceMethod_write(&constructed, nx_ServiceMethod_Id(model), nx_ServiceMethod_Name(model), nx_ServiceMethod_Input(model), nx_ServiceMethod_Output(model), nx_ServiceMethod_Cancellable(model), nx_ServiceMethod_Idempotency(model), nx_ServiceMethod_NativeExecution(model)); nx_complete_value(w,copy.value); break; }
case 594: { nx_ServiceProbe model=nx_ServiceProbe_read(args); (void)model; nx_ServiceProbe copy=nx_ServiceProbe_write(&constructed, nx_ServiceProbe_Binding(model), nx_ServiceProbe_Probe(model), nx_ServiceProbe_Input(model)); nx_complete_value(w,copy.value); break; }
case 595: { nx_SessionMetrics model=nx_SessionMetrics_read(args); (void)model; nx_SessionMetrics copy=nx_SessionMetrics_write(&constructed, nx_SessionMetrics_Session(model), nx_SessionMetrics_WorkingSetBytes(model), nx_SessionMetrics_CpuPercent(model), nx_SessionMetrics_ObservedAt(model)); nx_complete_value(w,copy.value); break; }
case 596: { nx_SettingChange model=nx_SettingChange_read(args); (void)model; nx_SettingChange copy=nx_SettingChange_write(&constructed, nx_SettingChange_Id(model), nx_SettingChange_Target(model), nx_SettingChange_Value(model), nx_SettingChange_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 597: { nx_SettingMigration model=nx_SettingMigration_read(args); (void)model; nx_SettingMigration copy=nx_SettingMigration_write(&constructed, nx_SettingMigration_Id(model), nx_SettingMigration_Target(model), nx_SettingMigration_FromVersion(model), nx_SettingMigration_ToVersion(model), nx_SettingMigration_Handler(model)); nx_complete_value(w,copy.value); break; }
case 598: { nx_SettingQuery model=nx_SettingQuery_read(args); (void)model; nx_SettingQuery copy=nx_SettingQuery_write(&constructed, nx_SettingQuery_Id(model), nx_SettingQuery_Target(model)); nx_complete_value(w,copy.value); break; }
case 599: { nx_SettingSchema model=nx_SettingSchema_read(args); (void)model; nx_SettingSchema copy=nx_SettingSchema_write(&constructed, nx_SettingSchema_Id(model), nx_SettingSchema_ValueSchema(model), nx_SettingSchema_Default(model), nx_SettingSchema_Scopes(model)); nx_complete_value(w,copy.value); break; }
case 600: { nx_SettingsOverlay model=nx_SettingsOverlay_read(args); (void)model; nx_SettingsOverlay copy=nx_SettingsOverlay_write(&constructed, nx_SettingsOverlay_Target(model), nx_SettingsOverlay_Values(model)); nx_complete_value(w,copy.value); break; }
case 601: { nx_SettingsProfile model=nx_SettingsProfile_read(args); (void)model; nx_SettingsProfile copy=nx_SettingsProfile_write(&constructed, nx_SettingsProfile_Id(model), nx_SettingsProfile_Name(model), nx_SettingsProfile_Values(model), nx_SettingsProfile_Revision(model)); nx_complete_value(w,copy.value); break; }
case 602: { nx_SignInChallenge model=nx_SignInChallenge_read(args); (void)model; nx_SignInChallenge copy=nx_SignInChallenge_write(&constructed, nx_SignInChallenge_Flow(model), nx_SignInChallenge_State(model), nx_SignInChallenge_Prompt(model), nx_SignInChallenge_VerificationUri(model), nx_SignInChallenge_UserCode(model)); nx_complete_value(w,copy.value); break; }
case 603: { nx_SignInContinue model=nx_SignInContinue_read(args); (void)model; nx_SignInContinue copy=nx_SignInContinue_write(&constructed, nx_SignInContinue_Flow(model), nx_SignInContinue_Response(model), nx_SignInContinue_Schema(model)); nx_complete_value(w,copy.value); break; }
case 604: { nx_SignInRequest model=nx_SignInRequest_read(args); (void)model; nx_SignInRequest copy=nx_SignInRequest_write(&constructed, nx_SignInRequest_Provider(model), nx_SignInRequest_Scope(model)); nx_complete_value(w,copy.value); break; }
case 605: { nx_SkinRequest model=nx_SkinRequest_read(args); (void)model; nx_SkinRequest copy=nx_SkinRequest_write(&constructed, nx_SkinRequest_Account(model), nx_SkinRequest_Image(model), nx_SkinRequest_Model(model)); nx_complete_value(w,copy.value); break; }
case 606: { nx_Snapshot_Definition model=nx_Snapshot_Definition_read(args); (void)model; nx_Snapshot_Definition copy=nx_Snapshot_Definition_write(&constructed, nx_Snapshot_Definition_Value(model), nx_Snapshot_Definition_Revision(model), nx_Snapshot_Definition_SchemaVersion(model), nx_Snapshot_Definition_ObservedAt(model)); nx_complete_value(w,copy.value); break; }
case 607: { nx_SpanRef model=nx_SpanRef_read(args); (void)model; nx_SpanRef copy=nx_SpanRef_write(&constructed, nx_SpanRef_Id(model)); nx_complete_value(w,copy.value); break; }
case 608: { nx_StateDescriptor model=nx_StateDescriptor_read(args); (void)model; nx_StateDescriptor copy=nx_StateDescriptor_write(&constructed, nx_StateDescriptor_Id(model), nx_StateDescriptor_Schema(model), nx_StateDescriptor_Scope(model)); nx_complete_value(w,copy.value); break; }
case 609: { nx_StateReadRequest model=nx_StateReadRequest_read(args); (void)model; nx_StateReadRequest copy=nx_StateReadRequest_write(&constructed, nx_StateReadRequest_Id(model), nx_StateReadRequest_Scope(model)); nx_complete_value(w,copy.value); break; }
case 610: { nx_StateSnapshot model=nx_StateSnapshot_read(args); (void)model; nx_StateSnapshot copy=nx_StateSnapshot_write(&constructed, nx_StateSnapshot_Value(model), nx_StateSnapshot_Schema(model), nx_StateSnapshot_Revision(model), nx_StateSnapshot_ObservedAt(model), nx_StateSnapshot_Cursor(model)); nx_complete_value(w,copy.value); break; }
case 611: { nx_StateUpdate model=nx_StateUpdate_read(args); (void)model; nx_StateUpdate copy=nx_StateUpdate_write(&constructed, nx_StateUpdate_Id(model), nx_StateUpdate_Scope(model), nx_StateUpdate_Value(model), nx_StateUpdate_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 612: { nx_StorageCommit model=nx_StorageCommit_read(args); (void)model; nx_StorageCommit copy=nx_StorageCommit_write(&constructed, nx_StorageCommit_Transaction(model), nx_StorageCommit_Writes(model)); nx_complete_value(w,copy.value); break; }
case 613: { nx_StorageEntry model=nx_StorageEntry_read(args); (void)model; nx_StorageEntry copy=nx_StorageEntry_write(&constructed, nx_StorageEntry_Key(model), nx_StorageEntry_Value(model)); nx_complete_value(w,copy.value); break; }
case 614: { nx_StorageKey model=nx_StorageKey_read(args); (void)model; nx_StorageKey copy=nx_StorageKey_write(&constructed, nx_StorageKey_Namespace(model), nx_StorageKey_Key(model)); nx_complete_value(w,copy.value); break; }
case 615: { nx_StorageMigration model=nx_StorageMigration_read(args); (void)model; nx_StorageMigration copy=nx_StorageMigration_write(&constructed, nx_StorageMigration_Namespace(model), nx_StorageMigration_FromVersion(model), nx_StorageMigration_ToVersion(model), nx_StorageMigration_Action(model)); nx_complete_value(w,copy.value); break; }
case 616: { nx_StorageMigrationInput model=nx_StorageMigrationInput_read(args); (void)model; nx_StorageMigrationInput copy=nx_StorageMigrationInput_write(&constructed, nx_StorageMigrationInput_Namespace(model), nx_StorageMigrationInput_FromVersion(model), nx_StorageMigrationInput_ToVersion(model), nx_StorageMigrationInput_Entries(model)); nx_complete_value(w,copy.value); break; }
case 617: { nx_StorageMigrationOutput model=nx_StorageMigrationOutput_read(args); (void)model; nx_StorageMigrationOutput copy=nx_StorageMigrationOutput_write(&constructed, nx_StorageMigrationOutput_Entries(model)); nx_complete_value(w,copy.value); break; }
case 618: { nx_StorageNamespace model=nx_StorageNamespace_read(args); (void)model; nx_StorageNamespace copy=nx_StorageNamespace_write(&constructed, nx_StorageNamespace_Token(model), nx_StorageNamespace_LoadInstanceId(model), nx_StorageNamespace_Namespace(model), nx_StorageNamespace_Revision(model)); nx_complete_value(w,copy.value); break; }
case 619: { nx_StorageQuery model=nx_StorageQuery_read(args); (void)model; nx_StorageQuery copy=nx_StorageQuery_write(&constructed, nx_StorageQuery_Namespace(model), nx_StorageQuery_Prefix(model), nx_StorageQuery_Page(model)); nx_complete_value(w,copy.value); break; }
case 620: { nx_StorageTransaction model=nx_StorageTransaction_read(args); (void)model; nx_StorageTransaction copy=nx_StorageTransaction_write(&constructed, nx_StorageTransaction_Token(model), nx_StorageTransaction_Namespace(model), nx_StorageTransaction_Revision(model)); nx_complete_value(w,copy.value); break; }
case 621: { nx_StorageValue model=nx_StorageValue_read(args); (void)model; nx_StorageValue copy=nx_StorageValue_write(&constructed, nx_StorageValue_Value(model), nx_StorageValue_Schema(model), nx_StorageValue_Revision(model)); nx_complete_value(w,copy.value); break; }
case 622: { nx_StorageWrite model=nx_StorageWrite_read(args); (void)model; nx_StorageWrite copy=nx_StorageWrite_write(&constructed, nx_StorageWrite_Namespace(model), nx_StorageWrite_Key(model), nx_StorageWrite_Value(model), nx_StorageWrite_Schema(model), nx_StorageWrite_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 623: { nx_SubscriptionBatch model=nx_SubscriptionBatch_read(args); (void)model; nx_SubscriptionBatch copy=nx_SubscriptionBatch_write(&constructed, nx_SubscriptionBatch_Items(model), nx_SubscriptionBatch_ResyncRequired(model)); nx_complete_value(w,copy.value); break; }
case 624: { nx_SubscriptionRead model=nx_SubscriptionRead_read(args); (void)model; nx_SubscriptionRead copy=nx_SubscriptionRead_write(&constructed, nx_SubscriptionRead_Subscription(model), nx_SubscriptionRead_Limit(model)); nx_complete_value(w,copy.value); break; }
case 625: { nx_SubscriptionRef model=nx_SubscriptionRef_read(args); (void)model; nx_SubscriptionRef copy=nx_SubscriptionRef_write(&constructed, nx_SubscriptionRef_Token(model), nx_SubscriptionRef_LoadInstanceId(model), nx_SubscriptionRef_Cursor(model), nx_SubscriptionRef_ResyncRequired(model)); nx_complete_value(w,copy.value); break; }
case 626: { nx_TagDefinition model=nx_TagDefinition_read(args); (void)model; nx_TagDefinition copy=nx_TagDefinition_write(&constructed, nx_TagDefinition_Id(model), nx_TagDefinition_Registry(model), nx_TagDefinition_Add(model), nx_TagDefinition_Remove(model), nx_TagDefinition_Include(model)); nx_complete_value(w,copy.value); break; }
case 627: { nx_TagResolution model=nx_TagResolution_read(args); (void)model; nx_TagResolution copy=nx_TagResolution_write(&constructed, nx_TagResolution_Members(model), nx_TagResolution_Revision(model)); nx_complete_value(w,copy.value); break; }
case 628: { nx_TaskCompletion model=nx_TaskCompletion_read(args); (void)model; nx_TaskCompletion copy=nx_TaskCompletion_write(&constructed, nx_TaskCompletion_Task(model), nx_TaskCompletion_Result(model), nx_TaskCompletion_Schema(model), nx_TaskCompletion_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 629: { nx_TaskCreate model=nx_TaskCreate_read(args); (void)model; nx_TaskCreate copy=nx_TaskCreate_write(&constructed, nx_TaskCreate_Id(model), nx_TaskCreate_Title(model), nx_TaskCreate_Operation(model), nx_TaskCreate_Cancellable(model)); nx_complete_value(w,copy.value); break; }
case 630: { nx_TaskFailure model=nx_TaskFailure_read(args); (void)model; nx_TaskFailure copy=nx_TaskFailure_write(&constructed, nx_TaskFailure_Task(model), nx_TaskFailure_Error(model), nx_TaskFailure_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 631: { nx_TaskProgress model=nx_TaskProgress_read(args); (void)model; nx_TaskProgress copy=nx_TaskProgress_write(&constructed, nx_TaskProgress_Task(model), nx_TaskProgress_Stage(model), nx_TaskProgress_Progress(model), nx_TaskProgress_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 632: { nx_TextResult model=nx_TextResult_read(args); (void)model; nx_TextResult copy=nx_TextResult_write(&constructed, nx_TextResult_Text(model)); nx_complete_value(w,copy.value); break; }
case 633: { nx_ThemeOptionChange model=nx_ThemeOptionChange_read(args); (void)model; nx_ThemeOptionChange copy=nx_ThemeOptionChange_write(&constructed, nx_ThemeOptionChange_Options(model), nx_ThemeOptionChange_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 634: { nx_ThemeOptions model=nx_ThemeOptions_read(args); (void)model; nx_ThemeOptions copy=nx_ThemeOptions_write(&constructed, nx_ThemeOptions_Theme(model), nx_ThemeOptions_Values(model), nx_ThemeOptions_Revision(model)); nx_complete_value(w,copy.value); break; }
case 635: { nx_ThemePreparation model=nx_ThemePreparation_read(args); (void)model; nx_ThemePreparation copy=nx_ThemePreparation_write(&constructed, nx_ThemePreparation_Theme(model), nx_ThemePreparation_Plan(model), nx_ThemePreparation_Issues(model)); nx_complete_value(w,copy.value); break; }
case 636: { nx_ThemeResource model=nx_ThemeResource_read(args); (void)model; nx_ThemeResource copy=nx_ThemeResource_write(&constructed, nx_ThemeResource_Theme(model), nx_ThemeResource_Name(model), nx_ThemeResource_Data(model)); nx_complete_value(w,copy.value); break; }
case 637: { nx_ThemeSummary model=nx_ThemeSummary_read(args); (void)model; nx_ThemeSummary copy=nx_ThemeSummary_write(&constructed, nx_ThemeSummary_Id(model), nx_ThemeSummary_Name(model), nx_ThemeSummary_Version(model), nx_ThemeSummary_Active(model)); nx_complete_value(w,copy.value); break; }
case 638: { nx_ThemeTransfer model=nx_ThemeTransfer_read(args); (void)model; nx_ThemeTransfer copy=nx_ThemeTransfer_write(&constructed, nx_ThemeTransfer_Theme(model), nx_ThemeTransfer_File(model)); nx_complete_value(w,copy.value); break; }
case 639: { nx_UICommand model=nx_UICommand_read(args); (void)model; nx_UICommand copy=nx_UICommand_write(&constructed, nx_UICommand_Id(model), nx_UICommand_Action(model), nx_UICommand_Title(model)); nx_complete_value(w,copy.value); break; }
case 640: { nx_UIComponent model=nx_UIComponent_read(args); (void)model; nx_UIComponent copy=nx_UIComponent_write(&constructed, nx_UIComponent_Id(model), nx_UIComponent_EntryFile(model), nx_UIComponent_Parameters(model)); nx_complete_value(w,copy.value); break; }
case 641: { nx_UIContribution model=nx_UIContribution_read(args); (void)model; nx_UIContribution copy=nx_UIContribution_write(&constructed, nx_UIContribution_Id(model), nx_UIContribution_View(model), nx_UIContribution_SemanticNode(model), nx_UIContribution_Mode(model), nx_UIContribution_Component(model), nx_UIContribution_Before(model), nx_UIContribution_After(model)); nx_complete_value(w,copy.value); break; }
case 642: { nx_UIDialog model=nx_UIDialog_read(args); (void)model; nx_UIDialog copy=nx_UIDialog_write(&constructed, nx_UIDialog_Id(model), nx_UIDialog_Page(model), nx_UIDialog_Model(model)); nx_complete_value(w,copy.value); break; }
case 643: { nx_UIDialogRef model=nx_UIDialogRef_read(args); (void)model; nx_UIDialogRef copy=nx_UIDialogRef_write(&constructed, nx_UIDialogRef_Id(model), nx_UIDialogRef_ViewScope(model)); nx_complete_value(w,copy.value); break; }
case 644: { nx_UIModelUpdate model=nx_UIModelUpdate_read(args); (void)model; nx_UIModelUpdate copy=nx_UIModelUpdate_write(&constructed, nx_UIModelUpdate_View(model), nx_UIModelUpdate_Schema(model), nx_UIModelUpdate_Value(model), nx_UIModelUpdate_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 645: { nx_UINavigateRequest model=nx_UINavigateRequest_read(args); (void)model; nx_UINavigateRequest copy=nx_UINavigateRequest_write(&constructed, nx_UINavigateRequest_Page(model), nx_UINavigateRequest_Arguments(model)); nx_complete_value(w,copy.value); break; }
case 646: { nx_UINavigation model=nx_UINavigation_read(args); (void)model; nx_UINavigation copy=nx_UINavigation_write(&constructed, nx_UINavigation_Id(model), nx_UINavigation_Page(model), nx_UINavigation_Title(model), nx_UINavigation_Icon(model)); nx_complete_value(w,copy.value); break; }
case 647: { nx_UINotification model=nx_UINotification_read(args); (void)model; nx_UINotification copy=nx_UINotification_write(&constructed, nx_UINotification_Title(model), nx_UINotification_Body(model), nx_UINotification_Action(model)); nx_complete_value(w,copy.value); break; }
case 648: { nx_UIPage model=nx_UIPage_read(args); (void)model; nx_UIPage copy=nx_UIPage_write(&constructed, nx_UIPage_Id(model), nx_UIPage_EntryFile(model), nx_UIPage_Schema(model), nx_UIPage_Localizations(model)); nx_complete_value(w,copy.value); break; }
case 649: { nx_UIShortcut model=nx_UIShortcut_read(args); (void)model; nx_UIShortcut copy=nx_UIShortcut_write(&constructed, nx_UIShortcut_Id(model), nx_UIShortcut_Command(model), nx_UIShortcut_Gesture(model), nx_UIShortcut_Scope(model)); nx_complete_value(w,copy.value); break; }
case 650: { nx_UIViewContract model=nx_UIViewContract_read(args); (void)model; nx_UIViewContract copy=nx_UIViewContract_write(&constructed, nx_UIViewContract_Id(model), nx_UIViewContract_Schema(model), nx_UIViewContract_Replaceable(model), nx_UIViewContract_RequiredState(model), nx_UIViewContract_RequiredCommands(model), nx_UIViewContract_PublicNodes(model), nx_UIViewContract_HostControl(model)); nx_complete_value(w,copy.value); break; }
case 651: { nx_UIViewReplacement model=nx_UIViewReplacement_read(args); (void)model; nx_UIViewReplacement copy=nx_UIViewReplacement_write(&constructed, nx_UIViewReplacement_Id(model), nx_UIViewReplacement_View(model), nx_UIViewReplacement_ViewContract(model), nx_UIViewReplacement_Page(model)); nx_complete_value(w,copy.value); break; }
case 652: { nx_UIViewWatch model=nx_UIViewWatch_read(args); (void)model; nx_UIViewWatch copy=nx_UIViewWatch_write(&constructed, nx_UIViewWatch_View(model), nx_UIViewWatch_ViewScope(model), nx_UIViewWatch_Cursor(model)); nx_complete_value(w,copy.value); break; }
case 653: { nx_ValidationIssue model=nx_ValidationIssue_read(args); (void)model; nx_ValidationIssue copy=nx_ValidationIssue_write(&constructed, nx_ValidationIssue_Code(model), nx_ValidationIssue_Message(model), nx_ValidationIssue_Target(model), nx_ValidationIssue_Fatal(model)); nx_complete_value(w,copy.value); break; }
case 654: { nx_ValidationReport model=nx_ValidationReport_read(args); (void)model; nx_ValidationReport copy=nx_ValidationReport_write(&constructed, nx_ValidationReport_Valid(model), nx_ValidationReport_Issues(model)); nx_complete_value(w,copy.value); break; }
case 655: { nx_Wardrobe model=nx_Wardrobe_read(args); (void)model; nx_Wardrobe copy=nx_Wardrobe_write(&constructed, nx_Wardrobe_Account(model), nx_Wardrobe_Skin(model), nx_Wardrobe_Capes(model), nx_Wardrobe_SupportsUpload(model)); nx_complete_value(w,copy.value); break; }
case 656: { nx_WatchRequest model=nx_WatchRequest_read(args); (void)model; nx_WatchRequest copy=nx_WatchRequest_write(&constructed, nx_WatchRequest_Target(model), nx_WatchRequest_Cursor(model), nx_WatchRequest_Schema(model)); nx_complete_value(w,copy.value); break; }
case 657: { nx_WorkflowDefinition model=nx_WorkflowDefinition_read(args); (void)model; nx_WorkflowDefinition copy=nx_WorkflowDefinition_write(&constructed, nx_WorkflowDefinition_Id(model), nx_WorkflowDefinition_Input(model), nx_WorkflowDefinition_Output(model), nx_WorkflowDefinition_Nodes(model), nx_WorkflowDefinition_DefinitionDigest(model), nx_WorkflowDefinition_Persistent(model), nx_WorkflowDefinition_Concurrency(model), nx_WorkflowDefinition_MaximumDepth(model), nx_WorkflowDefinition_MaximumWork(model)); nx_complete_value(w,copy.value); break; }
case 658: { nx_WorkflowNode model=nx_WorkflowNode_read(args); (void)model; nx_WorkflowNode copy=nx_WorkflowNode_write(&constructed, nx_WorkflowNode_Id(model), nx_WorkflowNode_Kind(model), nx_WorkflowNode_Target(model), nx_WorkflowNode_Inputs(model), nx_WorkflowNode_Children(model), nx_WorkflowNode_MaximumConcurrency(model), nx_WorkflowNode_MaximumAttempts(model), nx_WorkflowNode_BackoffMilliseconds(model), nx_WorkflowNode_Completion(model), nx_WorkflowNode_RetryableErrors(model), nx_WorkflowNode_InputSchema(model), nx_WorkflowNode_OutputSchema(model)); nx_complete_value(w,copy.value); break; }
case 659: { nx_WorkflowRequest model=nx_WorkflowRequest_read(args); (void)model; nx_WorkflowRequest copy=nx_WorkflowRequest_write(&constructed, nx_WorkflowRequest_Workflow(model), nx_WorkflowRequest_Inputs(model), nx_WorkflowRequest_DefinitionDigest(model)); nx_complete_value(w,copy.value); break; }
case 660: { nx_WorkflowRunRequest model=nx_WorkflowRunRequest_read(args); (void)model; nx_WorkflowRunRequest copy=nx_WorkflowRunRequest_write(&constructed, nx_WorkflowRunRequest_Run(model), nx_WorkflowRunRequest_ExpectedRevision(model), nx_WorkflowRunRequest_DefinitionDigest(model)); nx_complete_value(w,copy.value); break; }
case 661: { nx_WorkflowStep model=nx_WorkflowStep_read(args); (void)model; nx_WorkflowStep copy=nx_WorkflowStep_write(&constructed, nx_WorkflowStep_Id(model), nx_WorkflowStep_State(model), nx_WorkflowStep_SideEffects(model), nx_WorkflowStep_Failure(model)); nx_complete_value(w,copy.value); break; }
case 662: { nx_WorkflowStepRequest model=nx_WorkflowStepRequest_read(args); (void)model; nx_WorkflowStepRequest copy=nx_WorkflowStepRequest_write(&constructed, nx_WorkflowStepRequest_Run(model), nx_WorkflowStepRequest_StepId(model), nx_WorkflowStepRequest_ExpectedRevision(model), nx_WorkflowStepRequest_IdempotencyKey(model)); nx_complete_value(w,copy.value); break; }
case 663: { nx_WorkflowTrace model=nx_WorkflowTrace_read(args); (void)model; nx_WorkflowTrace copy=nx_WorkflowTrace_write(&constructed, nx_WorkflowTrace_Run(model), nx_WorkflowTrace_DefinitionDigest(model), nx_WorkflowTrace_Steps(model)); nx_complete_value(w,copy.value); break; }
case 664: { nx_WorldCopyRequest model=nx_WorldCopyRequest_read(args); (void)model; nx_WorldCopyRequest copy=nx_WorldCopyRequest_write(&constructed, nx_WorldCopyRequest_World(model), nx_WorldCopyRequest_Destination(model), nx_WorldCopyRequest_Name(model), nx_WorldCopyRequest_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 665: { nx_WorldMetadata model=nx_WorldMetadata_read(args); (void)model; nx_WorldMetadata copy=nx_WorldMetadata_write(&constructed, nx_WorldMetadata_World(model), nx_WorldMetadata_Format(model), nx_WorldMetadata_Fields(model)); nx_complete_value(w,copy.value); break; }
case 666: { nx_WorldRenameRequest model=nx_WorldRenameRequest_read(args); (void)model; nx_WorldRenameRequest copy=nx_WorldRenameRequest_write(&constructed, nx_WorldRenameRequest_World(model), nx_WorldRenameRequest_Name(model), nx_WorldRenameRequest_ExpectedRevision(model)); nx_complete_value(w,copy.value); break; }
case 667: { nx_WorldSummary model=nx_WorldSummary_read(args); (void)model; nx_WorldSummary copy=nx_WorldSummary_write(&constructed, nx_WorldSummary_Id(model), nx_WorldSummary_Instance(model), nx_WorldSummary_Name(model), nx_WorldSummary_Running(model), nx_WorldSummary_Revision(model)); nx_complete_value(w,copy.value); break; }
default: __builtin_trap(); } return nx_result(w); } nx_call_options options={"12345678-1234-1234-1234-123456789abc","conformance","revision",0,1000}; switch(operation) {
case 0: nx_Contracts_DefineService(w,nx_PublicContract_read(args),&options); break;
case 1: nx_Contracts_DefineProviderKind(w,nx_ProviderKindDefinition_read(args),&options); break;
case 2: nx_Contracts_DefineExtensionPoint(w,nx_ExtensionPointDefinition_read(args),&options); break;
case 3: nx_Contracts_Describe(w,nx_ContractQuery_read(args),&options); break;
case 4: nx_Contracts_List(w,nx_PageRequest_read(args),&options); break;
case 5: nx_Contracts_ValidateSchema(w,nx_SchemaValidationRequest_read(args),&options); break;
case 6: nx_Contracts_RegisterConsumer(w,nx_ConsumerDefinition_read(args),&options); break;
case 7: nx_Contracts_WatchAvailability(w,nx_QualifiedRequest_read(args),&options); break;
case 8: nx_Contracts_CheckCompatibility(w,nx_CompatibilityRequest_read(args),&options); break;
case 9: nx_Definitions_ListRegistries(w,nx_PageRequest_read(args),&options); break;
case 10: nx_Definitions_DescribeRegistry(w,nx_QualifiedRequest_read(args),&options); break;
case 11: nx_Definitions_DefineRegistry(w,nx_RegistryDescriptor_read(args),&options); break;
case 12: nx_Definitions_Register(w,nx_Definition_read(args),&options); break;
case 13: nx_Definitions_RegisterBatch(w,nx_DefinitionBatch_read(args),&options); break;
case 14: nx_Definitions_Get(w,nx_DefinitionQuery_read(args),&options); break;
case 15: nx_Definitions_Query(w,nx_DefinitionSearch_read(args),&options); break;
case 16: nx_Definitions_Watch(w,nx_QualifiedRequest_read(args),&options); break;
case 17: nx_Definitions_UpdateOwned(w,nx_DefinitionUpdate_read(args),&options); break;
case 18: nx_Definitions_RemoveOwned(w,nx_DefinitionRemove_read(args),&options); break;
case 19: nx_Definitions_RegisterTag(w,nx_TagDefinition_read(args),&options); break;
case 20: nx_Definitions_ResolveTag(w,nx_QualifiedRequest_read(args),&options); break;
case 21: nx_Definitions_PreviewOverlay(w,nx_OverlayDefinition_read(args),&options); break;
case 22: nx_Definitions_RegisterOverlay(w,nx_OverlayDefinition_read(args),&options); break;
case 23: nx_Definitions_ExplainResolution(w,nx_QualifiedRequest_read(args),&options); break;
case 24: nx_Predicates_Register(w,nx_PredicateDefinition_read(args),&options); break;
case 25: nx_Predicates_Evaluate(w,nx_PredicateRequest_read(args),&options); break;
case 26: nx_Predicates_Describe(w,nx_QualifiedRequest_read(args),&options); break;
case 27: nx_Actions_Register(w,nx_ActionDescriptor_read(args),&options); break;
case 28: nx_Actions_Describe(w,nx_QualifiedRequest_read(args),&options); break;
case 29: nx_Actions_Invoke(w,nx_ActionRequest_read(args),&options); break;
case 30: nx_Commands_List(w,nx_PageRequest_read(args),&options); break;
case 31: nx_Commands_Describe(w,nx_QualifiedRequest_read(args),&options); break;
case 32: nx_Commands_Execute(w,nx_ActionRequest_read(args),&options); break;
case 33: nx_Workflows_Register(w,nx_WorkflowDefinition_read(args),&options); break;
case 34: nx_Workflows_Validate(w,nx_WorkflowDefinition_read(args),&options); break;
case 35: nx_Workflows_Preview(w,nx_WorkflowRequest_read(args),&options); break;
case 36: nx_Workflows_Start(w,nx_WorkflowRequest_read(args),&options); break;
case 37: nx_Workflows_Read(w,nx_EntityRequest_read(args),&options); break;
case 38: nx_Workflows_Watch(w,nx_WatchRequest_read(args),&options); break;
case 39: nx_Workflows_Cancel(w,nx_OperationRequest_read(args),&options); break;
case 40: nx_Workflows_ListRuns(w,nx_PageRequest_read(args),&options); break;
case 41: nx_Workflows_Resume(w,nx_WorkflowRunRequest_read(args),&options); break;
case 42: nx_Workflows_RetryStep(w,nx_WorkflowStepRequest_read(args),&options); break;
case 43: nx_Workflows_ExplainPlan(w,nx_WorkflowRequest_read(args),&options); break;
case 44: nx_Workflows_ReadRunTrace(w,nx_EntityRequest_read(args),&options); break;
case 45: nx_Schedules_Register(w,nx_ScheduleDefinition_read(args),&options); break;
case 46: nx_Schedules_List(w,nx_PageRequest_read(args),&options); break;
case 47: nx_Schedules_Enable(w,nx_QualifiedRequest_read(args),&options); break;
case 48: nx_Schedules_Disable(w,nx_QualifiedRequest_read(args),&options); break;
case 49: nx_Schedules_TriggerNow(w,nx_QualifiedRequest_read(args),&options); break;
case 50: nx_Schedules_ReadNextRun(w,nx_QualifiedRequest_read(args),&options); break;
case 51: nx_Events_Describe(w,nx_QualifiedRequest_read(args),&options); break;
case 52: nx_Events_Subscribe(w,nx_EventSubscribeRequest_read(args),&options); break;
case 53: nx_Events_Define(w,nx_EventDescriptor_read(args),&options); break;
case 54: nx_Events_Publish(w,nx_EventEnvelope_read(args),&options); break;
case 55: nx_Events_Unsubscribe(w,nx_RegistrationRequest_read(args),&options); break;
case 56: nx_Events_UnsubscribeSubscription(w,nx_SubscriptionRef_read(args),&options); break;
case 57: nx_Events_RegisterSubscription(w,nx_EventSubscribeRequest_read(args),&options); break;
case 58: nx_State_Describe(w,nx_QualifiedRequest_read(args),&options); break;
case 59: nx_State_Read(w,nx_StateReadRequest_read(args),&options); break;
case 60: nx_State_Watch(w,nx_StateReadRequest_read(args),&options); break;
case 61: nx_State_DefineOwned(w,nx_StateDescriptor_read(args),&options); break;
case 62: nx_State_UpdateOwned(w,nx_StateUpdate_read(args),&options); break;
case 63: nx_State_CompareExchangeOwned(w,nx_StateUpdate_read(args),&options); break;
case 64: nx_UI_RegisterPage(w,nx_UIPage_read(args),&options); break;
case 65: nx_UI_RegisterComponent(w,nx_UIComponent_read(args),&options); break;
case 66: nx_UI_RegisterContribution(w,nx_UIContribution_read(args),&options); break;
case 67: nx_UI_RegisterViewReplacement(w,nx_UIViewReplacement_read(args),&options); break;
case 68: nx_UI_RegisterNavigation(w,nx_UINavigation_read(args),&options); break;
case 69: nx_UI_RegisterCommand(w,nx_UICommand_read(args),&options); break;
case 70: nx_UI_RegisterShortcut(w,nx_UIShortcut_read(args),&options); break;
case 71: nx_UI_ShowDialog(w,nx_UIDialog_read(args),&options); break;
case 72: nx_UI_CloseDialog(w,nx_EntityRequest_read(args),&options); break;
case 73: nx_UI_Navigate(w,nx_UINavigateRequest_read(args),&options); break;
case 74: nx_UI_Notify(w,nx_UINotification_read(args),&options); break;
case 75: nx_UI_PublishModel(w,nx_UIModelUpdate_read(args),&options); break;
case 76: nx_UI_UpdateModel(w,nx_UIModelUpdate_read(args),&options); break;
case 77: nx_UI_WatchViewLifecycle(w,nx_UIViewWatch_read(args),&options); break;
case 78: nx_UI_ListExtensionTargets(w,nx_PageRequest_read(args),&options); break;
case 79: nx_UI_DescribeViewContract(w,nx_QualifiedRequest_read(args),&options); break;
case 80: nx_UI_CreateDrawingSurface(w,nx_DrawingSurfaceRequest_read(args),&options); break;
case 81: nx_UI_SubmitDrawCommands(w,nx_DrawSubmission_read(args),&options); break;
case 82: nx_UI_SubscribeInput(w,nx_InputSubscription_read(args),&options); break;
case 83: nx_Plugins_ExportService(w,nx_ServiceDefinition_read(args),&options); break;
case 84: nx_Plugins_DescribeService(w,nx_ServiceLookup_read(args),&options); break;
case 85: nx_Plugins_BindService(w,nx_ServiceLookup_read(args),&options); break;
case 86: nx_Plugins_ProbeService(w,nx_ServiceProbe_read(args),&options); break;
case 87: nx_Plugins_CallService(w,nx_ServiceCall_read(args),&options); break;
case 88: nx_Plugins_WatchAvailability(w,nx_ServiceLookup_read(args),&options); break;
case 89: nx_Plugins_ReleaseBinding(w,nx_ServiceBinding_read(args),&options); break;
case 90: nx_Plugins_ReadOwnLoadReport(w,nx_Empty_read(args),&options); break;
case 91: nx_Diagnostics_Log(w,nx_DiagnosticReport_read(args),&options); break;
case 92: nx_Diagnostics_Report(w,nx_DiagnosticReport_read(args),&options); break;
case 93: nx_Diagnostics_CreateSpan(w,nx_DiagnosticSpan_read(args),&options); break;
case 94: nx_Diagnostics_ReadOwnReports(w,nx_PageRequest_read(args),&options); break;
case 95: nx_Resources_RegisterCleanup(w,nx_CleanupRequest_read(args),&options); break;
case 96: nx_Resources_Release(w,nx_RegistrationRequest_read(args),&options); break;
case 97: nx_Resources_ReadSubscription(w,nx_SubscriptionRead_read(args),&options); break;
case 98: nx_Resources_ReleaseSubscription(w,nx_SubscriptionRef_read(args),&options); break;
case 99: nx_Minecraft_Instances_List(w,nx_InstanceListRequest_read(args),&options); break;
case 100: nx_Minecraft_Instances_Read(w,nx_EntityRequest_read(args),&options); break;
case 101: nx_Minecraft_Instances_Watch(w,nx_WatchRequest_read(args),&options); break;
case 102: nx_Minecraft_Instances_Discover(w,nx_RootRequest_read(args),&options); break;
case 103: nx_Minecraft_Instances_ListRoots(w,nx_PageRequest_read(args),&options); break;
case 104: nx_Minecraft_Instances_AddRoot(w,nx_RootRegistration_read(args),&options); break;
case 105: nx_Minecraft_Instances_RemoveRoot(w,nx_RootRequest_read(args),&options); break;
case 106: nx_Minecraft_Instances_PrepareCreate(w,nx_InstanceCreateRequest_read(args),&options); break;
case 107: nx_Minecraft_Instances_CommitCreate(w,nx_PlanRequest_read(args),&options); break;
case 108: nx_Minecraft_Instances_Select(w,nx_EntityRequest_read(args),&options); break;
case 109: nx_Minecraft_Instances_Rename(w,nx_InstanceRenameRequest_read(args),&options); break;
case 110: nx_Minecraft_Instances_PrepareClone(w,nx_InstanceCloneRequest_read(args),&options); break;
case 111: nx_Minecraft_Instances_CommitClone(w,nx_PlanRequest_read(args),&options); break;
case 112: nx_Minecraft_Instances_PrepareDelete(w,nx_InstanceDeleteRequest_read(args),&options); break;
case 113: nx_Minecraft_Instances_CommitDelete(w,nx_PlanRequest_read(args),&options); break;
case 114: nx_Minecraft_Instances_ReadIdentity(w,nx_EntityRequest_read(args),&options); break;
case 115: nx_Minecraft_Instances_ReadEffectiveSettings(w,nx_EntityRequest_read(args),&options); break;
case 116: nx_Minecraft_Instances_OpenDirectory(w,nx_EntityRequest_read(args),&options); break;
case 117: nx_Minecraft_Install_ListGameVersions(w,nx_PageRequest_read(args),&options); break;
case 118: nx_Minecraft_Install_ListLoaderVersions(w,nx_LoaderVersionRequest_read(args),&options); break;
case 119: nx_Minecraft_Install_InspectLocalInstaller(w,nx_FileRef_read(args),&options); break;
case 120: nx_Minecraft_Install_ReadDraft(w,nx_EntityRequest_read(args),&options); break;
case 121: nx_Minecraft_Install_UpdateDraft(w,nx_InstallDraftUpdate_read(args),&options); break;
case 122: nx_Minecraft_Install_ValidateDraft(w,nx_InstallDraft_read(args),&options); break;
case 123: nx_Minecraft_Install_ResolvePlan(w,nx_InstallDraft_read(args),&options); break;
case 124: nx_Minecraft_Install_PreviewPlan(w,nx_EntityRequest_read(args),&options); break;
case 125: nx_Minecraft_Install_ExecutePlan(w,nx_PlanRequest_read(args),&options); break;
case 126: nx_Minecraft_Install_Cancel(w,nx_OperationRequest_read(args),&options); break;
case 127: nx_Minecraft_Install_ListRecoveries(w,nx_PageRequest_read(args),&options); break;
case 128: nx_Minecraft_Install_ResumeRecovery(w,nx_EntityRequest_read(args),&options); break;
case 129: nx_Minecraft_Install_DiscardRecovery(w,nx_EntityRequest_read(args),&options); break;
case 130: nx_Minecraft_Install_RegisterTemplate(w,nx_InstallTemplate_read(args),&options); break;
case 131: nx_Minecraft_Install_RegisterLoaderProvider(w,nx_ProviderDescriptor_read(args),&options); break;
case 132: nx_Minecraft_Java_List(w,nx_PageRequest_read(args),&options); break;
case 133: nx_Minecraft_Java_Discover(w,nx_RootRequest_read(args),&options); break;
case 134: nx_Minecraft_Java_Inspect(w,nx_FileRef_read(args),&options); break;
case 135: nx_Minecraft_Java_ReadRequirements(w,nx_EntityRequest_read(args),&options); break;
case 136: nx_Minecraft_Java_ResolveSelection(w,nx_JavaSelection_read(args),&options); break;
case 137: nx_Minecraft_Java_SelectGlobal(w,nx_JavaSelection_read(args),&options); break;
case 138: nx_Minecraft_Java_SelectForInstance(w,nx_JavaSelection_read(args),&options); break;
case 139: nx_Minecraft_Java_ListDistributions(w,nx_PageRequest_read(args),&options); break;
case 140: nx_Minecraft_Java_PrepareInstall(w,nx_JavaInstallRequest_read(args),&options); break;
case 141: nx_Minecraft_Java_Install(w,nx_PlanRequest_read(args),&options); break;
case 142: nx_Minecraft_Java_Remove(w,nx_EntityRequest_read(args),&options); break;
case 143: nx_Minecraft_Java_RegisterDistributionProvider(w,nx_ProviderDescriptor_read(args),&options); break;
case 144: nx_Minecraft_Java_ListManagedDistributions(w,nx_PageRequest_read(args),&options); break;
case 145: nx_Minecraft_Java_PrepareManagedInstall(w,nx_ManagedJavaInstallRequest_read(args),&options); break;
case 146: nx_Minecraft_Launch_ReadEffectiveProfile(w,nx_EntityRequest_read(args),&options); break;
case 147: nx_Minecraft_Launch_ListProfiles(w,nx_EntityRequest_read(args),&options); break;
case 148: nx_Minecraft_Launch_SaveProfile(w,nx_LaunchProfileWrite_read(args),&options); break;
case 149: nx_Minecraft_Launch_SelectProfile(w,nx_LaunchProfileSelection_read(args),&options); break;
case 150: nx_Minecraft_Launch_Prepare(w,nx_LaunchIntent_read(args),&options); break;
case 151: nx_Minecraft_Launch_ReadPlan(w,nx_EntityRequest_read(args),&options); break;
case 152: nx_Minecraft_Launch_ValidatePlan(w,nx_PlanRequest_read(args),&options); break;
case 153: nx_Minecraft_Launch_Start(w,nx_PlanRequest_read(args),&options); break;
case 154: nx_Minecraft_Launch_Cancel(w,nx_OperationRequest_read(args),&options); break;
case 155: nx_Minecraft_Launch_RegisterContribution(w,nx_LaunchContributionRegistration_read(args),&options); break;
case 156: nx_Minecraft_Launch_RegisterPreflight(w,nx_LaunchContributionRegistration_read(args),&options); break;
case 157: nx_Minecraft_Launch_ReadAttempt(w,nx_EntityRequest_read(args),&options); break;
case 158: nx_Minecraft_Launch_WatchAttempt(w,nx_WatchRequest_read(args),&options); break;
case 159: nx_Minecraft_Launch_ExplainContribution(w,nx_EntityRequest_read(args),&options); break;
case 160: nx_Minecraft_Processes_ListSessions(w,nx_PageRequest_read(args),&options); break;
case 161: nx_Minecraft_Processes_ReadSession(w,nx_EntityRequest_read(args),&options); break;
case 162: nx_Minecraft_Processes_WatchSession(w,nx_WatchRequest_read(args),&options); break;
case 163: nx_Minecraft_Processes_SubscribeLog(w,nx_LogRangeRequest_read(args),&options); break;
case 164: nx_Minecraft_Processes_ReadLogRange(w,nx_LogRangeRequest_read(args),&options); break;
case 165: nx_Minecraft_Processes_RequestClose(w,nx_EntityRequest_read(args),&options); break;
case 166: nx_Minecraft_Processes_Stop(w,nx_EntityRequest_read(args),&options); break;
case 167: nx_Minecraft_Processes_RevealWindow(w,nx_EntityRequest_read(args),&options); break;
case 168: nx_Minecraft_Processes_ReadMetrics(w,nx_EntityRequest_read(args),&options); break;
case 169: nx_Minecraft_Content_List(w,nx_ContentQuery_read(args),&options); break;
case 170: nx_Minecraft_Content_Inspect(w,nx_EntityRequest_read(args),&options); break;
case 171: nx_Minecraft_Content_Watch(w,nx_WatchRequest_read(args),&options); break;
case 172: nx_Minecraft_Content_ReadDependencyGraph(w,nx_EntityRequest_read(args),&options); break;
case 173: nx_Minecraft_Content_PlanInstall(w,nx_ContentChangeRequest_read(args),&options); break;
case 174: nx_Minecraft_Content_PlanEnable(w,nx_ContentChangeRequest_read(args),&options); break;
case 175: nx_Minecraft_Content_PlanDisable(w,nx_ContentChangeRequest_read(args),&options); break;
case 176: nx_Minecraft_Content_PlanRemove(w,nx_ContentChangeRequest_read(args),&options); break;
case 177: nx_Minecraft_Content_PlanUpdate(w,nx_ContentChangeRequest_read(args),&options); break;
case 178: nx_Minecraft_Content_Preview(w,nx_EntityRequest_read(args),&options); break;
case 179: nx_Minecraft_Content_Execute(w,nx_PlanRequest_read(args),&options); break;
case 180: nx_Minecraft_Content_ListTransactions(w,nx_EntityRequest_read(args),&options); break;
case 181: nx_Minecraft_Content_Rollback(w,nx_PlanRequest_read(args),&options); break;
case 182: nx_Minecraft_Content_ReadIntegrity(w,nx_EntityRequest_read(args),&options); break;
case 183: nx_Minecraft_Content_Verify(w,nx_EntityRequest_read(args),&options); break;
case 184: nx_Minecraft_Content_ListTrash(w,nx_EntityRequest_read(args),&options); break;
case 185: nx_Minecraft_Content_RestoreTrash(w,nx_ContentChangeRequest_read(args),&options); break;
case 186: nx_Minecraft_Content_ClearTrash(w,nx_PlanRequest_read(args),&options); break;
case 187: nx_Minecraft_Content_Import(w,nx_ContentTransfer_read(args),&options); break;
case 188: nx_Minecraft_Content_Export(w,nx_ContentTransfer_read(args),&options); break;
case 189: nx_Minecraft_Content_RegisterFormatProvider(w,nx_ProviderDescriptor_read(args),&options); break;
case 190: nx_Minecraft_Worlds_List(w,nx_EntityRequest_read(args),&options); break;
case 191: nx_Minecraft_Worlds_Read(w,nx_EntityRequest_read(args),&options); break;
case 192: nx_Minecraft_Worlds_ReadMetadata(w,nx_EntityRequest_read(args),&options); break;
case 193: nx_Minecraft_Worlds_Copy(w,nx_WorldCopyRequest_read(args),&options); break;
case 194: nx_Minecraft_Worlds_Rename(w,nx_WorldRenameRequest_read(args),&options); break;
case 195: nx_Minecraft_Worlds_PlanDelete(w,nx_EntityRequest_read(args),&options); break;
case 196: nx_Minecraft_Worlds_ListDataPacks(w,nx_EntityRequest_read(args),&options); break;
case 197: nx_Minecraft_Worlds_PlanSetDataPack(w,nx_DataPackSelection_read(args),&options); break;
case 198: nx_Minecraft_Worlds_ApplyDataPackPlan(w,nx_PlanRequest_read(args),&options); break;
case 199: nx_Minecraft_Worlds_Backup(w,nx_EntityRequest_read(args),&options); break;
case 200: nx_Minecraft_Worlds_PreviewRestore(w,nx_BackupRestore_read(args),&options); break;
case 201: nx_Minecraft_Worlds_Restore(w,nx_PlanRequest_read(args),&options); break;
case 202: nx_Minecraft_Worlds_ReadHealth(w,nx_EntityRequest_read(args),&options); break;
case 203: nx_Minecraft_Servers_ListSaved(w,nx_Empty_read(args),&options); break;
case 204: nx_Minecraft_Servers_SaveList(w,nx_ServerList_read(args),&options); break;
case 205: nx_Minecraft_Servers_ReadStatus(w,nx_EntityRequest_read(args),&options); break;
case 206: nx_Minecraft_Servers_DiscoverLan(w,nx_Empty_read(args),&options); break;
case 207: nx_Minecraft_Servers_Join(w,nx_ServerJoinRequest_read(args),&options); break;
case 208: nx_Catalog_ListProviders(w,nx_PageRequest_read(args),&options); break;
case 209: nx_Catalog_DescribeProvider(w,nx_QualifiedRequest_read(args),&options); break;
case 210: nx_Catalog_RegisterProvider(w,nx_ProviderDescriptor_read(args),&options); break;
case 211: nx_Catalog_Search(w,nx_CatalogSearch_read(args),&options); break;
case 212: nx_Catalog_ReadProject(w,nx_ResourceRef_read(args),&options); break;
case 213: nx_Catalog_ListVersions(w,nx_CatalogVersionQuery_read(args),&options); break;
case 214: nx_Catalog_ReadVersion(w,nx_ResourceVersionRef_read(args),&options); break;
case 215: nx_Catalog_ReadChangelog(w,nx_ResourceVersionRef_read(args),&options); break;
case 216: nx_Catalog_ResolveFiles(w,nx_ResourceVersionRef_read(args),&options); break;
case 217: nx_Catalog_ResolveDependencies(w,nx_ResourceVersionRef_read(args),&options); break;
case 218: nx_Catalog_ListFavorites(w,nx_PageRequest_read(args),&options); break;
case 219: nx_Catalog_SetFavorite(w,nx_FavoriteChange_read(args),&options); break;
case 220: nx_Catalog_PlanInstall(w,nx_CatalogInstallRequest_read(args),&options); break;
case 221: nx_Catalog_PlanUpdate(w,nx_CatalogInstallRequest_read(args),&options); break;
case 222: nx_Catalog_ExecutePlan(w,nx_PlanRequest_read(args),&options); break;
case 223: nx_Catalog_RegisterCollection(w,nx_ResourceCollection_read(args),&options); break;
case 224: nx_Catalog_RegisterTranslationProvider(w,nx_ProviderDescriptor_read(args),&options); break;
case 225: nx_Accounts_List(w,nx_PageRequest_read(args),&options); break;
case 226: nx_Accounts_ReadPublic(w,nx_EntityRequest_read(args),&options); break;
case 227: nx_Accounts_Watch(w,nx_WatchRequest_read(args),&options); break;
case 228: nx_Accounts_Select(w,nx_EntityRequest_read(args),&options); break;
case 229: nx_Accounts_BeginSignIn(w,nx_SignInRequest_read(args),&options); break;
case 230: nx_Accounts_ContinueSignIn(w,nx_SignInContinue_read(args),&options); break;
case 231: nx_Accounts_CancelSignIn(w,nx_EntityRequest_read(args),&options); break;
case 232: nx_Accounts_Refresh(w,nx_EntityRequest_read(args),&options); break;
case 233: nx_Accounts_SignOut(w,nx_EntityRequest_read(args),&options); break;
case 234: nx_Accounts_Remove(w,nx_EntityRequest_read(args),&options); break;
case 235: nx_Accounts_ReadLaunchEligibility(w,nx_EntityRequest_read(args),&options); break;
case 236: nx_Accounts_RequestLaunchGrant(w,nx_GrantRequest_read(args),&options); break;
case 237: nx_Accounts_ReadWardrobe(w,nx_EntityRequest_read(args),&options); break;
case 238: nx_Accounts_PreviewSkin(w,nx_SkinRequest_read(args),&options); break;
case 239: nx_Accounts_UploadSkin(w,nx_SkinRequest_read(args),&options); break;
case 240: nx_Accounts_SetCape(w,nx_CapeSelection_read(args),&options); break;
case 241: nx_Accounts_RegisterProvider(w,nx_ProviderDescriptor_read(args),&options); break;
case 242: nx_Settings_RegisterSchema(w,nx_SettingSchema_read(args),&options); break;
case 243: nx_Settings_RegisterPage(w,nx_UIPage_read(args),&options); break;
case 244: nx_Settings_Get(w,nx_SettingQuery_read(args),&options); break;
case 245: nx_Settings_GetEffective(w,nx_SettingQuery_read(args),&options); break;
case 246: nx_Settings_Watch(w,nx_SettingQuery_read(args),&options); break;
case 247: nx_Settings_PreviewChange(w,nx_SettingChange_read(args),&options); break;
case 248: nx_Settings_Apply(w,nx_PlanRequest_read(args),&options); break;
case 249: nx_Settings_Reset(w,nx_SettingQuery_read(args),&options); break;
case 250: nx_Settings_Migrate(w,nx_SettingMigration_read(args),&options); break;
case 251: nx_Settings_ListProfiles(w,nx_PageRequest_read(args),&options); break;
case 252: nx_Settings_SaveProfile(w,nx_SettingsProfile_read(args),&options); break;
case 253: nx_Settings_SelectProfile(w,nx_EntityRequest_read(args),&options); break;
case 254: nx_Settings_BeginTemporaryOverlay(w,nx_SettingsOverlay_read(args),&options); break;
case 255: nx_Settings_EndTemporaryOverlay(w,nx_RegistrationRequest_read(args),&options); break;
case 256: nx_Themes_List(w,nx_PageRequest_read(args),&options); break;
case 257: nx_Themes_Read(w,nx_EntityRequest_read(args),&options); break;
case 258: nx_Themes_Prepare(w,nx_EntityRequest_read(args),&options); break;
case 259: nx_Themes_Preview(w,nx_PlanRequest_read(args),&options); break;
case 260: nx_Themes_Commit(w,nx_PlanRequest_read(args),&options); break;
case 261: nx_Themes_Revert(w,nx_RegistrationRequest_read(args),&options); break;
case 262: nx_Themes_ReadOptions(w,nx_EntityRequest_read(args),&options); break;
case 263: nx_Themes_SaveOptions(w,nx_ThemeOptionChange_read(args),&options); break;
case 264: nx_Themes_ResetOptions(w,nx_EntityRequest_read(args),&options); break;
case 265: nx_Themes_ImportOptions(w,nx_ThemeTransfer_read(args),&options); break;
case 266: nx_Themes_ExportOptions(w,nx_ThemeTransfer_read(args),&options); break;
case 267: nx_Themes_MigrateOptions(w,nx_ThemeOptionChange_read(args),&options); break;
case 268: nx_Themes_ListResources(w,nx_EntityRequest_read(args),&options); break;
case 269: nx_Themes_ReadResource(w,nx_ThemeResource_read(args),&options); break;
case 270: nx_Themes_ReleaseResource(w,nx_BlobRef_read(args),&options); break;
case 271: nx_Backups_List(w,nx_EntityRequest_read(args),&options); break;
case 272: nx_Backups_Read(w,nx_EntityRequest_read(args),&options); break;
case 273: nx_Backups_Statistics(w,nx_EntityRequest_read(args),&options); break;
case 274: nx_Backups_PrepareCapture(w,nx_BackupCapture_read(args),&options); break;
case 275: nx_Backups_Capture(w,nx_PlanRequest_read(args),&options); break;
case 276: nx_Backups_PreviewRestore(w,nx_BackupRestore_read(args),&options); break;
case 277: nx_Backups_Restore(w,nx_PlanRequest_read(args),&options); break;
case 278: nx_Backups_VerifyOffline(w,nx_EntityRequest_read(args),&options); break;
case 279: nx_Backups_Export(w,nx_BackupTransfer_read(args),&options); break;
case 280: nx_Backups_Import(w,nx_BackupTransfer_read(args),&options); break;
case 281: nx_Backups_PreviewPrune(w,nx_BackupPrune_read(args),&options); break;
case 282: nx_Backups_Prune(w,nx_PlanRequest_read(args),&options); break;
case 283: nx_Backups_ReadRetention(w,nx_EntityRequest_read(args),&options); break;
case 284: nx_Backups_SetRetention(w,nx_BackupRetention_read(args),&options); break;
case 285: nx_Downloads_Resolve(w,nx_DownloadPlan_read(args),&options); break;
case 286: nx_Downloads_Start(w,nx_DownloadPlan_read(args),&options); break;
case 287: nx_Downloads_Read(w,nx_EntityRequest_read(args),&options); break;
case 288: nx_Downloads_Watch(w,nx_WatchRequest_read(args),&options); break;
case 289: nx_Downloads_Pause(w,nx_OperationRequest_read(args),&options); break;
case 290: nx_Downloads_Resume(w,nx_OperationRequest_read(args),&options); break;
case 291: nx_Downloads_Cancel(w,nx_OperationRequest_read(args),&options); break;
case 292: nx_Downloads_Verify(w,nx_EntityRequest_read(args),&options); break;
case 293: nx_Downloads_RegisterSourceResolver(w,nx_ProviderDescriptor_read(args),&options); break;
case 294: nx_Downloads_RegisterTransferProvider(w,nx_ProviderDescriptor_read(args),&options); break;
case 295: nx_Tasks_CreateOwned(w,nx_TaskCreate_read(args),&options); break;
case 296: nx_Tasks_Report(w,nx_TaskProgress_read(args),&options); break;
case 297: nx_Tasks_Complete(w,nx_TaskCompletion_read(args),&options); break;
case 298: nx_Tasks_Fail(w,nx_TaskFailure_read(args),&options); break;
case 299: nx_Tasks_List(w,nx_PageRequest_read(args),&options); break;
case 300: nx_Tasks_Read(w,nx_EntityRequest_read(args),&options); break;
case 301: nx_Tasks_Watch(w,nx_WatchRequest_read(args),&options); break;
case 302: nx_Tasks_Cancel(w,nx_OperationRequest_read(args),&options); break;
case 303: nx_Tasks_Retry(w,nx_OperationRequest_read(args),&options); break;
case 304: nx_Tasks_Dismiss(w,nx_EntityRequest_read(args),&options); break;
case 305: nx_Storage_OpenNamespace(w,nx_NamespaceRequest_read(args),&options); break;
case 306: nx_Storage_Read(w,nx_StorageKey_read(args),&options); break;
case 307: nx_Storage_Write(w,nx_StorageWrite_read(args),&options); break;
case 308: nx_Storage_CompareExchange(w,nx_StorageWrite_read(args),&options); break;
case 309: nx_Storage_Query(w,nx_StorageQuery_read(args),&options); break;
case 310: nx_Storage_BeginTransaction(w,nx_StorageNamespace_read(args),&options); break;
case 311: nx_Storage_Commit(w,nx_StorageCommit_read(args),&options); break;
case 312: nx_Storage_Migrate(w,nx_StorageMigration_read(args),&options); break;
case 313: nx_Files_Pick(w,nx_FilePick_read(args),&options); break;
case 314: nx_Files_List(w,nx_FileQuery_read(args),&options); break;
case 315: nx_Files_Stat(w,nx_FileRef_read(args),&options); break;
case 316: nx_Files_Read(w,nx_FileRead_read(args),&options); break;
case 317: nx_Files_WriteAtomic(w,nx_FileWrite_read(args),&options); break;
case 318: nx_Files_Watch(w,nx_FileRef_read(args),&options); break;
case 319: nx_Files_PrepareMove(w,nx_FileMove_read(args),&options); break;
case 320: nx_Files_Move(w,nx_PlanRequest_read(args),&options); break;
case 321: nx_Files_PrepareDelete(w,nx_FileDelete_read(args),&options); break;
case 322: nx_Files_Delete(w,nx_PlanRequest_read(args),&options); break;
case 323: nx_Files_OpenPackageFile(w,nx_PackageFileRequest_read(args),&options); break;
case 324: nx_Network_Request(w,nx_NetworkRequest_read(args),&options); break;
case 325: nx_Network_OpenResponseStream(w,nx_EntityRequest_read(args),&options); break;
case 326: nx_Network_Cancel(w,nx_OperationRequest_read(args),&options); break;
case 327: nx_Network_OpenConnection(w,nx_NetworkConnectionRequest_read(args),&options); break;
case 328: nx_Network_Listen(w,nx_NetworkConnectionRequest_read(args),&options); break;
case 329: nx_Network_Send(w,nx_NetworkSend_read(args),&options); break;
case 330: nx_Network_Receive(w,nx_NetworkReceive_read(args),&options); break;
case 331: nx_Network_Close(w,nx_NetworkConnection_read(args),&options); break;
case 332: nx_Platform_Describe(w,nx_Empty_read(args),&options); break;
case 333: nx_Platform_OpenUri(w,nx_UriRef_read(args),&options); break;
case 334: nx_Platform_RevealFile(w,nx_FileRef_read(args),&options); break;
case 335: nx_Platform_Notify(w,nx_UINotification_read(args),&options); break;
case 336: nx_Platform_ReadClipboard(w,nx_Empty_read(args),&options); break;
case 337: nx_Platform_WriteClipboard(w,nx_ClipboardContent_read(args),&options); break;
case 338: nx_Platform_PickFile(w,nx_FilePick_read(args),&options); break;
case 339: nx_Platform_QueryPower(w,nx_Empty_read(args),&options); break;
case 340: nx_Platform_QueryDisplay(w,nx_Empty_read(args),&options); break;
case 341: nx_Platform_QueryArchitecture(w,nx_Empty_read(args),&options); break;
case 342: nx_Minecraft_Diagnostics_Analyze(w,nx_EntityRequest_read(args),&options); break;
case 343: nx_Minecraft_Diagnostics_RegisterRuleProvider(w,nx_ProviderDescriptor_read(args),&options); break;
case 344: nx_Minecraft_Diagnostics_PreviewRepair(w,nx_RepairRequest_read(args),&options); break;
case 345: nx_Minecraft_Diagnostics_ExecuteRepair(w,nx_PlanRequest_read(args),&options); break;
case 346: nx_Legacy_Events_DeclareEvent(w,nx_LegacyEventDeclaration_read(args),&options); break;
case 347: nx_Legacy_Events_Subscribe(w,nx_LegacyEventSubscription_read(args),&options); break;
case 348: nx_Legacy_Events_Publish(w,nx_LegacyEventPublish_read(args),&options); break;
case 349: nx_Legacy_Events_Unsubscribe(w,nx_LegacyHandle_read(args),&options); break;
case 350: nx_Legacy_UI_DeclareSurface(w,nx_LegacySurface_read(args),&options); break;
case 351: nx_Legacy_UI_DeclareCommand(w,nx_LegacyCommand_read(args),&options); break;
case 352: nx_Legacy_UI_DeclarePlacement(w,nx_LegacyPlacement_read(args),&options); break;
case 353: nx_Legacy_UI_DeclareSettings(w,nx_LegacySettings_read(args),&options); break;
case 354: nx_Legacy_UI_PatchState(w,nx_LegacyPatch_read(args),&options); break;
case 355: nx_Legacy_UI_SetCommandState(w,nx_LegacyCommandState_read(args),&options); break;
case 356: nx_Legacy_Plugins_Describe(w,nx_LegacyServiceQuery_read(args),&options); break;
case 357: nx_Legacy_Plugins_Bind(w,nx_LegacyServiceRequirement_read(args),&options); break;
case 358: nx_Legacy_Plugins_Call(w,nx_LegacyServiceCall_read(args),&options); break;
case 359: nx_Legacy_Plugins_Release(w,nx_LegacyHandle_read(args),&options); break;
case 360: nx_Legacy_Plugins_RebindOptional(w,nx_LegacyServiceRequirement_read(args),&options); break;
case 361: nx_Legacy_Plugins_ExportService(w,nx_LegacyServiceDeclaration_read(args),&options); break;
case 362: nx_Legacy_Plugins_Probe(w,nx_LegacyServiceProbe_read(args),&options); break;
case 363: nx_Legacy_Diagnostics_Report(w,nx_LegacyDiagnostic_read(args),&options); break;
case 364: nx_Legacy_Diagnostics_ReportFinding(w,nx_LegacyFinding_read(args),&options); break;
case 365: nx_Legacy_Diagnostics_QueryRegistrations(w,nx_Empty_read(args),&options); break;
case 366: nx_Legacy_Diagnostics_QueryBindingStatus(w,nx_Empty_read(args),&options); break;
case 367: nx_Legacy_Resources_RegisterCleanup(w,nx_LegacyCleanup_read(args),&options); break;
default: __builtin_trap(); } waiting=1; } else { waiting=0; switch(operation) {
case 0: { nx_RegistrationRef result; if(nx_Contracts_DefineService_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 1: { nx_RegistrationRef result; if(nx_Contracts_DefineProviderKind_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 2: { nx_RegistrationRef result; if(nx_Contracts_DefineExtensionPoint_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 3: { nx_PublicContract result; if(nx_Contracts_Describe_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 4: { nx_Page_PublicContract result; if(nx_Contracts_List_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 5: { nx_ValidationReport result; if(nx_Contracts_ValidateSchema_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 6: { nx_RegistrationRef result; if(nx_Contracts_RegisterConsumer_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 7: { nx_SubscriptionRef result; if(nx_Contracts_WatchAvailability_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 8: { nx_ValidationReport result; if(nx_Contracts_CheckCompatibility_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 9: { nx_Page_RegistryDescriptor result; if(nx_Definitions_ListRegistries_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 10: { nx_RegistryDescriptor result; if(nx_Definitions_DescribeRegistry_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 11: { nx_RegistrationRef result; if(nx_Definitions_DefineRegistry_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 12: { nx_RegistrationRef result; if(nx_Definitions_Register_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 13: { nx_Page_RegistrationRef result; if(nx_Definitions_RegisterBatch_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 14: { nx_Snapshot_Definition result; if(nx_Definitions_Get_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 15: { nx_Page_Definition result; if(nx_Definitions_Query_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 16: { nx_SubscriptionRef result; if(nx_Definitions_Watch_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 17: { nx_RegistrationRef result; if(nx_Definitions_UpdateOwned_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 18: { nx_Empty result; if(nx_Definitions_RemoveOwned_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 19: { nx_RegistrationRef result; if(nx_Definitions_RegisterTag_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 20: { nx_TagResolution result; if(nx_Definitions_ResolveTag_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 21: { nx_MutationPlan result; if(nx_Definitions_PreviewOverlay_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 22: { nx_RegistrationRef result; if(nx_Definitions_RegisterOverlay_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 23: { nx_ResolutionReport result; if(nx_Definitions_ExplainResolution_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 24: { nx_RegistrationRef result; if(nx_Predicates_Register_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 25: { nx_PredicateResult result; if(nx_Predicates_Evaluate_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 26: { nx_PredicateDefinition result; if(nx_Predicates_Describe_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 27: { nx_RegistrationRef result; if(nx_Actions_Register_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 28: { nx_ActionDescriptor result; if(nx_Actions_Describe_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 29: { nx_OperationRef result; if(nx_Actions_Invoke_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 30: { nx_Page_ActionDescriptor result; if(nx_Commands_List_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 31: { nx_ActionDescriptor result; if(nx_Commands_Describe_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 32: { nx_OperationRef result; if(nx_Commands_Execute_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 33: { nx_RegistrationRef result; if(nx_Workflows_Register_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 34: { nx_ValidationReport result; if(nx_Workflows_Validate_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 35: { nx_MutationPlan result; if(nx_Workflows_Preview_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 36: { nx_OperationRef result; if(nx_Workflows_Start_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 37: { nx_OperationRecord result; if(nx_Workflows_Read_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 38: { nx_SubscriptionRef result; if(nx_Workflows_Watch_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 39: { nx_OperationRef result; if(nx_Workflows_Cancel_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 40: { nx_Page_OperationRecord result; if(nx_Workflows_ListRuns_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 41: { nx_OperationRef result; if(nx_Workflows_Resume_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 42: { nx_OperationRef result; if(nx_Workflows_RetryStep_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 43: { nx_ValidationReport result; if(nx_Workflows_ExplainPlan_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 44: { nx_WorkflowTrace result; if(nx_Workflows_ReadRunTrace_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 45: { nx_RegistrationRef result; if(nx_Schedules_Register_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 46: { nx_Page_ScheduleState result; if(nx_Schedules_List_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 47: { nx_ScheduleState result; if(nx_Schedules_Enable_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 48: { nx_ScheduleState result; if(nx_Schedules_Disable_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 49: { nx_OperationRef result; if(nx_Schedules_TriggerNow_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 50: { nx_ScheduleState result; if(nx_Schedules_ReadNextRun_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 51: { nx_EventDescriptor result; if(nx_Events_Describe_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 52: { nx_SubscriptionRef result; if(nx_Events_Subscribe_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 53: { nx_RegistrationRef result; if(nx_Events_Define_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 54: { nx_Empty result; if(nx_Events_Publish_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 55: { nx_Empty result; if(nx_Events_Unsubscribe_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 56: { nx_Empty result; if(nx_Events_UnsubscribeSubscription_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 57: { nx_EventSubscriptionRegistration result; if(nx_Events_RegisterSubscription_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 58: { nx_StateDescriptor result; if(nx_State_Describe_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 59: { nx_StateSnapshot result; if(nx_State_Read_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 60: { nx_SubscriptionRef result; if(nx_State_Watch_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 61: { nx_RegistrationRef result; if(nx_State_DefineOwned_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 62: { nx_StateSnapshot result; if(nx_State_UpdateOwned_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 63: { nx_StateSnapshot result; if(nx_State_CompareExchangeOwned_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 64: { nx_RegistrationRef result; if(nx_UI_RegisterPage_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 65: { nx_RegistrationRef result; if(nx_UI_RegisterComponent_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 66: { nx_RegistrationRef result; if(nx_UI_RegisterContribution_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 67: { nx_RegistrationRef result; if(nx_UI_RegisterViewReplacement_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 68: { nx_RegistrationRef result; if(nx_UI_RegisterNavigation_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 69: { nx_RegistrationRef result; if(nx_UI_RegisterCommand_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 70: { nx_RegistrationRef result; if(nx_UI_RegisterShortcut_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 71: { nx_UIDialogRef result; if(nx_UI_ShowDialog_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 72: { nx_Empty result; if(nx_UI_CloseDialog_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 73: { nx_Empty result; if(nx_UI_Navigate_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 74: { nx_Empty result; if(nx_UI_Notify_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 75: { nx_StateSnapshot result; if(nx_UI_PublishModel_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 76: { nx_StateSnapshot result; if(nx_UI_UpdateModel_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 77: { nx_SubscriptionRef result; if(nx_UI_WatchViewLifecycle_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 78: { nx_Page_UIViewContract result; if(nx_UI_ListExtensionTargets_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 79: { nx_UIViewContract result; if(nx_UI_DescribeViewContract_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 80: { nx_DrawingSurfaceRef result; if(nx_UI_CreateDrawingSurface_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 81: { nx_Empty result; if(nx_UI_SubmitDrawCommands_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 82: { nx_SubscriptionRef result; if(nx_UI_SubscribeInput_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 83: { nx_RegistrationRef result; if(nx_Plugins_ExportService_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 84: { nx_PublicContract result; if(nx_Plugins_DescribeService_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 85: { nx_ServiceBinding result; if(nx_Plugins_BindService_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 86: { nx_ValidationReport result; if(nx_Plugins_ProbeService_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 87: { nx_OperationRef result; if(nx_Plugins_CallService_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 88: { nx_SubscriptionRef result; if(nx_Plugins_WatchAvailability_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 89: { nx_Empty result; if(nx_Plugins_ReleaseBinding_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 90: { nx_LoadReport result; if(nx_Plugins_ReadOwnLoadReport_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 91: { nx_Empty result; if(nx_Diagnostics_Log_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 92: { nx_Empty result; if(nx_Diagnostics_Report_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 93: { nx_SpanRef result; if(nx_Diagnostics_CreateSpan_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 94: { nx_Page_DiagnosticReport result; if(nx_Diagnostics_ReadOwnReports_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 95: { nx_RegistrationRef result; if(nx_Resources_RegisterCleanup_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 96: { nx_Empty result; if(nx_Resources_Release_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 97: { nx_SubscriptionBatch result; if(nx_Resources_ReadSubscription_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 98: { nx_Empty result; if(nx_Resources_ReleaseSubscription_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 99: { nx_Page_InstanceSummary result; if(nx_Minecraft_Instances_List_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 100: { nx_InstanceDetails result; if(nx_Minecraft_Instances_Read_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 101: { nx_SubscriptionRef result; if(nx_Minecraft_Instances_Watch_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 102: { nx_OperationRef result; if(nx_Minecraft_Instances_Discover_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 103: { nx_Page_RootRegistration result; if(nx_Minecraft_Instances_ListRoots_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 104: { nx_RootRegistration result; if(nx_Minecraft_Instances_AddRoot_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 105: { nx_Empty result; if(nx_Minecraft_Instances_RemoveRoot_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 106: { nx_MutationPlan result; if(nx_Minecraft_Instances_PrepareCreate_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 107: { nx_OperationRef result; if(nx_Minecraft_Instances_CommitCreate_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 108: { nx_InstanceSummary result; if(nx_Minecraft_Instances_Select_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 109: { nx_InstanceSummary result; if(nx_Minecraft_Instances_Rename_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 110: { nx_MutationPlan result; if(nx_Minecraft_Instances_PrepareClone_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 111: { nx_OperationRef result; if(nx_Minecraft_Instances_CommitClone_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 112: { nx_MutationPlan result; if(nx_Minecraft_Instances_PrepareDelete_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 113: { nx_OperationRef result; if(nx_Minecraft_Instances_CommitDelete_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 114: { nx_InstanceSummary result; if(nx_Minecraft_Instances_ReadIdentity_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 115: { nx_Page_EffectiveSetting result; if(nx_Minecraft_Instances_ReadEffectiveSettings_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 116: { nx_Empty result; if(nx_Minecraft_Instances_OpenDirectory_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 117: { nx_Page_GameVersion result; if(nx_Minecraft_Install_ListGameVersions_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 118: { nx_Page_LoaderVersion result; if(nx_Minecraft_Install_ListLoaderVersions_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 119: { nx_InstallerInspection result; if(nx_Minecraft_Install_InspectLocalInstaller_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 120: { nx_InstallDraft result; if(nx_Minecraft_Install_ReadDraft_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 121: { nx_InstallDraft result; if(nx_Minecraft_Install_UpdateDraft_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 122: { nx_ValidationReport result; if(nx_Minecraft_Install_ValidateDraft_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 123: { nx_InstallPlan result; if(nx_Minecraft_Install_ResolvePlan_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 124: { nx_InstallPlan result; if(nx_Minecraft_Install_PreviewPlan_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 125: { nx_OperationRef result; if(nx_Minecraft_Install_ExecutePlan_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 126: { nx_OperationRef result; if(nx_Minecraft_Install_Cancel_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 127: { nx_Page_RecoveryRecord result; if(nx_Minecraft_Install_ListRecoveries_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 128: { nx_OperationRef result; if(nx_Minecraft_Install_ResumeRecovery_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 129: { nx_Empty result; if(nx_Minecraft_Install_DiscardRecovery_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 130: { nx_RegistrationRef result; if(nx_Minecraft_Install_RegisterTemplate_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 131: { nx_RegistrationRef result; if(nx_Minecraft_Install_RegisterLoaderProvider_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 132: { nx_Page_JavaRuntime result; if(nx_Minecraft_Java_List_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 133: { nx_OperationRef result; if(nx_Minecraft_Java_Discover_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 134: { nx_JavaRuntime result; if(nx_Minecraft_Java_Inspect_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 135: { nx_JavaRequirements result; if(nx_Minecraft_Java_ReadRequirements_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 136: { nx_JavaRuntime result; if(nx_Minecraft_Java_ResolveSelection_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 137: { nx_JavaRuntime result; if(nx_Minecraft_Java_SelectGlobal_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 138: { nx_JavaRuntime result; if(nx_Minecraft_Java_SelectForInstance_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 139: { nx_Page_JavaDistribution result; if(nx_Minecraft_Java_ListDistributions_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 140: { nx_MutationPlan result; if(nx_Minecraft_Java_PrepareInstall_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 141: { nx_OperationRef result; if(nx_Minecraft_Java_Install_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 142: { nx_OperationRef result; if(nx_Minecraft_Java_Remove_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 143: { nx_RegistrationRef result; if(nx_Minecraft_Java_RegisterDistributionProvider_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 144: { nx_Page_ManagedJavaOffer result; if(nx_Minecraft_Java_ListManagedDistributions_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 145: { nx_MutationPlan result; if(nx_Minecraft_Java_PrepareManagedInstall_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 146: { nx_LaunchProfile result; if(nx_Minecraft_Launch_ReadEffectiveProfile_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 147: { nx_Page_LaunchProfile result; if(nx_Minecraft_Launch_ListProfiles_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 148: { nx_LaunchProfile result; if(nx_Minecraft_Launch_SaveProfile_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 149: { nx_LaunchProfile result; if(nx_Minecraft_Launch_SelectProfile_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 150: { nx_LaunchPlan result; if(nx_Minecraft_Launch_Prepare_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 151: { nx_LaunchPlan result; if(nx_Minecraft_Launch_ReadPlan_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 152: { nx_ValidationReport result; if(nx_Minecraft_Launch_ValidatePlan_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 153: { nx_OperationRef result; if(nx_Minecraft_Launch_Start_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 154: { nx_OperationRef result; if(nx_Minecraft_Launch_Cancel_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 155: { nx_RegistrationRef result; if(nx_Minecraft_Launch_RegisterContribution_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 156: { nx_RegistrationRef result; if(nx_Minecraft_Launch_RegisterPreflight_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 157: { nx_LaunchAttempt result; if(nx_Minecraft_Launch_ReadAttempt_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 158: { nx_SubscriptionRef result; if(nx_Minecraft_Launch_WatchAttempt_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 159: { nx_LaunchContributionReport result; if(nx_Minecraft_Launch_ExplainContribution_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 160: { nx_Page_GameSession result; if(nx_Minecraft_Processes_ListSessions_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 161: { nx_GameSession result; if(nx_Minecraft_Processes_ReadSession_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 162: { nx_SubscriptionRef result; if(nx_Minecraft_Processes_WatchSession_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 163: { nx_SubscriptionRef result; if(nx_Minecraft_Processes_SubscribeLog_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 164: { nx_LogChunk result; if(nx_Minecraft_Processes_ReadLogRange_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 165: { nx_OperationRef result; if(nx_Minecraft_Processes_RequestClose_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 166: { nx_OperationRef result; if(nx_Minecraft_Processes_Stop_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 167: { nx_Empty result; if(nx_Minecraft_Processes_RevealWindow_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 168: { nx_SessionMetrics result; if(nx_Minecraft_Processes_ReadMetrics_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 169: { nx_Page_ContentItem result; if(nx_Minecraft_Content_List_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 170: { nx_ContentItem result; if(nx_Minecraft_Content_Inspect_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 171: { nx_SubscriptionRef result; if(nx_Minecraft_Content_Watch_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 172: { nx_ContentDependencyGraph result; if(nx_Minecraft_Content_ReadDependencyGraph_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 173: { nx_ContentPlan result; if(nx_Minecraft_Content_PlanInstall_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 174: { nx_ContentPlan result; if(nx_Minecraft_Content_PlanEnable_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 175: { nx_ContentPlan result; if(nx_Minecraft_Content_PlanDisable_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 176: { nx_ContentPlan result; if(nx_Minecraft_Content_PlanRemove_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 177: { nx_ContentPlan result; if(nx_Minecraft_Content_PlanUpdate_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 178: { nx_ContentPlan result; if(nx_Minecraft_Content_Preview_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 179: { nx_OperationRef result; if(nx_Minecraft_Content_Execute_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 180: { nx_Page_ContentTransaction result; if(nx_Minecraft_Content_ListTransactions_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 181: { nx_OperationRef result; if(nx_Minecraft_Content_Rollback_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 182: { nx_IntegrityReport result; if(nx_Minecraft_Content_ReadIntegrity_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 183: { nx_OperationRef result; if(nx_Minecraft_Content_Verify_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 184: { nx_Page_ContentItem result; if(nx_Minecraft_Content_ListTrash_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 185: { nx_OperationRef result; if(nx_Minecraft_Content_RestoreTrash_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 186: { nx_OperationRef result; if(nx_Minecraft_Content_ClearTrash_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 187: { nx_OperationRef result; if(nx_Minecraft_Content_Import_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 188: { nx_OperationRef result; if(nx_Minecraft_Content_Export_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 189: { nx_RegistrationRef result; if(nx_Minecraft_Content_RegisterFormatProvider_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 190: { nx_Page_WorldSummary result; if(nx_Minecraft_Worlds_List_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 191: { nx_WorldSummary result; if(nx_Minecraft_Worlds_Read_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 192: { nx_WorldMetadata result; if(nx_Minecraft_Worlds_ReadMetadata_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 193: { nx_OperationRef result; if(nx_Minecraft_Worlds_Copy_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 194: { nx_WorldSummary result; if(nx_Minecraft_Worlds_Rename_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 195: { nx_MutationPlan result; if(nx_Minecraft_Worlds_PlanDelete_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 196: { nx_Page_ContentItem result; if(nx_Minecraft_Worlds_ListDataPacks_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 197: { nx_MutationPlan result; if(nx_Minecraft_Worlds_PlanSetDataPack_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 198: { nx_OperationRef result; if(nx_Minecraft_Worlds_ApplyDataPackPlan_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 199: { nx_OperationRef result; if(nx_Minecraft_Worlds_Backup_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 200: { nx_MutationPlan result; if(nx_Minecraft_Worlds_PreviewRestore_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 201: { nx_OperationRef result; if(nx_Minecraft_Worlds_Restore_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 202: { nx_IntegrityReport result; if(nx_Minecraft_Worlds_ReadHealth_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 203: { nx_ServerList result; if(nx_Minecraft_Servers_ListSaved_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 204: { nx_ServerList result; if(nx_Minecraft_Servers_SaveList_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 205: { nx_ServerStatus result; if(nx_Minecraft_Servers_ReadStatus_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 206: { nx_SubscriptionRef result; if(nx_Minecraft_Servers_DiscoverLan_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 207: { nx_OperationRef result; if(nx_Minecraft_Servers_Join_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 208: { nx_Page_ProviderDescriptor result; if(nx_Catalog_ListProviders_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 209: { nx_ProviderDescriptor result; if(nx_Catalog_DescribeProvider_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 210: { nx_RegistrationRef result; if(nx_Catalog_RegisterProvider_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 211: { nx_Page_CatalogProject result; if(nx_Catalog_Search_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 212: { nx_CatalogProject result; if(nx_Catalog_ReadProject_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 213: { nx_Page_CatalogVersion result; if(nx_Catalog_ListVersions_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 214: { nx_CatalogVersion result; if(nx_Catalog_ReadVersion_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 215: { nx_TextResult result; if(nx_Catalog_ReadChangelog_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 216: { nx_Page_CatalogFile result; if(nx_Catalog_ResolveFiles_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 217: { nx_Page_CatalogDependency result; if(nx_Catalog_ResolveDependencies_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 218: { nx_Page_CatalogProject result; if(nx_Catalog_ListFavorites_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 219: { nx_Empty result; if(nx_Catalog_SetFavorite_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 220: { nx_ContentPlan result; if(nx_Catalog_PlanInstall_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 221: { nx_ContentPlan result; if(nx_Catalog_PlanUpdate_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 222: { nx_OperationRef result; if(nx_Catalog_ExecutePlan_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 223: { nx_RegistrationRef result; if(nx_Catalog_RegisterCollection_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 224: { nx_RegistrationRef result; if(nx_Catalog_RegisterTranslationProvider_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 225: { nx_Page_AccountPublic result; if(nx_Accounts_List_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 226: { nx_AccountPublic result; if(nx_Accounts_ReadPublic_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 227: { nx_SubscriptionRef result; if(nx_Accounts_Watch_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 228: { nx_AccountPublic result; if(nx_Accounts_Select_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 229: { nx_SignInChallenge result; if(nx_Accounts_BeginSignIn_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 230: { nx_SignInChallenge result; if(nx_Accounts_ContinueSignIn_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 231: { nx_Empty result; if(nx_Accounts_CancelSignIn_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 232: { nx_OperationRef result; if(nx_Accounts_Refresh_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 233: { nx_Empty result; if(nx_Accounts_SignOut_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 234: { nx_Empty result; if(nx_Accounts_Remove_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 235: { nx_LaunchEligibility result; if(nx_Accounts_ReadLaunchEligibility_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 236: { nx_LaunchGrant result; if(nx_Accounts_RequestLaunchGrant_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 237: { nx_Wardrobe result; if(nx_Accounts_ReadWardrobe_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 238: { nx_BlobRef result; if(nx_Accounts_PreviewSkin_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 239: { nx_OperationRef result; if(nx_Accounts_UploadSkin_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 240: { nx_OperationRef result; if(nx_Accounts_SetCape_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 241: { nx_RegistrationRef result; if(nx_Accounts_RegisterProvider_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 242: { nx_RegistrationRef result; if(nx_Settings_RegisterSchema_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 243: { nx_RegistrationRef result; if(nx_Settings_RegisterPage_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 244: { nx_StateSnapshot result; if(nx_Settings_Get_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 245: { nx_EffectiveSetting result; if(nx_Settings_GetEffective_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 246: { nx_SubscriptionRef result; if(nx_Settings_Watch_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 247: { nx_MutationPlan result; if(nx_Settings_PreviewChange_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 248: { nx_OperationRef result; if(nx_Settings_Apply_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 249: { nx_StateSnapshot result; if(nx_Settings_Reset_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 250: { nx_OperationRef result; if(nx_Settings_Migrate_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 251: { nx_Page_SettingsProfile result; if(nx_Settings_ListProfiles_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 252: { nx_SettingsProfile result; if(nx_Settings_SaveProfile_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 253: { nx_SettingsProfile result; if(nx_Settings_SelectProfile_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 254: { nx_RegistrationRef result; if(nx_Settings_BeginTemporaryOverlay_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 255: { nx_Empty result; if(nx_Settings_EndTemporaryOverlay_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 256: { nx_Page_ThemeSummary result; if(nx_Themes_List_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 257: { nx_ThemeSummary result; if(nx_Themes_Read_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 258: { nx_ThemePreparation result; if(nx_Themes_Prepare_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 259: { nx_RegistrationRef result; if(nx_Themes_Preview_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 260: { nx_OperationRef result; if(nx_Themes_Commit_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 261: { nx_Empty result; if(nx_Themes_Revert_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 262: { nx_ThemeOptions result; if(nx_Themes_ReadOptions_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 263: { nx_ThemeOptions result; if(nx_Themes_SaveOptions_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 264: { nx_ThemeOptions result; if(nx_Themes_ResetOptions_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 265: { nx_OperationRef result; if(nx_Themes_ImportOptions_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 266: { nx_OperationRef result; if(nx_Themes_ExportOptions_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 267: { nx_OperationRef result; if(nx_Themes_MigrateOptions_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 268: { nx_Page_ThemeResource result; if(nx_Themes_ListResources_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 269: { nx_BlobRef result; if(nx_Themes_ReadResource_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 270: { nx_Empty result; if(nx_Themes_ReleaseResource_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 271: { nx_Page_BackupSummary result; if(nx_Backups_List_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 272: { nx_BackupSummary result; if(nx_Backups_Read_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 273: { nx_BackupStatistics result; if(nx_Backups_Statistics_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 274: { nx_MutationPlan result; if(nx_Backups_PrepareCapture_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 275: { nx_OperationRef result; if(nx_Backups_Capture_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 276: { nx_MutationPlan result; if(nx_Backups_PreviewRestore_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 277: { nx_OperationRef result; if(nx_Backups_Restore_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 278: { nx_IntegrityReport result; if(nx_Backups_VerifyOffline_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 279: { nx_OperationRef result; if(nx_Backups_Export_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 280: { nx_OperationRef result; if(nx_Backups_Import_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 281: { nx_MutationPlan result; if(nx_Backups_PreviewPrune_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 282: { nx_OperationRef result; if(nx_Backups_Prune_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 283: { nx_RetentionPolicy result; if(nx_Backups_ReadRetention_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 284: { nx_RetentionPolicy result; if(nx_Backups_SetRetention_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 285: { nx_DownloadPlan result; if(nx_Downloads_Resolve_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 286: { nx_OperationRef result; if(nx_Downloads_Start_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 287: { nx_DownloadState result; if(nx_Downloads_Read_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 288: { nx_SubscriptionRef result; if(nx_Downloads_Watch_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 289: { nx_OperationRef result; if(nx_Downloads_Pause_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 290: { nx_OperationRef result; if(nx_Downloads_Resume_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 291: { nx_OperationRef result; if(nx_Downloads_Cancel_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 292: { nx_IntegrityReport result; if(nx_Downloads_Verify_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 293: { nx_RegistrationRef result; if(nx_Downloads_RegisterSourceResolver_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 294: { nx_RegistrationRef result; if(nx_Downloads_RegisterTransferProvider_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 295: { nx_OperationRef result; if(nx_Tasks_CreateOwned_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 296: { nx_Empty result; if(nx_Tasks_Report_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 297: { nx_Empty result; if(nx_Tasks_Complete_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 298: { nx_Empty result; if(nx_Tasks_Fail_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 299: { nx_Page_OperationRecord result; if(nx_Tasks_List_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 300: { nx_OperationRecord result; if(nx_Tasks_Read_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 301: { nx_SubscriptionRef result; if(nx_Tasks_Watch_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 302: { nx_OperationRef result; if(nx_Tasks_Cancel_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 303: { nx_OperationRef result; if(nx_Tasks_Retry_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 304: { nx_Empty result; if(nx_Tasks_Dismiss_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 305: { nx_StorageNamespace result; if(nx_Storage_OpenNamespace_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 306: { nx_StorageValue result; if(nx_Storage_Read_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 307: { nx_StorageValue result; if(nx_Storage_Write_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 308: { nx_StorageValue result; if(nx_Storage_CompareExchange_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 309: { nx_Page_StorageEntry result; if(nx_Storage_Query_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 310: { nx_StorageTransaction result; if(nx_Storage_BeginTransaction_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 311: { nx_StorageNamespace result; if(nx_Storage_Commit_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 312: { nx_OperationRef result; if(nx_Storage_Migrate_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 313: { nx_FileRef result; if(nx_Files_Pick_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 314: { nx_Page_FileStat result; if(nx_Files_List_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 315: { nx_FileStat result; if(nx_Files_Stat_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 316: { nx_BlobRef result; if(nx_Files_Read_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 317: { nx_FileStat result; if(nx_Files_WriteAtomic_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 318: { nx_SubscriptionRef result; if(nx_Files_Watch_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 319: { nx_MutationPlan result; if(nx_Files_PrepareMove_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 320: { nx_OperationRef result; if(nx_Files_Move_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 321: { nx_MutationPlan result; if(nx_Files_PrepareDelete_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 322: { nx_OperationRef result; if(nx_Files_Delete_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 323: { nx_FileRef result; if(nx_Files_OpenPackageFile_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 324: { nx_NetworkResponse result; if(nx_Network_Request_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 325: { nx_BlobRef result; if(nx_Network_OpenResponseStream_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 326: { nx_Empty result; if(nx_Network_Cancel_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 327: { nx_NetworkConnection result; if(nx_Network_OpenConnection_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 328: { nx_NetworkConnection result; if(nx_Network_Listen_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 329: { nx_Empty result; if(nx_Network_Send_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 330: { nx_NetworkPacket result; if(nx_Network_Receive_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 331: { nx_Empty result; if(nx_Network_Close_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 332: { nx_PlatformDescription result; if(nx_Platform_Describe_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 333: { nx_Empty result; if(nx_Platform_OpenUri_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 334: { nx_Empty result; if(nx_Platform_RevealFile_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 335: { nx_Empty result; if(nx_Platform_Notify_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 336: { nx_ClipboardContent result; if(nx_Platform_ReadClipboard_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 337: { nx_Empty result; if(nx_Platform_WriteClipboard_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 338: { nx_FileRef result; if(nx_Platform_PickFile_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 339: { nx_PowerState result; if(nx_Platform_QueryPower_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 340: { nx_Page_DisplayInfo result; if(nx_Platform_QueryDisplay_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 341: { nx_ArchitectureInfo result; if(nx_Platform_QueryArchitecture_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 342: { nx_DiagnosticAnalysis result; if(nx_Minecraft_Diagnostics_Analyze_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 343: { nx_RegistrationRef result; if(nx_Minecraft_Diagnostics_RegisterRuleProvider_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 344: { nx_MutationPlan result; if(nx_Minecraft_Diagnostics_PreviewRepair_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 345: { nx_OperationRef result; if(nx_Minecraft_Diagnostics_ExecuteRepair_result(value,&result)) nx_complete_value(w,result.value); else nx_complete_value(w,nx_reply_error(value)); break; }
case 346: { nx_value result; if(nx_Legacy_Events_DeclareEvent_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 347: { nx_value result; if(nx_Legacy_Events_Subscribe_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 348: { nx_value result; if(nx_Legacy_Events_Publish_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 349: { nx_value result; if(nx_Legacy_Events_Unsubscribe_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 350: { nx_value result; if(nx_Legacy_UI_DeclareSurface_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 351: { nx_value result; if(nx_Legacy_UI_DeclareCommand_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 352: { nx_value result; if(nx_Legacy_UI_DeclarePlacement_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 353: { nx_value result; if(nx_Legacy_UI_DeclareSettings_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 354: { nx_value result; if(nx_Legacy_UI_PatchState_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 355: { nx_value result; if(nx_Legacy_UI_SetCommandState_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 356: { nx_value result; if(nx_Legacy_Plugins_Describe_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 357: { nx_value result; if(nx_Legacy_Plugins_Bind_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 358: { nx_value result; if(nx_Legacy_Plugins_Call_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 359: { nx_value result; if(nx_Legacy_Plugins_Release_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 360: { nx_value result; if(nx_Legacy_Plugins_RebindOptional_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 361: { nx_value result; if(nx_Legacy_Plugins_ExportService_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 362: { nx_value result; if(nx_Legacy_Plugins_Probe_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 363: { nx_value result; if(nx_Legacy_Diagnostics_Report_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 364: { nx_value result; if(nx_Legacy_Diagnostics_ReportFinding_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 365: { nx_value result; if(nx_Legacy_Diagnostics_QueryRegistrations_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 366: { nx_value result; if(nx_Legacy_Diagnostics_QueryBindingStatus_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
case 367: { nx_value result; if(nx_Legacy_Resources_RegisterCleanup_result(value,&result)) nx_complete_value(w,result); else nx_complete_value(w,nx_reply_error(value)); break; }
default: __builtin_trap(); } } return nx_result(w); }
