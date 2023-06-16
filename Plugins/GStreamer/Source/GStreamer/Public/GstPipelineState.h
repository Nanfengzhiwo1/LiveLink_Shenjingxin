// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GstPipelineState.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EGstPipelineState : uint8
{
	Pending = 0,
	None = 1,
	Ready = 2,
	Paused = 3,
	Playing = 4
};
