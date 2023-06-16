// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "BonePresets.h"
#include "HumanoidBoneSettings.h"
#include "IBoneSettingsProvider.h"
#include "RuntimeRetargetAnimInstance.h"
#include "GameFramework/Character.h"
#include "MediaPipeRetargetCharacter.generated.h"

UCLASS(BlueprintType)
class MEDIAPIPE_API AMediaPipeRetargetCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMediaPipeRetargetCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Retarget", meta=(EditCondition="SourceBySkeletalMesh == nullptr"))
	TObjectPtr<AActor> SourceByActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Retarget", meta=(EditCondition="SourceByActor == nullptr"))
	TObjectPtr<USkeletalMeshComponent> SourceBySkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Retarget", meta=(EditCondition="BonePreset == EBonePresets::Custom"))
	FHumanoidBoneSettings BoneSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Retarget|Remap")
	EBonePresets BonePreset = EBonePresets::UE5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Retarget|Remap")
	TObjectPtr<UMediaPipeRemapAsset> RemapAsset;

	void ApplyBoneSettingsProvider(IBoneSettingsProvider* Provider);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool isValid;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
