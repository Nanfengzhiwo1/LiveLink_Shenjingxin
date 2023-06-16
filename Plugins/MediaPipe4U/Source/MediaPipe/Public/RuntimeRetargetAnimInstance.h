// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "MediaPipeAnimInstance.h"
#include "RuntimeRetargetSource.h"
#include "Animation/AnimInstance.h"
#include "RuntimeRetargetAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MEDIAPIPE_API URuntimeRetargetAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	
	virtual FAnimInstanceProxy* CreateAnimInstanceProxy() override;
	
	UFUNCTION(BlueprintCallable, Category="RuntimeRetarget")
	FRuntimeRetargetSource& GetSource();

	UFUNCTION(BlueprintCallable, Category="RuntimeRetarget")
	void ConfigureRetarget(const USkeletalMeshComponent* SourceSkeletalMesh, const FHumanoidBoneSettings& SourceBones, const FHumanoidBoneSettings& TargetBones);

	void ApplyBoneSettingsProvider(IBoneSettingsProvider* Provider);

	UFUNCTION(BlueprintCallable, Category="RuntimeRetarget")
	bool IsSuspended() const;

	UFUNCTION(BlueprintCallable, Category="RuntimeRetarget")
	void Suspend();

	UFUNCTION(BlueprintCallable, Category="RuntimeRetarget")
	void Resume();

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IKRig")
	// TObjectPtr<UIKRetargeter> IKRetargeter = nullptr;

	//UIKRetargeter* GetIKRetargeter(bool& bIsIKRetargetChanged);
private:

	FRuntimeRetargetSource Source;
	FAnimInstanceProxy* Proxy;

	void SetupRetargetToProxy();

	int SuspendCounter = 0;
	FHumanoidBoneSettings BoneSettings;
};
