// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "IImageWrapper.h"
#include "ump_commons.h"

class MEDIAPIPE_API MediaPipeImageUtils
{
public:
	static int GetImageAlignedWidthStep(int ImageWidth, int Channels = 4, int Depth = 8, int Align = 4);
	static int ChannelSizeInByteForFormat(MediaPipeImageFormat Format);
	static int GetImageWidthStep(int ImageWidth, MediaPipeImageFormat Format);
	static int GetImageNumOfChannel(MediaPipeImageFormat Format);
	static int GetImageByteDepth(MediaPipeImageFormat Format);
	static int GetOpenCVMatType(MediaPipeImageFormat Format);
	static FString GetFormatName(MediaPipeImageFormat Format);
	static ERGBFormat GetRGBFormat(MediaPipeImageFormat Format);
	
};
