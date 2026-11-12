# ABI 100 models and enumerations

Generated from the contract catalog. IDs/revisions are opaque. Optional values use `?`;
arrays use `[]`. `Page<T>` carries Items, NextCursor and Revision. `Snapshot<T>` carries
Value, Revision, SchemaVersion and ObservedAt. Codecs reject malformed or oversized values.

## RegistrationState

`Staged`, `Active`, `Retired`

## OperationState

`Pending`, `Running`, `CancellationRequested`, `Completed`, `Failed`, `Cancelled`, `OutcomeUnknown`

## ConfirmationRequirement

`None`, `UserConfirmation`

## CapabilityAvailability

`Supported`, `Unavailable`, `Denied`, `Unsupported`

## IdempotencyMode

`ReadOnly`, `RequiredKey`, `OutcomeMayBeUnknown`

## SelectionPolicy

`UserSelection`, `ObjectOwnership`, `ExplicitRequest`, `ContractPriority`

## MergePolicy

`Add`, `Merge`, `Replace`, `Mask`

## OrderingPolicy

`ExplicitConstraints`, `UserSelection`, `RejectAmbiguity`

## ActivationPolicy

`GroupCommit`

## OwnershipPolicy

`OwnerOnly`, `AuditedOverlay`

## PredicateOutcome

`True`, `False`, `Unknown`, `Error`

## WorkflowNodeKind

`Sequence`, `If`, `Switch`, `ForEach`, `Parallel`, `Action`, `Subflow`, `Delay`, `WaitEvent`, `Retry`, `Try`, `Finally`, `Compensate`, `AskUser`, `Checkpoint`, `Return`, `Fail`

## ConcurrencyPolicy

`Parallel`, `Queue`, `RejectDuplicate`, `ReplacePending`

## ScheduleTrigger

`Interval`, `AtTime`, `Event`

## MissedSchedulePolicy

`Skip`, `Coalesce`, `ReplayBounded`

## DeliveryGuarantee

`BestEffortAtMostOnce`, `AtLeastOnce`

## UIContributionMode

`Append`, `Prepend`, `Wrap`, `Hide`, `Replace`

## DrawCommandKind

`Line`, `Rectangle`, `Ellipse`, `Path`, `Text`, `Image`, `Clip`, `Transform`

## InputEventKind

`Pointer`, `Key`, `Text`, `Focus`

## ProviderFailurePolicy

`Unavailable`, `RetryBounded`, `FailOperation`

## DiagnosticSeverity

`Trace`, `Info`, `Warning`, `Error`

## LaunchArgumentScope

`Jvm`, `Game`

## SignInState

`Pending`, `Challenge`, `Completed`, `Failed`, `Cancelled`

## FilePickKind

`File`, `Directory`, `SaveFile`

## ExtensionMode

`Advisory`, `Required`

## DeletionPolicy

`FreezeReferences`, `RejectWhileReferenced`, `FailSubsequentCalls`

## ParallelCompletion

`All`, `AnySuccess`

## SubscriptionLifetime

`Transient`, `Resumable`

## ReentryPolicy

`Reject`, `Queue`, `AllowBounded`

## Empty

| Field | Type |
| --- | --- |

## TextResult

| Field | Type |
| --- | --- |
| `Text` | `string` |

## BooleanResult

| Field | Type |
| --- | --- |
| `Value` | `bool` |

## PageRequest

| Field | Type |
| --- | --- |
| `Cursor` | `string?` |
| `Limit` | `long` |

## EntityRequest

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |

## QualifiedRequest

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |

## RegistrationRequest

| Field | Type |
| --- | --- |
| `Registration` | `RegistrationRef` |

## WatchRequest

| Field | Type |
| --- | --- |
| `Target` | `EntityId` |
| `Cursor` | `string?` |
| `Schema` | `SchemaRef` |

## SubscriptionRef

| Field | Type |
| --- | --- |
| `Token` | `Guid` |
| `LoadInstanceId` | `Guid` |
| `Cursor` | `string?` |
| `ResyncRequired` | `bool` |

## FileRef

| Field | Type |
| --- | --- |
| `Token` | `Guid` |
| `LoadInstanceId` | `Guid` |
| `Scope` | `string` |

## RootRef

| Field | Type |
| --- | --- |
| `Token` | `Guid` |
| `LoadInstanceId` | `Guid` |

## BlobRef

| Field | Type |
| --- | --- |
| `Token` | `Guid` |
| `LoadInstanceId` | `Guid` |
| `Size` | `long` |
| `Sha256` | `string` |

## CredentialRef

| Field | Type |
| --- | --- |
| `Token` | `Guid` |
| `LoadInstanceId` | `Guid` |
| `Provider` | `QualifiedId` |

## LaunchGrant

| Field | Type |
| --- | --- |
| `Token` | `Guid` |
| `LoadInstanceId` | `Guid` |
| `Account` | `EntityId` |

## SchemaRef

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Version` | `ulong` |
| `Digest` | `string` |

## Reference

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Required` | `bool` |

## NamedValue

| Field | Type |
| --- | --- |
| `Name` | `string` |
| `Value` | `AbiValue` |

## LocalizedText

| Field | Type |
| --- | --- |
| `MessageKey` | `string` |
| `Arguments` | `NamedValue[]` |

## RegistrationRef

| Field | Type |
| --- | --- |
| `Handle` | `ulong` |
| `Owner` | `string` |
| `LoadInstanceId` | `Guid` |
| `DefinitionId` | `QualifiedId` |
| `State` | `RegistrationState` |

## ValidationIssue

| Field | Type |
| --- | --- |
| `Code` | `string` |
| `Message` | `LocalizedText` |
| `Target` | `string` |
| `Fatal` | `bool` |

## ValidationReport

| Field | Type |
| --- | --- |
| `Valid` | `bool` |
| `Issues` | `ValidationIssue[]` |

