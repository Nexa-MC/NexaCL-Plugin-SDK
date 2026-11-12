#!/usr/bin/env python3
"""Render reviewed behavior notes together with the authoritative ABI catalog."""
import argparse
import json
import re
from pathlib import Path

root = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser()
parser.add_argument('--verify', action='store_true')
args = parser.parse_args()
spec = json.loads((root / 'contracts/abi100.json').read_text(encoding="utf-8"))
support = json.loads((root / 'contracts/host-support.json').read_text(encoding="utf-8"))
notes = json.loads((root / 'eng/reference-notes.json').read_text(encoding="utf-8"))
implemented = {tuple(value) for value in support['implemented']}
catalog = {(group['name'], op['name']) for group in spec['groups'] for op in group['operations']}
if len(implemented) != len(support['implemented']) or not implemented <= catalog:
    raise SystemExit('Host support contains duplicate or unknown operation names.')
if any('hostBinding' in op for group in spec['groups'] for op in group['operations']):
    raise SystemExit('Per-Host status belongs only in host-support.json, not the ABI catalog.')
files = {}

def slug(name):
    return name.lower().replace('.', '-')

def model_link(name):
    base = name.rstrip('?').removesuffix('[]')
    if base.startswith(('Page<', 'Snapshot<')):
        inner = base.split('<', 1)[1][:-1]
        return f'`{name}` ([wrapper](models.md#containers), [item](models/{slug(inner)}.md))'
    if base in spec['models']:
        return f'[`{name}`](models/{slug(base)}.md)'
    if base in spec['enums']:
        return f'[`{name}`](models.md#{slug(base)})'
    return f'`{name}`'

field_notes = {
    'ExpectedRevision': 'Revision observed before this change. Preserve it exactly; a mismatch requires re-reading and reconciling the target.',
    'Revision': 'Opaque version token issued by the owner. Do not increment it or substitute another object’s revision.',
    'LoadInstanceId': 'Identity of the admitted load that owns this handle; it is not portable to a replacement load.',
    'Token': 'Opaque Host-issued handle token. Keep it with its owner and resource type.',
    'Schema': 'Exact schema identity, version and fingerprint used to validate Value.',
    'InputSchema': 'Schema that the producer must use for the operation’s input value.',
    'OutputSchema': 'Schema the consumer uses to validate the successful output value.',
    'ResultSchema': 'Schema for the operation result; inspect operation state before interpreting Result.',
    'ObservedAt': 'Observation timestamp supplied with the snapshot; it does not make a cached value current.',
    'Cursor': 'Opaque continuation or observation cursor. Reuse only in the issuing query/scope; absence and invalidity are different.',
    'NextCursor': 'Continuation for the next page; absence ends this page sequence.',
    'Limit': 'Requested bound on returned items. The Host may impose a smaller domain-specific limit.',
    'DeadlineMilliseconds': 'Requested deadline in milliseconds; queue time consumes this budget and caller deadlines can shorten it.',
    'Handler': 'Callback identifier registered by this plugin. A handler alone is not a public action or provider registration.',
    'Scope': 'Explicit target scope. The Host checks that the caller is authorized for it.',
    'Id': 'Identity in this model’s domain. Use the identity issued or declared for this object, not a display name or filesystem path.',
    'Inputs': 'Typed input value encoded under the declared input schema.',
    'Value': 'Payload interpreted using the accompanying or declared schema; Null is not a substitute for an error.',
    'Result': 'Typed operation output. It is meaningful only when the operation state and result schema permit reading it.',
    'Failure': 'Structured terminal failure, when present. Preserve its identity rather than reporting an empty successful result.',
    'State': 'Current state from the enum or model below; do not infer successful completion from admission alone.',
    'DisplayName': 'User-facing localized label; it is not an authority-bearing identity.',
    'Summary': 'User-facing description of the proposed or observed result; it does not replace the bound target identity.',
    'Confirmation': 'Declared confirmation requirement. The Host owns the prompt and decision.',
    'InputsHash': 'Digest binding a plan to its prepared inputs. Do not replace inputs after review.',
    'Namespace': 'Private storage namespace identity or handle. It remains subject to current-load ownership.',
    'SchemaVersion': 'Version of the declared data schema; independent of SDK and ABI versions.',
    'Key': 'Key within this model’s owning namespace or record. It does not grant access outside that owner.',
    'Permissions': 'Permission names relevant to this descriptor. Declaring them does not grant them.',
    'Capabilities': 'Exact capabilities advertised or required by this descriptor, subject to the Host’s accepted table.',
    'SupportedScopes': 'Scopes the provider declares it can handle; declaration does not authorize every target.',
    'Concurrency': 'Declared execution policy. A provider family may reject enum members whose semantics it does not implement.',
    'FailurePolicy': 'How this provider family reports callback failures; it does not automatically make retries safe.',
    'Configuration': 'Schema for provider configuration, not arbitrary executable Host configuration.',
}
# Context-specific descriptions override broad names.
model_notes = {
    ('PackageFileRequest', 'Path'): 'Normalized relative path of an admitted package payload, for example page.nxml.',
    ('StorageKey', 'Key'): 'Private entry key inside the supplied namespace.',
    ('ProviderDescriptor', 'Kind'): 'Host-supported provider family. Registration succeeds only for a mapped family.',
    ('ProviderDescriptor', 'SchemaHash'): 'Digest of the provider callback envelope schema; current catalog read providers use BusinessProviderCall.',
    ('ProviderDescriptor', 'ContractVersion'): 'Provider contract version; current catalog read-provider callbacks use 100.',
    ('ProviderDescriptor', 'Selection'): 'Selection rule; the current catalog callback boundary supports ExplicitRequest.',
    ('BusinessProviderCall', 'Method'): 'Exact method name from the supported provider family, such as Search.',
    ('BusinessProviderCall', 'Kind'): 'Provider family whose method is being dispatched.',
    ('ScopedTarget', 'Kind'): 'Qualified scope kind accepted by the target service.',
    ('ScopedTarget', 'Entity'): 'Optional entity within that scope; absent is not permission to choose any entity.',
}

