// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "ForwardAndUpward.generated.h"


UENUM(BlueprintType)
enum class ForwardAxis : uint8
{
	ZX,
	XZ,
	ZY,
	YZ,
	XY,
	YX,
};

USTRUCT(BlueprintType)
struct MEDIAPIPE_API FForwardAndUpward
{
	GENERATED_BODY()
	
	FVector Forward;
	FVector Upward;
	ForwardAxis Axis;

	FForwardAndUpward(FVector forward, FVector upward, ForwardAxis axis) : Forward(forward), Upward(upward), Axis(axis){}

	FForwardAndUpward(FVector forward, FVector upward) : Forward(forward), Upward(upward), Axis(ForwardAxis::ZX){}

	FForwardAndUpward() : Forward(FVector::ForwardVector), Upward(FVector::UpVector), Axis(ForwardAxis::ZX){}

	void Normalize()
	{
		Forward.Normalize();
		Upward.Normalize();
	}

	FVector GetCross() const;

	FForwardAndUpward Inverse() const;

	FQuat Rotator() const;
	
	FQuat InverseRotator() const;

	static const FForwardAndUpward Identity;
};