## MutationPlan

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Revision` | `Revision` |
| `InputsHash` | `string` |
| `Summary` | `LocalizedText` |
| `Confirmation` | `ConfirmationRequirement` |
| `Constraints` | `NamedValue[]` |

## PlanRequest

| Field | Type |
| --- | --- |
| `Plan` | `EntityId` |
| `ExpectedRevision` | `Revision` |
| `ConfirmationToken` | `string?` |

## OperationRef

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `State` | `OperationState` |

## OperationRequest

| Field | Type |
| --- | --- |
| `Operation` | `EntityId` |

## OperationRecord

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `State` | `OperationState` |
| `Progress` | `double` |
| `Stage` | `string` |
| `ResultSchema` | `SchemaRef` |
| `Result` | `AbiValue` |
| `Failure` | `OperationFailure?` |
| `Revision` | `Revision` |

## OperationFailure

| Field | Type |
| --- | --- |
| `Code` | `string` |
| `Message` | `LocalizedText` |
| `CorrelationId` | `Guid` |
| `Retryable` | `bool` |
| `Details` | `NamedValue[]` |

## RetentionPolicy

| Field | Type |
| --- | --- |
| `KeepCount` | `long` |
| `KeepDays` | `long` |
| `MaximumBytes` | `long` |

## ScopedTarget

| Field | Type |
| --- | --- |
| `Kind` | `QualifiedId` |
| `Entity` | `EntityId?` |
| `Scope` | `string` |

## CapabilityDescription

| Field | Type |
| --- | --- |
| `Id` | `string` |
| `Version` | `ulong` |
| `Availability` | `CapabilityAvailability` |
| `Scopes` | `string[]` |
| `Quotas` | `NamedValue[]` |

## PublicContract

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Version` | `ulong` |
| `Schema` | `SchemaRef` |
| `Methods` | `ServiceMethod[]` |

## ServiceMethod

| Field | Type |
| --- | --- |
| `Id` | `ulong` |
| `Name` | `string` |
| `Input` | `SchemaRef` |
| `Output` | `SchemaRef` |
| `Cancellable` | `bool` |
| `Idempotency` | `IdempotencyMode` |
| `NativeExecution` | `bool` |

## ContractQuery

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Version` | `ulong` |

## ProviderKindDefinition

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Contract` | `PublicContract` |
| `Selection` | `SelectionPolicy` |

## ExtensionPointDefinition

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Input` | `SchemaRef` |
| `Output` | `SchemaRef` |
| `Mode` | `ExtensionMode` |
| `DeadlineMilliseconds` | `long` |
| `MergePolicy` | `string` |
| `Ordering` | `OrderingPolicy` |
| `Reentry` | `ReentryPolicy` |
| `AllowedFields` | `string[]` |
| `FailurePolicy` | `ProviderFailurePolicy` |

## ConsumerDefinition

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Contract` | `QualifiedId` |
| `Version` | `ulong` |
| `Handler` | `ulong` |

## SchemaValidationRequest

| Field | Type |
| --- | --- |
| `Schema` | `SchemaRef` |
| `Value` | `AbiValue` |

## CompatibilityRequest

| Field | Type |
| --- | --- |
| `Contract` | `QualifiedId` |
| `Version` | `ulong` |
| `SchemaDigest` | `string` |

## RegistryDescriptor

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Schema` | `SchemaRef` |
| `EntryIdentity` | `string` |
| `ReferenceTypes` | `QualifiedId[]` |
| `MergePolicy` | `MergePolicy` |
| `OrderingPolicy` | `OrderingPolicy` |
| `Activation` | `ActivationPolicy` |
| `Ownership` | `OwnershipPolicy` |
| `SupportedOperations` | `string[]` |
| `ValidationRules` | `QualifiedId[]` |
| `Consumer` | `QualifiedId` |
| `Deletion` | `DeletionPolicy` |
| `MergeContract` | `QualifiedId` |

## Definition

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Registry` | `QualifiedId` |
| `Schema` | `SchemaRef` |
| `Body` | `AbiValue` |
| `References` | `Reference[]` |

## DefinitionBatch

| Field | Type |
| --- | --- |
| `Definitions` | `Definition[]` |

## DefinitionQuery

| Field | Type |
| --- | --- |
| `Registry` | `QualifiedId` |
| `Id` | `QualifiedId` |

## DefinitionSearch

| Field | Type |
| --- | --- |
| `Registry` | `QualifiedId` |
| `Tags` | `QualifiedId[]` |
| `Page` | `PageRequest` |

## DefinitionUpdate

| Field | Type |
| --- | --- |
| `Definition` | `Definition` |
| `ExpectedRevision` | `Revision` |

## DefinitionRemove

| Field | Type |
| --- | --- |
| `Registry` | `QualifiedId` |
| `Id` | `QualifiedId` |
| `ExpectedRevision` | `Revision` |

## TagDefinition

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Registry` | `QualifiedId` |
| `Add` | `QualifiedId[]` |
| `Remove` | `QualifiedId[]` |
| `Include` | `QualifiedId[]` |

## TagResolution

| Field | Type |
| --- | --- |
| `Members` | `QualifiedId[]` |
| `Revision` | `Revision` |

## OverlayDefinition

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Target` | `QualifiedId` |
| `Mode` | `MergePolicy` |
| `Schema` | `SchemaRef` |
| `Patch` | `AbiValue` |
| `Before` | `QualifiedId[]` |
| `After` | `QualifiedId[]` |

## ResolutionReport

| Field | Type |
| --- | --- |
| `Target` | `QualifiedId` |
| `Active` | `bool` |
| `Contributions` | `QualifiedId[]` |
| `Issues` | `ValidationIssue[]` |
| `Revision` | `Revision` |

## PredicateDefinition

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Input` | `SchemaRef` |
| `Handler` | `ulong?` |
| `Expression` | `AbiValue` |

## PredicateRequest

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Inputs` | `AbiValue` |
| `Consistency` | `Revision` |

## PredicateResult

| Field | Type |
| --- | --- |
| `Outcome` | `PredicateOutcome` |
| `InputRevision` | `Revision` |
| `Issues` | `ValidationIssue[]` |

