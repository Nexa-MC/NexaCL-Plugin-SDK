"""Enforce the Beta contract freeze and append-only experimental contracts."""
import argparse
import hashlib
import json
from pathlib import Path, PurePosixPath
import subprocess
import uuid

ROOT = Path(__file__).resolve().parents[1]


def validate(policy, read, previous=None):
    if policy.get('schemaVersion') != 1 or policy.get('abi') != 100:
        raise ValueError('Unknown SDK evolution policy')
    if previous is not None:
        for key in ('schemaVersion', 'baselineVersion', 'abi', 'frozenFiles'):
            if policy.get(key) != previous.get(key):
                raise ValueError('The published Beta baseline cannot be rewritten: ' + key)
    files = policy['frozenFiles']
    if not {'contracts/abi100.json', 'contracts/abi100-legacy.json'} <= files.keys():
        raise ValueError('Missing stable ABI baseline')
    for path, digest in files.items():
        if hashlib.sha256(read(path)).hexdigest() != digest:
            raise ValueError('Frozen contract changed; allocate an EXP_ID instead: ' + path)
    experiments = {}
    contracts = set()
    for item in policy['experiments']:
        identifier = item['expId']
        parsed = uuid.UUID(identifier)
        if str(parsed) != identifier or parsed.int == 0 or identifier in experiments:
            raise ValueError('EXP_ID must be a unique canonical nonzero UUID')
        path = item['schema']
        if path != 'contracts/experiments/' + identifier + '.json':
            raise ValueError('Experiment schema must use its EXP_ID as the filename')
        body = read(path)
        if hashlib.sha256(body).hexdigest() != item['sha256']:
            raise ValueError('Experiment schema fingerprint differs from its registered value')
        schema = json.loads(body)
        contract = schema['contractId']
        if (schema['expId'] != identifier or schema['baseAbi'] != policy['abi']
                or not contract.startswith('nexa.experimental.') or contract in contracts
                or not schema.get('operations') or not schema.get('semantics')):
            raise ValueError('Invalid or duplicate experiment contract')
        if item['status'] not in ('experimental', 'promoted'):
            raise ValueError('An experiment cannot be retired or removed')
        documentation = PurePosixPath(item['documentation'])
        if (documentation.is_absolute() or '..' in documentation.parts
                or not str(documentation).startswith('docs/') or documentation.suffix != '.md'):
            raise ValueError('Experiment documentation must be a local docs Markdown page')
        read(str(documentation))
        experiments[identifier] = item
        contracts.add(contract)
    for old in (previous or {}).get('experiments', []):
        new = experiments.get(old['expId'])
        if new is None:
            raise ValueError('A published EXP_ID cannot be removed')
        if any(new.get(key) != value for key, value in old.items() if key != 'status'):
            raise ValueError('A published EXP_ID cannot change schema or meaning')
        if old['status'] == 'promoted' and new['status'] != 'promoted':
            raise ValueError('A promoted EXP_ID cannot return to experimental')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--base', help='Previous Git revision used to enforce append-only registration')
    args = parser.parse_args()
    policy = json.loads((ROOT / 'contracts/evolution.json').read_text())
    previous = None
    if args.base and set(args.base) != {'0'}:
        # Missing on the first adoption only; an invalid revision is an error.
        subprocess.run(['git', 'rev-parse', '--verify', args.base + '^{commit}'], cwd=ROOT, check=True, stdout=subprocess.DEVNULL)
        path = args.base + ':contracts/evolution.json'
        exists = subprocess.run(['git', 'cat-file', '-e', path], cwd=ROOT, capture_output=True)
        if exists.returncode == 0:
            previous = json.loads(subprocess.check_output(['git', 'show', path], cwd=ROOT))
    validate(policy, lambda path: (ROOT / path).read_bytes(), previous)
    print('Beta ABI baseline and EXP_ID registry verified.')


if __name__ == '__main__':
    main()
