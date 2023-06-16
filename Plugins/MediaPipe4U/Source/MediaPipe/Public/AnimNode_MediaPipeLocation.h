// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "AnimNode_MediaPipeBase.h"
#include "ILocationSolver.h"
#include "Ground/GroundSolveSettings.h"
#include "AnimNode_MediaPipeLocation.generated.h"

class UAnimGraphNode_MediaPipeLocation;

/**
 * 
 */
USTRUCT(BlueprintInternalUseOnly)
struct MEDIAPIPE_API FAnimNode_MediaPipeLocation : public FAnimNode_MediaPipeBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bLockHorizontalMove = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bLockVerticalMove = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bLockForwardMove = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	float SmoothSpeed =200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	bool bUseGroundIK = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="MediaPipe", meta = (PinHiddenByDefault, EditCondition="bUseGroundIK"))
	FGroundSolveSettings GroundSolveSettings;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe", meta = (PinShownByDefault))
	FVector MovementScale = FVector(1.0, 1.0, 1.0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	float DepthInterpSpeed =0.5;
	
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
protected:
	virtual void EvaluateComponentPose_AnyThread(FComponentSpacePoseContext& Output) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
private:
	TWeakPtr<ILocationSolver> LocationSolver;
	TWeakPtr<IGroundSolver> GroundSolver;

	friend class UAnimGraphNode_MediaPipeLocation;
};
