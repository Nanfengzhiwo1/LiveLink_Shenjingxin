// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class MEDIAPIPELIVELINK_API IMediaPipeLiveLinkModule : public IModuleInterface
{
public:
	static IMediaPipeLiveLinkModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IMediaPipeLiveLinkModule>("MediaPipeLiveLink");
	}

	static bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("MediaPipeLiveLink");
	}
};
