// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IWaveStream.h"
#include "WaveChunk.h"
#include "Components/SynthComponent.h"
#include "LipSync/LipSyncComponent.h"
#include "SpeechSynthComponent.generated.h"

class AMediaPipeSpeechActor;

UCLASS(ClassGroup=(MediaPipeSpeech), BlueprintType)
class MEDIAPIPESPEECH_API USpeechSynthComponent : public USynthComponent 
{
	GENERATED_BODY()

	DECLARE_EVENT(USpeechSynthComponent, FAudioSampleEvent);

public:
	USpeechSynthComponent(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintCallable, Category="Speech")
	virtual void Pause();

	UFUNCTION(BlueprintCallable, Category="Speech")
	virtual void Resume();

	UFUNCTION(BlueprintCallable, Category="Speech")
	bool IsPaused();

	UFUNCTION(BlueprintCallable, Category="Speech|LipSync")
	void BindLipSync(ULipSyncComponent* LipSyncComponent);

	UFUNCTION(BlueprintCallable, Category="Speech|LipSync")
	void RemoveLipSync();
	
	virtual bool WriteChunk(const TSharedRef<FWaveChunk>& InChunk);
	FAudioSampleEvent& AudioSampleTrigger();
protected:
	virtual bool Init(int32& SampleRate) override;
	virtual int32 OnGenerateAudio(float* OutAudio, int32 NumSamples) override;
	virtual void BeginPlay() override;
private:
	int32 CurrentSampleRate = 24000;
	TSharedPtr<IWaveStream> WaveStream;
	FAudioSampleEvent AudioSampleEvent;
	bool bSilence;
	TWeakObjectPtr<ULipSyncComponent> LipSync;
	friend class AMediaPipeSpeechActor;
};
