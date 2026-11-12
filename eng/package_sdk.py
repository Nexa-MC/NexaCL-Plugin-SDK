#!/usr/bin/env python3
"""Package C/Wasm headers, schemas, authoring example and documentation reproducibly."""
import hashlib
import json
from pathlib import Path
import xml.etree.ElementTree as ET
import zipfile
root = Path(__file__).resolve().parents[1]
version = ET.parse(root/'src/Nexa.Plugin.Sdk.Abi100/Nexa.Plugin.Sdk.Abi100.csproj').findtext('.//Version')
files = [(p, 'include/nexa/'+p.name) for p in sorted((root/'sdk/wasm/include/nexa').glob('*.h'))]
files += [(root/p, p) for p in ['contracts/abi100.json', 'contracts/abi100-legacy.json', 'samples/WasmHello/plugin.c', 'samples/WasmWorkflow/plugin.c', 'samples/WasmStateStorage/plugin.c', 'samples/WasmDesktop/plugin.c', 'samples/WasmDesktop/page.nxml', 'docs/wasm-sdk.md', 'LICENSE']]
files += [(root/'sdk/wasm/README.md', 'README.md')]
output = root/'artifacts/packages'/f'Nexa.Plugin.WasmSdk.{version}.zip'
output.parent.mkdir(parents=True, exist_ok=True)
digests={}
with zipfile.ZipFile(output,'w',compression=zipfile.ZIP_DEFLATED) as archive:
    for path, name in files:
        data=path.read_bytes(); digests[name]=hashlib.sha256(data).hexdigest()
        info=zipfile.ZipInfo(name,(1980,1,1,0,0,0)); info.external_attr=0o100644<<16; info.compress_type=zipfile.ZIP_DEFLATED
        archive.writestr(info,data)
    archive.writestr(zipfile.ZipInfo('SHA256.json',(1980,1,1,0,0,0)),json.dumps(digests,sort_keys=True,indent=2)+'\n')
print(output)
