// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "AnimNode_MediaPipeBase.h"
#include "AnimNode_MediaPipePose.generated.h"

USTRUCT(BlueprintInternalUseOnly)
struct MEDIAPIPE_API  FAnimNode_MediaPipePose : public FAnimNode_MediaPipeBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bLockShoulders = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bLockLegs = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bLockHip = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bLockSpine = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bLockChest = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bLockHead = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bLockHand = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bLockKnee = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bLockFoot = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe|IK", meta = (PinShownByDefault))
	bool bUseLegIK = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe|IK", meta = (PinShownByDefault))
	bool bUseArmIK = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe|IK", meta = (PinShownByDefault))
	bool bOptimize = false;


	
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
protected:
	virtual void EvaluateComponentPose_AnyThread(FComponentSpacePoseContext& Output) override;
	//virtual void EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms) override;
private:
	TWeakPtr<IPoseSolver> PoseSolver;
};
