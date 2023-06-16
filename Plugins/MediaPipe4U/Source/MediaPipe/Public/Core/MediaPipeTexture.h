// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include <functional>

#include "CoreMinimal.h"
#include "IImageWrapper.h"
#include "IPooledFrame.h"
#include "ump_commons.h"


class MEDIAPIPE_API MediaPipeTexture : public IMediaPipeTexture, public IPooledFrame
{
public:
	MediaPipeTexture();
	MediaPipeTexture(int FrameWidth, int FrameHeight, MediaPipeImageFormat FrameFormat, long Id = 0);
	MediaPipeTexture(const MediaPipeTexture& InTexture, long Id = 0);
	MediaPipeTexture(const MediaPipeTexture* InTexture, long Id = 0);
	virtual ~MediaPipeTexture() override;
	virtual long GetImageId() const override;
	virtual void* GetData() const override;
	virtual long DataSize() const override;
	virtual void Release() override;
	bool AdoptCvMat(void* SrcMat);
	bool CopyFromCvMat(void* SrcMat);
	bool CopyFromData(void* InData, SIZE_T DataSize);
	bool CopyFromImage(IImageWrapper* InImage, int32 BitDepth = 8);

	//Pooling implement
	virtual void SetIsReturnRequired(bool bMustReturn) override;
	virtual bool IsReturnRequired() const override;
	bool bAllowShared = true;
	std::function<void(MediaPipeTexture*)> ReleaseCallback = [](MediaPipeTexture*){};
	
	TArray<uint8> Data{};
	int Width = 0;
	int Height = 0;
	MediaPipeImageFormat Format;
	//Pooled Frame interface
	virtual int GetFormat() const override;
	virtual int GetWidth() const override;
	virtual int GetHeight() const override;
	virtual void AddReference(int Amount = 1) override;
private:
	void DeleteCVMat();
	void* Mat = nullptr;
	long MatSizeInBytes = 0;
	int32 ReferenceCount = 0;
	bool bReturnRequired = false;
	long ImageId = 0;
};
