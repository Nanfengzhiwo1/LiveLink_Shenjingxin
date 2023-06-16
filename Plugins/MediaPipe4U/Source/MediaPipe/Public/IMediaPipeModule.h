// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "MediaPipePluginInfo.h"
#include "ThirdPartyLibLoader.h"
#include "Modules/ModuleManager.h"

class MEDIAPIPE_API IMediaPipeModule : public IModuleInterface
{
public:

	static inline IMediaPipeModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IMediaPipeModule>("MediaPipe");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("MediaPipe");
	}
	virtual FString GetLicenseFile() = 0;
	virtual FMediaPipePluginInfo GetPluginInfo() = 0;
	virtual FString GetMediaPipeDataFolder() = 0;
	virtual  void SetLogDebug(bool DEnabled) = 0;
	virtual FThirdPartyLibLoader& GetMediaPipeLibrary() = 0;
	virtual FThirdPartyLibLoader& GetMediaPipeWinCameraLibrary() = 0;
};
