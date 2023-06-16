// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "BoneContainer.h"
#include "BoneItem.h"

struct FBvhBoneCacheItem
{
public:
	FBoneItem Bone;
	bool bIsRoot;
	FName Parent;
	FQuat InitInverse;
};
