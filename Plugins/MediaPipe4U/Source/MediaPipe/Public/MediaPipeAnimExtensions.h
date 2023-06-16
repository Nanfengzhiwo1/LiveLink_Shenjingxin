// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MediaPipeFrame.h"
#include "MediaPipePoseContext.h"
#include "UObject/Interface.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimNodeBase.h"
#include "MediaPipeAnimExtensions.generated.h"


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMediaPipeAnimExtensions : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MEDIAPIPE_API IMediaPipeAnimExtensions
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual  FString GetExtensionName() = 0;

	virtual void OnAddOn(UAnimInstance* AnimInstance) = 0;
	
	 virtual void BeforePoseSolve(const FMediaPipeFrame& Frame, FComponentSpacePoseContext& Context) = 0;

	virtual void AfterPoseSolved(const FMediaPipeFrame& Frame, FComponentSpacePoseContext& Context) = 0;

	virtual void BeforeHandSolve(const FMediaPipeFrame& LeftHandFrame, const FMediaPipeFrame& RightHandFrame, FComponentSpacePoseContext& Context) = 0;

	virtual void AfterHandSolved(const FMediaPipeFrame& LeftHandFrame, const FMediaPipeFrame& RightHandFrame, FComponentSpacePoseContext& Context) = 0;

	virtual void AfterAllSolved(const FMediaPipePoseContext& MediaPipePoseContext) = 0;

	virtual void OnCaptureStarted() = 0;
	virtual void OnCaptureStopped() = 0;

	virtual bool IsDisabled() = 0;

	virtual void SetDisabled(bool Disabled) = 0;
};
