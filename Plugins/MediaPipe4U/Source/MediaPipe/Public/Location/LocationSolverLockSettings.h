// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "LocationSolverLockSettings.generated.h"

USTRUCT(BlueprintType)
struct MEDIAPIPE_API FLocationSolverLockSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	bool bLockHorizontalMove = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	bool bLockVerticalMove = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	bool bLockForwardMove = false;
};
