// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "MediaPipeBone.generated.h"

USTRUCT(BlueprintType)
struct FMediaPipeBone
{
	GENERATED_BODY()

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Generic")
	FName BoneName = NAME_None;

	operator FName() const
	{
		return BoneName;
	}
};
