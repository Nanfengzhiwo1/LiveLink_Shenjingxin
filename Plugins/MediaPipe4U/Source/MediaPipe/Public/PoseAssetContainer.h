// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstanceProxy.h"
#include "Animation/PoseAsset.h"

struct FPoseAssetContainer
{
	FPoseAssetContainer(UPoseAsset* InPoseAsset);
	bool BlendCSPose(const FName& PoseName, FAnimInstanceProxy* AnimInstanceProxy, FCSPose<FCompactPose>& Output);
	bool BlendLocalPose(const FName& PoseName, FPoseContext& Output);
	bool IsValid() const;
private:
	void BuildPoseList(const FBoneContainer& RequiredBones);
	FAnimExtractContext PoseExtractContext;
	int32 GetPoseIndexByName(const FName& InBasePoseName) const;
	TWeakObjectPtr<UPoseAsset> PoseAsset;
	mutable FCriticalSection BuildListMutex;
	bool bListBuilt = false;
};
