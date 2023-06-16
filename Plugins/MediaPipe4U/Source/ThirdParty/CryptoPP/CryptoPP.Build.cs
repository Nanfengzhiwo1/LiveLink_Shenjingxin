using UnrealBuildTool;
using System.IO;

public class CryptoPP : ModuleRules
{
    public const string BinaryOutputDir = "$(BinaryOutputDir)";

    public CryptoPP(ReadOnlyTargetRules Target) : base(Target)
    {
	    Type = ModuleType.External;
	    string modulePath = ModuleDirectory;
	    if (Target.Platform == UnrealTargetPlatform.Win64)
	    {
		    PublicAdditionalLibraries.Add(Path.Combine(modulePath, "lib", "cryptlib.lib"));
		    PublicIncludePaths.Add(Path.Combine(modulePath, "include"));
	    }
	    
	    bEnableUndefinedIdentifierWarnings = false;
	    bEnableExceptions = true;
	    //bUseRTTI = true;
    }
}
