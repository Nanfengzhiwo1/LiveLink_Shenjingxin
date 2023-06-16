// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "IImageConsumer.h"
#include "ResolutionLimits.h"
#include "ump_commons.h"
#include "Engine/Texture2D.h"
#include "UObject/Interface.h"
#include "MediaPipeImageSource.generated.h"

DECLARE_EVENT_ThreeParams(IMediaPipeImageSource, FTextureCreatedDelegate, UTexture2D*, int, int);

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class  UMediaPipeImageSource : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MEDIAPIPE_API IMediaPipeImageSource
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="MediaPipe")
	int GetFrameWidth();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="MediaPipe")
	int GetFrameHeight();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="MediaPipe")
	bool IsStaticSource();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="MediaPipe")
	bool IsFrameCreated();
	
	FTextureCreatedDelegate& OnTextureCreatedTrigger();
	virtual  IImageSource* GetImageSource() =0;
	virtual bool IsSupportHorizontalFlip() = 0;
	virtual bool IsSupportLimitResolution() = 0;
	virtual void LimitResolution(int ResolutionX, int ResolutionY) = 0;
	virtual void SetHorizontalFlip(bool bFlip) = 0;
	virtual void UnLimitResolution() = 0;
protected:
	FTextureCreatedDelegate OnTextureCreated;
};
