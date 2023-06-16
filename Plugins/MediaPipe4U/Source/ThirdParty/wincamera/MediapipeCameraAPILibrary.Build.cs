// Fill out your copyright notice in the Description page of Project Settings.

using System;
using System.IO;
using UnrealBuildTool;
using Console = Internal.Console;

public class MediapipeCameraAPILibrary : ModuleRules
{
	public const string BinaryOutputDir = "$(BinaryOutputDir)";
	
	public MediapipeCameraAPILibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string apiDll = Path.Combine(ModuleDirectory, "lib", "Win64", "mediapipe4u_win_camera.dll");

			AddDLL(apiDll);
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
