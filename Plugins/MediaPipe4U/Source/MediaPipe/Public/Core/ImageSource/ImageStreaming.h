// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include <functional>
#include "IImageConsumer.h"
#include "MediaPipeTexture.h"
#include "TextureSupported.h"
#include "ump_commons.h"
#include "Engine/Texture.h"

class MEDIAPIPE_API IImageStreaming : public IImageSource
{
public:
	virtual void SetPoolSize(int PoolSize) = 0;
	virtual int GetPoolSize() const = 0;
	virtual void Clear(bool bResizeToZero = true) = 0;
	/*return true, if texture size or format has changed*/
	virtual bool PreparePool(const int& Width, const int& Height, MediaPipeImageFormat Format, int WidthStep = -1) = 0;
	virtual bool PushFrame(std::function<bool(MediaPipeTexture*)> TextureUpdater) = 0;
	virtual bool PushFrame(ETextureSupported TextureType, UTexture* Texture) = 0;
	virtual bool IsTextPoolInitialized() const = 0;
	virtual float GetFrameRate() = 0;
	virtual float GetPoolingFrameRate() = 0;
	virtual void ClearFrameCounter() = 0;
};
