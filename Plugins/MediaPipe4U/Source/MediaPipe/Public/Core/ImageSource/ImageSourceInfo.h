// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "ump_commons.h"

struct MEDIAPIPE_API FImageSourceInfo
{
public:
	FImageSourceInfo(){}
	FImageSourceInfo(const FImageSourceInfo& Value);
	
	int Width = 0;
	int Height = 0;
	int WidthStep = 0;
	MediaPipeImageFormat Format = MediaPipeImageFormat::UNKNOWN;
	bool bIsStatic = false;
	int CvMatType = 0;
	int NumOfChannels = 0;
	int ByteDepth = 0;
	
	static FImageSourceInfo MakeFromImageSource(const IImageSource* ImageSource);
	static FImageSourceInfo Make(int Width, int Height, MediaPipeImageFormat Format, bool bIsStatic);

	void ResetToEmpty();
	void Reset(int ImageWidth, int ImageHeight, MediaPipeImageFormat ImageFormat, bool bIsStaticImage);
	bool ResetByImageSource(const IImageSource* ImageSource);

	FImageSourceInfo& operator= (const FImageSourceInfo& Value);
};
