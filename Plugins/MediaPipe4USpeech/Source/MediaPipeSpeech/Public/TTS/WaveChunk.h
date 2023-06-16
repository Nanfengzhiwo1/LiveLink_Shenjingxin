// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "WaveChunk.generated.h"

USTRUCT(BlueprintType)
struct MEDIAPIPESPEECH_API FWaveChunk
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="WavChunk")
	int32 SampleRate = 24000;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="WavChunk")
	FGuid SentenceId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="WavChunk")
	int ChunkIndex = -1;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="WavChunk")
	FString SentenceFragment;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="WavChunk")
	bool bHasNext = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="WavChunk")
	TArray<float> AudioData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="WavChunk")
	float AudioDurationMills = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="WavChunk")
	int IndexOfText = -1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="WavChunk")
	int TotalNumOfChunks = 0;
};
