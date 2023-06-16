// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink	

#pragma once

#include "CoreMinimal.h"
#include "ImageConsumerProvider.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/Object.h"
#include "ImageFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintThreadSafe, ScriptName = "MediaPipeImageUtils"))
class MEDIAPIPE_API UImageFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static bool RegisterImageConsumer(const TScriptInterface<IImageConsumerProvider>& Consumer);
	
	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static bool UnregisterImageConsumer(const TScriptInterface<IImageConsumerProvider>& Consumer);
	
	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static void UnregisterAllImageConsumers();
};
