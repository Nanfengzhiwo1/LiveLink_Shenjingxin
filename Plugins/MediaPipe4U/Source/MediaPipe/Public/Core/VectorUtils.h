// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "ForwardAndUpward.h"

struct FVectorLine
{
	FVector Start;
	FVector End;
};

class MEDIAPIPE_API VectorUtils
{
public:
	static FForwardAndUpward CalcForwardAndUpward(const FVector& Root, const FVector& Tip1, const FVector& Tip2,
	                                              const bool UseOrthoNormalize = false);
	
	static FVector MirrorXRotationAxis(const FVector V)
	{
		return FVector(V.X, -V.Y, -V.Z);
	}

	static FVector MirrorZRotationAxis(const FVector& V);

	static FVector Abs(const FVector V);

	static FVector MirrorYRotationAxis(const FVector& V);

	static bool GetStandardAxis(const FVector& V, EAxis::Type& OutAxis, int& OutInvert);

	static FVector GetBoneLocalAxis(const FTransform& Bone, const FVector& ComponentSpaceAxis);

	static void OrthoNormalize(FVector& Normal, FVector& Tangent);

	static FVector TriangleNormal(const FVector& A, const FVector& B, const FVector& C);

	static FVector GetBetweenPoint(const FVector& Start, const FVector& End, const float Percent = 0.5f);

	static double AngleRad(const FVector& A, const FVector& B);

	static double Angle(const FVector& A, const FVector& B);

	static FVector SecondaryAxis(FVector Axis);

	static FVector SingleAxis(const FVector& Axis);

	static FVector ComputePoleVector(const FVector& A, const FVector& B, const FVector& C, float Offset = 100.f);
	static FVectorLine ComputePoleLine(const FVector& A, const FVector& B, const FVector& C, float Offset = 100.f);
	
	static FVector MoveTowards(const FVector& Current, const FVector& Target, float MaxSpeed, float DeltaTime, float MaxDistance = 9999.0f);

	
	static FVector SpringInterpTo(FVector Current, FVector Target, FVector& Velocity, float DeltaTime, FVector InterpSpeed,
	                             float MaxVelocity);
	
	static float SpringInterpTo(float Current, float Target, float& Velocity, float DeltaTime, float InterpSpeed,
	                          float MaxVelocity);
 
	static double SpringInterpTo(double Current, double Target, double& Velocity, float DeltaTime, float InterpSpeed,
							  float MaxVelocity);
};
