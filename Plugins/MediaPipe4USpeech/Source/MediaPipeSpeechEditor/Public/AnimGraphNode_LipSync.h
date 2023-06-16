// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "LipSync/AnimNode_LipSync.h"
#include "AnimGraphNode_LipSync.generated.h"

/**
 * 
 */
UCLASS(meta=(Keywords = "MediaPipe ControlRig Lip Sync"))
class MEDIAPIPESPEECHEDITOR_API UAnimGraphNode_LipSync : public UAnimGraphNode_Base
{
	GENERATED_BODY()
public:

	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual FLinearColor GetNodeTitleColor() const override;

	UPROPERTY(EditAnywhere, Category=Settings)
	FAnimNode_LipSync Node;
protected:
	
	virtual const FAnimNode_LipSync* GetNode() const { return &Node; }
};
