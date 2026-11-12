"""Reject stale API pages, broken local Markdown links and accidental runtime references."""
import json,re,subprocess,sys
from pathlib import Path
root=Path(__file__).resolve().parents[1]
def verify_note_markup(value):
 if isinstance(value, dict):
  for child in value.values():verify_note_markup(child)
 elif isinstance(value, list):
  for child in value:verify_note_markup(child)
 elif isinstance(value, str) and re.search(r'<[A-Za-z][^>]*>', re.sub(r'`[^`]*`', '', value)):
  raise SystemExit('Reference notes must quote generic types and path placeholders as inline code: '+value)
verify_note_markup(json.loads((root/'eng/reference-notes.json').read_text(encoding='utf-8')))
subprocess.run([sys.executable,str(root/'eng/sync_doc_examples.py'),'--verify'],check=True)
subprocess.run([sys.executable,str(root/'eng/generate_docs.py'),'--verify'],check=True)
for path in [*root.glob('*.md'),*(root/'docs').rglob('*.md')]:
 for target in re.findall(r'\]\(([^)]+)\)',path.read_text(encoding="utf-8")):
  target=target.split('#',1)[0]
  if not target or '://' in target or target.startswith('mailto:'):continue
  if not (path.parent/target).exists():raise SystemExit(f'Broken link: {path.relative_to(root)} -> {target}')
for project in (root/'src').rglob('*.csproj'):
 if 'Plugin.Hosting' in project.read_text(encoding="utf-8") or 'PluginSidecar' in project.read_text(encoding="utf-8"):raise SystemExit('Authoring SDK depends on runtime: '+str(project))
print('SDK documentation links and ownership verified.')
