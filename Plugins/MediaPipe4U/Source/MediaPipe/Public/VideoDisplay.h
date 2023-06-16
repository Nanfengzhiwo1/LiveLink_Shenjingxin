// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "VideoDisplay.generated.h"

UENUM(BlueprintType)
enum class EVideoDisplay : uint8
{
	Raw,
	Annotated
};

UENUM(BlueprintType)
enum class EMediaPipeAnnotations : uint8
{
	HolisticTracking,
	PoseTracking,
	FaceTracking
};
