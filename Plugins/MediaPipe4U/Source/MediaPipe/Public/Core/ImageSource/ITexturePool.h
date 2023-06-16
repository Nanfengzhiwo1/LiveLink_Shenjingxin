// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "TextureOut.h"

class MEDIAPIPE_API ITexturePool
{
public:
	virtual ~ITexturePool() = default;
	virtual int GetFrameCount() const = 0;;
	virtual  void Clear() = 0;
	virtual  void ResizeTexture(int Width, int Height, int Format) = 0;
	virtual  void ResizeTexture(int Width, int Height) = 0;
	virtual  int GetTextureWidth() const = 0;
	virtual  int GetTextureHeight() const = 0;
	virtual  int GetImageFormat() const = 0;
	virtual  bool TryGetTextureFrame(FTextureOut& OutFrame) = 0;
	virtual  int GetPoolSize() const = 0;
	virtual  void SetPoolSize(int Size) = 0;
	virtual bool IsStale(const IPooledFrame* Texture) const = 0;
};
