// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "TransformValueType.generated.h"

UENUM(BlueprintType)
enum class ETransformValueType : uint8
{
	InitValue,
	CurrentValue,
	OffsetValue
};