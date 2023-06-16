// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
using UnrealBuildTool;

public class MediaPipeBVH : ModuleRules
{
	public MediaPipeBVH(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.NoPCHs;
		bUsePrecompiled = true;
		PrecompileForTargets = PrecompileTargetsType.None;
		bEnableExceptions = true;
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
				"Engine",
				"MediaPipe", 
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core", 
				"CoreUObject",
				"Engine",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