## ActionDescriptor

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Input` | `SchemaRef` |
| `Output` | `SchemaRef` |
| `RequiredCapabilities` | `string[]` |
| `Scopes` | `string[]` |
| `Idempotency` | `IdempotencyMode` |
| `Cancellable` | `bool` |
| `SupportsPreview` | `bool` |
| `Confirmation` | `ConfirmationRequirement` |
| `Compensation` | `QualifiedId?` |
| `Title` | `LocalizedText` |
| `Handler` | `ulong?` |

## ActionRequest

| Field | Type |
| --- | --- |
| `Action` | `QualifiedId` |
| `Target` | `ScopedTarget` |
| `Inputs` | `AbiValue` |
| `ExpectedRevision` | `Revision?` |
| `IdempotencyKey` | `string` |

## WorkflowDefinition

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Input` | `SchemaRef` |
| `Output` | `SchemaRef` |
| `Nodes` | `WorkflowNode[]` |
| `DefinitionDigest` | `string` |
| `Persistent` | `bool` |
| `Concurrency` | `ConcurrencyPolicy` |
| `MaximumDepth` | `long` |
| `MaximumWork` | `long` |

## WorkflowNode

| Field | Type |
| --- | --- |
| `Id` | `string` |
| `Kind` | `WorkflowNodeKind` |
| `Target` | `QualifiedId?` |
| `Inputs` | `AbiValue` |
| `Children` | `WorkflowNode[]` |
| `MaximumConcurrency` | `long` |
| `MaximumAttempts` | `long` |
| `BackoffMilliseconds` | `long` |
| `Completion` | `ParallelCompletion` |
| `RetryableErrors` | `string[]` |
| `InputSchema` | `SchemaRef` |
| `OutputSchema` | `SchemaRef` |

## WorkflowRequest

| Field | Type |
| --- | --- |
| `Workflow` | `QualifiedId` |
| `Inputs` | `AbiValue` |
| `DefinitionDigest` | `string` |

## WorkflowRunRequest

| Field | Type |
| --- | --- |
| `Run` | `EntityId` |
| `ExpectedRevision` | `Revision` |
| `DefinitionDigest` | `string` |

## WorkflowStepRequest

| Field | Type |
| --- | --- |
| `Run` | `EntityId` |
| `StepId` | `string` |
| `ExpectedRevision` | `Revision` |
| `IdempotencyKey` | `string` |

## WorkflowTrace

| Field | Type |
| --- | --- |
| `Run` | `EntityId` |
| `DefinitionDigest` | `string` |
| `Steps` | `WorkflowStep[]` |

## WorkflowStep

| Field | Type |
| --- | --- |
| `Id` | `string` |
| `State` | `OperationState` |
| `SideEffects` | `LocalizedText[]` |
| `Failure` | `OperationFailure?` |

## ScheduleDefinition

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Workflow` | `QualifiedId` |
| `Trigger` | `ScheduleTrigger` |
| `TimeZone` | `string` |
| `At` | `DateTimeOffset?` |
| `IntervalMilliseconds` | `long?` |
| `Event` | `QualifiedId?` |
| `Missed` | `MissedSchedulePolicy` |
| `ReplayLimit` | `long` |
| `DebounceMilliseconds` | `long` |

## ScheduleState

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Enabled` | `bool` |
| `NextRun` | `DateTimeOffset?` |
| `Revision` | `Revision` |

## EventDescriptor

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Schema` | `SchemaRef` |
| `OrderingPartition` | `string` |
| `Delivery` | `DeliveryGuarantee` |
| `Durable` | `bool` |
| `QueueLimit` | `long` |

## EventSubscribeRequest

| Field | Type |
| --- | --- |
| `Event` | `QualifiedId` |
| `Schema` | `SchemaRef` |
| `Cursor` | `string?` |
| `Handler` | `ulong` |
| `IgnoreSelf` | `bool` |
| `Deduplicate` | `bool` |
| `Scope` | `ScopedTarget` |
| `Lifetime` | `SubscriptionLifetime` |
| `Reentry` | `ReentryPolicy` |
| `QueueLimit` | `long` |

## EventEnvelope

| Field | Type |
| --- | --- |
| `EventId` | `Guid` |
| `Event` | `QualifiedId` |
| `Schema` | `SchemaRef` |
| `Entity` | `EntityId?` |
| `Revision` | `Revision` |
| `OccurredAt` | `DateTimeOffset` |
| `CorrelationId` | `Guid` |
| `CausationId` | `Guid?` |
| `Origin` | `string` |
| `Scope` | `ScopedTarget` |
| `Payload` | `AbiValue` |

## StateDescriptor

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Schema` | `SchemaRef` |
| `Scope` | `ScopedTarget` |

## StateReadRequest

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Scope` | `ScopedTarget` |

## StateSnapshot

| Field | Type |
| --- | --- |
| `Value` | `AbiValue` |
| `Schema` | `SchemaRef` |
| `Revision` | `Revision` |
| `ObservedAt` | `DateTimeOffset` |
| `Cursor` | `string?` |

## StateUpdate

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Scope` | `ScopedTarget` |
| `Value` | `AbiValue` |
| `ExpectedRevision` | `Revision` |

## UIPage

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `EntryFile` | `FileRef` |
| `Schema` | `SchemaRef` |
| `Localizations` | `QualifiedId[]` |

## UIComponent

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `EntryFile` | `FileRef` |
| `Parameters` | `SchemaRef` |

## UIContribution

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `View` | `QualifiedId` |
| `SemanticNode` | `string` |
| `Mode` | `UIContributionMode` |
| `Component` | `QualifiedId` |
| `Before` | `QualifiedId[]` |
| `After` | `QualifiedId[]` |

## UIViewReplacement

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `View` | `QualifiedId` |
| `ViewContract` | `SchemaRef` |
| `Page` | `QualifiedId` |

