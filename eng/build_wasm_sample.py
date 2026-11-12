#!/usr/bin/env python3
"""Build an import-free C guest and deterministic developer ZIP (not a Market grant)."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import zipfile

root = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser()
parser.add_argument('--clang', default='clang')
parser.add_argument('--out', type=Path, default=root / 'artifacts/wasm-sample')
args = parser.parse_args()
args.out.mkdir(parents=True, exist_ok=True)
wasm = args.out / 'plugin.wasm'
subprocess.run([args.clang, '--target=wasm32-unknown-unknown', '-std=c11', '-O2',
                '-Wall', '-Wextra', '-Werror', '-ffreestanding', '-fno-builtin', '-nostdlib',
                '-I', str(root / 'sdk/wasm/include'), str(root / 'samples/WasmHello/plugin.c'),
                '-Wl,--no-entry', '-Wl,--export-memory', '-Wl,--initial-memory=262144',
                '-Wl,--max-memory=524288', '-o', str(wasm)], check=True)
payload = wasm.read_bytes()
manifest = {
    'manifestVersion': 1, 'pluginId': 'example.wasm', 'pluginVersion': '1.0.0',
    'bootstrapVersion': 1, 'entry': {'assembly': '', 'type': ''},
    'target': {'operatingSystems': [], 'architectures': [], 'runtime': 'nexa-wasm-1'},
    'declaredAbiCandidates': [100], 'requiredDependencies': [], 'optionalDependencies': [],
    'conflicts': [], 'requestedPermissions': ['nexa.definitions.write'],
    'requiredCapabilities': [{'contractId': 'nexa.definitions', 'minimumVersion': 1}],
    'optionalCapabilities': [], 'webAssemblyEntryPath': 'plugin.wasm',
    'payloads': [{'path': 'plugin.wasm', 'size': len(payload), 'sha256': hashlib.sha256(payload).hexdigest()}]
}
with zipfile.ZipFile(args.out / 'plugin.zip', 'w', compression=zipfile.ZIP_DEFLATED) as archive:
    for name, data in [('plugin.json', json.dumps(manifest, sort_keys=True, separators=(',', ':')).encode()), ('plugin.wasm', payload)]:
        entry = zipfile.ZipInfo(name, date_time=(1980, 1, 1, 0, 0, 0))
        entry.external_attr = 0o100644 << 16
        archive.writestr(entry, data)
print(args.out / 'plugin.zip')

# Compile every generated SDK call/model, plus the callback lifecycle fixture.
for source, output in [('tests/wasm/conformance.c', 'conformance.wasm'), ('tests/wasm/callback.c', 'callback.wasm'), ('tests/wasm/codec.c', 'codec.wasm')]:
    subprocess.run([args.clang, '--target=wasm32-unknown-unknown', '-std=c11', '-O1', '-Wall', '-Wextra', '-Werror',
                    '-ffreestanding', '-fno-builtin', '-nostdlib', '-I', str(root / 'sdk/wasm/include'), str(root / source),
                    '-Wl,--no-entry', '-Wl,--export-memory', '-Wl,-z,stack-size=131072',
                    '-Wl,--initial-memory=1048576', '-Wl,--max-memory=1048576', '-o', str(args.out / output)], check=True)

# Runnable workflow authoring example: all registrations use the generated SDK.
workflow = args.out / 'workflow.wasm'
subprocess.run([args.clang, '--target=wasm32-unknown-unknown', '-std=c11', '-O2',
                '-Wall', '-Wextra', '-Werror', '-ffreestanding', '-fno-builtin', '-nostdlib',
                '-I', str(root / 'sdk/wasm/include'), str(root / 'samples/WasmWorkflow/plugin.c'),
                '-Wl,--no-entry', '-Wl,--export-memory', '-Wl,-z,stack-size=131072',
                '-Wl,--initial-memory=1048576', '-Wl,--max-memory=1048576', '-o', str(workflow)], check=True)
payload = workflow.read_bytes()
manifest.update(pluginId='example.workflow', webAssemblyEntryPath='workflow.wasm',
    requestedPermissions=['nexa.actions.write', 'nexa.workflows.write', 'nexa.workflows.read',
        'nexa.schedules.write', 'nexa.schedules.read', 'nexa.resources.write'],
    requiredCapabilities=[{'contractId': contract, 'minimumVersion': 1} for contract in
        ['nexa.actions', 'nexa.workflows', 'nexa.schedules', 'nexa.resources']],
    payloads=[{'path': 'workflow.wasm', 'size': len(payload), 'sha256': hashlib.sha256(payload).hexdigest()}])
with zipfile.ZipFile(args.out / 'workflow.zip', 'w', compression=zipfile.ZIP_DEFLATED) as archive:
    for name, data in [('plugin.json', json.dumps(manifest, sort_keys=True, separators=(',', ':')).encode()), ('workflow.wasm', payload)]:
        entry = zipfile.ZipInfo(name, date_time=(1980, 1, 1, 0, 0, 0)); entry.external_attr = 0o100644 << 16
        archive.writestr(entry, data)
print(args.out / 'workflow.zip')

# Desktop vertical slice: a verified package asset, staged page and confirmed action.
desktop = args.out / 'desktop.wasm'
subprocess.run([args.clang, '--target=wasm32-unknown-unknown', '-std=c11', '-O2', '-Wall', '-Wextra', '-Werror',
    '-ffreestanding', '-fno-builtin', '-nostdlib', '-I', str(root / 'sdk/wasm/include'), str(root / 'samples/WasmDesktop/plugin.c'),
    '-Wl,--no-entry', '-Wl,--export-memory', '-Wl,-z,stack-size=131072', '-Wl,--initial-memory=1048576', '-Wl,--max-memory=1048576', '-o', str(desktop)], check=True)
files = {'desktop.wasm': desktop.read_bytes(), 'page.nxml': (root / 'samples/WasmDesktop/page.nxml').read_bytes()}
manifest.update(pluginId='example.desktop', webAssemblyEntryPath='desktop.wasm',
    requestedPermissions=['nexa.files.read','nexa.ui.write','nexa.actions.write','nexa.actions.read','nexa.tasks.read','nexa.minecraft.instances.read','nexa.accounts.read'],
    requiredCapabilities=[{'contractId': c, 'minimumVersion': 1} for c in ['nexa.files','nexa.ui','nexa.actions','nexa.tasks']],
    optionalCapabilities=[{'contractId': c, 'minimumVersion': 1} for c in ['nexa.minecraft.instances','nexa.accounts']],
    payloads=[{'path': name, 'size': len(data), 'sha256': hashlib.sha256(data).hexdigest()} for name,data in files.items()])
files['plugin.json'] = json.dumps(manifest,sort_keys=True,separators=(',',':')).encode()
with zipfile.ZipFile(args.out/'desktop.zip','w',compression=zipfile.ZIP_DEFLATED) as archive:
    for name,data in files.items():
        entry=zipfile.ZipInfo(name,date_time=(1980,1,1,0,0,0));entry.external_attr=0o100644<<16;archive.writestr(entry,data)
print(args.out/'desktop.zip')

# Advanced Desktop UI: a verified package asset, staged page and confirmed action.
desktop = args.out / 'advanced.wasm'
subprocess.run([args.clang, '--target=wasm32-unknown-unknown', '-std=c11', '-O2', '-Wall', '-Wextra', '-Werror',
    '-ffreestanding', '-fno-builtin', '-nostdlib', '-I', str(root / 'sdk/wasm/include'), str(root / 'samples/WasmAdvancedUi/plugin.c'),
    '-Wl,--no-entry', '-Wl,--export-memory', '-Wl,-z,stack-size=131072', '-Wl,--initial-memory=1048576', '-Wl,--max-memory=1048576', '-o', str(desktop)], check=True)
files = {'advanced.wasm': desktop.read_bytes(), 'page.nxml': (root / 'samples/WasmAdvancedUi/page.nxml').read_bytes()}
files['component.nxml'] = (root/'samples/WasmAdvancedUi/component.nxml').read_bytes()
manifest.update(pluginId='example.advanced', webAssemblyEntryPath='advanced.wasm',
    requestedPermissions=['nexa.files.read','nexa.ui.write','nexa.ui.read','nexa.resources.read','nexa.actions.write','nexa.actions.read','nexa.tasks.read','nexa.minecraft.instances.read','nexa.accounts.read'],
    requiredCapabilities=[{'contractId': c, 'minimumVersion': 1} for c in ['nexa.files','nexa.ui','nexa.actions','nexa.tasks','nexa.resources']],
    optionalCapabilities=[{'contractId': c, 'minimumVersion': 1} for c in ['nexa.minecraft.instances','nexa.accounts']],
    payloads=[{'path': name, 'size': len(data), 'sha256': hashlib.sha256(data).hexdigest()} for name,data in files.items()])
files['plugin.json'] = json.dumps(manifest,sort_keys=True,separators=(',',':')).encode()
with zipfile.ZipFile(args.out/'advanced.zip','w',compression=zipfile.ZIP_DEFLATED) as archive:
    for name,data in files.items():
        entry=zipfile.ZipInfo(name,date_time=(1980,1,1,0,0,0));entry.external_attr=0o100644<<16;archive.writestr(entry,data)
print(args.out/'advanced.zip')
