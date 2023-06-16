// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "AnimNode_MediaPipeBase.h"
#include "MediaPipeSource.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "AnimNode_MediaPipeHead.generated.h"

/**
 * 
 */
USTRUCT(BlueprintInternalUseOnly)
struct MEDIAPIPE_API FAnimNode_MediaPipeHead : public FAnimNode_MediaPipeBase
{
	GENERATED_BODY()

	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
protected:
	virtual void EvaluateComponentPose_AnyThread(FComponentSpacePoseContext& Output) override;
	//virtual void EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms) override;
private:
	TWeakPtr<IHeadSolver> HeadSolver;
};
