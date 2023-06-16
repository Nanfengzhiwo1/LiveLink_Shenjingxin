// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "GstAppSinkComponent.h"
#include "GstPipelineComponent.h"
#include "IGstListener.h"
#include "MediaPipeImageSourceComponent.h"
#include "GStreamerImageSourceComponent.generated.h"


UCLASS(ClassGroup="MediaPipe", meta=(BlueprintSpawnableComponent))
class MEDIAPIPEGSTREAMER_API UGStreamerImageSourceComponent : public UMediaPipeImageSourceComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	UGStreamerImageSourceComponent();

	/*if set to TRUE, those decoders within "Hardware" klass will be ignored. Otherwise they will be tried.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category="GStreamer")
	bool bForeSoftwareDecoding = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GStreamer")
	bool bUseBuffering = false;

	/*Buffer size when buffering streams (-1 default value)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category="GStreamer", meta=(EditCondition="bUseBuffering"))
	int BufferSize = -1;

	/*Buffer size when buffering streams (-1 default value)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category="GStreamer", meta=(EditCondition="bUseBuffering"))
	int64 BufferDuration = -1;

	UFUNCTION(BlueprintGetter, Category="GStreamer")
	UGstPipelineComponent* GetPipeline() const { return GStreamerPipeline; }

	UFUNCTION(BlueprintGetter, Category="GStreamer")
	UGstAppSinkComponent* GetSink() const { return GStreamerSink; }

	UFUNCTION(BlueprintCallable, Category="GStreamer")
	bool StartGStreamerLaunch(const FString& GStreamerCommand);
	
	UFUNCTION(BlueprintCallable, Category="GStreamer")
	bool Start(const FString& InFileOrUri);
	
	UFUNCTION(BlueprintCallable, Category="GStreamer")
	void Stop();
	void SafeRemoveEventHandlers();

	UFUNCTION(BlueprintGetter, Category="GStreamer")
	bool IsRunning() const { return bIsRunning; }

	UFUNCTION(BlueprintCallable, Category="GStreamer")
	bool Pause();

	UFUNCTION(BlueprintCallable, Category="GStreamer")
	void Resume();

	UFUNCTION(BlueprintCallable, Category="GStreamer")
	bool Seek(float Percent);

	//MediaPipeImageSource Impl
	virtual bool IsSupportLimitResolution() override;
	virtual bool IsSupportHorizontalFlip() override;

protected:
	// Called when the game starts
	virtual void UninitializeComponent() override;
	virtual  void InitializeComponent() override;
	
	UPROPERTY(BlueprintGetter=GetPipeline, Category="GStreamer")
	UGstPipelineComponent* GStreamerPipeline;

	UPROPERTY(BlueprintGetter=GetSink, Category="GStreamer")
	UGstAppSinkComponent* GStreamerSink;

	UPROPERTY(VisibleAnywhere, BlueprintGetter=IsRunning, Category="GStreamer")
	bool bIsRunning = false;
	bool bIsTextureChanged = false;


	FDelegateHandle TextureUpdateHandler;

	UFUNCTION()
	void OnHandleTextureCreated(UGstAppSinkComponent* AppSink, UTexture2D* NewTexture, EGstVideoFormat Format, int Width, int Height);

	UFUNCTION()
	void OnHandleTextureUpdated(FGstTextureContext& Context);

	UFUNCTION(BlueprintImplementableEvent, Category="GStreamer")
	void OnStateChanged(EGstPipelineState OldState, EGstPipelineState NewState);

private:
	//gst linstener
	FString SourceUri;
	FString FilePath;
	bool bIsFile = false;

	bool BuildUriAndValidate(const FString& InFileOrUri);
	FString BuildTransformElement() const;
	static FString BuildFileSourceElement(const FString& FilePath);
	FString BuildUriSourceElement(const FString& Uri) const;
};
