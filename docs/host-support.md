# Host implementation snapshot

NexaCL development main integration; no new launcher Alpha is implied.

This snapshot maps **297/346** ABI 100 operations.
A mapping remains subject to permission, phase, ownership, platform and business
constraints. Source revision: `195083d163f6569e8e6e9d4389a285e5e7749921`. SDK wrappers deliberately
cover the full proposal so other compatible Hosts can implement their own mappings.

Always negotiate required/optional capabilities and handle unavailable operations.
Consult the launcher's integration document for partial behaviors such as custom
catalog installation, optional installer files and resource budgets. The table is
not a claim that all provider families or production Market delivery are complete.

## Unmapped methods

- `Minecraft.Instances.PrepareClone`
- `Minecraft.Instances.CommitClone`
- `Minecraft.Instances.PrepareDelete`
- `Minecraft.Instances.CommitDelete`
- `Minecraft.Install.ListRecoveries`
- `Minecraft.Install.ResumeRecovery`
- `Minecraft.Install.DiscardRecovery`
- `Minecraft.Install.RegisterTemplate`
- `Minecraft.Install.RegisterLoaderProvider`
- `Minecraft.Java.ListDistributions`
- `Minecraft.Java.PrepareInstall`
- `Minecraft.Java.RegisterDistributionProvider`
- `Minecraft.Launch.RegisterContribution`
- `Minecraft.Launch.RegisterPreflight`
- `Minecraft.Launch.ExplainContribution`
- `Minecraft.Content.ClearTrash`
- `Minecraft.Content.RegisterFormatProvider`
- `Minecraft.Worlds.PlanDelete`
- `Minecraft.Worlds.PreviewRestore`
- `Minecraft.Worlds.Restore`
- `Catalog.RegisterCollection`
- `Catalog.RegisterTranslationProvider`
- `Accounts.SignOut`
- `Accounts.RegisterProvider`
- `Settings.RegisterSchema`
- `Settings.RegisterPage`
- `Settings.Migrate`
- `Themes.MigrateOptions`
- `Themes.ListResources`
- `Themes.ReadResource`
- `Themes.ReleaseResource`
- `Backups.List`
- `Backups.Read`
- `Backups.Statistics`
- `Backups.PrepareCapture`
- `Backups.Capture`
- `Backups.PreviewRestore`
- `Backups.Restore`
- `Backups.VerifyOffline`
- `Backups.Export`
- `Backups.Import`
- `Backups.PreviewPrune`
- `Backups.Prune`
- `Backups.ReadRetention`
- `Backups.SetRetention`
- `Downloads.RegisterSourceResolver`
- `Downloads.RegisterTransferProvider`
- `Tasks.Retry`
- `Minecraft.Diagnostics.RegisterRuleProvider`

## 简体中文

以上为开发分支接入快照，不代表所有已发布 Alpha。存在路由仍需满足权限、生命周期、归属、
平台和业务条件。未实现项逐条列出；生产 Market 接入与部分业务语义另有边界。
