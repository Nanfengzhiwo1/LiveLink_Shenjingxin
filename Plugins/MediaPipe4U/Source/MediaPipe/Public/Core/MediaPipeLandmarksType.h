// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "MediaPipeLandmarksType.generated.h"

UENUM()
enum class EMediaPipeLandmarksType : uint8
{
	None,
	PoseLandmarks,
	PoseWorldLandmarks,
	LeftHandLandmarks,
	RightHandLandmarks,
	FaceLandmarks,
};
