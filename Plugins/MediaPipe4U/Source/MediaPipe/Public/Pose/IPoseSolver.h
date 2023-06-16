// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "IMediaPipeSolver.h"
#include "ISolverProvider.h"
#include "MediaPipePoseJoint.h"
#include "PoseSolverLockSettings.h"

class MEDIAPIPE_API IPoseSolver : public virtual ISolverProvider
{
public:
	virtual  FPoseSolverLockSettings& GetLocks() = 0;
	virtual  void ApplyLocks() = 0;
	virtual void UseLegIK(bool bUse) = 0;
	virtual void UseArmIK(bool bUse) = 0;
	virtual bool GetOptimize() = 0;
	virtual void SetOptimize(bool Enabled) = 0;
	virtual void AddSecondarySmooth(EMediaPipePoseJoint Joint, float Smooth) = 0;
	virtual void RemoveSecondarySmooth(EMediaPipePoseJoint Joint) = 0;
	virtual void ClearAllSecondarySmooth() = 0;
};
