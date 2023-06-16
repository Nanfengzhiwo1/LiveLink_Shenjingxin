// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "Engine/EngineTypes.h"
#include "GroundSolveSettings.generated.h"

USTRUCT(BlueprintType)
struct MEDIAPIPE_API FGroundSolveSettings
{
	FGroundSolveSettings(const FGroundSolveSettings& Other)
		: CollisionChannel(Other.CollisionChannel),
		  HipsRotationMultiplier(Other.HipsRotationMultiplier),
		  MaxSquashIterations(Other.MaxSquashIterations),
		  MaxStretchIterations(Other.MaxStretchIterations),
		  MaxFinalIterations(Other.MaxFinalIterations),
		  FeetSmoothSpeed(Other.FeetSmoothSpeed),
		  FeetSmoothAngularSpeed(Other.FeetSmoothAngularSpeed),
		  FeetDampingDistance(Other.FeetDampingDistance),
		  JumpVelocityThreshold(Other.JumpVelocityThreshold),
		  InertiaSmoothFactor(Other.InertiaSmoothFactor),
		  bInertiaEnabled(Other.bInertiaEnabled)
	{
	}

	FGroundSolveSettings(FGroundSolveSettings&& Other) noexcept
		: CollisionChannel(std::move(Other.CollisionChannel)),
		  HipsRotationMultiplier(Other.HipsRotationMultiplier),
		  MaxSquashIterations(Other.MaxSquashIterations),
		  MaxStretchIterations(Other.MaxStretchIterations),
		  MaxFinalIterations(Other.MaxFinalIterations),
		  FeetSmoothSpeed(Other.FeetSmoothSpeed),
		  FeetSmoothAngularSpeed(Other.FeetSmoothAngularSpeed),
		  FeetDampingDistance(Other.FeetDampingDistance),
		  JumpVelocityThreshold(Other.JumpVelocityThreshold),
		  InertiaSmoothFactor(Other.InertiaSmoothFactor),
		  bInertiaEnabled(Other.bInertiaEnabled)
	{
	}

	FGroundSolveSettings& operator=(const FGroundSolveSettings& Other)
	{
		if (this == &Other)
			return *this;
		CollisionChannel = Other.CollisionChannel;
		HipsRotationMultiplier = Other.HipsRotationMultiplier;
		MaxSquashIterations = Other.MaxSquashIterations;
		MaxStretchIterations = Other.MaxStretchIterations;
		MaxFinalIterations = Other.MaxFinalIterations;
		FeetSmoothSpeed = Other.FeetSmoothSpeed;
		FeetSmoothAngularSpeed = Other.FeetSmoothAngularSpeed;
		FeetDampingDistance = Other.FeetDampingDistance;
		JumpVelocityThreshold = Other.JumpVelocityThreshold;
		InertiaSmoothFactor = Other.InertiaSmoothFactor;
		bInertiaEnabled = Other.bInertiaEnabled;
		return *this;
	}

	FGroundSolveSettings& operator=(FGroundSolveSettings&& Other) noexcept
	{
		if (this == &Other)
			return *this;
		CollisionChannel = std::move(Other.CollisionChannel);
		HipsRotationMultiplier = Other.HipsRotationMultiplier;
		MaxSquashIterations = Other.MaxSquashIterations;
		MaxStretchIterations = Other.MaxStretchIterations;
		MaxFinalIterations = Other.MaxFinalIterations;
		FeetSmoothSpeed = Other.FeetSmoothSpeed;
		FeetSmoothAngularSpeed = Other.FeetSmoothAngularSpeed;
		FeetDampingDistance = Other.FeetDampingDistance;
		JumpVelocityThreshold = Other.JumpVelocityThreshold;
		InertiaSmoothFactor = Other.InertiaSmoothFactor;
		bInertiaEnabled = Other.bInertiaEnabled;
		return *this;
	}

	GENERATED_BODY()

	FGroundSolveSettings(){}
	
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SolverSettings)
	TEnumAsByte<ECollisionChannel> CollisionChannel = ECC_WorldStatic;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SolverSettings)
	float HipsRotationMultiplier = 1.0f;
	
	/** Number of iterations to improve squashing poses. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category = SolverSettings, meta = (ClampMin = "0", ClampMax = "100", UIMin = "0", UIMax = "100"))
	int32 MaxSquashIterations = 6;

	/** Number of iterations to improve stretching poses. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SolverSettings, meta = (ClampMin = "0", ClampMax = "100", UIMin = "0", UIMax = "100"))
	int32 MaxStretchIterations = 6;

	/** Number of iterations to cleanup final pose. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SolverSettings, meta = (ClampMin = "0", ClampMax = "100", UIMin = "0", UIMax = "100"))
	int32 MaxFinalIterations = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SolverSettings, meta = (ClampMin = "0", ClampMax = "200", UIMin = "0", UIMax = "200"))
	float FeetSmoothSpeed = 50.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SolverSettings, meta = (ClampMin = "0", ClampMax = "720", UIMin = "0", UIMax = "720"))
	float FeetSmoothAngularSpeed = 45.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SolverSettings, meta = (ClampMin = "0", ClampMax = "100", UIMin = "0", UIMax = "100"))
	float FeetVerticalOffset = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SolverSettings)
	float FeetDampingDistance = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SolverSettings)
	float JumpVelocityThreshold = 35.0f;

	UPROPERTY(EditAnywhere, Category = SolverSettings, BlueprintReadWrite, meta = (ClampMin = "1", ClampMax = "1000", UIMin = "0", UIMax = "100", Input, EditCondition = "bInertiaEnabled"))
	float InertiaSmoothFactor = 2.0f;

	UPROPERTY(EditAnywhere, Category = SolverSettings, BlueprintReadWrite)
	bool bInertiaEnabled = true;
};
