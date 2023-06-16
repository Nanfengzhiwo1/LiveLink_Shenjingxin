// Fill out your copyright notice in the Description page of Project Settings.

using System;
using System.IO;
using UnrealBuildTool;
using Console = Internal.Console;

public class MediapipeAPILibrary : ModuleRules
{
	public const string BinaryOutputDir = "$(BinaryOutputDir)";
	
	public MediapipeAPILibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string apiDll = Path.Combine(ModuleDirectory, "lib", "Win64", "mediapipe_api.dll");

			AddDLL(apiDll);

			string MPDataDir = Path.Combine(ModuleDirectory, "Data");

			if (Target.Type != TargetType.Editor)
				AddDepFolder(MPDataDir);
		}
	}
	
	private void CopyToBinaries(string filepath)
	{
		Console.WriteLine($"Deploy MediaPipe File: {filepath}");
		string binariesDir =  Path.Combine(PluginDirectory, "../../Binaries/Win64");;
		string filename = Path.GetFileName(filepath);

		if (!Directory.Exists(binariesDir))
			Directory.CreateDirectory(binariesDir);
		
		File.Copy(filepath, Path.Combine(binariesDir, filename), true);
	}

	private void CopyDirectory(string sourceDir, string destinationDir, bool recursive)
	{
		// Get information about the source directory
		var dir = new DirectoryInfo(sourceDir);

		// Check if the source directory exists
		if (!dir.Exists)
			throw new DirectoryNotFoundException("Source directory not found");

		// Cache directories before we start copying
		DirectoryInfo[] dirs = dir.GetDirectories();

		// Create the destination directory
		Directory.CreateDirectory(destinationDir);

		// Get the files in the source directory and copy to the destination directory
		foreach (FileInfo file in dir.GetFiles())
		{
			string targetFilePath = Path.Combine(destinationDir, file.Name);
			file.CopyTo(targetFilePath,true);
		}

		// If recursive and copying subdirectories, recursively call this method
		if (recursive)
		{
			foreach (DirectoryInfo subDir in dirs)
			{
				string newDestinationDir = Path.Combine(destinationDir, subDir.Name);
				CopyDirectory(subDir.FullName, newDestinationDir, true);
			}
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
			Console.WriteLine($"Find MediaPipe File: {relativePah}");
			string dst = Path.Combine(BinaryOutputDir, relativePah);
			RuntimeDependencies.Add(dst, filePath);
		}
	}
}
