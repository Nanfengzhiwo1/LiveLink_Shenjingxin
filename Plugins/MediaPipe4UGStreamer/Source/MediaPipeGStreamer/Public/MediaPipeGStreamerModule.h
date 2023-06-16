// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FMediaPipeGStreamerModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
