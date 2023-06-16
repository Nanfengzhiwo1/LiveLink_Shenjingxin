// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"

struct FRotationConstraint
{
	FRotationConstraint(){}
	
	FRotationConstraint(const FVector& RotationAxis, float MaxDegrees, float MinDegrees)
		: RotationAxis(RotationAxis),
		  MaxDegrees(MaxDegrees),
		  MinDegrees(MinDegrees)
	{
	}
	
	FRotationConstraint(const FRotationConstraint& Other)
		: RotationAxis(Other.RotationAxis),
		  MaxDegrees(Other.MaxDegrees),
		  MinDegrees(Other.MinDegrees)
	{
	}

	FRotationConstraint(FRotationConstraint&& Other) noexcept
		: RotationAxis(std::move(Other.RotationAxis)),
		  MaxDegrees(Other.MaxDegrees),
		  MinDegrees(Other.MinDegrees)
	{
	}

	FRotationConstraint& operator=(const FRotationConstraint& Other)
	{
		if (this == &Other)
			return *this;
		RotationAxis = Other.RotationAxis;
		MaxDegrees = Other.MaxDegrees;
		MinDegrees = Other.MinDegrees;
		return *this;
	}

	FRotationConstraint& operator=(FRotationConstraint&& Other) noexcept
	{
		if (this == &Other)
			return *this;
		RotationAxis = std::move(Other.RotationAxis);
		MaxDegrees = Other.MaxDegrees;
		MinDegrees = Other.MinDegrees;
		return *this;
	}


	FVector RotationAxis = FVector::ZeroVector;
	float MaxDegrees = 180;
	float MinDegrees = 0;
};
