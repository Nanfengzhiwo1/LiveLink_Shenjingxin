// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BvhBoneCacheItem.h"
#include "GameFramework/Actor.h"
#include "Animation/AnimNodeBase.h"
#include "HumanoidBoneSettings.h"
#include "IBvHWriter.h"
#include "HumanoidBones.h"
#include "MediaPipeAnimExtensionActor.h"
#include "MediaPipeRemapAsset.h"
#include "MediaPipeBVHRecorder.generated.h"

UCLASS(BlueprintType)
class MEDIAPIPEBVH_API AMediaPipeBVHRecorder : public AMediaPipeAnimExtensionActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMediaPipeBVHRecorder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BVH")
	float FrameRate = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BVH")
	bool bUseRootBone = false;

	UFUNCTION(BlueprintCallable, Category="BVH")
	int64 GetFrameCount() const;

	UFUNCTION(BlueprintCallable, Category="BVH")
	FString GetFrameTimeString() const;

	UFUNCTION(BlueprintCallable, Category="BVH")
	void Open();

	UFUNCTION(BlueprintCallable, Category="BVH")
	bool IsOpened();

	UFUNCTION(BlueprintCallable, Category="BVH")
	bool HasData();

	UFUNCTION(BlueprintCallable, Category="BVH")
	bool CloseAndSave(const FString& File);

	UFUNCTION(BlueprintCallable, Category="BVH")
	void Close();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BVH")
	bool AutoStop = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BVH")
	bool bFirstFrameWithRefPose = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BVH")
	bool bDebugFormat = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BVH")
	bool bHighPrecision = false;

#pragma region ExtensionsInterface
	virtual FName GetExporterName() override;
	virtual void OnAddOn(UAnimInstance* AnimInstance) override;
	virtual void BeforePoseSolve(const FMediaPipeFrame& Frame, FComponentSpacePoseContext& Context) override;
	virtual void AfterAllSolved(const FMediaPipePoseContext& MediaPipePoseContext) override;
	virtual void OnCaptureStopped() override;
#pragma endregion 
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	bool bBoneCached = false;
	bool bInitialized = false;
	bool bOpened = false;
	bool bHasData = false;
	float CurrentFrameRate = 0;
	float SecondsPerFrame = 0;
	float LatestRecordDeltaSeconds = 0;
	void InitJoints();
	void Initialize(const FComponentSpacePoseContext& Context);
	bool AddMotion(const USkeleton* Skeleton);
	bool AddMotion(FComponentSpacePoseContext& Context);
	bool CacheBones(const TWeakPtr<FHumanoidBoneSettings> BoneSettings);
	bool AddJointChain(EHumanoidBones Bone, bool bIsRoot = false);
	bool AddJointChain(FName Tip, bool bIsRoot = false);
	bool GetJointTransform(const FName& BoneName, FCSPose<FCompactPose>& InPose, FTransform& BoneTransform) const;
	bool WriteJointMotion(const FName& JointName, std::function<FTransform(const FBvhBoneCacheItem& BoneItem)> TransformGetter);
	TSharedPtr<IBvHWriter> Writer;
	FTransform ComponentTransform;
	TMap<FName, FBvhBoneCacheItem> Bones;
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;
	TMap<EHumanoidBones, FName> BoneNameMapping;
	
};

