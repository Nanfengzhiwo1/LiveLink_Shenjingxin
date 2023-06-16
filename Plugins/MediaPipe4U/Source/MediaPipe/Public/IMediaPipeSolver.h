// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "CoreMinimal.h"
#include "HumanoidBoneSettings.h"
#include "MediaPipeAnimMode.h"
#include "MediaPipeFrame.h"
#include "Animation/AnimNodeBase.h"


class MEDIAPIPE_API IMediaPipeSolver
{
public:
	virtual ~IMediaPipeSolver() = default;
	virtual  bool IsInitialized() const = 0;
	virtual  void Initialize(const FAnimInstanceProxy* InAnimInstanceProxy) = 0;
	virtual void MapJoints(TSharedRef<FHumanoidBoneSettings>& Settings) = 0;
	virtual bool Solve(const FMediaPipeFrame& MediaPipeFrame, FComponentSpacePoseContext& Output, float Alpha = 1.0f) = 0;
	virtual  void SetFilterParams(float KalmanParamQ, float KalmanParamR, float Smooth) = 0;
	virtual  void GetFilterParams(float& KalmanParamQ, float& KalmanParamR, float& Smooth) = 0;
	virtual void OnAnimModeChanged(EMediaPipeAnimMode Mode) = 0;
	virtual bool IsBoneCached() const = 0;
	virtual bool IsDisabled() const = 0;
	virtual void SetDisabled(bool Disabled) = 0;
	virtual void ResetState() = 0;
	virtual float GetMediaPipeFPS() const = 0;
	virtual float GetFPS() const = 0;
	virtual float GetMinScoreThresh() const = 0;
	virtual void SetMinScoreThresh(float Threshold) = 0;
	virtual void SetDrawDebugEnabled(bool bEnabled) = 0;
	virtual bool IsDrawDebugEnabled() = 0;
	virtual void DebugDraw(FNodeDebugData& DebugData) = 0;
	virtual void PerformCalibration() = 0;
	virtual void UnCalibration() = 0;
	
	virtual bool IsJointPrepared() = 0;
	
	
};
