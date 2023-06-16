// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "AnimNode_MediaPipeBase.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "AnimNode_MediaPipeHand.generated.h"

/**
 * 
 */
USTRUCT(BlueprintInternalUseOnly)
struct MEDIAPIPE_API FAnimNode_MediaPipeHand : public FAnimNode_MediaPipeBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bOptimize = true;
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
protected:
	virtual void EvaluateComponentPose_AnyThread(FComponentSpacePoseContext& Output) override;
private:
	TWeakPtr<IHandSolver> HandsSolver;
};
