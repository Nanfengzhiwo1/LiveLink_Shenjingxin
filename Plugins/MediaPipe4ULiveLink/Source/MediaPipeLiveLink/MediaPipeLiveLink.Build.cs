// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
using UnrealBuildTool;

public class MediaPipeLiveLink : ModuleRules
{
	public MediaPipeLiveLink(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.NoPCHs;
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
				"CoreUObject",
				"MediaPipe", 
				"LiveLinkInterface",
				"AugmentedReality"
				
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Engine",
				"Slate",
				"SlateCore", 
				"JsonUtilities",
				"InputDevice",
				// "Networking",
				// "Sockets",
				"OSC"
				// ... add private dependencies that you statically link with here ...	
			}
		);
	}
}
