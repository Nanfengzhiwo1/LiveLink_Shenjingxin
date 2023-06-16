// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "CoreMinimal.h"
#include "FingerAxis.generated.h"

USTRUCT()
struct FFingerAxis
{
	GENERATED_BODY()

	FFingerAxis(): Twist(FVector::ZAxisVector), Swing(FVector::YAxisVector) {}

	FFingerAxis(const FVector RotationAxis, const FVector SwingAxis): Twist(RotationAxis), Swing(SwingAxis) {}

	UPROPERTY(EditAnywhere,  Category="MediaPipe | Hand")
	FVector Twist;

	UPROPERTY(EditAnywhere,  Category="MediaPipe | Hand")
	FVector Swing;

	MEDIAPIPE_API static const FFingerAxis Default;
};
