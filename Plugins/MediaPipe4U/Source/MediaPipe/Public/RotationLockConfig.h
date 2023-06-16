// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "RotationLockConfig.generated.h"

USTRUCT(BlueprintType)
struct MEDIAPIPE_API FRotationLockConfig
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	bool bLockYaw = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	bool bLockRoll = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	bool bLockPitch = false;

	bool HasLock() const
	{
		return bLockYaw || bLockRoll || bLockPitch;
	}
};
