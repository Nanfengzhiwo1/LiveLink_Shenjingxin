// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "CoreMinimal.h"
#include "FingerAxis.h"
#include "MediaPipeHandJoint.h"
#include "FingersSettings.generated.h"

USTRUCT(BlueprintType)
struct FFingersSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="MediaPipe | Hand")
	TMap<EMediaPipeHandJoint, FFingerAxis> RotateAxis;

	FFingerAxis GetAxis(EMediaPipeHandJoint Joint)
	{
		if (RotateAxis.Contains(Joint))
		{
			return RotateAxis[Joint];
		}
		return FFingerAxis::Default;
	}
};
