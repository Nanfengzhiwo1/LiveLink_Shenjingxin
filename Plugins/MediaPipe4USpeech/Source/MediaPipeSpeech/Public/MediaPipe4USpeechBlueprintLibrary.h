// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink	

#pragma once

#include "CoreMinimal.h"
#include "MediaPipe4USpeechBlueprintLibrary.generated.h"

UCLASS(meta=(ScriptName="MediaPipe4USpeechLibrary"))
class MEDIAPIPESPEECH_API UMediaPipe4USpeechBlueprintLibrary :  public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category="MediaPipe4U Speech")
	static void GetGlobalLipSyncParameters(float& Alpha, float& BlendScale, float& MaxDelaySeconds);

	UFUNCTION(BlueprintCallable, Category="MediaPipe4U Speech")
	static void SetGlobLipSyncParameters(float Alpha = 1.0f, float BlendScale = 1.2f, float MaxDelaySeconds = 0.5);
};
