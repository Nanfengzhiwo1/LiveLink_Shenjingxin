// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include <functional>

#include "MediaPipeTexture.h"


class MEDIAPIPE_API FDynamicTexture
{
public:
	FDynamicTexture();
	~FDynamicTexture();

	bool Enqueue(IMediaPipeOutFrame* InMat);
	void NextFrame();
	UTexture2D* GetTextureObject() const;

	std::function<void(UTexture2D* Texture, int Width, int Height)> FuncTextureCreated;
	int GetWidth() const { return Width; }
	int GetHeight() const { return Height; }

	void Stop(bool WaitToCompleted = true);

	bool bIsSized = false;
	int MaxPoolSize = 5;
private:
	void ReleaseBufferPool();
	bool Resize(TSharedPtr<IMediaPipeOutFrame> Mat);
	void Release();
	void RenderCmd_CreateTexture();
	void RenderCmd_UpdateTexture(TSharedPtr<IMediaPipeOutFrame>, bool bIsNew);


	UTexture2D* TextureObject = nullptr;
	TQueue<TSharedPtr<IMediaPipeOutFrame>> TexturePool;
	FCriticalSection BufferMux;
	MediaPipeImageFormat Format = MediaPipeImageFormat::UNKNOWN;
	EPixelFormat PixelFormat = PF_Unknown;
	int Pitch = 0;
	int Width = 0;
	int Height = 0;
	bool bIsStarted = true;
	int32 PoolSize = 0;
	std::atomic<bool> bIsBusying = false;
};
