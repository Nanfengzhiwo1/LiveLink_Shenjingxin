// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "ARTrackable.h"
#include "FacePostProcessingContext.h"

class MEDIAPIPE_API IFaceDataPostProcessor
{
public:
	virtual ~IFaceDataPostProcessor() = default;
	virtual void PostProcess(const FFacePostProcessingContext& Context) = 0;
	virtual  int GetOrder() const = 0;
	virtual void SetEnabled(const bool bEnabled) = 0;
	virtual bool IsEnabled() const = 0;
};
