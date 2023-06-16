// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "IImageSourceLoopThread.h"
#include "ImageStreaming.h"
#include "LoopResult.h"
#include "MediaPipeImageSource.h"
#include "ump_commons.h"
#include "Components/ActorComponent.h"
#include "MediaPipeImageSourceComponent.generated.h"

struct FImageSourceLoopRunnable;

UCLASS(Abstract, ClassGroup=(MediaPipe))
class MEDIAPIPE_API UMediaPipeImageSourceComponent : public UActorComponent, public IMediaPipeImageSource
{
	GENERATED_BODY()
	

public:
	// Sets default values for this component's properties
	UMediaPipeImageSourceComponent();
	void PrepareTexturePool(const int& Width, const int& Height, MediaPipeImageFormat Format);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	int GetTexturePoolSize() const;
	
	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	void SetTexturePoolSize(int PoolSize);
	
	void GetFPS(float& FrameRate, float& PoolingFrameRate);
	void ClearFPSCounter();
	
	virtual int GetFrameWidth_Implementation() override;
	virtual int GetFrameHeight_Implementation() override;
	virtual bool IsStaticSource_Implementation() override final;
	virtual bool IsFrameCreated_Implementation() override final;

	virtual bool IsSupportHorizontalFlip() override PURE_VIRTUAL(UMediaPipeImageSourceComponent::IsSupportHorizontalFlip, return false;);
	virtual bool IsSupportLimitResolution() override PURE_VIRTUAL(UMediaPipeImageSourceComponent::IsSupportLimitResolution, return false;);
	//MediapipeImageSource Interface
	virtual void SetHorizontalFlip(bool bFlip) override;
	virtual void LimitResolution(int ResolutionX, int ResolutionY) override;
	virtual void UnLimitResolution() override;
	virtual IImageSource* GetImageSource() override;

protected:
	bool bIsHorizontalFlip = false;
	int MaxResolutionX = -1;
	int MaxResolutionY = -1;
	bool bIsFrameCreated;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual ELoopResult HandleInLoop();
	virtual void OnLoopCompleted();
	//Loop support
	bool StartLoopThread();
	void StopLoopThread();
	bool IsLoopThread() const;
	IImageStreaming* Streaming() const;
 
	bool NotifyTexture2DCreated(MediaPipeTexture* InTexture);
	void ResetTexture2D();
private: 
	void CreateTexture2D(MediaPipeTexture* InTexture);
	void UpdateTextureOnRenderThread(MediaPipeTexture* InTexture);
	void RenderCmd_UpdateTexture(MediaPipeTexture* InTexture) const;
	
	TSharedPtr<IImageSourceLoopThread> LoopThread;
	void LoopThreadStopNotify();
	std::atomic<bool> LoopThreadCreated = false;
	friend FImageSourceLoopRunnable;
	TUniquePtr<IImageStreaming> StreamingPtr;
	UPROPERTY()
	UTexture2D* TextureObject = nullptr;
	FImageSourceInfo Texture2DInfo;
	EPixelFormat Texture2DFormat;
	TextureCompressionSettings Texture2DCompression;
};


