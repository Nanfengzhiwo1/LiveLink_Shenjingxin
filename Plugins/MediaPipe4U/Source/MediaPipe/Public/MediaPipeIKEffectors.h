// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink	

#pragma once

#include "CoreMinimal.h"
#include "MediaPipeIKEffectors.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct MEDIAPIPE_API FMediaPipeIKEffectors
{
	GENERATED_BODY()

   UPROPERTY(EditAnywhere, Category="MediaPipe")
   FTransform FootLeft;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	FTransform FootRight;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	FTransform HandLeft;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	FTransform HandRight;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	FTransform Head;

	UPROPERTY(EditAnywhere, Category="MediaPipe")
	FTransform Pelvis;
};
