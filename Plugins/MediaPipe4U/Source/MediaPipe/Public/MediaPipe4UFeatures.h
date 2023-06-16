// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "PluginEdition.h"

#define DECLARE_FEATURE(FeatureName) \
const static FName FeatureName;

class FMediaPipe4UFeatures
{
public:
	DECLARE_FEATURE(MotionCapture)
	DECLARE_FEATURE(BvhExporter)
	DECLARE_FEATURE(FingerCapture)
	DECLARE_FEATURE(FaceCapture)
	DECLARE_FEATURE(FaceRemotingCapture)
	DECLARE_FEATURE(Speech)
};
