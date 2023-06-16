// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "LipSyncVisemes.h"
#include "OVRLipSyncFrame.generated.h"

USTRUCT(BlueprintType)
struct MEDIAPIPESPEECH_API FOVRLipSyncFrame
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LipSync")
	TArray<float> Visemes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LipSync")
	float LaughterScore = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LipSync")
	int FrameDelay = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LipSync")
	int64 TimestampMills = 0;

	float GetVisemeWeight(ELipSyncViseme Viseme);
	float GetVisemeWeightByIndex(int VisemeIndex);
};
