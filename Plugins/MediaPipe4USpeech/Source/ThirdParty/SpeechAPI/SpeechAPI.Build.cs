// Fill out your copyright notice in the Description page of Project Settings.

using System;
using System.IO;
using UnrealBuildTool;
using Console = Internal.Console;

public class SpeechAPI : ModuleRules
{
	public const string BinaryOutputDir = "$(BinaryOutputDir)";
	
	public SpeechAPI(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string apiDll = Path.Combine(ModuleDirectory, "lib", "Win64", "speech_api.dll");
			string libiomp5mdDll = Path.Combine(ModuleDirectory, "lib", "Win64", "libiomp5md.dll");
			string mklmlDll = Path.Combine(ModuleDirectory, "lib", "Win64", "mklml.dll");

			AddDLL(apiDll);
			AddDLL(libiomp5mdDll);
			AddDLL(mklmlDll);

			string MPDataDir = Path.Combine(ModuleDirectory, "Data");

			if (Target.Type != TargetType.Editor)
				AddDepFolder(MPDataDir);
		}
	}

	private void AddDLL(string sourceFile)
	{
		string fileName = Path.GetFileName(sourceFile);
		PublicDelayLoadDLLs.Add(fileName);
		string dst = "$(TargetOutputDir)/ThirdParty/" + fileName;
		RuntimeDependencies.Add(dst, sourceFile);
	}

	private void AddDepFolder(string SourceDir)
	{
		foreach (string filePath in Directory.GetFiles(SourceDir, "*.*", SearchOption.AllDirectories))
		{
			string relativePah = Path.GetRelativePath(SourceDir, filePath);
			Console.WriteLine($"Find Speech Module File: {relativePah}");
			string dst = Path.Combine(BinaryOutputDir, relativePah);
			RuntimeDependencies.Add(dst, filePath);
		}
	}
}
