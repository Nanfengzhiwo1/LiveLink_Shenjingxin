// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "LiveLinkRetargetAsset.h"
#include "MediaPipeAnimInstance.h"
#include "Animation/AnimInstanceProxy.h"
#include "StandardMediaPipeAnimInstance.generated.h"


struct FStandardMediaPipeAnimInstanceProxy;
/**
 * 
 */
UCLASS(Transient, NotBlueprintable)
class MEDIAPIPE_API UStandardMediaPipeAnimInstance : public UMediaPipeAnimInstance
{
	GENERATED_BODY()
public:
	UStandardMediaPipeAnimInstance();
	virtual ~UStandardMediaPipeAnimInstance() override;

	UFUNCTION(BlueprintCallable, Category = "MediaPipe|Live Link")
	void SetRetargetAsset(TSubclassOf<ULiveLinkRetargetAsset> RetargetAsset);
	
	virtual FAnimInstanceProxy* CreateAnimInstanceProxy() override final;
	virtual bool LoadBoneSettings(TSharedPtr<IBoneSettingsProvider> = nullptr) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(transient)
	TObjectPtr<ULiveLinkRetargetAsset> CurrentRetargetAsset;
	friend FStandardMediaPipeAnimInstanceProxy;
};
