// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "LoopResult.generated.h"

UENUM(BlueprintType)
enum class ELoopResult : uint8
{
	Continue,
	Break,
};
