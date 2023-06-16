// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "HumanoidBones.h"
#include "MediaPipeBone.h"
#include "Animation/Skeleton.h"
#include "UObject/Object.h"
#include "MediaPipeRemapAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, NotBlueprintable, hideCategories=Object)
class MEDIAPIPE_API UMediaPipeRemapAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Skeleton")
	 USkeletalMesh* SkeletalMesh;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone Root;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone Hips;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftUpperLeg;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightUpperLeg;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftLowerLeg;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightLowerLeg;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftFoot;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightFoot;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftToe;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightToe;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone Spine;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone Chest;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone Neck;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone Head;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftShoulder;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightShoulder;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftUpperArm;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightUpperArm;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftLowerArm;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightLowerArm;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftHand;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightHand;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftThumbProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftThumbIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftThumbDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftIndexProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftIndexIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftIndexDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftMiddleProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftMiddleIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftMiddleDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftRingProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftRingIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftRingDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftLittleProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftLittleIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone LeftLittleDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightThumbProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightThumbIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightThumbDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightIndexProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightIndexIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightIndexDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightMiddleProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightMiddleIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightMiddleDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightRingProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightRingIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightRingDistal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightLittleProximal;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightLittleIntermediate;

	UPROPERTY(EditAnywhere, Category="Body")
	FMediaPipeBone RightLittleDistal;


	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	void GetBoneMapping(TMap<EHumanoidBones, FName>& OutMappings) const;

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	FName GetBone(EHumanoidBones Bone) const;
};
