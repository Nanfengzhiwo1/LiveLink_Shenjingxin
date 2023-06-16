// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

#include "CoreMinimal.h"
#include "ARTrackable.h"
#include "BlendShapesPublishedEventArguments.generated.h"

static TMap<EARFaceBlendShape, float> EmptyMap = TMap<EARFaceBlendShape, float>{};

USTRUCT()
struct MEDIAPIPE_API FBlendShapesPublishedEventArguments
{
	GENERATED_BODY()
	
	FBlendShapesPublishedEventArguments()
	{
	}

	FBlendShapesPublishedEventArguments(const FBlendShapesPublishedEventArguments& Other)
		: BlendShapes(Other.BlendShapes),
		  bIsStaticImage(Other.bIsStaticImage)
	{
	}

	FBlendShapesPublishedEventArguments(FBlendShapesPublishedEventArguments&& Other) noexcept
		: BlendShapes(Other.BlendShapes),
		  bIsStaticImage(Other.bIsStaticImage)
	{
	}

	FBlendShapesPublishedEventArguments& operator=(const FBlendShapesPublishedEventArguments& Other)
	{
		if (this == &Other)
			return *this;
		BlendShapes = Other.BlendShapes;
		bIsStaticImage = Other.bIsStaticImage;
		return *this;
	}

	FBlendShapesPublishedEventArguments& operator=(FBlendShapesPublishedEventArguments&& Other) noexcept
	{
		if (this == &Other)
			return *this;
		BlendShapes = Other.BlendShapes;
		bIsStaticImage = Other.bIsStaticImage;
		return *this;
	}

	FBlendShapesPublishedEventArguments(TSharedRef<TMap<EARFaceBlendShape, float>> InBlendShapes, bool bIsStatic) : BlendShapes(InBlendShapes), bIsStaticImage(bIsStatic)
	{}


	TSharedPtr<TMap<EARFaceBlendShape, float>> BlendShapes;

	bool bIsStaticImage = false;
};
