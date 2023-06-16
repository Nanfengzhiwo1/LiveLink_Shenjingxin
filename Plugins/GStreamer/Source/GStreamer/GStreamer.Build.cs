using System;
using UnrealBuildTool;
using System.IO;
using EpicGames.Core;

public class GStreamer : ModuleRules
{
    public const string BinaryOutputDir = "$(BinaryOutputDir)";
    
    public GStreamer(ReadOnlyTargetRules Target) : base(Target)
    {
        DefaultBuildSettings = BuildSettingsVersion.V2;
        PCHUsage = PCHUsageMode.NoPCHs; // UseExplicitOrSharedPCHs;
        bUseUnity = false;
        bEnableUndefinedIdentifierWarnings = false;
        bUsePrecompiled = true;
        PrecompileForTargets = PrecompileTargetsType.None;

        PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "RHI",
                "RenderCore",
                "Slate",
                "SlateCore"
            }
        );
        
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            var GStreamerRoot = Environment.GetEnvironmentVariable("GSTREAMER_1_0_ROOT_MSVC_X86_64");
            if (string.IsNullOrWhiteSpace(GStreamerRoot))
            {
                GStreamerRoot = Environment.GetEnvironmentVariable("GSTREAMER_ROOT");
            }

            if (string.IsNullOrWhiteSpace(GStreamerRoot))
            {
                Console.WriteLine("Miss GSTREAMER_1_0_ROOT_MSVC_X86_64 or GSTREAMER_ROOT environment variables.");
                return;
            }
            string binPath = Path.Combine(GStreamerRoot, "bin");
            string etcPath = Path.Combine(GStreamerRoot, "etc"); 
            string libPath = Path.Combine(GStreamerRoot, "lib");

            if (!Target.bBuildEditor)
            {
                CopyDirectory(binPath, Path.Combine("gstreamer", "bin"), true);
                CopyDirectory(etcPath, Path.Combine("gstreamer", "etc"), true);
                CopyDirectory(libPath, Path.Combine("gstreamer", "lib"), true);
            }
        
            Console.WriteLine($"GStreamer path: {Environment.NewLine}{GStreamerRoot}");
            //const string GStreamerRoot = @"D:\gstreamer\1.0\msvc_x86_64"; // path to gstreamer development package

            PrivateIncludePaths.Add(Path.Combine(GStreamerRoot, "include"));
            PrivateIncludePaths.Add(Path.Combine(GStreamerRoot, "include", "gstreamer-1.0"));
            PrivateIncludePaths.Add(Path.Combine(GStreamerRoot, "include", "glib-2.0"));
            PrivateIncludePaths.Add(Path.Combine(GStreamerRoot, "lib", "glib-2.0", "include"));

            PublicSystemLibraryPaths.Add(libPath);

            PublicAdditionalLibraries.Add(Path.Combine(libPath, "glib-2.0.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(libPath, "gobject-2.0.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(libPath, "gstreamer-1.0.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(libPath, "gstvideo-1.0.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(libPath, "gstapp-1.0.lib"));

            PublicDelayLoadDLLs.Add("glib-2.0-0.dll");
            PublicDelayLoadDLLs.Add("gobject-2.0-0.dll");
            PublicDelayLoadDLLs.Add("gstreamer-1.0-0.dll");
            PublicDelayLoadDLLs.Add("gstvideo-1.0-0.dll");
            PublicDelayLoadDLLs.Add("gstapp-1.0-0.dll");
        }
    }
    
    private void CopyDirectory(string sourceDir, string destinationDir, bool recursive)
    {
        if (Directory.Exists(sourceDir))
        {
            foreach (string filePath in Directory.GetFiles(sourceDir, "*.*", SearchOption.AllDirectories))
            {
                var ext = Path.GetExtension(filePath);
                if (!ext.Equals(".lib", StringComparison.OrdinalIgnoreCase) 
                    && !ext.Equals(".a", StringComparison.OrdinalIgnoreCase) 
                    && !ext.Equals(".def", StringComparison.OrdinalIgnoreCase)
                    && !ext.Equals(".pdb", StringComparison.OrdinalIgnoreCase)
                    && !ext.Equals(".la", StringComparison.OrdinalIgnoreCase)
                    && !ext.Equals(".so", StringComparison.OrdinalIgnoreCase)
                    && !ext.Equals(".h", StringComparison.OrdinalIgnoreCase))
                {
                    string relativePah = Path.GetRelativePath(sourceDir, filePath);
                    Console.WriteLine($"Find File: {Path.Combine(destinationDir, relativePah)}");
                    string dst = Path.Combine(BinaryOutputDir, destinationDir, relativePah);
                    RuntimeDependencies.Add(dst, filePath);
                }
            }
            
            // Get information about the source directory
            var dir = new DirectoryInfo(sourceDir);
            // If recursive and copying subdirectories, recursively call this method
            if (recursive)
            {
                foreach (DirectoryInfo subDir in dir.GetDirectories())
                {
                    CopyDirectory(subDir.FullName,  Path.Combine(destinationDir, subDir.Name), true);
                }
            }
        }
    }
}
