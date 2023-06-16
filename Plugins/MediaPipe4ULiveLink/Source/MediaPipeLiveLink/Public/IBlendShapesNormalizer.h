// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "ARTrackable.h"

class MEDIAPIPELIVELINK_API IBlendShapesNormalizer
{
public:
	virtual ~IBlendShapesNormalizer() = default;
	virtual void PerformCalibration(const FARBlendShapeMap& InValues) = 0;
	virtual void ResetCalibration() = 0;
	virtual void Normalize(FARBlendShapeMap& InOutValues, float GlobalScale = 1.0f) = 0;
};