def description(model, field):
    name, typ = field['name'], field['type']
    note = model_notes.get((model, name), field_notes.get(name, ''))
    base = typ.removesuffix('?').removesuffix('[]')
    if not note:
        if base in spec['models']:
            note = f'Structured {base} value; follow its linked field contract.'
        elif base in spec['enums']:
            note = 'Use an exact enum member listed in the reference. The Host can support a subset for a particular operation.'
        elif base in ('EntityId', 'QualifiedId', 'Revision'):
            note = 'Identity or revision in this model’s domain; preserve ownership and exact spelling.'
        else:
            note = 'Domain value named by this field; additional accepted values and bounds are determined by the operation and Host policy.'
    if typ.endswith('?'):
        note += ' Nullable; omission is distinct from an empty value. No implicit default is promised by this type.'
    if typ.endswith('[]'):
        note += ' A bounded collection; do not assume an unbounded result or unspecified ordering.'
    return note

def fields_table(model):
    if model not in spec['models']:
        return ''
    fields = spec['models'][model]
    if not fields:
        return 'This model has no fields. Send its encoded empty object, not an arbitrary Null value.\n\n'
    return ('| Field | Type | Meaning |\n| --- | --- | --- |\n' + ''.join(
        f"| `{f['name']}` | {model_link(f['type'])} | {description(model, f)} |\n" for f in fields) + '\n')

