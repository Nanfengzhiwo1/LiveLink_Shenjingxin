// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "ARTrackable.h"

struct MEDIAPIPE_API FFacePostProcessingContext
{
	FFacePostProcessingContext()
	{
		
	}
	FFacePostProcessingContext(const TSharedRef<FARBlendShapeMap>& Values, bool bIsStatic)
	: BlendShapeWeights(Values),
	bStatic(bIsStatic)
	{}
	
	TSharedPtr<FARBlendShapeMap> BlendShapeWeights = nullptr;
	bool bStatic = false;
};
