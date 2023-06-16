// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "BoneIndices.h"
#include "BoneContainer.h"
#include "BoneItem.generated.h"

USTRUCT()
struct FSkeletonBone : public FBoneReference
{
	GENERATED_BODY()
	
	FSkeletonBone() : FBoneReference()
	{
	}

	FSkeletonBone(const FName& InBoneName) : FBoneReference(InBoneName)
	{
	}

	FCompactPoseBoneIndex PoseIndex = FCompactPoseBoneIndex(INDEX_NONE);

	FSkeletonPoseBoneIndex SkeletonIndex = FSkeletonPoseBoneIndex(INDEX_NONE);

	FMeshPoseBoneIndex MeshIndex = FMeshPoseBoneIndex(INDEX_NONE);

	bool IsValid() const;
};


USTRUCT()
struct FBoneItem
{
	GENERATED_BODY()

	FTransform Transform= FTransform::Identity;
	FTransform LocalTransform= FTransform::Identity;

	bool HasParent = false;

	FSkeletonBone BoneIndices{};

	FSkeletonBone ParentBoneIndices{};
};

