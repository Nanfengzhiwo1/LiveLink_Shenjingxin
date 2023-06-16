// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OVRLipSyncProcessor.h"
#include "OVRLipSyncFrame.h"
#include "LipSyncComponent.generated.h"

UENUM(BlueprintType)
enum class EOVRLipSyncProviderKind : uint8
{
	Original = 0,
	Enhanced = 1,
	EnhancedWithLaughter = 2,
};


UCLASS(ClassGroup=(MediaPipeSpeech), meta=(BlueprintSpawnableComponent))
class MEDIAPIPESPEECH_API ULipSyncComponent : public UActorComponent
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLipSyncOutFrame, const FOVRLipSyncFrame&, Frame);
	DECLARE_EVENT_OneParam(ULipSyncComponent, FLipSyncOutFrameEvent, const TSharedPtr<FOVRLipSyncFrame>&);
public:
	// Sets default values for this component's properties
	ULipSyncComponent();
	
	UPROPERTY(EditAnywhere, Category="LipSync")
	int32 SampleRate = 48000;

	UPROPERTY(EditAnywhere, Category="LipSync")
	int32 BufferSize = 4096;

	UPROPERTY(EditAnywhere, Category="LipSync")
	EOVRLipSyncProviderKind Kind;

	UFUNCTION(BlueprintCallable, Category = "LipSync", Meta = (ToolTip = "Feed AudioBuffer containing packaged mono 32-bit signed integer PCM values"))
	void FeedAudio32Async(const TArray<float>& AudioData);

	void FeedAudio32NativeAsync(const float* Data, int Length) const;

	UFUNCTION(BlueprintCallable, Category = "LipSync", Meta = (ToolTip = "Feed AudioBuffer containing packaged mono 16-bit signed integer PCM values"))
	void FeedAudio16Async(const TArray<uint8>& AudioData);

	void FeedAudio16NativeAsync(const int16* Data, int Length) const;

	UPROPERTY(BlueprintAssignable, Category="LipSync")
	FOnLipSyncOutFrame OnLipSyncOutFrame;

	FLipSyncOutFrameEvent& LipSyncOutFrameTrigger();

	UFUNCTION(BlueprintCallable, Category = "LipSync", Meta = (ToolTip = "Get latest frame"))
	bool GetLipSyncFrame(FOVRLipSyncFrame& Frame);
	
protected:
	void OnLipSyncCallback(TSharedPtr<FOVRLipSyncFrame>& LipSyncOutput);
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
private:
	TSharedPtr<FOVRLipSyncProcessor> Processor;
	FLipSyncOutFrameEvent LipSyncOutFrameEvent;
};