// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "MediaPipeImageSource.h"
#include "MediaPipeTexture.h"
#include "StaticImageSourceInstance.h"
#include "StaticImageSourceComponent.generated.h"




UCLASS(ClassGroup="MediaPipe", meta=(BlueprintSpawnableComponent))
class MEDIAPIPE_API UStaticImageSourceComponent : public UActorComponent, public IMediaPipeImageSource
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	virtual bool OpenFile(const FString& FilePath);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	FString GetCurrentFile() { return File; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	int CalculateCount = 1;

	//UnrealInterface
	virtual int GetFrameWidth_Implementation() override final;
	virtual int GetFrameHeight_Implementation() override final;
	virtual bool IsStaticSource_Implementation() override final;
	virtual bool IsFrameCreated_Implementation() override final;
	
	virtual IImageSource* GetImageSource() override final;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//MediaPipe ImageSource
	virtual bool IsSupportHorizontalFlip() override { return false; }
	virtual bool IsSupportLimitResolution() override { return false; }
	virtual void LimitResolution(int ResolutionX, int ResolutionY) override {}
	virtual void UnLimitResolution() override {}
	virtual void SetHorizontalFlip(bool bFlip) override {}
private:
	FStaticImageSourceInstance StaticImageSourceInstance;
	bool bFrameCreated = false;
	FString File;
	FStaticImageSourceInstance Instance;
	FCriticalSection Lock;
	UPROPERTY(Transient)
	UTexture2D* Frame = nullptr;
	void RaiseTextureCreateEvent(TSharedPtr<MediaPipeTexture> InTexture);
};
