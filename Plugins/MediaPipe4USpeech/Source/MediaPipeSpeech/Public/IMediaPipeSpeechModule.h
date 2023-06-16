// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "Modules/ModuleManager.h"
#include "ThirdPartyLibLoader.h"

class MEDIAPIPESPEECH_API IMediaPipeSpeechModule : public IModuleInterface
{
public:
	static IMediaPipeSpeechModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IMediaPipeSpeechModule>("MediaPipeSpeech");
	}
	
	virtual  FThirdPartyLibLoader& GetAPILibrary() = 0;
	virtual  FThirdPartyLibLoader& GetOVRLipSyncLibrary() = 0;
	virtual const FString& GetSpeechWorkDir() = 0;
	virtual const FString& GetOVRLipSyncDataDir() = 0;
};
