// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "TwistCorrectionSettings.generated.h"

USTRUCT(BlueprintType)
struct MEDIAPIPE_API FTwistCorrectionSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	float WristCorrectAlpha = 0.8f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	float LowerArmCorrectAlpha = 0.15f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	float HeadCorrectAlpha = 0.5f;
};