index = '''# ABI 100 API reference

Use this reference after building the [first plugin](../quickstart.md). Each group
explains its purpose and normal call sequence, followed by exact operation contracts.
Fields link to their model or enum definitions. Catalog facts are generated;
behavior notes are reviewed source in `eng/reference-notes.json`.

## Read an operation entry

1. Check its recorded Host status and the installed launcher's capabilities.
2. Confirm the exact permission, legal phase and target ownership.
3. Construct the typed request and invocation options.
4. Inspect Success before decoding the result. An OperationRef requires further observation.
5. Handle conflicts, cancellation and resource release using the group guide.

A wrapper does not implement an unavailable operation. SDK-local method IDs are not
transport opcodes. Field types do not imply undocumented defaults or unrestricted
paths. See [models](models.md), [errors](../errors.md), and [Host support](../host-support.md).

| Capability | Contract | Mapped / declared |
| --- | --- | --- |
'''
for group in spec['groups']:
    name = group['name']
    context = notes['groups'][name]
    mapped = sum((name, op['name']) in implemented for op in group['operations'])
    index += f"| [{name}]({slug(name)}.md) | `{group['contractId']}` | {mapped} / {len(group['operations'])} |\n"
    body = f"# {name}\n\n{context['purpose']}\n\nContract: `{group['contractId']}`. [API index](index.md).\n\n## Typical sequence\n\n{context['sequence']}\n\n## Behavior and limits\n\n{context['limits']}\n\nThe recorded Host maps {mapped} of {len(group['operations'])} operations in this group.\nA mapping is subject to permission, phase, scope, platform and business preconditions.\n[Host snapshot](../host-support.md) identifies the source revision; negotiate against\nthe actual installed Host.\n\n## Operations\n\n"
    body += ' · '.join(f"[{o['name']}](#{o['name'].lower()})" for o in group['operations']) + '\n\n'
    for op in group['operations']:
        full = name + '.' + op['name']
        mapped = (name, op['name']) in implemented
        body += f"### {op['name']}\n\n{model_link(op['input'])} → {model_link(op['output'])}\n\n"
        body += '| Property | Contract |\n| --- | --- |\n' + ''.join(f'| {k} | {v} |\n' for k,v in [
            ('Local SDK method ID', f"`{op['methodId']}`"), ('Kind',op['kind']),
            ('Permission',f"`{op['permission']}`"),('Legal phases',', '.join(op['phases'])),
            ('Idempotency',op['idempotency']),('Host status','Mapped in recorded snapshot' if mapped else '**Not mapped in recorded snapshot**')])+'\n'
        if full in notes['operations']:
            body += notes['operations'][full]+'\n\n'
        if not mapped:
            body += 'The recorded Host cannot provide this operation. Keep it optional or require a Host that explicitly implements it; do not return synthetic success.\n\n'
        body += '**Request fields**\n\n'+fields_table(op['input'])
        if op['input'] not in spec['models']:
            body += 'Use the linked request type, including its container or handle ownership rules.\n\n'
        body += '**Successful result**\n\n'
        out=op['output']
        result_notes={
            'OperationRef':'Work has been admitted. Read or watch the owned operation through Tasks to establish its terminal result; admission is not completion.',
            'RegistrationRef':'Retain the registration identity for the permitted update/release operation. Staged registrations become visible only at group activation.',
            'SubscriptionRef':'Retain the subscription identity, consume bounded batches or callbacks as specified, handle gaps, and release it when no longer needed.',
            'MutationPlan':'Retain the exact plan ID and revision, review its bound inputs and confirmation requirement, then use the corresponding commit operation.',
            'Empty':'There is no result payload beyond the encoded Empty model. Check Success; an empty failure value is not successful completion.',
            'BlobRef':'The Host retains bytes under an opaque, owned blob handle. It is not the bytes themselves and is not portable across loads.',
            'FileRef':'An opaque file reference within the granted or package scope. It does not grant access to neighboring files.',
        }
        if out.startswith('Page<'):
            result='Read Items and continue with NextCursor while preserving the original query. An absent cursor ends the sequence; an invalid cursor is an error.'
        elif out.startswith('Snapshot<'):
            result='Read Value together with Revision, SchemaVersion and ObservedAt. Preserve the revision for conditional changes and observation time for freshness.'
        else:
            result=result_notes.get(out,'Decode the exact output model after Success. Preserve its identities, revision and schema metadata for subsequent domain operations.')
        body += result+'\n\n'
        body += '**Failure and retry**\n\n'
        body += 'Unavailable capability, denied permission, wrong phase, malformed schema or foreign ownership fails the call. '
        if op['idempotency']=='RequiredKey':
            body += 'Supply a key for the intended effect and retain that key and inputs while resolving an uncertain reply. Do not retry with changed inputs under the same key. '
        elif op['idempotency']=='OutcomeMayBeUnknown':
            body += 'An interrupted external effect can have an unknown outcome; reconcile before issuing another effect. '
        else:
            body += 'A read-only classification does not bypass budgets or guarantee a failed request can be retried indefinitely. '
        if op['kind'] in ('Mutation','Operation'):
            body += 'Re-read after revision conflicts; cancellation does not prove rollback. '
        body += 'Preserve structured errors; see [recovery guidance](../errors.md).\n\n'
        cname=name.replace('.','_')
        body += f'''**C binding** (call fragment; the caller supplies the encoded request and buffers):

```c
nx_{cname}_{op['name']}(&reply, request, &options);
```

The next resume receives the reply. Check `nx_reply_success` before
`nx_{cname}_{op['name']}_result`. See the [complete continuation example](../tutorials/page-and-action.md)
and [Wasm ownership rules](../wasm-sdk.md). This fragment is not a standalone guest.

'''
    files[f'docs/api/{slug(name)}.md']=body
