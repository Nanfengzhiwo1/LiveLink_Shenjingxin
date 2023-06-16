// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "ParameterValue.h"

class AMediaPipeFaceLinkActor;
class UMediaPipeHolisticComponent;

struct MEDIAPIPELIVELINK_API FFaceSolutionInitializationContext
{
	TWeakObjectPtr<UMediaPipeHolisticComponent> MediaPipeHolisticComponent;
	bool bIsStaticImage;
	TMap<FName, FParameterValue>  Parameters;
	TWeakObjectPtr<AMediaPipeFaceLinkActor> LiveLinkActor;
};
