// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CurveSmoothParams.generated.h"

USTRUCT(BlueprintType)
struct MEDIAPIPE_API FCurveSmoothParams
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category="NvAR")
	int Iterations = 5;

	UPROPERTY(EditAnywhere, Category="NvAR")
	float Smooth = 0.4f;
};