files['docs/api/index.md']=index
body='''# Models, containers and enumerations

This reference records the exact fields used by generated ABI 100 codecs. A field
without `?` is required by its model; nullable values must be encoded as the model
expects. Empty strings, empty arrays, Null and a failed reply have different meanings.
No unspecified default, numeric bound or filesystem authority should be inferred
from a C# type. Operation/domain policy can impose additional constraints.

## Containers

| Type | Fields | Interpretation |
| --- | --- | --- |
| `Page<T>` | Items, NextCursor, Revision | Bounded result sequence; reuse a cursor only for the same query and owner |
| `Snapshot<T>` | Value, Revision, SchemaVersion, ObservedAt | Value plus exact revision, schema version and observation time |
| `AbiReply<T>` | Success, Value, Error | Read Value only after Success; failure is not an empty successful result |

QualifiedId, EntityId, Revision, FileRef and related handles are not interchangeable.
Schemas include transitive model/enum fingerprints. Codecs reject malformed or oversized
values; passing codec validation does not establish business authorization.

## Enumerations

Enum spelling is part of the wire contract. The presence of a member does not mean
every operation or provider family accepts it. See the operation's behavior notes.

'''
for name,values in spec['enums'].items():
    body+=f"### {name}\n\n"+', '.join(f'`{v}`' for v in values)+'\n\n'
body+='## Model index\n\n| Model | Fields |\n| --- | --- |\n'+''.join(f'| [{n}](models/{slug(n)}.md) | {len(fields)} |\n' for n,fields in spec['models'].items())+'\n'
for name in spec['models']:
    table=fields_table(name).replace('(models/', '(../models/').replace('(models.md', '(../models.md')
    uses=[(g['name'],o['name']) for g in spec['groups'] for o in g['operations'] if name in (o['input'],o['output'])]
    page=f'# {name}\n\n[Model index](../models.md) · [API index](../index.md).\n\n'
    page+='This is the exact wire model. Non-nullable fields are required; field types do not imply undocumented defaults. Domain ownership, bounds and phase checks still apply.\n\n'+table
    if uses:page+='## Used directly by\n\n'+''.join(f'- [{group}.{operation}](../{slug(group)}.md#{operation.lower()})\n' for group,operation in uses)+'\n'
    page+='For nested uses, follow the model links from the owning request or result. A successful decode establishes shape, not permission or business success.\n'
    files[f'docs/api/models/{slug(name)}.md']=page
files['docs/api/models.md']=body
remaining=[g['name']+'.'+o['name'] for g in spec['groups'] for o in g['operations'] if (g['name'],o['name']) not in implemented]
files['docs/host-support.md']=f'''# Host implementation snapshot

Use this page to distinguish a declared SDK operation from an implemented launcher
route. The recorded development Host maps **{len(implemented)}/{sum(len(g['operations']) for g in spec['groups'])}** ABI 100 operations.
**{len(remaining)} operations remain unmapped.**\nSource revision: `{support['hostCommit']}`.

{support['description']}

## What the count means

A mapping still requires permission, legal phase, ownership, supported platform and
business preconditions. It does not promise complete provider families or every
option in a request. The SDK deliberately describes the complete catalog so
compatible Hosts can implement more routes. Older released Alphas can map fewer.

The current custom catalog provider supports seven read methods. Custom catalog
installation and favorites are not implied. Managed Java offers use the additive
multi-file distribution path; the older distribution routes below remain absent.
Production Market delivery is a separate unfinished integration boundary.

## Before requiring a capability

Check the actual Host's negotiated capabilities, then handle per-call unavailability.
Make a nonessential feature optional and explain why its UI is unavailable. Do not
replace a failed operation with a successful empty result or a private implementation
that bypasses Host ownership. Source mappings are recorded in
`contracts/host-support.json`; update them only from implementation evidence.\nThe ABI catalog contains no per-Host status. The retained C/C# descriptor field\n`HostBinding` has the neutral value `HostDefined` for compatibility; it is not\na runtime support flag.

## Unmapped operations

'''+''.join(f'- `{name}`\n' for name in remaining)+'\n[API reference](api/index.md) · [Migration](migration.md)\n'
legacy = json.loads((root / 'contracts/abi100-legacy.json').read_text(encoding='utf-8'))
legacy_body = '''# Retained Nexa preview bindings

These 22 dispatch slots preserve the earlier Nexa Bootstrap/ABI preview contract.
They are unrelated to historical PCL.N.Plugin.* injection plugins. New features
should use the current typed capability operations unless an existing integration
specifically requires a retained slot. Numeric IDs remain local SDK dispatch IDs,
not transport opcodes. The current catalog uses its own non-overlapping IDs.

The C bindings use the `nx_Legacy_*` prefix. Results in this compatibility catalog
are generic AbiValue; use the matching legacy facade's decoder instead of assuming
that a similarly named current method returns the same shape. The current Host
mapping count does not add these slots to the 346-operation catalog.

## Lifecycle and authority

A retained method still requires negotiated access and its documented load scope.
Legacy service ExportService belongs to Initialize, Bind to PostInitialize, Probe
to Checkup and ordinary Call to Active. Finalize cannot add registrations. Cleanup
uses the actual owned handle; do not reinterpret it as a current RegistrationRef.
The event slot 3 is reserved and must not be invoked. Verify legacy integration
against the actual Host rather than assuming namespace compatibility is sufficient.

## Dispatch table

| Family | Contract | Method | ID | Input | Output |
| --- | --- | --- | --- | --- | --- |
'''
for group in legacy['groups']:
    for op in group['operations']:
        legacy_body += f"| {group['name']} | `{group['contractId']}` | {op['name']} | {op['methodId']} | [{op['input']}](#{slug(op['input'])}) | `{op['output']}` |\n"
