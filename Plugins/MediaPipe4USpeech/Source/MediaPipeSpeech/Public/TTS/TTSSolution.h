// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "WaveChunk.h"
#include "UObject/Interface.h"
#include "TTSSolution.generated.h"

class ITTSSolution;
class FTTSCommand;

UENUM(BlueprintType)
enum class ESpeechState : uint8
{
	Finished,
	Failed,
	Canceled
};

struct MEDIAPIPESPEECH_API FWavClip
{
	TArray<float> Data;
	float DurationMills;
};

DECLARE_EVENT_TwoParams(ITTSSolution, FTTSInferenceCompletedEvent, const FGuid&,  ESpeechState)
DECLARE_EVENT_OneParam(ITTSSolution, FTTSWavChunkReceivedEvent, const TSharedRef<FWaveChunk>&)

// This class does not need to be modified.
UINTERFACE()
class UTTSSolution : public UInterface
{
	GENERATED_BODY()
};
/**
 * 
 */
class MEDIAPIPESPEECH_API ITTSSolution
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual int GetSpeakerId() = 0;
	virtual int32 GetSampleRate() =0;

	virtual  bool TextToSpeech(const FString& Sentence, FWavClip& OutWav) = 0;
	
	virtual void RaiseWavChunkReceivedEvent(TSharedRef<FWaveChunk> InWavChunk) = 0;
	virtual void RaiseInferenceCompletedEvent(const FGuid& SentenceId, ESpeechState State) = 0;

	virtual FTTSInferenceCompletedEvent& GetInferenceCompletedEvent() = 0;
	virtual FTTSWavChunkReceivedEvent& GetWavChunkReceivedEvent() = 0;

	virtual void SetDebugLogEnabled(bool bEnabled) = 0;
};
