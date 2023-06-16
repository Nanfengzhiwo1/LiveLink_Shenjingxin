// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_ComponentToLocalSpace.h"
#include "AnimNode_MediaPipeControlRigAlign.h"
#include "OptionalPinRigControl.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraph/EdGraphNode.h"
#include "UObject/ObjectSaveContext.h"
#include "AnimGraphNode_MediaPipeControlRigAlign.generated.h"
/**
 * 
 */

UCLASS(meta=(Keywords = "MediaPipe ControlRig"))
class MEDIAPIPEEDITOR_API UAnimGraphNode_MediaPipeControlRigAlign : public UAnimGraphNode_Base
{
 GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category=Settings)
	FAnimNode_MediaPipeControlRigAlign Node;
	
	// UEdGraphNode interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual FLinearColor GetNodeTitleColor() const override;
	const TArray<FName>& GetAvailableControls() const;
protected:
	TArray<FOptionalPinRigControl> GetCustomProperties();
	 void OnControlPinChanged(FName Name, bool bPin, IDetailLayoutBuilder* DetailLayoutBuilder);
	 void OnControlBindChanged(FName PropertyName, FName ControlName);
	 void OnInstanceClassChanged(IDetailLayoutBuilder* DetailLayoutBuilder);
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
	virtual void CreateCustomPins(TArray<UEdGraphPin*>* OldPins) override;
	virtual void ValidateNodeDuringCompilation(FCompilerResultsLog& MessageLog) const override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PreSave(FObjectPreSaveContext SaveContext) override;
private:
	void ExportToNodeData();
	void SetControlToAnimNode(const FName& PropertyName, const FName& ControlName);
	void RebuildExposedProperties();
	UPROPERTY(EditAnywhere, Category="MediaPipe")
	TMap<FName, FOptionalPinRigControl> CustomPinProperties;
	TArray<FName> ControlsInControlRig;
};