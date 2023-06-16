// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "ControlRig.h"
#include "IKControlsAlignment.h"
#include "Animation/AnimNodeSpaceConversions.h"
#include "AnimNode_MediaPipeControlRigAlign.generated.h"
/**
 * 
 */
class UAnimGraphNode_MediaPipeControlRigAlign;

USTRUCT()
struct MEDIAPIPE_API FAnimNode_MediaPipeControlRigAlign : public FAnimNode_ConvertComponentToLocalSpace
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ControlRig, meta = (PinShownByDefault), Category="ControlRig")
	TSubclassOf<UControlRig> ControlRigClass;
	
	virtual void OnInitializeAnimInstance(const FAnimInstanceProxy* InProxy, const UAnimInstance* InAnimInstance) override;
	virtual bool NeedsOnInitializeAnimInstance() const override { return true; }
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
private: 
	bool GetIKByControlName(const FName& RigControlName, FName& OutIKName);
	
	UPROPERTY()
	TMap<FName, FName> ControlBindings;
	static const FStructProperty* FindAlignmentField(const FName& Name);
	FIKControlsAlignment* IKControlsAlignment;
	
	friend class UAnimGraphNode_MediaPipeControlRigAlign;
};