## UIViewContract

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Schema` | `SchemaRef` |
| `Replaceable` | `bool` |
| `RequiredState` | `QualifiedId[]` |
| `RequiredCommands` | `QualifiedId[]` |
| `PublicNodes` | `string[]` |
| `HostControl` | `bool` |

## UINavigation

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Page` | `QualifiedId` |
| `Title` | `LocalizedText` |
| `Icon` | `QualifiedId?` |

## UICommand

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Action` | `QualifiedId` |
| `Title` | `LocalizedText` |

## UIShortcut

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Command` | `QualifiedId` |
| `Gesture` | `string` |
| `Scope` | `QualifiedId` |

## UIDialog

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Page` | `QualifiedId` |
| `Model` | `AbiValue` |

## UIDialogRef

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `ViewScope` | `Guid` |

## UINavigateRequest

| Field | Type |
| --- | --- |
| `Page` | `QualifiedId` |
| `Arguments` | `AbiValue` |

## UINotification

| Field | Type |
| --- | --- |
| `Title` | `LocalizedText` |
| `Body` | `LocalizedText` |
| `Action` | `QualifiedId?` |

## UIModelUpdate

| Field | Type |
| --- | --- |
| `View` | `EntityId` |
| `Schema` | `SchemaRef` |
| `Value` | `AbiValue` |
| `ExpectedRevision` | `Revision?` |

## UIViewWatch

| Field | Type |
| --- | --- |
| `View` | `EntityId` |
| `ViewScope` | `Guid` |
| `Cursor` | `string?` |

## DrawingSurfaceRequest

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Width` | `double` |
| `Height` | `double` |
| `ViewScope` | `Guid` |

## DrawingSurfaceRef

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `ViewScope` | `Guid` |
| `Revision` | `Revision` |

## DrawCommand

| Field | Type |
| --- | --- |
| `Kind` | `DrawCommandKind` |
| `Coordinates` | `double[]` |
| `Color` | `string` |
| `Text` | `string?` |
| `Image` | `BlobRef?` |

## DrawSubmission

| Field | Type |
| --- | --- |
| `Surface` | `DrawingSurfaceRef` |
| `Commands` | `DrawCommand[]` |
| `ExpectedRevision` | `Revision` |

## InputSubscription

| Field | Type |
| --- | --- |
| `Surface` | `DrawingSurfaceRef` |
| `Events` | `InputEventKind[]` |
| `Handler` | `ulong` |

## ProviderDescriptor

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Kind` | `QualifiedId` |
| `ContractVersion` | `ulong` |
| `SchemaHash` | `string` |
| `DisplayName` | `LocalizedText` |
| `Capabilities` | `string[]` |
| `SupportedScopes` | `string[]` |
| `Selection` | `SelectionPolicy` |
| `Concurrency` | `ConcurrencyPolicy` |
| `DeadlineMilliseconds` | `long` |
| `FailurePolicy` | `ProviderFailurePolicy` |
| `Configuration` | `SchemaRef` |
| `Handler` | `ulong` |

## ServiceDefinition

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Contract` | `PublicContract` |
| `Handler` | `ulong` |
| `Probe` | `QualifiedId?` |

## ServiceLookup

| Field | Type |
| --- | --- |
| `Provider` | `string` |
| `Service` | `QualifiedId` |
| `MinimumVersion` | `ulong` |
| `MaximumVersion` | `ulong` |
| `Required` | `bool` |

## ServiceBinding

| Field | Type |
| --- | --- |
| `Handle` | `ulong` |
| `Provider` | `string` |
| `ProviderLoadInstance` | `Guid` |
| `Contract` | `QualifiedId` |
| `Version` | `ulong` |

## ServiceCall

| Field | Type |
| --- | --- |
| `Binding` | `ServiceBinding` |
| `Method` | `ulong` |
| `Input` | `AbiValue` |
| `CallChain` | `Guid[]` |
| `Delegation` | `ScopedTarget?` |

## ServiceProbe

| Field | Type |
| --- | --- |
| `Binding` | `ServiceBinding` |
| `Probe` | `QualifiedId` |
| `Input` | `AbiValue` |

## LoadReport

| Field | Type |
| --- | --- |
| `Plugin` | `string` |
| `LoadInstance` | `Guid` |
| `State` | `string` |
| `Findings` | `ValidationIssue[]` |
| `DependencyChain` | `string[]` |

## DiagnosticReport

| Field | Type |
| --- | --- |
| `Code` | `string` |
| `Message` | `LocalizedText` |
| `Severity` | `DiagnosticSeverity` |
| `CorrelationId` | `Guid` |
| `OperationId` | `Guid?` |

## DiagnosticSpan

| Field | Type |
| --- | --- |
| `Name` | `string` |
| `CorrelationId` | `Guid` |
| `Parent` | `Guid?` |
| `Attributes` | `NamedValue[]` |

## SpanRef

| Field | Type |
| --- | --- |
| `Id` | `Guid` |

## CleanupRequest

| Field | Type |
| --- | --- |
| `Callback` | `ulong` |

## InstanceSummary

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Name` | `string` |
| `GameVersion` | `string` |
| `Loader` | `QualifiedId?` |
| `Root` | `RootRef` |
| `Revision` | `Revision` |

## InstanceDetails

| Field | Type |
| --- | --- |
| `Summary` | `InstanceSummary` |
| `Directory` | `FileRef` |
| `Running` | `bool` |
| `Tags` | `QualifiedId[]` |

## InstanceListRequest

| Field | Type |
| --- | --- |
| `Root` | `RootRef?` |
| `Page` | `PageRequest` |

## RootRequest

| Field | Type |
| --- | --- |
| `Root` | `RootRef` |

## RootRegistration

| Field | Type |
| --- | --- |
| `Root` | `RootRef` |
| `DisplayName` | `string` |

## InstanceCreateRequest

| Field | Type |
| --- | --- |
| `Template` | `QualifiedId` |
| `Name` | `string` |
| `Root` | `RootRef` |
| `GameVersion` | `string` |
| `Loader` | `QualifiedId?` |

## InstanceCloneRequest

| Field | Type |
| --- | --- |
| `Source` | `EntityId` |
| `Name` | `string` |
| `Destination` | `RootRef` |
| `ExpectedRevision` | `Revision` |

## InstanceRenameRequest

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Name` | `string` |
| `ExpectedRevision` | `Revision` |

