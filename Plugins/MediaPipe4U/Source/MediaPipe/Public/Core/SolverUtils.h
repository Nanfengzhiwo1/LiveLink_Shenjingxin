// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "BodyIKControls.h"
#include "IKControlsAlignment.h"
#include "MediaPipeAnimContext.h"
#include "Pose/IPoseSolver.h"
#include "MediaPipePoseJoint.h"
#include "TransformValueType.h"

class FSolverUtils
{
public:
	FIKControlsAlignment* GetIKControlsAlignment();
	explicit FSolverUtils(const TSharedPtr<IPoseSolver>& InPoseSolver);
	bool GetBodyControlIK(FMediaPipeAnimContext* Context,ETransformValueType ValueType,EBoneControlSpace Space,FBodyIKControls& OutIKControls) const;
private:
	TSharedPtr<IPoseSolver> PoseSolver;
	FIKControlsAlignment IKControlsAlignment;
	
	bool GetPoseJointInitTransform(FMediaPipeAnimContext* Context, EMediaPipePoseJoint Joint, EBoneControlSpace Space, FTransform& Out) const;
	bool GetPoseJointLatestTransform(FMediaPipeAnimContext* Context,EMediaPipePoseJoint Joint, EBoneControlSpace Space, FTransform& Out) const;
	
	bool GetBodyInitControlIK(
		FMediaPipeAnimContext* Context,
		EBoneControlSpace Space,
		FBodyIKControls& OutIKControls
	) const;

	bool GetBodyCurrentControlIK(
		FMediaPipeAnimContext* Context,
		EBoneControlSpace Space,
		FBodyIKControls& OutIKControls
	) const;
};
