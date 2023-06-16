// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "MediaPipeDebugDrawOptions.generated.h"

USTRUCT(BlueprintType)
struct FMediaPipeDebugDrawOptions
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	float BodyPointSize = 2.0f;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	float HandPointSize = 1.0f;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	float IKPointSize = 10.0f;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	float FacePointSize = 1.5f;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	float FaceLineThickness = 0.2f;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	FColor FaceLineColor = FColor::White;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	float LineThickness = 1.0f;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	FColor PointColor = FColor::Orange;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	FColor HighlightPointColor = FColor::Green;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	FColor LineColor = FColor::White;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	FColor TextColor = FColor::Green;

};
