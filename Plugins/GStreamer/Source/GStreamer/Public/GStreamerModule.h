#pragma once

#include "Modules/ModuleManager.h"


class GSTREAMER_API IGStreamerModule : public IModuleInterface
{
public:

	static inline IGStreamerModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IGStreamerModule>("GStreamer");
	}

	static inline bool IsAvailable()
	{
		if(FModuleManager::Get().IsModuleLoaded("GStreamer"))
		{
			auto& moduler = FModuleManager::LoadModuleChecked<IGStreamerModule>("GStreamer");
			return moduler.IsGStreamerLoaded();
		}
		return false;
	}

	virtual bool IsGStreamerLoaded() = 0;
	virtual  bool LoadGStreamer() = 0;
};
