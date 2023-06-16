// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "ImageSourceInfo.h"
#include "MediaPipeTexture.h"

/**
 * 
 */
class MEDIAPIPE_API IImageConsumer
{
public:
	virtual ~IImageConsumer() = default;
	virtual  bool CanConsume() = 0;
	virtual bool Consume(const FImageSourceInfo& SourceInfo, IMediaPipeTexture* Texture) = 0;
};
