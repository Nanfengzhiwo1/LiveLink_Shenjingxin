// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "MediaPipeTexture.h"
#include "ump_commons.h"

struct FStaticImageSourceInstance : IImageSource
{
public:
    void SetTexture(TSharedPtr<MediaPipeTexture> InTexture, int CalculationCount = 1);
	
	virtual bool GetTexture(IMediaPipeTexture*& outTexture) override;
	virtual bool IsStatic() const override;
	virtual int GetWidth() const override;
	virtual int GetHeight() const override;
	virtual int GetWidthStep() const override;
	virtual MediaPipeImageFormat GetFormat() const override;

	bool IsValid() const;
	void Reset();

private:
	void ReleaseTexture(const FGuid InTextureId);
	FRWLock TextureLock;
	TSharedPtr<MediaPipeTexture> Texture{};
	FGuid TextureId;
	int32 CalcCounter = 1;
};
