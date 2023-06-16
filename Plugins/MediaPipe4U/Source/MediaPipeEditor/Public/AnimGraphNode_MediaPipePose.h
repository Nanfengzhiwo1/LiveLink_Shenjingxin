// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "AnimNode_MediaPipePose.h"
#include "AnimGraphNode_MediaPipePose.generated.h"

UCLASS(meta=(Keywords = "MediaPipe Pose Solver"))
class MEDIAPIPEEDITOR_API  UAnimGraphNode_MediaPipePose : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()
public:
	// UPROPERTY(EditAnywhere, Category = Debug)
	// bool bDebugDraw = true;
	
	// UEdGraphNode interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual void Draw(FPrimitiveDrawInterface* PDI, USkeletalMeshComponent* PreviewSkelMeshComp) const override;
protected:
	virtual const FAnimNode_MediaPipePose* GetNode() const override { return &Node; }
	
	// virtual void CustomizePinData(UEdGraphPin* Pin, FName SourcePropertyName, int32 ArrayIndex) const override;
	// virtual void CreateOutputPins() override;

	
private:
	
	UPROPERTY(EditAnywhere, Category=Settings)
	FAnimNode_MediaPipePose Node;
};
