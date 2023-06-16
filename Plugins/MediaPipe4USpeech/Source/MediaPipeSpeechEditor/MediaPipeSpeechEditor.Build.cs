using UnrealBuildTool;

public class MediaPipeSpeechEditor : ModuleRules
{
    public MediaPipeSpeechEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bUsePrecompiled = true;
        PrecompileForTargets = PrecompileTargetsType.None;
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Engine",
                "Slate",
                "SlateCore",
                "BlueprintGraph",
                "AnimGraph",
                "MediaPipe",
                "MediaPipeEditor",
                "EditorStyle",
                "UnrealEd",
                "WorkspaceMenuStructure",
                "DesktopPlatform",
                "OVRLipSyncLibrary",
                "MediaPipeSpeech", 
            }
        );
    }
}
