// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "ThirdPartyLibLoader.h"
#include "Modules/ModuleManager.h"

class MEDIAPIPENVAR_API IMediaPipeNvARModule: public IModuleInterface
{
public:
	virtual FString SdkFolder() = 0;
	virtual FString ModelFolder() = 0;
	virtual  bool NvARSdkLoaded() = 0;
	virtual FString GetSdkVersion() = 0;
	virtual FThirdPartyLibLoader& GetBridgeLibrary() = 0;
	static IMediaPipeNvARModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IMediaPipeNvARModule>("MediaPipeNvAR");
	}

	static bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("MediaPipeNvAR") &&
			FModuleManager::LoadModuleChecked<IMediaPipeNvARModule>("MediaPipeNvAR").NvARSdkLoaded();
	}
};
