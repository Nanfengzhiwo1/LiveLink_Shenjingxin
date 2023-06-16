// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CameraParams.h"
#include "MediaPipeTexture.h"
#include "ResolutionLimits.h"

class IWebcamProvider
{
public:
	virtual ~IWebcamProvider() = default;
	virtual  bool Open(int DeviceId, int ResolutionX, int ResolutionY, int FPS, FCameraParams& OutParams) = 0;
	virtual  bool IsOpened() = 0;
	virtual void Close() = 0;
	virtual bool Read(MediaPipeTexture& Texture) = 0;
	virtual void UnLimitResolution() = 0;
	virtual void LimitResolution(int LimitResX, int LimitResY) = 0;
	virtual void SetHorizontalFlip(bool bFlip) = 0;
	virtual bool IsSupportResolutionLimit() = 0;
	virtual bool IsSupportHorizontalFlip() = 0;
	virtual bool ListCameras(TArray<FString>& Cameras) = 0;
};
