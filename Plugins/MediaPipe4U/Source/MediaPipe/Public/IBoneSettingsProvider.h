// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "HumanoidBoneSettings.h"
#include "BoneContainer.h"

class MEDIAPIPE_API IBoneSettingsProvider
{
public:
	virtual ~IBoneSettingsProvider() = default;
	virtual  void ApplyBoneSettings(const FBoneContainer& BoneContainer, FHumanoidBoneSettings& BoneSettings) = 0;
	
	static void LoadBoneSetting(const FBoneContainer& BoneContainer, FBoneReference& BoneReference, const FName& BoneName);
};
