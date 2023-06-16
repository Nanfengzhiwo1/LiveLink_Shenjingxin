// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CalibrationPolicy.generated.h"

UENUM(BlueprintType)
enum class  ECalibrationPolicy : uint8
{
	AlwaysOnStart,
	OneTime,
	Manual
};
