// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "TwistCorrectionResult.generated.h"

USTRUCT(BlueprintType)
struct FTwistCorrectionResult
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	float ParentTwistAngleRad = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	float TwistAngleRad = 0;
};
