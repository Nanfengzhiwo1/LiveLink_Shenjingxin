// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "RotationAngle.generated.h"


UENUM(BlueprintType)
enum class ERotationAngle : uint8
{
	Rotation0,
	Rotation90,
	Rotation180,
	Rotation270,
};

inline int RotationAngleValue(const ERotationAngle RotationAngle)
{
	switch (RotationAngle)
	{
	case ERotationAngle::Rotation0:
		return 0;
	case ERotationAngle::Rotation90:
		return 90;
	case ERotationAngle::Rotation180:
		return 180;
	case ERotationAngle::Rotation270:
		return 270;
	default:
		return 0;
	}
}
