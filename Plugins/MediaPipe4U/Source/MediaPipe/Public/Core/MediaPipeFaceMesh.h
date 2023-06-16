// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "CoreMinimal.h"
#include "MediaPipeLandmark.h"
#include "MediaPipeFaceMesh.generated.h"


USTRUCT(BlueprintType)
struct MEDIAPIPE_API FMediaPipeFaceMesh
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="MediaPipe")
	FTransform Pose;

	UPROPERTY(BlueprintReadOnly, Category="MediaPipe")
	TArray<FMediaPipeLandmark> Vertices;

	UPROPERTY(BlueprintReadOnly, Category="MediaPipe")
	TArray<FVector2D> TextureVertices;

	UPROPERTY(BlueprintReadOnly, Category="MediaPipe")
	TArray<int> Indices;
};
