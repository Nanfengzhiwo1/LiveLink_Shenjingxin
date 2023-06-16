// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TTSSampleRate.h"
#include "TTSSolution.h"
#include "Components/ActorComponent.h"
#include "TTSSolutionComponent.generated.h"


UCLASS(Abstract, ClassGroup=(MediaPipe))
class MEDIAPIPESPEECH_API UTTSSolutionComponent : public UActorComponent, public ITTSSolution
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TTS")
	int SpeakerId = 174;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TTS")
	ETTSSampleRate SampleRate = ETTSSampleRate::TTS_SR_24000;

	virtual bool ListSpeakers(TMap<FString, int>& OutSpeakers) { return false; }

	// TTSSolution Interface
	virtual int32 GetSampleRate() override;
	virtual int GetSpeakerId() override;
	virtual void RaiseWavChunkReceivedEvent(TSharedRef<FWaveChunk> InWavChunk) override;
	virtual void RaiseInferenceCompletedEvent(const FGuid& SentenceId, ESpeechState State) override;

	virtual FTTSInferenceCompletedEvent& GetInferenceCompletedEvent() override;
	virtual FTTSWavChunkReceivedEvent& GetWavChunkReceivedEvent() override;

	virtual bool TextToSpeech(const FString& Sentence, FWavClip& OutWav) override PURE_VIRTUAL(UTTSSolutionComponent::TextToSpeech, return false;)

	virtual void SetDebugLogEnabled(bool bEnabled) override final;
	virtual FString GetPathInWorkDir(const FString& RelativePath);
protected:
	bool bDebugLogEnabled = false;
	virtual void OnDebugLogEnabledChanged();
	virtual void BeginPlay() override;
private:
	FTTSInferenceCompletedEvent InferenceCompletedEvent;
	FTTSWavChunkReceivedEvent WavChunkReceivedEvent;
};
