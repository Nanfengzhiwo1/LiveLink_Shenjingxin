// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "FootInfo.generated.h"

USTRUCT()
struct FFootInfo
{
	FFootInfo()
	{}
	
	FFootInfo(const FFootInfo& Other)
		: FootHeight(Other.FootHeight),
		  FootAngle(Other.FootAngle)
	{
	}

	FFootInfo(FFootInfo&& Other) noexcept
		: FootHeight(Other.FootHeight),
		  FootAngle(Other.FootAngle)
	{
	}

	FFootInfo& operator=(const FFootInfo& Other)
	{
		if (this == &Other)
			return *this;
		FootHeight = Other.FootHeight;
		FootAngle = Other.FootAngle;
		return *this;
	}

	FFootInfo& operator=(FFootInfo&& Other) noexcept
	{
		if (this == &Other)
			return *this;
		FootHeight = Other.FootHeight;
		FootAngle = Other.FootAngle;
		return *this;
	}

	GENERATED_BODY()

	float FootHeight = -1.0f;
	float FootAngle = 0.0f;

	bool IsValid() const { return FootHeight >= 0; }
};
