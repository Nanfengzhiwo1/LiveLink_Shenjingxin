// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "HumanoidBoneSettings.h"
#include "Animation/AnimNodeBase.h"

struct MEDIAPIPE_API FMediaPipePoseContext
{
	FMediaPipePoseContext(
		TWeakPtr<FHumanoidBoneSettings> InBoneSettings, FComponentSpacePoseContext& InPoseContext, TMap<FName, float>& InMorphTargetCurves)
	: PoseContext(InPoseContext), BoneSettings(InBoneSettings), MorphTargetCurve(InMorphTargetCurves)
	{}

	FComponentSpacePoseContext& PoseContext;
	const TWeakPtr<FHumanoidBoneSettings> BoneSettings;
	TMap<FName, float>& MorphTargetCurve;
	float DeltaSeconds = 0;
};
