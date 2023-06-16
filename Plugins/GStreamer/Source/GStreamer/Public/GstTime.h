// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "GstTime.generated.h"

USTRUCT(BlueprintType)
struct GSTREAMER_API FGstTime
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="GStreamer")
	int64 Total = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="GStreamer")
	int64 Current = 0;

	float GetPercent();
};

inline float FGstTime::GetPercent()
{
	if(Total <= 0)
	{
		return 0;
	}
	if(Current == Total)
	{
		return 1;
	}
	return (Current/ 100000.0f) / (Total / 100000.0f);
}