## InstanceDeleteRequest

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `ExpectedRevision` | `Revision` |
| `RetainUserData` | `bool` |

## EffectiveSetting

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Value` | `AbiValue` |
| `Source` | `string` |
| `Revision` | `Revision` |

## GameVersion

| Field | Type |
| --- | --- |
| `Id` | `string` |
| `Kind` | `string` |
| `ReleasedAt` | `DateTimeOffset` |

## LoaderVersionRequest

| Field | Type |
| --- | --- |
| `Loader` | `QualifiedId` |
| `GameVersion` | `string` |
| `Page` | `PageRequest` |

## LoaderVersion

| Field | Type |
| --- | --- |
| `Loader` | `QualifiedId` |
| `Version` | `string` |
| `GameVersion` | `string` |
| `Stable` | `bool` |

## InstallerInspection

| Field | Type |
| --- | --- |
| `File` | `FileRef` |
| `Loader` | `QualifiedId?` |
| `Version` | `string?` |
| `Issues` | `ValidationIssue[]` |

## InstallDraft

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Instance` | `EntityId` |
| `GameVersion` | `string` |
| `Loaders` | `LoaderVersion[]` |
| `OptionalFiles` | `ResourceVersionRef[]` |
| `Revision` | `Revision` |

## InstallDraftUpdate

| Field | Type |
| --- | --- |
| `Draft` | `InstallDraft` |
| `ExpectedRevision` | `Revision` |

## InstallPlan

| Field | Type |
| --- | --- |
| `Plan` | `MutationPlan` |
| `Instance` | `EntityId` |
| `Steps` | `InstallStep[]` |

## InstallStep

| Field | Type |
| --- | --- |
| `Action` | `QualifiedId` |
| `Inputs` | `AbiValue` |
| `Effects` | `LocalizedText[]` |
| `Reversible` | `bool` |

## RecoveryRecord

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Operation` | `EntityId` |
| `Summary` | `LocalizedText` |
| `Revision` | `Revision` |

## InstallTemplate

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `GameVersion` | `string` |
| `Loaders` | `QualifiedId[]` |
| `Content` | `ResourceVersionRef[]` |
| `Workflow` | `QualifiedId` |

## JavaRuntime

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Version` | `string` |
| `Architecture` | `string` |
| `Vendor` | `string` |
| `File` | `FileRef` |
| `Managed` | `bool` |

## JavaRequirements

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `MinimumMajor` | `long` |
| `MaximumMajor` | `long?` |
| `Architecture` | `string` |

## JavaSelection

| Field | Type |
| --- | --- |
| `Instance` | `EntityId?` |
| `Runtime` | `EntityId?` |
| `VersionLocal` | `bool` |
| `ExpectedRevision` | `Revision?` |

## JavaDistribution

| Field | Type |
| --- | --- |
| `Provider` | `QualifiedId` |
| `Version` | `string` |
| `Architecture` | `string` |
| `OperatingSystem` | `string` |
| `Download` | `DownloadPlan` |

## JavaInstallRequest

| Field | Type |
| --- | --- |
| `Distribution` | `JavaDistribution` |
| `Target` | `RootRef` |

## LaunchProfile

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Name` | `string` |
| `MemoryMiB` | `long` |
| `Java` | `EntityId?` |
| `Width` | `long` |
| `Height` | `long` |
| `Arguments` | `LaunchArgument[]` |
| `Environment` | `NamedValue[]` |
| `Revision` | `Revision` |

## LaunchArgument

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Value` | `string` |
| `Scope` | `LaunchArgumentScope` |

## LaunchProfileWrite

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Profile` | `LaunchProfile` |
| `ExpectedRevision` | `Revision` |

## LaunchProfileSelection

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Profile` | `EntityId` |
| `ExpectedRevision` | `Revision` |

## LaunchIntent

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Grant` | `LaunchGrant` |
| `Profile` | `EntityId` |
| `Target` | `LaunchTarget?` |

## LaunchTarget

| Field | Type |
| --- | --- |
| `Server` | `EntityId?` |
| `World` | `EntityId?` |

## LaunchPlan

| Field | Type |
| --- | --- |
| `Plan` | `MutationPlan` |
| `Instance` | `EntityId` |
| `Profile` | `LaunchProfile` |
| `ProviderVersions` | `NamedValue[]` |
| `Suppressed` | `ValidationIssue[]` |

## LaunchAttempt

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Instance` | `EntityId` |
| `State` | `OperationState` |
| `Session` | `EntityId?` |
| `Issues` | `ValidationIssue[]` |
| `Revision` | `Revision` |

## LaunchContributionRegistration

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Fields` | `string[]` |
| `Handler` | `ulong` |
| `Required` | `bool` |

## LaunchContributionReport

| Field | Type |
| --- | --- |
| `Attempt` | `EntityId` |
| `Accepted` | `QualifiedId[]` |
| `Suppressed` | `ValidationIssue[]` |

## GameSession

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Instance` | `EntityId` |
| `StartedAt` | `DateTimeOffset` |
| `Running` | `bool` |

## LogRangeRequest

| Field | Type |
| --- | --- |
| `Session` | `EntityId` |
| `Cursor` | `string?` |
| `Limit` | `long` |

## LogChunk

| Field | Type |
| --- | --- |
| `Session` | `EntityId` |
| `Lines` | `string[]` |
| `NextCursor` | `string?` |
| `Gap` | `bool` |

## SessionMetrics

| Field | Type |
| --- | --- |
| `Session` | `EntityId` |
| `WorkingSetBytes` | `long` |
| `CpuPercent` | `double` |
| `ObservedAt` | `DateTimeOffset` |

## ContentItem

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Instance` | `EntityId` |
| `Kind` | `QualifiedId` |
| `Name` | `string` |
| `Version` | `ResourceVersionRef?` |
| `Enabled` | `bool` |
| `Revision` | `Revision` |

## ContentQuery

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Kind` | `QualifiedId?` |
| `Page` | `PageRequest` |

