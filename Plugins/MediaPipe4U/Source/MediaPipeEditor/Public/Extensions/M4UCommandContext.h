// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

#include "CoreMinimal.h"
#include "MediaPipeAnimInstance.h"
#include "MediaPipeHolisticComponent.h"
#include "StaticImageSourceComponent.h"
	
/**
 * 
 */
class MEDIAPIPEEDITOR_API FM4UCommandContext : public TSharedFromThis<FM4UCommandContext>
{
public:
	FM4UCommandContext(){}
	void ResetState();

	bool IsMediaPipeRunning() const;

	TWeakObjectPtr<UMediaPipeHolisticComponent> MediaPipeHolisticComponent = nullptr;
	TWeakObjectPtr<UStaticImageSourceComponent> StaticImageSourceInWorld = nullptr;
	TWeakObjectPtr<UMediaPipeAnimInstance> MediaPipeAnimInstance = nullptr;

	mutable TWeakObjectPtr<UWorld> World = nullptr;
};