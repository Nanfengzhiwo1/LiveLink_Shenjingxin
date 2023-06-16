// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CameraInfo.generated.h"

USTRUCT(BlueprintType)
struct MEDIAPIPE_API FCameraInfo
{
	GENERATED_BODY()
	
	double HFoV = 90.0f;
	double VFoV = 59.0f;
	double RefDistance = 270; //Distance where the width of shoulders are equal to the avatar width of shoulders in 2D, using this for reference to measure depth //270
	double Distance = RefDistance;
	double DistanceChanges = 0;
	double TargetDistance = RefDistance;
};
