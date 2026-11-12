"""Keep complete tutorial examples identical to compiled source files."""
import argparse
import re
from pathlib import Path
root=Path(__file__).resolve().parents[1]
p=argparse.ArgumentParser();p.add_argument('--verify',action='store_true');args=p.parse_args()
pattern=re.compile(r'<!-- example:([^ ]+) language:(\w+) -->.*?<!-- /example -->',re.S)
count=0
for doc in (root/'docs').rglob('*.md'):
 if 'zh-CN' in doc.parts:continue
 original=doc.read_text(encoding="utf-8")
 def replace(match):
  global count
  source=(root/match[1]).resolve()
  if not source.is_relative_to(root) or not source.is_file():raise SystemExit('Invalid example source: '+match[1])
  count+=1
  return f'<!-- example:{match[1]} language:{match[2]} -->\n```{match[2]}\n{source.read_text(encoding="utf-8").rstrip()}\n```\n<!-- /example -->'
 updated=pattern.sub(replace,original)
 if args.verify and updated!=original:raise SystemExit('Stale tutorial example: '+str(doc))
 if not args.verify and updated!=original:doc.write_text(updated, encoding="utf-8", newline="\n")
print(f'Tutorial source examples {"verified" if args.verify else "synchronized"}: {count}')
