// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "LipSyncMapAsset.generated.h"

UCLASS(Abstract, Meta = (LoadBehavior = "LazyOnDemand"))
class MEDIAPIPESPEECH_API ULipSyncMapAsset : public UDataAsset
{
	GENERATED_BODY()
};
