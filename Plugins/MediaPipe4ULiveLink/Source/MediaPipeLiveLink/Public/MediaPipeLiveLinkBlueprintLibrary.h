// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "MediaPipeLiveLinkBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS(meta=(ScriptName="MediaPipeLiveLinkLibrary"))
class MEDIAPIPELIVELINK_API UMediaPipeLiveLinkBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "MediaPipe|LiveLink")
	static void ListFaceSolutions(TArray<FName>& Solutions, int& SolutionCount);
};
