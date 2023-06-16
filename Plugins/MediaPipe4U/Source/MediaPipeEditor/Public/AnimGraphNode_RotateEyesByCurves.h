// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "AnimNode_RotateEyesByCurves.h"
#include "UObject/Object.h"
#include "AnimGraphNode_RotateEyesByCurves.generated.h"

/**
 * 
 */
UCLASS(meta=(Keywords = "Rotate Eyes By Curves"))
class MEDIAPIPEEDITOR_API UAnimGraphNode_RotateEyesByCurves : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()
public:

	// UEdGraphNode interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual FLinearColor GetNodeTitleColor() const override;
protected:
	virtual const FAnimNode_RotateEyesByCurves* GetNode() const override { return &Node; }
private:
	
	UPROPERTY(EditAnywhere, Category=Settings)
	FAnimNode_RotateEyesByCurves Node;
};
