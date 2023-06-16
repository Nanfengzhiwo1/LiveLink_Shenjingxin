// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "RotationLockConfig.h"

#include "PoseSolverLockSettings.generated.h"

USTRUCT(BlueprintType)
struct FPoseSolverLockSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	bool bIsLockShoulders = false;
	UPROPERTY(EditAnywhere, Category="MediaPipe")
	bool bIsLockLegs = false;
	UPROPERTY(EditAnywhere, Category="MediaPipe")
	bool bIsLockKnee = false;
	UPROPERTY(EditAnywhere, Category="MediaPipe")
	bool bIsLockFoot = false;
	UPROPERTY(EditAnywhere, Category="MediaPipe")
	bool bIsLockHip = false;
	UPROPERTY(EditAnywhere, Category="MediaPipe")
	bool bIsLockSpine = false;
	UPROPERTY(EditAnywhere, Category="MediaPipe")
	bool bIsLockChest = false;
	UPROPERTY(EditAnywhere, Category="MediaPipe")
	bool bIsLockHead = false;
	UPROPERTY(EditAnywhere, Category="MediaPipe")
	bool bIsLockHand = false;

	UPROPERTY(EditAnywhere, Category="MediaPipe|Advance")
	FRotationLockConfig SpineLock;
	UPROPERTY(EditAnywhere, Category="MediaPipe|Advance")
	FRotationLockConfig HipLock;
};