## ContentChangeRequest

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Items` | `EntityId[]` |
| `Versions` | `ResourceVersionRef[]` |
| `ExpectedRevision` | `Revision` |

## ContentDependencyGraph

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Nodes` | `ContentItem[]` |
| `Edges` | `ContentDependency[]` |
| `Revision` | `Revision` |

## ContentDependency

| Field | Type |
| --- | --- |
| `From` | `EntityId` |
| `To` | `EntityId` |
| `Required` | `bool` |
| `Conflict` | `bool` |

## ContentPlan

| Field | Type |
| --- | --- |
| `Plan` | `MutationPlan` |
| `Changes` | `ContentItem[]` |
| `Issues` | `ValidationIssue[]` |

## ContentTransaction

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Instance` | `EntityId` |
| `State` | `OperationState` |
| `Plan` | `EntityId` |
| `Revision` | `Revision` |

## IntegrityReport

| Field | Type |
| --- | --- |
| `Target` | `EntityId` |
| `Valid` | `bool` |
| `Issues` | `ValidationIssue[]` |
| `Revision` | `Revision` |

## ContentTransfer

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `File` | `FileRef` |
| `Format` | `QualifiedId` |
| `Selection` | `EntityId[]` |

## WorldSummary

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Instance` | `EntityId` |
| `Name` | `string` |
| `Running` | `bool` |
| `Revision` | `Revision` |

## WorldMetadata

| Field | Type |
| --- | --- |
| `World` | `EntityId` |
| `Format` | `QualifiedId` |
| `Fields` | `NamedValue[]` |

## WorldCopyRequest

| Field | Type |
| --- | --- |
| `World` | `EntityId` |
| `Destination` | `EntityId` |
| `Name` | `string` |
| `ExpectedRevision` | `Revision` |

## WorldRenameRequest

| Field | Type |
| --- | --- |
| `World` | `EntityId` |
| `Name` | `string` |
| `ExpectedRevision` | `Revision` |

## DataPackSelection

| Field | Type |
| --- | --- |
| `World` | `EntityId` |
| `Packs` | `ResourceVersionRef[]` |
| `EnabledOrder` | `QualifiedId[]` |
| `ExpectedRevision` | `Revision` |

## ServerRecord

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Name` | `string` |
| `Address` | `string` |
| `Port` | `long` |

## ServerList

| Field | Type |
| --- | --- |
| `Servers` | `ServerRecord[]` |
| `Revision` | `Revision` |

## ServerStatus

| Field | Type |
| --- | --- |
| `Server` | `EntityId` |
| `Reachable` | `bool` |
| `Description` | `string` |
| `PlayersOnline` | `long` |
| `PlayersMaximum` | `long` |
| `Protocol` | `string` |

## ServerJoinRequest

| Field | Type |
| --- | --- |
| `Server` | `EntityId` |
| `Intent` | `LaunchIntent` |

## ResourceRef

| Field | Type |
| --- | --- |
| `Provider` | `QualifiedId` |
| `ProjectId` | `string` |

## ResourceVersionRef

| Field | Type |
| --- | --- |
| `Resource` | `ResourceRef` |
| `VersionId` | `string` |

## CatalogSearch

| Field | Type |
| --- | --- |
| `Providers` | `QualifiedId[]` |
| `Query` | `string` |
| `Kind` | `QualifiedId?` |
| `GameVersion` | `string?` |
| `Loader` | `QualifiedId?` |
| `Page` | `PageRequest` |

## CatalogProject

| Field | Type |
| --- | --- |
| `Resource` | `ResourceRef` |
| `Name` | `string` |
| `Summary` | `string` |
| `Kind` | `QualifiedId` |
| `Categories` | `QualifiedId[]` |

## CatalogVersionQuery

| Field | Type |
| --- | --- |
| `Resource` | `ResourceRef` |
| `GameVersion` | `string?` |
| `Page` | `PageRequest` |

## CatalogVersion

| Field | Type |
| --- | --- |
| `Version` | `ResourceVersionRef` |
| `Name` | `string` |
| `GameVersions` | `string[]` |
| `Loaders` | `QualifiedId[]` |
| `Files` | `CatalogFile[]` |

## CatalogFile

| Field | Type |
| --- | --- |
| `Name` | `string` |
| `Source` | `UriRef` |
| `Size` | `long` |
| `Sha256` | `string` |

## CatalogDependency

| Field | Type |
| --- | --- |
| `Version` | `ResourceVersionRef` |
| `Required` | `bool` |
| `Conflict` | `bool` |

## FavoriteChange

| Field | Type |
| --- | --- |
| `Resource` | `ResourceRef` |
| `Favorite` | `bool` |
| `ExpectedRevision` | `Revision?` |

## CatalogInstallRequest

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Versions` | `ResourceVersionRef[]` |
| `ExpectedRevision` | `Revision` |

## ResourceCollection

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Resources` | `ResourceRef[]` |
| `Tags` | `QualifiedId[]` |

## AccountPublic

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Provider` | `QualifiedId` |
| `DisplayName` | `string` |
| `Avatar` | `UriRef?` |
| `Revision` | `Revision` |

## SignInRequest

| Field | Type |
| --- | --- |
| `Provider` | `QualifiedId` |
| `Scope` | `string` |

## SignInChallenge

| Field | Type |
| --- | --- |
| `Flow` | `EntityId` |
| `State` | `SignInState` |
| `Prompt` | `LocalizedText` |
| `VerificationUri` | `UriRef?` |
| `UserCode` | `string?` |

## SignInContinue

| Field | Type |
| --- | --- |
| `Flow` | `EntityId` |
| `Response` | `AbiValue` |
| `Schema` | `SchemaRef` |

## LaunchEligibility

| Field | Type |
| --- | --- |
| `Account` | `EntityId` |
| `Allowed` | `bool` |
| `Reasons` | `ValidationIssue[]` |

## GrantRequest

