// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "MediaPipeSourceInfo.generated.h"

USTRUCT(BlueprintType)
struct MEDIAPIPE_API FMediaPipeSourceInfo
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MediaPipe")
	int ImageWidth = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MediaPipe")
	int ImageHeight = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MediaPipe")
	bool bIsStatic = false;

	bool IsValid() const;
};
