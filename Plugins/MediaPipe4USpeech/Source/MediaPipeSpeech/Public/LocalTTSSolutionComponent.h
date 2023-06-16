// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "TTSSolutionComponent.h"
#include "speech_api.h"
#include "LocalTTSSolutionComponent.generated.h"


UCLASS(ClassGroup=(MediaPipeSpeech), BlueprintType)
class MEDIAPIPESPEECH_API ULocalTTSSolutionComponent : public UTTSSolutionComponent
{
	GENERATED_BODY()
	DECLARE_DELEGATE(FOnStopped)
public:
	// Sets default values for this component's properties
	ULocalTTSSolutionComponent();

	/*Voice encoder ml model file*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TTS")
	FString VoiceCoderModelFile = "vocoder.nb";

	/*Acoustic model file*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TTS")
	FString AcousticModelFile = "acoustic.nb";

	/*Text front profile for acoustic model*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TTS")
	FString ConfigFile = "front.conf";

	UFUNCTION(BlueprintCallable, Category="TTS")
	bool ReLoadConfig();

	virtual bool TextToSpeech(const FString& Sentence, FWavClip& OutWav) override;

	UFUNCTION(BlueprintCallable, Category="TTS")
	virtual bool ListSpeakers(TMap<FString, int>& OutSpeakers) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void OnDebugLogEnabledChanged() override;
	void StopSpeak(FOnStopped OnStopped);
private:
	bool ReLoadConfigInternal();
	bool LoadSpeakers();
	TMap<FString, int> Speakers;
	mutable FCriticalSection SendMutex;
	void* SpeechAPI;
	ILogger* SpeechLogger;
	bool bIsStopping;
};
