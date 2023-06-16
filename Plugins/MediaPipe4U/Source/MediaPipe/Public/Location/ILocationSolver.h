// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "ISolverProvider.h"
#include "LocationSolverLockSettings.h"
#include "Ground/IGroundSolver.h"

class ILocationSolver : public ISolverProvider
{
public:
	virtual FLocationSolverLockSettings GetLockSettings() const =0;
	virtual void SetLockSettings(const FLocationSolverLockSettings& Settings) = 0;
	virtual void SetMovementScale(const FVector& Scale) = 0;
	virtual void SetDepthInterpSpeed(float SpeedValue) = 0;
	virtual void SetSmoothSpeed(float SpeedValue) = 0;
	virtual void SetAspectRatio(float Ratio) = 0;
	virtual FVector GetMovementVelocity() = 0;
};
