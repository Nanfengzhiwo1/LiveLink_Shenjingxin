// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink 
#pragma once

#include "CoreMinimal.h"
#include "AnimNode_ControlRig.h"
#include "LipSyncComponent.h"
#include "AnimNodes/AnimNode_LayeredBoneBlend.h"
#include "AnimNode_LipSync.generated.h"

UENUM(BlueprintType)
enum class ELipSyncCurveApplyMode : uint8
{
	/** Blend input with new curve value, using Alpha setting on the node */
	Blend,

	/** Blend the new curve value with the last curve value using Alpha to determine the weighting (.5 is a moving average, higher values react to new values faster, lower slower) */
	WeightedMovingAverage,
};

/**
 * 
 */
USTRUCT(BlueprintInternalUseOnly)
struct MEDIAPIPESPEECH_API FAnimNode_LipSync : public FAnimNode_Base
{
	GENERATED_BODY()

	FAnimNode_LipSync();
	virtual ~FAnimNode_LipSync() override;

	UPROPERTY(EditAnywhere, EditFixedSize, BlueprintReadWrite, Category = Links)
	FPoseLink SourcePose;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LipSync", meta = (PinShownByDefault))
    float Alpha = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LipSync", meta=(PinShownByDefault, ClampMin=1, ClampMax=10, EditCondition = "ApplyMode == EModifyCurveApplyMode::Blend"))
	float WeightScale = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LipSync", meta=(PinShownByDefault, ClampMin=0.01, ClampMax=5))
	float MaxDelaySeconds = 0.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LipSync")
	ELipSyncCurveApplyMode ApplyMode = ELipSyncCurveApplyMode::WeightedMovingAverage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LipSync")
	bool bUseGlobalParameters = true;

	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual void Evaluate_AnyThread(FPoseContext& Output) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual bool NeedsOnInitializeAnimInstance() const override;
	virtual void OnInitializeAnimInstance(const FAnimInstanceProxy* InProxy, const UAnimInstance* InAnimInstance) override;
private: 
	void ProcessCurveWMAOperation(FPoseContext& Output, const SmartName::UID_Type& NameUID, float CurrentValue, float& InOutLastValue);
	void ProcessCurveOperation(FPoseContext& Output,
	                           const SmartName::UID_Type& NameUID, float CurrentValue, float NewValue);
	TWeakObjectPtr<ULipSyncComponent> CurrentLipSyncComponent;
	TArray<float> LastCurveValues;
	TArray<FName> CurveNames;
	TArray<float> ZeroCurveValues;
	bool bInitializeLastValuesMap = false;
	int BlendShapeCount;
};

