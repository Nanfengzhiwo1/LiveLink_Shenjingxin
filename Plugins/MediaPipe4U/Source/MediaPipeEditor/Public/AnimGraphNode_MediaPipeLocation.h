// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "AnimNode_MediaPipeLocation.h"
#include "AnimGraphNode_MediaPipeLocation.generated.h"

/**
 * 
 */
UCLASS(meta=(Keywords = "MediaPipe Location Solver"))
class MEDIAPIPEEDITOR_API UAnimGraphNode_MediaPipeLocation : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()
public:

	// UEdGraphNode interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual FLinearColor GetNodeTitleColor() const override;
	/** Enable drawing of debug information in viewport. */
protected:
	virtual const FAnimNode_MediaPipeLocation* GetNode() const override { return &Node; }
	virtual void Draw(FPrimitiveDrawInterface* PDI, USkeletalMeshComponent* PreviewSkelMeshComp) const override;
	
private:
	
	UPROPERTY(EditAnywhere, Category=Settings)
	FAnimNode_MediaPipeLocation Node;
};