| Field | Type |
| --- | --- |
| `Account` | `EntityId` |
| `Instance` | `EntityId` |

## Wardrobe

| Field | Type |
| --- | --- |
| `Account` | `EntityId` |
| `Skin` | `UriRef?` |
| `Capes` | `Cape[]` |
| `SupportsUpload` | `bool` |

## Cape

| Field | Type |
| --- | --- |
| `Id` | `string` |
| `Title` | `string` |
| `Image` | `UriRef?` |

## SkinRequest

| Field | Type |
| --- | --- |
| `Account` | `EntityId` |
| `Image` | `BlobRef` |
| `Model` | `string` |

## CapeSelection

| Field | Type |
| --- | --- |
| `Account` | `EntityId` |
| `CapeId` | `string?` |

## SettingSchema

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `ValueSchema` | `SchemaRef` |
| `Default` | `AbiValue` |
| `Scopes` | `string[]` |

## SettingQuery

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Target` | `ScopedTarget` |

## SettingChange

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Target` | `ScopedTarget` |
| `Value` | `AbiValue` |
| `ExpectedRevision` | `Revision` |

## SettingMigration

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Target` | `ScopedTarget` |
| `FromVersion` | `ulong` |
| `ToVersion` | `ulong` |
| `Handler` | `ulong` |

## SettingsProfile

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Name` | `string` |
| `Values` | `EffectiveSetting[]` |
| `Revision` | `Revision` |

## SettingsOverlay

| Field | Type |
| --- | --- |
| `Target` | `ScopedTarget` |
| `Values` | `EffectiveSetting[]` |

## ThemeSummary

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Name` | `string` |
| `Version` | `string` |
| `Active` | `bool` |

## ThemePreparation

| Field | Type |
| --- | --- |
| `Theme` | `EntityId` |
| `Plan` | `MutationPlan` |
| `Issues` | `ValidationIssue[]` |

## ThemeOptions

| Field | Type |
| --- | --- |
| `Theme` | `EntityId` |
| `Values` | `NamedValue[]` |
| `Revision` | `Revision` |

## ThemeOptionChange

| Field | Type |
| --- | --- |
| `Options` | `ThemeOptions` |
| `ExpectedRevision` | `Revision` |

## ThemeTransfer

| Field | Type |
| --- | --- |
| `Theme` | `EntityId` |
| `File` | `FileRef` |

## ThemeResource

| Field | Type |
| --- | --- |
| `Theme` | `EntityId` |
| `Name` | `string` |
| `Data` | `BlobRef` |

## BackupSummary

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Instance` | `EntityId` |
| `CreatedAt` | `DateTimeOffset` |
| `Size` | `long` |
| `Revision` | `Revision` |

## BackupStatistics

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Count` | `long` |
| `Bytes` | `long` |

## BackupCapture

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Target` | `FileRef?` |
| `Include` | `QualifiedId[]` |
| `Exclude` | `QualifiedId[]` |

## BackupRestore

| Field | Type |
| --- | --- |
| `Backup` | `EntityId` |
| `Destination` | `EntityId` |
| `ExpectedRevision` | `Revision` |

## BackupTransfer

| Field | Type |
| --- | --- |
| `Backup` | `EntityId?` |
| `File` | `FileRef` |

## BackupPrune

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Retention` | `RetentionPolicy` |
| `ExpectedRevision` | `Revision` |

## BackupRetention

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Policy` | `RetentionPolicy` |
| `ExpectedRevision` | `Revision` |

## DownloadPlan

| Field | Type |
| --- | --- |
| `Sources` | `DownloadSource[]` |
| `Target` | `FileRef` |
| `Size` | `long?` |
| `Sha256` | `string?` |

## DownloadSource

| Field | Type |
| --- | --- |
| `Uri` | `UriRef` |
| `Provider` | `QualifiedId?` |
| `Credential` | `CredentialRef?` |

## DownloadState

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `State` | `OperationState` |
| `BytesReceived` | `long` |
| `TotalBytes` | `long?` |
| `Failures` | `OperationFailure[]` |
| `Revision` | `Revision` |

