// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
using UnrealBuildTool;
using System.IO;
using System.Linq;
using Internal;

public class MediaPipe : ModuleRules
{
    public const string BinaryOutputDir = "$(BinaryOutputDir)";

    public MediaPipe(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.NoPCHs; // UseExplicitOrSharedPCHs;
        bUseUnity = false;
        //bUseRTTI = true;
        bEnableUndefinedIdentifierWarnings = false;
        bEnableExceptions = true;
        bUsePrecompiled = true;
        PrecompileForTargets = PrecompileTargetsType.None;

        PublicDependencyModuleNames.AddRange(
                new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "Projects",
                "MediaAssets",
                "UMG", 
                "LiveLinkInterface",
                "LiveLinkAnimationCore", 
                "ControlRig",
                "AugmentedReality",
                }
            );

        
        // AddVcPackage("protobuf", true,
        //     "libprotobuf"
        // );
        
        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "HTTP",
                "InputCore",
                "RHI",
                "AnimationCore",
                "AnimGraphRuntime",
                "RenderCore",
                "MediaAssets",
                "AnimationCore",
                "Slate",
                "SlateCore",
                "UMG",
                "MediapipeAPILibrary",
                "MediapipeCameraAPILibrary",
                "CryptoPP",
                "OpenSSL",
                "Json",
                "JsonUtilities", 
                "IKRig",
                "OpenCV", 
                "OpenCVHelper",
                "Sockets"
            }
        );
        
        
        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(new string[]{ "Settings", "UnrealEd" });
        }

        PublicIncludePaths.AddRange(
            new string[]
            {
                "$(ModuleDir)/Public/Core",
                "$(ModuleDir)/Public/Core/ImageSource",
                "$(ModuleDir)/Public/LiveLink",
                "$(ModuleDir)/Public/Pose",
                "$(ModuleDir)/Public/Hand",
                "$(ModuleDir)/Public/Location",
                "$(ModuleDir)/Public/Core/CppUtils"
            });
        string licenseFolder = Path.Combine(ModuleDirectory, "license");
        AddDepFolder(licenseFolder);
        // protobuf deps
        
        PublicDefinitions.Add("MP_IMPORTS = 1");
        //
        PublicDefinitions.Add("M4U_VER_MAJOR=2022");
        PublicDefinitions.Add("M4U_VER_MINOR=1");
        PublicDefinitions.Add("M4U_VER_REVISION=1");
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
