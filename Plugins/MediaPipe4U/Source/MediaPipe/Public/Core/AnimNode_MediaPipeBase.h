// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "MediaPipeAnimInstance.h"
#include "MediaPipeLandmarksType.h"
#include "MediaPipeSource.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "AnimNode_MediaPipeBase.generated.h"

/**
 * 
 */
USTRUCT(BlueprintInternalUseOnly)
struct MEDIAPIPE_API FAnimNode_MediaPipeBase : public FAnimNode_SkeletalControlBase
{
	GENERATED_BODY()

	FAnimNode_MediaPipeBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinHiddenByDefault))
	float KalmanQ = 0.001;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinHiddenByDefault))
	float KalmanR = 0.0015;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault, ClampMin=0.f, ClampMax=1.f))
	float Smooth = 0.3f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug", meta = (PinHiddenByDefault))
	bool bDebugDraw = false;
	virtual void EvaluateComponentSpaceInternal(FComponentSpacePoseContext& Context) override final;
	virtual void GatherDebugData(FNodeDebugData& DebugData) override final;
	bool IsEvaluateEnabled(const FComponentSpacePoseContext& Output);
protected:
	TWeakPtr<FMediaPipeAnimContext> SharedContext;
	virtual bool NeedsOnInitializeAnimInstance() const override;
	virtual void OnInitializeAnimInstance(const FAnimInstanceProxy* InProxy, const UAnimInstance* InAnimInstance) override;
	virtual bool IsValidToEvaluate(const USkeleton* Skeleton, const FBoneContainer& RequiredBones) override;
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
};
