// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "ModelComplexity.generated.h"

UENUM(BlueprintType)
enum class EModelComplexity : uint8
{
	Lite = 0,
	Full = 1,
	Heavy = 2,
};
