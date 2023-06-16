// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "MediaPipeLandmark.generated.h"

USTRUCT(BlueprintType)
struct MEDIAPIPE_API FMediaPipeLandmark
{
	GENERATED_BODY()

	UPROPERTY(Category = "Landmark", BlueprintReadOnly)
	FVector Pos = {0, 0, 0};

	UPROPERTY(Category = "Landmark", BlueprintReadOnly)
	float Visibility = 0;

	UPROPERTY(Category = "Landmark", BlueprintReadOnly)
	float Presence = 0;

	UPROPERTY(Category = "Landmark", BlueprintReadOnly)
	bool bIsImageCoordinate = true;
};

using FMediaPipeLandmarkList = TArray<FMediaPipeLandmark>;