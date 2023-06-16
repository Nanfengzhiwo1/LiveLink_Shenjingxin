// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "PluginEdition.h"
#include "MediaPipePluginInfo.generated.h"

USTRUCT(BlueprintType)
struct FMediaPipePluginInfo
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MediaPipe")
	FString AuthorizedTo = TEXT("Anonymous");

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MediaPipe")
	EPluginEdition Edition = EPluginEdition::Ultimate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MediaPipe")
	FDateTime Expired = FDateTime(2099,12,31);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MediaPipe")
	FString Version;
};
