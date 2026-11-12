#!/usr/bin/env python3
"""Generate API reference from the same immutable catalog as the language bindings."""
import argparse
import json
from pathlib import Path
root = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(); parser.add_argument('--verify', action='store_true'); args = parser.parse_args()
spec = json.loads((root/'contracts/abi100.json').read_text())
support = json.loads((root/'contracts/host-support.json').read_text())
implemented = {tuple(v) for v in support['implemented']}
files = {}
index = '# ABI 100 API reference\n\nGenerated from `contracts/abi100.json`. Local method IDs are not transport opcodes.\nSee [model definitions](models.md), [permissions](../permissions.md), and [Host support](../host-support.md).\n\n| Capability | Contract | Operations |\n| --- | --- | --- |\n'
for group in spec['groups']:
 slug = group['name'].lower().replace('.', '-')
 index += f"| [{group['name']}]({slug}.md) | `{group['contractId']}` | {len(group['operations'])} |\n"
 body = f"# {group['name']}\n\nContract: `{group['contractId']}`. [Capability index](index.md).\n\nAll calls return `AbiReply<T>`; inspect success before reading the value.\nThe Host verifies permission, lifecycle phase, ownership and business preconditions.\nMapped status records a development snapshot, not a promise for every released launcher.\n\n"
 for operation in group['operations']:
  label = 'Mapped in recorded Host snapshot' if (group['name'],operation['name']) in implemented else 'Not mapped in recorded Host snapshot'
  body += f"### {operation['name']}\n\n`{operation['input']} -> {operation['output']}`\n\n| Property | Contract |\n| --- | --- |\n| SDK method ID | `{operation['methodId']}` |\n| Kind | {operation['kind']} |\n| Permission | `{operation['permission']}` |\n| Legal phases | {', '.join(operation['phases'])} |\n| Idempotency | {operation['idempotency']} |\n| Host status | {label} |\n\n"
  body += 'Input and output fields are defined in [models](models.md). '
  if operation['idempotency']=='RequiredKey': body += 'Supply a unique idempotency key for a new effect and retain it while checking an uncertain result. '
  if operation['output']=='MutationPlan': body += 'Review the plan and execute its exact ID/revision through the corresponding commit operation. '
  if operation['output']=='OperationRef': body += 'Track the returned operation through Tasks; admission is not completion. '
  if operation['output']=='SubscriptionRef': body += 'Read bounded batches, handle resynchronization and release the subscription before retirement. '
  body += 'Respect cancellation and the caller budget.\n\n'
 files[f'docs/api/{slug}.md'] = body
files['docs/api/index.md'] = index
body = '# ABI 100 models and enumerations\n\nGenerated from the contract catalog. IDs/revisions are opaque. Optional values use `?`;\narrays use `[]`. `Page<T>` carries Items, NextCursor and Revision. `Snapshot<T>` carries\nValue, Revision, SchemaVersion and ObservedAt. Codecs reject malformed or oversized values.\n\n'
for name,values in spec['enums'].items(): body += f"## {name}\n\n"+', '.join(f'`{v}`' for v in values)+'\n\n'
for name,fields in spec['models'].items():
 body += f'## {name}\n\n| Field | Type |\n| --- | --- |\n'
 body += ''.join(f"| `{field['name']}` | `{field['type']}` |\n" for field in fields)+'\n'
files['docs/api/models.md'] = body
remaining=[g['name']+'.'+o['name'] for g in spec['groups'] for o in g['operations'] if (g['name'],o['name']) not in implemented]
files['docs/host-support.md'] = f'''# Host implementation snapshot

{support['description']}

This snapshot maps **{len(implemented)}/{sum(len(g['operations']) for g in spec['groups'])}** ABI 100 operations.
A mapping remains subject to permission, phase, ownership, platform and business
constraints. Source revision: `{support['hostCommit']}`. SDK wrappers deliberately
cover the full proposal so other compatible Hosts can implement their own mappings.

Always negotiate required/optional capabilities and handle unavailable operations.
Consult the launcher's integration document for partial behaviors such as custom
catalog installation, optional installer files and resource budgets. The table is
not a claim that all provider families or production Market delivery are complete.

## Unmapped methods

'''+''.join(f'- `{name}`\n' for name in remaining)+'''\n## 简体中文

以上为开发分支接入快照，不代表所有已发布 Alpha。存在路由仍需满足权限、生命周期、归属、
平台和业务条件。未实现项逐条列出；生产 Market 接入与部分业务语义另有边界。
'''
for name,body in files.items():
 path=root/name
 if args.verify:
  if not path.exists() or path.read_text()!=body: raise SystemExit('Stale API documentation: '+name)
 else:path.parent.mkdir(parents=True,exist_ok=True);path.write_text(body)
print(f'API documentation {"verified" if args.verify else "generated"}: {len(files)} files')
