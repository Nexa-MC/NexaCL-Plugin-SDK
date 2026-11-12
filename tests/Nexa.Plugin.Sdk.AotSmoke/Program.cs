using Nexa.Plugin.Sdk.Abi100;
using Nexa.Plugin.Sdk.Abi100.Data;
var resource = new ResourceRef(new("example:catalog"), "project");
var project = new CatalogProject(resource, "Project", "Summary", new("nexa:resource/mod"), []);
var page = new Page<CatalogProject>([project], null, new("revision"));
var encoded = Page<CatalogProject>.Write(page);
if (!Abi100Schemas.Validate(Abi100Schemas.PageOfCatalogProject, encoded)) throw new InvalidOperationException("Page schema rejected");
var decoded = Page<CatalogProject>.Read(encoded);
if (decoded.Items.Length != 1 || decoded.Items[0].Resource != resource || decoded.Items[0].Name != project.Name
    || !decoded.Items[0].Categories.IsEmpty || decoded.Revision != page.Revision) throw new InvalidOperationException("Typed round trip changed fields");
if (Abi100Schemas.Validate(Abi100Schemas.CatalogVersion, encoded)) throw new InvalidOperationException("Wrong schema accepted");
if (Abi100Catalog.Operations.Length != 346) throw new InvalidOperationException("Operation catalog changed");
Console.WriteLine("PASS: standalone SDK NativeAOT schema dispatch and typed collection codecs.");
