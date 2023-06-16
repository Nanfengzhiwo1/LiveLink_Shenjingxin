// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "GlobalLipSyncParameters.h"
#include "Misc/LazySingleton.h"

struct FGlobalLipSyncParameters
{
	static FGlobalLipSyncParameters& Get()
	{
		return TLazySingleton<FGlobalLipSyncParameters>::Get();
	}

	float Alpha = 1.0f;

	float BlendScale = 1.2f;

	float MaxDelaySeconds = 0.5;

private:
	FGlobalLipSyncParameters(){}
	friend class FLazySingleton;
};
