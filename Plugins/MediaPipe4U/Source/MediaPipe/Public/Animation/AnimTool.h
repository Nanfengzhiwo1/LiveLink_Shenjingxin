// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "Animation/AnimSequence.h"
#include "Animation/SmartName.h"

struct MEDIAPIPE_API FAnimSequenceCreationContext
{
	USkeleton* Skeleton = nullptr;
	int FrameCount = 0;
	float FPS = 30.0f;

	ERichCurveInterpMode CurveInterpMode = RCIM_Linear;
	bool bAutoSetTangents = true;

	FRawCurveTracks RawCurveData;
    TMap<FName, FRawAnimSequenceTrack> BoneTracks;

	int CurrentFrameIndex = 0;
	float TimeStepSec = 0;
	const FSmartNameMapping* GetSkeletonNameMapping();
	bool IsValid();

private:
	const FSmartNameMapping* NameMapping = nullptr;
};

struct MEDIAPIPE_API FBoneKey
{
	FName BoneName;
	FTransform BoneTransform;
};

struct MEDIAPIPE_API FCurveKey
{
	FName CurveName;
	float Value;
};

class MEDIAPIPE_API FAnimTool
{
public:
	static bool BeginBuildAnimSequence(USkeleton* InSkeleton, float FPS, int FrameCount, FAnimSequenceCreationContext& OutContext);
	static UAnimSequence* EndBuildAnimSequence(FAnimSequenceCreationContext& InContext, FName AnimSequenceName, UObject* Package);
	
	static bool AddAnimFrame(FAnimSequenceCreationContext& Context, const TArray<FBoneKey>& BoneKeys,
							 const TArray<FCurveKey>& CurveKeys);
};
