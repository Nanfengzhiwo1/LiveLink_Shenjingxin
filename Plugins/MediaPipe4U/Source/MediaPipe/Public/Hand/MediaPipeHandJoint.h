// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "MediaPipeHandJoint.generated.h"

UENUM(BlueprintType)
enum class EMediaPipeHandJoint : uint8
{
	Wrist = 0,
	ThumbCMC = 1,
	ThumbMCP = 2,
	ThumbIP = 3,
	ThumbTIP = 4,
	IndexMCP = 5,
	IndexPIP = 6,
	IndexDIP = 7,
	IndexTIP = 8,
	MiddleMCP = 9,
	MiddlePIP = 10,
	MiddleDIP = 11,
	MiddleTIP = 12,
	RingMCP = 13,
	RingPIP = 14,
	RingDIP = 15,
	RingTIP = 16,
	PinkyMCP = 17,
	PinkyPIP = 18,
	PinkyDIP = 19,
	PinkyTIP = 20,

	Count,
};