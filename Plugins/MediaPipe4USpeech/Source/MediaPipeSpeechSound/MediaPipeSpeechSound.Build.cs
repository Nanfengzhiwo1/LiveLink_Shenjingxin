using UnrealBuildTool;

public class MediaPipeSpeechSound : ModuleRules
{
    public MediaPipeSpeechSound(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bUsePrecompiled = true;
        PrecompileForTargets = PrecompileTargetsType.None;
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", 
                "MediaPipeSpeech",
                "MetasoundGraphCore",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore", 
                "MetasoundEngine",
                "MetasoundFrontend"
            }
        );
    }
}
