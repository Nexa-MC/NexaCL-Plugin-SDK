#!/usr/bin/env python3
"""Bundle the two authoring packages with exact public SDK sources and documentation."""
import hashlib,json,subprocess,zipfile
from pathlib import Path
import xml.etree.ElementTree as ET
root=Path(__file__).resolve().parents[1]
version=ET.parse(root/'src/Nexa.Plugin.Sdk.Abi100/Nexa.Plugin.Sdk.Abi100.csproj').findtext('.//Version')
commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip()
files={}
for name in ['Nexa.Plugin.Bootstrap.V1','Nexa.Plugin.Sdk.Abi100']:
 path=root/'artifacts/packages'/f'{name}.{version}.nupkg';files['packages/'+path.name]=path.read_bytes()
for name in ['src','contracts','sdk','samples','tests','docs','eng']:
 for path in sorted((root/name).rglob('*')):
  if path.is_file() and not any(p in {'bin','obj','__pycache__'} for p in path.relative_to(root).parts):files[path.relative_to(root).as_posix()]=path.read_bytes()
for name in ['README.md','README.zh-CN.md','LICENSE','SECURITY.md','CONTRIBUTING.md','CONTRIBUTING.zh-CN.md','Directory.Build.props','global.json','NuGet.Config','NexaCL-Plugin-SDK.slnx']:
 files[name]=(root/name).read_bytes()
files['sdk-manifest.json']=(json.dumps({'version':version,'commit':commit,'repository':'Nexa-MC/NexaCL-Plugin-SDK','packages':[f'{name}.{version}.nupkg' for name in ['Nexa.Plugin.Bootstrap.V1','Nexa.Plugin.Sdk.Abi100']]},indent=2)+'\n').encode()
files['SHA256.json']=(json.dumps({name:hashlib.sha256(data).hexdigest() for name,data in sorted(files.items())},indent=2)+'\n').encode()
output=root/'artifacts/packages'/f'Nexa.Plugin.Sdk.Bundle.{version}.zip'
with zipfile.ZipFile(output,'w',compression=zipfile.ZIP_DEFLATED) as archive:
 for name,data in sorted(files.items()):
  info=zipfile.ZipInfo(name,(1980,1,1,0,0,0));info.external_attr=0o100644<<16;info.compress_type=zipfile.ZIP_DEFLATED;archive.writestr(info,data)
release={'repository':'Nexa-MC/NexaCL-Plugin-SDK','commit':commit,'version':version,'release':'v'+version,'file':output.name,'size':output.stat().st_size,'sha256':hashlib.sha256(output.read_bytes()).hexdigest()}
(root/'artifacts/packages/sdk.release.json').write_text(json.dumps(release,indent=2)+'\n')
print(output)
