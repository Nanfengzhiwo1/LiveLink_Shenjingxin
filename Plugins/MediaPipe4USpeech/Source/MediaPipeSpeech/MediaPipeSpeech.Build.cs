using UnrealBuildTool;

public class MediaPipeSpeech : ModuleRules
{
	public MediaPipeSpeech(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		bUsePrecompiled = true;
		PrecompileForTargets = PrecompileTargetsType.None;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core", 
				"Engine",
				"AudioMixer", 
				"OVRLipSyncLibrary",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Projects",
				// "Slate",
				// "SlateCore",
				"MediaPipe",
				"SpeechAPI",
				"ControlRig",
				"AnimGraphRuntime",
				"OVRLipSyncLibrary",
				// ... add private dependencies that you statically link with here ...	
			}
		);

		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.Add("UnrealEd");
		}
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
		
		PublicIncludePaths.AddRange(
			new string[]
			{
				"$(ModuleDir)/Public/TTS",
				"$(ModuleDir)/Public/Sound",
			});  
		
	}
}
