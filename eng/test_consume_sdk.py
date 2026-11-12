import hashlib,io,json,tempfile,unittest,zipfile
from pathlib import Path
from consume_sdk import checked_files,prepare
class ConsumptionTests(unittest.TestCase):
 def fixture(self,name='packages/example.nupkg'):
  files={name:b'package','sdk-manifest.json':json.dumps({'version':'0.2.0-alpha.10','commit':'a'*40,'repository':'Nexa-MC/NexaCL-Plugin-SDK'}).encode()}
  files['SHA256.json']=json.dumps({n:hashlib.sha256(v).hexdigest() for n,v in files.items()}).encode()
  stream=io.BytesIO()
  with zipfile.ZipFile(stream,'w') as archive:
   for n,v in files.items():archive.writestr(n,v)
  payload=stream.getvalue();return payload,{'version':'0.2.0-alpha.10','commit':'a'*40,'repository':'Nexa-MC/NexaCL-Plugin-SDK','release':'v0.2.0-alpha.10','file':'Nexa.Plugin.Sdk.Bundle.0.2.0-alpha.10.zip','size':len(payload),'sha256':hashlib.sha256(payload).hexdigest()}
 def test_identity_and_digest(self):
  payload,lock=self.fixture();self.assertIn('packages/example.nupkg',checked_files(payload,lock))
  with self.assertRaises(ValueError):checked_files(payload+b'x',lock)
  with self.assertRaises(ValueError):checked_files(payload,{**lock,'commit':'b'*40})
 def test_traversal(self):
  for name in ['../outside','/absolute','packages\\outside','C:/outside']:
   payload,lock=self.fixture(name)
   with self.assertRaises(ValueError):checked_files(payload,lock)
 def test_repair_cache_and_preserve_unowned_directory(self):
  payload,lock=self.fixture()
  with tempfile.TemporaryDirectory() as directory:
   root=Path(directory);bundle=root/'bundle.zip';bundle.write_bytes(payload);pin=root/'lock.json';pin.write_text(json.dumps(lock));cache=root/'cache'
   prepare(pin,cache,bundle);(cache/'packages/example.nupkg').write_bytes(b'changed');prepare(pin,cache,bundle)
   self.assertEqual(b'package',(cache/'packages/example.nupkg').read_bytes())
   unknown=root/'unknown';unknown.mkdir();(unknown/'user.txt').write_text('keep')
   with self.assertRaises(ValueError):prepare(pin,unknown,bundle)
   self.assertEqual('keep',(unknown/'user.txt').read_text())
if __name__=='__main__':unittest.main()
