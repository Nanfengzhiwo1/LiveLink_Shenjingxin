// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "HumanoidBoneSettings.h"

#include "RuntimeRetargetSource.generated.h"

USTRUCT(BlueprintType)
struct FRuntimeRetargetSource
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Retarget")
	USkeletalMeshComponent* SkeletalMeshComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Retarget")
	FHumanoidBoneSettings BoneSettings;

	bool IsValid() const;
};
