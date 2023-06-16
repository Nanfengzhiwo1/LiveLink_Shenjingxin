// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "IWebcamProvider.h"
#include "MediaPipeImageSource.h"
#include "MediaPipeImageSourceComponent.h"
#include "WebcamImageSourceComponent.generated.h"


UCLASS(ClassGroup=(MediaPipe), meta=(BlueprintSpawnableComponent))
class MEDIAPIPE_API UWebcamImageSourceComponent : public UMediaPipeImageSourceComponent, public IImageSource
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWebcamImageSourceComponent();
	virtual ~UWebcamImageSourceComponent() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Webcam")
	int DeviceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Webcam")
	int FrameWidth = 640;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Webcam")
	int FrameHeight = 480;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Webcam")
	float FrameRate = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Webcam")
	bool HorizontalFlip = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Webcam")
	FName ProviderName = "OpenCV";
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Webcam")
	// bool bEnableStreaming = true;

	UFUNCTION(BlueprintCallable, Category="Webcam")
	bool Open();
	
	UFUNCTION(BlueprintCallable, Category="Webcam")
	void Close();

	UFUNCTION(BlueprintCallable, Category="Webcam")
	void PauseCapture();

	UFUNCTION(BlueprintCallable, Category="Webcam")
	void ResumeCapture();

	//Image Source interface
	virtual bool GetTexture(IMediaPipeTexture*& outTexture) override;
	virtual bool IsStatic() const override;
	virtual int GetWidth() const override;
	virtual int GetHeight() const override;
	virtual int GetWidthStep() const override;
	
	virtual MediaPipeImageFormat GetFormat() const override;

	
	virtual ELoopResult HandleInLoop() override;

	//IMediaPipeImageSource interface
	virtual IImageSource* GetImageSource() override;

	virtual bool IsSupportHorizontalFlip() override;
	virtual bool IsSupportLimitResolution() override;
protected:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void DestroyComponent(bool bPromoteChildren) override;
private:
	FCriticalSection ProviderMutex;
	FName CurrentProvider = NAME_None;
	bool CreateWebcamProvider();
	bool ReadTexture(MediaPipeTexture* InOutTexture);
	std::atomic<bool> bIsRunning;
	MediaPipeTexture StagingText;
	bool bStopCapture;
	bool bStreamingMode = true;
	bool bFirstFrame;
	int64 ImageId;
	TSharedPtr<IWebcamProvider> WebcamProvider;
};
