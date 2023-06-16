// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
using UnrealBuildTool;
using System.IO;

public class MediaPipeEditor : ModuleRules
{
    public const string BinaryOutputDir = "$(BinaryOutputDir)";

    public MediaPipeEditor(ReadOnlyTargetRules target) : base(target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bUseUnity = false;
        //bUseRTTI = true;
        bUsePrecompiled = true;
        PrecompileForTargets = PrecompileTargetsType.None;


        PublicDependencyModuleNames.AddRange(
                new string[] {
                    "Core",
                    "Slate",
                    "AnimGraph",
                    "MediaPipe", 
                    "ControlRigDeveloper"
                }
            );

        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "SlateCore",
                "AnimGraph",
                "BlueprintGraph",
                "MediaPipe", 
                "AssetTools",
                "PropertyEditor",
                "UnrealEd", 
                "Persona", 
                "MainFrame",
                "AssetRegistry",
                "EditorStyle",
                "ContentBrowser",
                "DesktopPlatform",
                "Json",
                "JsonUtilities",
                "ControlRig",
                "GraphEditor",
                "InputCore",
                "ToolMenus", 
                "PlacementMode", 
                "WorkspaceMenuStructure",
                "ToolWidgets",
                "MaterialEditor"
                // "EditorFramework",
                // "Kismet",
                // "RigVMDeveloper",
                // "GraphEditor",
                // "ApplicationCore",
                //"ControlRigEditor",
                //"ControlRigDeveloper", 
            }
        );
        
        // if (Target.bBuildEditor)
        // {
        //     PrivateIncludePathModuleNames.Add("ControlRigEditor");
        //     DynamicallyLoadedModuleNames.Add("ControlRigEditor");
        // }


    }

    
}
