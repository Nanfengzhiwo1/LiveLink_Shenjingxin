// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "PluginEdition.generated.h"

UENUM(BlueprintType)
enum class EPluginEdition : uint8
{
	Trial = 0,
	Starter = 10,
	Professional = 20,
	Ultimate = 255
};
