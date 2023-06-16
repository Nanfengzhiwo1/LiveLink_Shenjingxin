// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "BonePresets.generated.h"

UENUM(BlueprintType)
enum class EBonePresets : uint8
{
	Custom,
	UE5,
	VRoid,
	Daz,
	CharacterCreator
};
