// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "BodyIKControls.generated.h"

USTRUCT(BlueprintType)
struct MEDIAPIPE_API FBodyIKControls
{
	GENERATED_BODY()

	FBodyIKControls(){}
	
	FBodyIKControls(const FBodyIKControls& Other);

	FBodyIKControls(FBodyIKControls&& Other) noexcept;

	FBodyIKControls Inverse() const;

	FBodyIKControls& operator=(const FBodyIKControls& Other);

	FBodyIKControls operator*(const FBodyIKControls& Other) const;
	
	FBodyIKControls& operator=(FBodyIKControls&& Other) noexcept;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform  Pelvis = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform  Spine = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform  Chest = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform  Head = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform  LeftFoot = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform  RightFoot = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform  LeftHand = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform  RightHand = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform  LeftArmPole = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform  RightArmPole = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform  LeftLegPole = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform  RightLegPole = FTransform::Identity;
};
