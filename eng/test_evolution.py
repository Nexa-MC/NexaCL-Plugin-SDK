import copy
import hashlib
import json
import unittest
from verify_evolution import validate


class EvolutionTests(unittest.TestCase):
    def setUp(self):
        self.files = {'contracts/abi100.json': b'stable', 'contracts/abi100-legacy.json': b'legacy'}
        self.policy = dict(schemaVersion=1, abi=100, baselineVersion='0.2.0-beta.1',
                           frozenFiles={p: hashlib.sha256(b).hexdigest() for p, b in self.files.items()}, experiments=[])

    def add_experiment(self):
        identifier = '3cfaa786-a376-4c64-bd2b-6de818638a73'
        path = 'contracts/experiments/' + identifier + '.json'
        self.files[path] = json.dumps(dict(expId=identifier, baseAbi=100, contractId='nexa.experimental.example/1',
                                         operations=[{'id': 1}], semantics='Test fixture only')).encode()
        self.files['docs/example.md'] = b'Example'
        self.policy['experiments'].append(dict(expId=identifier, schema=path,
            sha256=hashlib.sha256(self.files[path]).hexdigest(), status='experimental', documentation='docs/example.md'))

    def test_stable_baseline_and_additive_experiment(self):
        previous = copy.deepcopy(self.policy)
        validate(self.policy, self.files.__getitem__)
        self.add_experiment()
        validate(self.policy, self.files.__getitem__, previous)

    def test_contract_change_and_baseline_rewrite_are_rejected(self):
        previous = copy.deepcopy(self.policy)
        self.files['contracts/abi100.json'] = b'changed'
        with self.assertRaisesRegex(ValueError, 'Frozen contract'):
            validate(self.policy, self.files.__getitem__)
        self.policy['frozenFiles']['contracts/abi100.json'] = hashlib.sha256(b'changed').hexdigest()
        with self.assertRaisesRegex(ValueError, 'cannot be rewritten'):
            validate(self.policy, self.files.__getitem__, previous)

    def test_existing_experiment_cannot_disappear_or_change(self):
        self.add_experiment()
        previous = copy.deepcopy(self.policy)
        self.policy['experiments'] = []
        with self.assertRaisesRegex(ValueError, 'cannot be removed'):
            validate(self.policy, self.files.__getitem__, previous)
        self.policy = copy.deepcopy(previous)
        item = self.policy['experiments'][0]
        self.files[item['schema']] += b' '
        item['sha256'] = hashlib.sha256(self.files[item['schema']]).hexdigest()
        with self.assertRaisesRegex(ValueError, 'cannot change'):
            validate(self.policy, self.files.__getitem__, previous)

    def test_promotion_keeps_old_contract(self):
        self.add_experiment()
        previous = copy.deepcopy(self.policy)
        self.policy['experiments'][0]['status'] = 'promoted'
        validate(self.policy, self.files.__getitem__, previous)
        with self.assertRaisesRegex(ValueError, 'cannot return'):
            validate(previous, self.files.__getitem__, self.policy)


if __name__ == '__main__':
    unittest.main()
