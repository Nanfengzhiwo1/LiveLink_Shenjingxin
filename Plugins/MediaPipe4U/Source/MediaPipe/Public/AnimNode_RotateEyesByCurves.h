// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "AnimNode_RotateEyesByCurves.generated.h"

/**
 * 
 */
USTRUCT(BlueprintInternalUseOnly)
struct MEDIAPIPE_API FAnimNode_RotateEyesByCurves : public FAnimNode_SkeletalControlBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Curve | RightEye")
	FName EyeLookInRightCurveName = "EyeLookInRight";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Curve | LeftEye")
	FName EyeLookInLeftCurveName = "EyeLookInLeft";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Curve | LeftEye")
	FName EyeLookOutLeftCurveName = "EyeLookOutLeft";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Curve | RightEye")
	FName EyeLookOutRightCurveName = "EyeLookOutRight";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Curve | RightEye")
	FName EyeLookUpRightCurveName = "EyeLookUpRight";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Curve | LeftEye")
	FName EyeLookUpLeftCurveName = "EyeLookUpLeft";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Curve | RightEye")
	FName EyeLookDownRightCurveName = "EyeLookDownRight";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Curve | LeftEye")
	FName EyeLookDownLeftCurveName = "EyeLookDownLeft";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Curve")
	bool bRemoveCurveValue = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation", meta = (PinShownByDefault))
	float Smooth = 0.3f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Limit", meta = (PinShownByDefault))
	float YawAngleDegreeRange = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Limit", meta = (PinShownByDefault))
	float PitchAngleDegreeRange = 4;

	UPROPERTY(EditAnywhere, Category="Bones")
	FBoneReference EyeLeftBone{};

	UPROPERTY(EditAnywhere, Category="Bones")
	FBoneReference EyeRightBone{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bones", meta = (PinShownByDefault))
	bool bAllowEyeYaw = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bones", meta = (PinShownByDefault))
	bool bAllowEyePitch = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bones")
	bool bAutoAxis = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	bool bDisabled = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bones", meta = (EditCondition = "bAutoAxis == false"))
	FVector EyeLeftYawAxis = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bones", meta = (EditCondition = "bAutoAxis == false"))
	FVector EyeRightYawAxis = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bones", meta = (EditCondition = "bAutoAxis == false"))
	FVector EyeLeftPitchAxis = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bones", meta = (EditCondition = "bAutoAxis == false"))
	FVector EyeRightPitchAxis = FVector::ZeroVector;

	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
protected:
	virtual void EvaluateComponentPose_AnyThread(FComponentSpacePoseContext& Output) override;
private:
	bool bInitialized = false;
	FCompactPoseBoneIndex LeftEyeBoneIndex = FCompactPoseBoneIndex(INDEX_NONE);
	FCompactPoseBoneIndex RightEyeBoneIndex =  FCompactPoseBoneIndex(INDEX_NONE);

	void InitBones(FComponentSpacePoseContext& Output);

	static bool GetCurveValue(const FComponentSpacePoseContext& Output, const FName& CurveName, float& OutValue);
	static bool SetCurveValue(FComponentSpacePoseContext& Output, const FName& CurveName, const float& NewValue);
	void CorrectAxis(FVector& InOutAxis, bool bExceptZAxis);

	FQuat GetRotationByCurve(float CurveValue, FVector RotationAxis, float AngleDegreeRange);

	FQuat EyeLeftInitRotation = FQuat::Identity;
	FQuat EyeRightInitRotation = FQuat::Identity;
};
