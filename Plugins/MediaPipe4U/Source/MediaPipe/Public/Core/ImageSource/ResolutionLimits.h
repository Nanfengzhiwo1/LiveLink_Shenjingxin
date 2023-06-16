// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

#include "CoreMinimal.h"
#include "ResolutionLimits.generated.h"

UENUM(BlueprintType)
enum class EResolutionLimits : uint8
{
	None,
	P480_16_9,
	P720_16_9,
	P1080_16_9
};
