// Copyright Epic Games, Inc. All Rights Reserved.
using System;
using System.IO;
using UnrealBuildTool;

public class NvARAPI : ModuleRules
{
	public const string BinaryOutputDir = "$(BinaryOutputDir)";
	
	public NvARAPI(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		string dll = Path.Combine(ModuleDirectory, "lib", "Win64", "nvar-api.dll");
		
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			AddDLL(dll);
		}
	}
	
	private void AddDLL(string sourceFile)
	{
		string fileName = Path.GetFileName(sourceFile);
		PublicDelayLoadDLLs.Add(fileName);
		string dst = "$(TargetOutputDir)/ThirdParty/" + fileName;
		RuntimeDependencies.Add(dst, sourceFile);
	}
}
