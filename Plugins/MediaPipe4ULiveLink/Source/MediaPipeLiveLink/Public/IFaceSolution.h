// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "ARTrackable.h"
#include "FaceSolutionInitializationContext.h"
#include "MediaPipeHolisticComponent.h"
#include "ImageSourceInfo.h"

class MEDIAPIPELIVELINK_API IFaceSolution
{
public:
	DECLARE_MULTICAST_DELEGATE_OneParam(FOnFaceBlendShapesSolved, TSharedPtr<FARBlendShapeMap> SolvedBlendShapes)
	virtual ~IFaceSolution() = default;

	virtual bool Initialize(const FFaceSolutionInitializationContext& Context) = 0;
	virtual bool IsSolveFromImageFrame() = 0;
	virtual bool SolveFrame(const FImageSourceInfo& InSourceInfo, const IMediaPipeTexture* Texture) = 0;
	virtual void UnInitialize(UMediaPipeHolisticComponent* MediaPipeHolisticComponent) = 0;

	virtual FOnFaceBlendShapesSolved& OnFaceBlendShapesSolved() = 0;
};
