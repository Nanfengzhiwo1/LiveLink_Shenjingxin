// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink	

#pragma once

#include "CoreMinimal.h"
#include "ARTrackable.h"
#include "FaceSmoothParams.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct MEDIAPIPE_API FFaceSmoothParams
{
	GENERATED_BODY()
	FFaceSmoothParams(){}
	FFaceSmoothParams(const FFaceSmoothParams& InParams);

	FFaceSmoothParams(FFaceSmoothParams&& Other) noexcept
		: Iterations(Other.Iterations),
		  EyesSmooth(Other.EyesSmooth),
		  EyeBallsSmooth(Other.EyeBallsSmooth),
		  BrownSmooth(Other.BrownSmooth),
		  MouthSmooth(Other.MouthSmooth),
		  CheekSmooth(Other.CheekSmooth),
		  JawSmooth(Other.JawSmooth),
		  NoseSmooth(Other.NoseSmooth),
		  HeadSmooth(Other.HeadSmooth)
	{
	}

	UPROPERTY(EditAnywhere, Category="Smooth", meta=(ClampMin=1, ClampMax=20, UIMin = 1, UIMax = 20))
	int Iterations = 5;
	
	UPROPERTY(EditAnywhere, Category="Smooth", meta=(ClampMin=0.0f, ClampMax=1.0f, UIMin = 0.0f, UIMax = 1.0f))
	float EyesSmooth = 0.3f;

	UPROPERTY(EditAnywhere, Category="Smooth", meta=(ClampMin=0.0f, ClampMax=1.0f, UIMin = 0.0f, UIMax = 1.0f))
	float EyeBallsSmooth = 0.15f;
	
	UPROPERTY(EditAnywhere, Category="Smooth", meta=(ClampMin=0.0f, ClampMax=1.0f, UIMin = 0.0f, UIMax = 1.0f))
	float BrownSmooth = 0.4f;
	
	UPROPERTY(EditAnywhere, Category="Smooth", meta=(ClampMin=0.0f, ClampMax=1.0f, UIMin = 0.0f, UIMax = 1.0f))
	float MouthSmooth = 0.2f;

	UPROPERTY(EditAnywhere, Category="Smooth", meta=(ClampMin=0.0f, ClampMax=1.0f, UIMin = 0.0f, UIMax = 1.0f))
	float CheekSmooth = 0.4f;
	
	UPROPERTY(EditAnywhere, Category="Smooth", meta=(ClampMin=0.0f, ClampMax=1.0f, UIMin = 0.0f, UIMax = 1.0f))
	float JawSmooth = 0.4f;

	UPROPERTY(EditAnywhere, Category="Smooth", meta=(ClampMin=0.0f, ClampMax=1.0f, UIMin = 0.0f, UIMax = 1.0f))
	float NoseSmooth = 0.4f;

	UPROPERTY(EditAnywhere, Category="Smooth", meta=(ClampMin=0.0f, ClampMax=1.0f, UIMin = 0.0f, UIMax = 1.0f))
	float HeadSmooth = 0.5f;

	FFaceSmoothParams& operator=(const FFaceSmoothParams& Other);

	FFaceSmoothParams& operator=(FFaceSmoothParams&& Other) noexcept;
	
	friend bool operator==(const FFaceSmoothParams& Lhs, const FFaceSmoothParams& RHS);

	friend bool operator!=(const FFaceSmoothParams& Lhs, const FFaceSmoothParams& RHS);

	void ClaimValues();
	void GetSmoothParams(EARFaceBlendShape BlendShape, int& OutIterations, float& OutSmooth) const;
};

