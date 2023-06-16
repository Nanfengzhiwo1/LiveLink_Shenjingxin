// Fill out your copyright notice in the Description page of Project Settings.

using System;
using System.IO;
using UnrealBuildTool;
using Console = Internal.Console;

public class OVRLipSyncLibrary : ModuleRules
{
	public const string BinaryOutputDir = "$(BinaryOutputDir)";
	
	public OVRLipSyncLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		string LibraryDirectory = Path.Combine(ModuleDirectory, "lib");

		bool loaded = false;
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicAdditionalLibraries.Add(Path.Combine(LibraryDirectory, "Win64", "OVRLipSyncShim.lib"));
			string apiDll = Path.Combine(LibraryDirectory, "Win64", "OVRLipSync.dll");
			AddDynamicLib(apiDll);
			loaded = true;
		}
		
		else if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			PublicAdditionalLibraries.Add(Path.Combine(LibraryDirectory, "Mac", "libOVRLipSyncShim.a"));
			string apiSo = Path.Combine(LibraryDirectory, "Mac", "libOVRLipSync.dylib");
			AddDynamicLib(apiSo);
			loaded = true;
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			string Android64Directory = Path.Combine(LibraryDirectory, "Android", "arm64-v8a");
			string Android32Directory = Path.Combine(LibraryDirectory, "Android", "armeabi-v7a");
			PublicSystemLibraryPaths.Add(LibraryDirectory);
			PublicSystemLibraryPaths.Add(Android32Directory);
			PublicSystemLibraryPaths.Add(Android64Directory);
			PrivateDependencyModuleNames.Add("AndroidPermission");
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "OVRLipSync_APL.xml"));
			PublicAdditionalLibraries.Add(Path.Combine(Android32Directory, "libOVRLipSyncShim.a"));
			PublicAdditionalLibraries.Add(Path.Combine(Android64Directory, "libOVRLipSyncShim.a"));
			loaded = true;
		}

		if (loaded)
		{
			string DataFolder = Path.Combine(ModuleDirectory, "Data");
			if (Target.Type != TargetType.Editor)
			{
				AddDepFolder(DataFolder);
			}

			PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Include"));
			//PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Include"));
		}
	}
	
	private void AddDynamicLib(string sourceFile)
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
