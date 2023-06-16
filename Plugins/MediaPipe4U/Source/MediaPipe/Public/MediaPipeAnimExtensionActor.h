// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MediaPipeAnimContext.h"
#include "MediaPipeAnimExtensions.h"
#include "MediaPipeFrame.h"
#include "GameFramework/Actor.h"
#include "Animation/AnimNodeBase.h"
#include "MediaPipeAnimExtensionActor.generated.h"

UCLASS(Abstract)
class MEDIAPIPE_API AMediaPipeAnimExtensionActor : public AActor, public IMediaPipeAnimExtensions
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMediaPipeAnimExtensionActor();
	UFUNCTION(BlueprintGetter)
	virtual bool IsDisabled() override;
	UFUNCTION(BlueprintSetter)
	virtual void SetDisabled(bool Disabled) override;
	virtual FString GetExtensionName() override { return this->GetClass()->GetName(); };

	virtual void OnAddOn(UAnimInstance* AnimInstance) override {}
	virtual void OnCaptureStarted() override {}
	virtual void OnCaptureStopped() override {}
	virtual void BeforePoseSolve(const FMediaPipeFrame& Frame, FComponentSpacePoseContext& Context) override {}
	virtual void AfterPoseSolved(const FMediaPipeFrame& Frame, FComponentSpacePoseContext& Context) override {}
	virtual void BeforeHandSolve(const FMediaPipeFrame& LeftHandFrame, const FMediaPipeFrame& RightHandFrame, FComponentSpacePoseContext& Context) override {}
	virtual void AfterHandSolved(const FMediaPipeFrame& LeftHandFrame, const FMediaPipeFrame& RightHandFrame, FComponentSpacePoseContext& Context) override {}
	virtual  void AfterAllSolved(const FMediaPipePoseContext&) override {}
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	TSharedPtr<FMediaPipeAnimContext> GetAnimContext(const FComponentSpacePoseContext& Context) const;

	UPROPERTY(BlueprintGetter=IsDisabled, BlueprintSetter=SetDisabled, Category="MediaPipe")
	bool bDisabled = false;
};
