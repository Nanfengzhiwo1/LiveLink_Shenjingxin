// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GstSampleImpl.h"
#include "Engine/Texture2D.h"

#include "GstTextureContext.generated.h"

/**
 * 
 */
USTRUCT()
struct GSTREAMER_API FGstTextureContext
{
	GENERATED_BODY();

	UPROPERTY()
	UTexture2D* Texture = nullptr;
	
	IGstSample* Sample = nullptr;
};