legacy_body += '\n## Empty\n\nEncode the empty model; it is not an arbitrary Null payload.\n\n'
for name, fields in legacy['models'].items():
    legacy_body += f'## {name}\n\n| Field | Type | Required literal |\n| --- | --- | --- |\n'
    for field in fields:
        legacy_body += f"| `{field['name']}` | `{field['type']}` | {field.get('constant', 'No literal fixed by the catalog')} |\n"
    legacy_body += '\nFields follow the retained facade contract. A raw integer handle remains owner-scoped; a string schema ID must match its digest. Do not substitute a current DTO merely because it contains similar fields.\n\n'
files['docs/api/legacy.md'] = legacy_body
files['docs/api/index.md'] += '\nFor existing Nexa preview integrations, see [the 22 retained bindings](legacy.md). These are separate from the retired PCL injection SDK.\n'
summary = '\n## Gaps by capability group\n\n| Group | Mapped | Missing | Unmapped operations |\n| --- | --- | --- | --- |\n'
for group in spec['groups']:
    missing=[op['name'] for op in group['operations'] if (group['name'],op['name']) not in implemented]
    if missing:
        summary+=f"| {group['name']} | {len(group['operations'])-len(missing)} | {len(missing)} | "+', '.join(f'`{name}`' for name in missing)+' |\n'
files['docs/host-support.md'] = files['docs/host-support.md'].replace('## Unmapped operations', summary.lstrip() + '\n## Unmapped operations')
files['docs/api/resources.md'] += '\n## Why numbering starts at 2\n\nSlot 1 is occupied by the retained Bootstrap-era `RegisterCleanup` in `contracts/abi100-legacy.json`. It is included in the 22 legacy operations, not a twenty-third burned slot. The current typed cleanup operation has ID 2 and must not be renumbered. The additional reserved slot is Events/3; it remains unavailable.\n'
files['docs/api/legacy.md'] += '\n## Reserved versus occupied IDs\n\nResources/1 is the retained cleanup operation listed above. Events/3 is reserved and excluded from the 22 callable legacy operations. A gap is not authority to assign a new operation: published IDs must retain their meaning.\n'
# Keep untranslated technical references explicit, synchronized, and locally linkable.
for name, body in list(files.items()):
    relative = name.removeprefix('docs/')
    files['docs/zh-CN/' + relative] = '> 本页为英文技术参考；字段、编号与支持状态直接来自同一契约源。中文学习路线见 [开发文档](%sindex.md)。\n\n' % ('../' * (len(Path(relative).parts)-1)) + body
for relative in ('wasm-sdk.md', 'runtime-services.md', 'documentation.md'):
    files['docs/zh-CN/' + relative] = '> 本页保留英文技术原文；中文入门与专题见 [开发文档](index.md)。\n\n' + (root / 'docs' / relative).read_text(encoding="utf-8")
for name,body in files.items():
    path=root/name
    if args.verify:
        if not path.exists() or path.read_text(encoding="utf-8")!=body:
            raise SystemExit('Stale API documentation: '+name)
    else:
        path.parent.mkdir(parents=True,exist_ok=True)
        path.write_text(body, encoding="utf-8", newline="\n")
print(f'API documentation {"verified" if args.verify else "generated"}: {len(files)} files')
