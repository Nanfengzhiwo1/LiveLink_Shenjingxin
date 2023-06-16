#include "BoneItem.h"

bool FSkeletonBone::IsValid() const
{
	return SkeletonIndex != INDEX_NONE && MeshIndex != INDEX_NONE && PoseIndex != INDEX_NONE;
}
