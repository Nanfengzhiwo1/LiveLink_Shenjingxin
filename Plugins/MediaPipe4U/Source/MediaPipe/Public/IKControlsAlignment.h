// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IPoseSolver.h"
#include "Animation/AnimTypes.h"
#include "MediaPipePoseJoint.h"
#include "IKControlsAlignment.generated.h"

USTRUCT(BlueprintType)
struct FControlAlignment
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform InitCSTransform = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FTransform InitLocalTransform = FTransform::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	bool bIsLoaded = false;

	FTransform GetInitTransform(EBoneControlSpace Space) const;
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct MEDIAPIPE_API FIKControlsAlignment
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FControlAlignment Pelvis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FControlAlignment Spine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FControlAlignment Chest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FControlAlignment Head;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FControlAlignment LeftFoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FControlAlignment RightFoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FControlAlignment LeftHand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FControlAlignment RightHand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FControlAlignment LeftArmPole;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FControlAlignment RightArmPole;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FControlAlignment LeftLegPole;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FControlAlignment RightLegPole;

	void Reset();
	
	bool AlignAllControls(const TWeakPtr<IPoseSolver>& PoseSolver);
	FTransform GetIKControlOffset(EMediaPipePoseJoint IKJoint, EBoneControlSpace Space) const;
private:
	TMap<EMediaPipePoseJoint, FTransform> GlobalControlOffsets;
	TMap<EMediaPipePoseJoint, FTransform> LocalControlOffsets;
};
