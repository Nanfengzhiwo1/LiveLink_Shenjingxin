// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CameraParams.generated.h"

USTRUCT(BlueprintType)
struct FCameraParams
{
	GENERATED_BODY()

	FCameraParams(){}
	
	FCameraParams(const FCameraParams& InParams)
	{
		DeviceId = InParams.DeviceId;
		ResolutionX = InParams.ResolutionX;
		ResolutionY = InParams.ResolutionY;
		FPS = InParams.FPS;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	int DeviceId = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	int ResolutionX = 1280;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	int ResolutionY = 720;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	int FPS = 30;
};
