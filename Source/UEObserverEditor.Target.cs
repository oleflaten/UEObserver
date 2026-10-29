// OEF 2026

using UnrealBuildTool;
using System.Collections.Generic;

public class UEObserverEditorTarget : TargetRules
{
	public UEObserverEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V7;

		ExtraModuleNames.AddRange( new string[] { "UEObserver" } );
	}
}
