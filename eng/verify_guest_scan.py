#!/usr/bin/env python3
"""Execute the freestanding decoder under a real Wasm fuel budget.

Requires wasmtime==39.0.0. No timing thresholds or native signal assumptions.
"""
import argparse
from pathlib import Path
import struct
import random
import subprocess
import tempfile
import wasmtime

root = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser()
parser.add_argument('--clang', default='clang')
args = parser.parse_args()


def mapping(entries):
    return b'\x08' + struct.pack('<I', len(entries)) + b''.join(
        struct.pack('<I', len(key)) + key + value for key, value in entries)


with tempfile.TemporaryDirectory() as temporary:
    wasm = Path(temporary) / 'scan.wasm'
    subprocess.run([args.clang, '--target=wasm32-unknown-unknown', '-std=c11', '-O2',
                    '-Wall', '-Wextra', '-Werror', '-ffreestanding', '-fno-builtin', '-nostdlib',
                    '-I', str(root / 'sdk/wasm/include'), str(root / 'tests/wasm/scan.c'),
                    '-Wl,--no-entry', '-Wl,--export-memory', '-Wl,--initial-memory=4456448',
                    '-o', str(wasm)], check=True)
    config = wasmtime.Config()
    config.consume_fuel = True
    engine = wasmtime.Engine(config)
    module = wasmtime.Module.from_file(engine, str(wasm))

    def run(data, expected=None, reject=False):
        with wasmtime.Store(engine) as store:
            store.set_fuel(10_000_000)
            exports = wasmtime.Instance(store, module, []).exports(store)
            exports['memory'].write(store, data, exports['input'](store))
            try:
                nodes = exports['scan'](store, len(data))
            except wasmtime.Trap as error:
                assert reject and 'fuel' not in str(error), str(error)
                return
            assert not reject, 'Malformed value accepted'
            assert nodes == expected, (nodes, expected)
            assert exports['missing_and_null'](store) == 1
            return 10_000_000 - store.get_fuel()

    # Equal, descending and non-adjacent duplicate keys must all fail.
    for keys in [(b'a', b'a'), (b'b', b'a'), (b'a', b'b', b'a')]:
        run(mapping([(key, b'\0') for key in keys]), reject=True)
    # UTF-16 ordinal differs from UTF-8 lexical order around supplementary text.
    keys = ['', '\0', 'a', 'a\0', '\ud7ff', '\U00010000', '\U0010ffff', '\ue000', '\uffff']
    run(mapping([(key.encode(), b'\0') for key in keys]), len(keys) + 1)
    run(mapping([(key.encode(), b'\0') for key in ['\ue000', '\U00010000']]), reject=True)
    rng = random.Random(100)
    unicode_keys = {""}
    for _ in range(512):
        scalars = [rng.choice([rng.randrange(0xd800), rng.randrange(0xe000, 0x110000)]) for _ in range(rng.randrange(1, 6))]
        unicode_keys.add(''.join(map(chr, scalars)))
    unicode_keys = sorted(unicode_keys, key=lambda key: key.encode('utf-16-be'))
    run(mapping([(key.encode(), b'\0') for key in unicode_keys]), len(unicode_keys) + 1)
    for invalid in [b'\xed\xa0\x80', b'\xc0\x80', b'\xf4\x90\x80\x80', b'\xe2']:
        run(mapping([(invalid, b'\0')]), reject=True)
    run(mapping([(b'a', mapping([(b'b', b'\0'), (b'a', b'\0')]))]), reject=True)
    # All nested nodes count toward the same 16,384-node budget.
    nested = b'\x07\x01\0\0\0\0'
    run(mapping([(f'{i:05}'.encode(), nested) for i in range(8191)]), 16383)
    run(mapping([(f'{i:05}'.encode(), nested) for i in range(8192)]), reject=True)
    fuels = [run(mapping([(f'{i:05}'.encode(), b'\0') for i in range(n)]), n + 1)
             for n in [1024, 2048, 16383]]
    assert fuels[1] < fuels[0] * 2.2, fuels
    print(f'Guest scan checks passed; fuel for 1024/2048/16383 keys: {fuels}')
