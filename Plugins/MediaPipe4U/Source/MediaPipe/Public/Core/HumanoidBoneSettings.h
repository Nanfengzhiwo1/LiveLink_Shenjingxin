// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "BoneContainer.h"
#include "HumanoidBones.h"
#include "HumanoidBoneSettings.generated.h"

USTRUCT(BlueprintType)
struct MEDIAPIPE_API FHumanoidBoneSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference Root;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference Hips;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftUpperLeg;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightUpperLeg;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftLowerLeg;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightLowerLeg;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftFoot;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightFoot;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftToe;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightToe;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference Spine;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference Chest;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference Neck;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference Head;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftShoulder;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightShoulder;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftUpperArm;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightUpperArm;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftLowerArm;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightLowerArm;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftHand;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightHand;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftThumbProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftThumbIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftThumbDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftIndexProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftIndexIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftIndexDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftMiddleProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftMiddleIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftMiddleDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftRingProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftRingIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftRingDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftLittleProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftLittleIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference LeftLittleDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightThumbProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightThumbIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightThumbDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightIndexProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightIndexIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightIndexDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightMiddleProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightMiddleIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightMiddleDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightRingProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightRingIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightRingDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightLittleProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightLittleIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FBoneReference RightLittleDistal;

	bool IsValid() const { return Hips.BoneName != NAME_None; }
	
	void GetBoneMapping(TMap<EHumanoidBones, FBoneReference>& OutMappings) const;

	FBoneReference GetBone(EHumanoidBones Bone) const;

	TArray<FBoneReference*>& GetAllBones();
private:
	TArray<FBoneReference*> Bones;
};