## TaskCreate

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Title` | `LocalizedText` |
| `Operation` | `EntityId` |
| `Cancellable` | `bool` |

## TaskProgress

| Field | Type |
| --- | --- |
| `Task` | `EntityId` |
| `Stage` | `string` |
| `Progress` | `double` |
| `ExpectedRevision` | `Revision` |

## TaskCompletion

| Field | Type |
| --- | --- |
| `Task` | `EntityId` |
| `Result` | `AbiValue` |
| `Schema` | `SchemaRef` |
| `ExpectedRevision` | `Revision` |

## TaskFailure

| Field | Type |
| --- | --- |
| `Task` | `EntityId` |
| `Error` | `OperationFailure` |
| `ExpectedRevision` | `Revision` |

## NamespaceRequest

| Field | Type |
| --- | --- |
| `Namespace` | `QualifiedId` |
| `SchemaVersion` | `ulong` |

## StorageNamespace

| Field | Type |
| --- | --- |
| `Token` | `Guid` |
| `LoadInstanceId` | `Guid` |
| `Namespace` | `QualifiedId` |
| `Revision` | `Revision` |

## StorageKey

| Field | Type |
| --- | --- |
| `Namespace` | `StorageNamespace` |
| `Key` | `string` |

## StorageValue

| Field | Type |
| --- | --- |
| `Value` | `AbiValue` |
| `Schema` | `SchemaRef` |
| `Revision` | `Revision` |

## StorageWrite

| Field | Type |
| --- | --- |
| `Namespace` | `StorageNamespace` |
| `Key` | `string` |
| `Value` | `AbiValue` |
| `Schema` | `SchemaRef` |
| `ExpectedRevision` | `Revision?` |

## StorageQuery

| Field | Type |
| --- | --- |
| `Namespace` | `StorageNamespace` |
| `Prefix` | `string` |
| `Page` | `PageRequest` |

## StorageTransaction

| Field | Type |
| --- | --- |
| `Token` | `Guid` |
| `Namespace` | `StorageNamespace` |
| `Revision` | `Revision` |

## StorageCommit

| Field | Type |
| --- | --- |
| `Transaction` | `StorageTransaction` |
| `Writes` | `StorageWrite[]` |

## StorageMigration

| Field | Type |
| --- | --- |
| `Namespace` | `StorageNamespace` |
| `FromVersion` | `ulong` |
| `ToVersion` | `ulong` |
| `Action` | `QualifiedId` |

## FilePick

| Field | Type |
| --- | --- |
| `Title` | `LocalizedText` |
| `Kind` | `FilePickKind` |
| `Extensions` | `string[]` |

## FileQuery

| Field | Type |
| --- | --- |
| `Directory` | `FileRef` |
| `Page` | `PageRequest` |

## FileStat

| Field | Type |
| --- | --- |
| `File` | `FileRef` |
| `Name` | `string` |
| `IsDirectory` | `bool` |
| `Size` | `long` |
| `ModifiedAt` | `DateTimeOffset` |
| `Revision` | `Revision` |

## FileRead

| Field | Type |
| --- | --- |
| `File` | `FileRef` |
| `Offset` | `long` |
| `Length` | `long` |

## FileWrite

| Field | Type |
| --- | --- |
| `File` | `FileRef` |
| `Data` | `BlobRef` |
| `ExpectedRevision` | `Revision` |

## FileMove

| Field | Type |
| --- | --- |
| `File` | `FileRef` |
| `Destination` | `FileRef` |
| `ExpectedRevision` | `Revision` |

## FileDelete

| Field | Type |
| --- | --- |
| `File` | `FileRef` |
| `ExpectedRevision` | `Revision` |
| `Recursive` | `bool` |

## NetworkRequest

| Field | Type |
| --- | --- |
| `Uri` | `UriRef` |
| `Method` | `string` |
| `Headers` | `NamedValue[]` |
| `Body` | `BlobRef?` |
| `Credential` | `CredentialRef?` |

## NetworkResponse

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `StatusCode` | `long` |
| `Headers` | `NamedValue[]` |
| `Body` | `BlobRef?` |

## NetworkConnectionRequest

| Field | Type |
| --- | --- |
| `Protocol` | `QualifiedId` |
| `Address` | `string` |
| `Port` | `long` |
| `Scope` | `string` |

## NetworkConnection

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Protocol` | `QualifiedId` |
| `Scope` | `string` |
| `LoadInstanceId` | `Guid` |

## NetworkSend

| Field | Type |
| --- | --- |
| `Connection` | `NetworkConnection` |
| `Data` | `BlobRef` |
| `Destination` | `string?` |

## NetworkReceive

| Field | Type |
| --- | --- |
| `Connection` | `NetworkConnection` |
| `MaximumBytes` | `long` |

## NetworkPacket

| Field | Type |
| --- | --- |
| `Data` | `BlobRef` |
| `Source` | `string?` |
| `EndOfStream` | `bool` |

## PlatformDescription

| Field | Type |
| --- | --- |
| `Capabilities` | `CapabilityDescription[]` |

## ClipboardContent

| Field | Type |
| --- | --- |
| `Text` | `string?` |
| `Image` | `BlobRef?` |

## PowerState

| Field | Type |
| --- | --- |
| `OnBattery` | `bool` |
| `ChargePercent` | `double?` |
| `Saving` | `bool` |

## DisplayInfo

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Width` | `long` |
| `Height` | `long` |
| `Scale` | `double` |

## ArchitectureInfo

| Field | Type |
| --- | --- |
| `OperatingSystem` | `string` |
| `Architecture` | `string` |

## DiagnosticAnalysis

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Reports` | `DiagnosticReport[]` |
| `Issues` | `ValidationIssue[]` |

## RepairRequest

| Field | Type |
| --- | --- |
| `Instance` | `EntityId` |
| `Findings` | `QualifiedId[]` |
| `ExpectedRevision` | `Revision` |

## DeclarativeContentPack

| Field | Type |
| --- | --- |
| `Id` | `QualifiedId` |
| `Schema` | `SchemaRef` |
| `Definitions` | `Definition[]` |

## StorageEntry

| Field | Type |
| --- | --- |
| `Key` | `string` |
| `Value` | `StorageValue` |

## SubscriptionRead

| Field | Type |
| --- | --- |
| `Subscription` | `SubscriptionRef` |
| `Limit` | `long` |

## SubscriptionBatch

| Field | Type |
| --- | --- |
| `Items` | `AbiValue[]` |
| `ResyncRequired` | `bool` |

## PackageFileRequest

| Field | Type |
| --- | --- |
| `Path` | `string` |

## EventSubscriptionRegistration

| Field | Type |
| --- | --- |
| `Registration` | `RegistrationRef` |
| `Subscription` | `SubscriptionRef` |

## ManagedJavaOffer

| Field | Type |
| --- | --- |
| `Id` | `EntityId` |
| `Provider` | `QualifiedId` |
| `Version` | `string` |
| `Platform` | `string` |
| `Files` | `long` |
| `Bytes` | `long` |
| `Licenses` | `UriRef[]` |
| `ExpiresAt` | `DateTimeOffset` |
| `Revision` | `Revision` |

## ManagedJavaInstallRequest

| Field | Type |
| --- | --- |
| `Offer` | `EntityId` |
| `ExpectedRevision` | `Revision` |

## StorageMigrationInput

| Field | Type |
| --- | --- |
| `Namespace` | `QualifiedId` |
| `FromVersion` | `ulong` |
| `ToVersion` | `ulong` |
| `Entries` | `StorageEntry[]` |

## StorageMigrationOutput

| Field | Type |
| --- | --- |
| `Entries` | `StorageEntry[]` |

## BusinessProviderCall

| Field | Type |
| --- | --- |
| `Provider` | `QualifiedId` |
| `Kind` | `QualifiedId` |
| `Method` | `string` |
| `InputSchema` | `SchemaRef` |
| `OutputSchema` | `SchemaRef` |
| `Inputs` | `AbiValue` |

