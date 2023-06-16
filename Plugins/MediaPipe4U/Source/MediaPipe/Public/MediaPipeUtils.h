// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include <functional>

#include "CoreMinimal.h"
#include "BoneItem.h"
#include "MediaPipeAnimInstance.h"
#include "MediaPipeAnimMode.h"
#include "MediaPipePluginInfo.h"
#include "TwistCorrectionResult.h"
#include "Components/Image.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Animation/AnimTypes.h"
#include "MediaPipeLandmark.h"
#include "Ground/GroundSolveSettings.h"
#include "Kismet/GameplayStatics.h"

#include "MediaPipeUtils.generated.h"

UENUM(BlueprintType)
enum class EAnchorPosition : uint8
{
	TopLeft,
	TopRight,
	BottomLeft,
	BottomRight,
	TopCenter,
	BottomCenter,
	MiddleCenter
};

UENUM(BlueprintType)
enum class EModificationMode : uint8
{
	Replace,
	Additive
};

USTRUCT(BlueprintType)
struct FSizeInt
{
	GENERATED_BODY()
	
	int Width;
	int Height;
};

UCLASS(meta=(BlueprintThreadSafe, ScriptName = "MediaPipeUtils"))
class UMediaPipeUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	static MEDIAPIPE_API FString PrintAsciiTable(const TArray<TArray<FString>>& Rows);
	static MEDIAPIPE_API FString PrintAsciiTable(const TArray<FString>& Headers, const TArray<TArray<FString>>& Rows);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool IsPlaying();

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool IsInPlayedWorld(const UObject* ActorOrComponent);

	
	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API void SetLogDebug(bool Enabled);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool GetLocalIPAddress(FString& IPAddress);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool AnchorWidgetInCanvas(UWidget* Widget, int TextureWidth, int TextureHeight,
												float MaxImageWidthPercent, float MaxImageHeightPercent,
												EAnchorPosition AnchorPosition);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool SetTextureToImage(UImage* Image, UTexture2D* Texture, int TextureWidth, int TextureHeight,
	                                            float MaxImageWidthPercent, float MaxImageHeightPercent,
	                                            EAnchorPosition AnchorPosition);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool FindSkeletalMeshComponent(AActor* Actor,
															 USkeletalMeshComponent*& OutSkeletalMeshComponent);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool FindMediaPipeAnimationInstance(AActor* Actor,
	                                                         UMediaPipeAnimInstance*& MediaPipeAnimInstance);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API UMediaPipeAnimInstance* FindFirstMediaPipeAnimInstance(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool GetPoseOptimize(UMediaPipeAnimInstance* MediaPipeAnimInstance);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API void SetPoseOptimize(UMediaPipeAnimInstance* MediaPipeAnimInstance, bool bOptimize);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool GetHandOptimize(UMediaPipeAnimInstance* MediaPipeAnimInstance);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API void SetHandOptimize(UMediaPipeAnimInstance* MediaPipeAnimInstance, bool bOptimize);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool SetPoseSmooth(UMediaPipeAnimInstance* MediaPipeAnimInstance, float Smooth);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool IsGroundIKEnabled(UMediaPipeAnimInstance* MediaPipeAnimInstance);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API void SetGroundIKEnabled(UMediaPipeAnimInstance* MediaPipeAnimInstance, bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool SetGroundIKSettings(UMediaPipeAnimInstance* MediaPipeAnimInstance, const FGroundSolveSettings& InSettings);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool GetGroundIKSettings(UMediaPipeAnimInstance* MediaPipeAnimInstance, FGroundSolveSettings& OutSettings);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool GetPoseSmooth(UMediaPipeAnimInstance* MediaPipeAnimInstance, float& Smooth);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool SetFingerSmooth(UMediaPipeAnimInstance* MediaPipeAnimInstance, float Smooth);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool GetFingerSmooth(UMediaPipeAnimInstance* MediaPipeAnimInstance, float& Smooth);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool SetJointLocks(UMediaPipeAnimInstance* MediaPipeAnimInstance,
	                                        const FPoseSolverLockSettings& InLocks);
	
	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API FTwistCorrectionSettings GetTwistCorrectionSettings(UMediaPipeAnimInstance* MediaPipeAnimInstance); 
	
	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool SetTwistCorrectionSettings(UMediaPipeAnimInstance* MediaPipeAnimInstance,
											const FTwistCorrectionSettings& Settings); 

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool FindMediaPipeAnimationMesh(AActor* Actor, USkeletalMeshComponent*& SkeletalMeshComponent);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool SetMediaPipeAnimationMode(AActor* Character, EMediaPipeAnimMode Mode);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool ChangeModelComplexity(UMediaPipeHolisticComponent* MediaPipeComponent,
	                                                EModelComplexity ModelComplexity);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool FindSkeletalMeshComponentByName(AActor* Actor, FName ComponentName,
	                                                          USkeletalMeshComponent*& OutSkeletalMeshComponent);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API FString Base64Utf8Encode(const FString& Text);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool Base64Utf8Decode(const FString& EncodedText, FString& DecodedText);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool ListWebcams(TArray<FString>& OutNames, const FName& ProviderName = FName(TEXT("OpenCV")));

	template<typename  T>
	static T* FindComponent(const UObject* WorldContextObject)
	{
		auto* c = FindComponent(T::StaticClass(), WorldContextObject);
		return c ? static_cast<T*>(c) : nullptr;
	}
	
	static MEDIAPIPE_API UActorComponent* FindComponent(const TSubclassOf<UActorComponent>& ComponentClass, const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API UMediaPipeHolisticComponent* FindMediaPipeHolisticComponent(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool RefreshLicense();
	// UFUNCTION(BlueprintCallable, Category="MediaPipe")
	// static MEDIAPIPE_API UIKRigDefinition* CreateRigControl(const USkeletalMeshComponent* SkeletalMeshComponent, const FHumanoidBoneSettings& InSettings);
	//
	// UFUNCTION(BlueprintCallable, Category="MediaPipe")
	// static MEDIAPIPE_API UIKRetargeter* CreateIKRetargeter(const FRuntimeRetargetSource& From, const FRuntimeRetargetSource& To);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool IsInEditor();

	static FQuat RemoveTwist(const FTransform& InParentTransform, FTransform& InOutTransform,
	                         const FTransform& OriginalLocalTransform, const FVector& InAlignVector);
	
	static FTwistCorrectionResult CorrectTwist(
		FTransform& InOutParentLocalTransform,
		FTransform& InOutLocalTransform,
		const FTransform& OriginalLocalTransform,
		const FVector& InAlignVector,
		const FVector& InParentAlignVector,
		float Alpha,
		float InnerAngleDegree,
		float OuterAngleDegree);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool GetResolutionLimitSize(EResolutionLimits Limitation, int& LimitedWidth, int& LimitedHeight);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API FVector2D CalcImageSize(int TextureWidth, int TextureHeight, float MaxImageWidthPercent,
	                                             float MaxImageHeightPercent, int ScreenWidth, int ScreenHeight);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool LimitSizeByResolution(int TextureWidth, int TextureHeight, EResolutionLimits Limitation, FSizeInt& LimitedSize);
	
	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API bool LimitSize(int TextureWidth, int TextureHeight, int MaxWidth, int MaxHeight, FSizeInt& LimitedSize);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API FString GetDurationString(int64 Millisecond);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API FMediaPipePluginInfo PluginInfo();

	static MEDIAPIPE_API TSharedPtr<IBoneSettingsProvider> CreatePresetBoneSettingsProvider(
		EBonePresets Preset, UMediaPipeRemapAsset* RemapAsset);

	static MEDIAPIPE_API FCompactPoseBoneIndex GetPoseBoneIndex(const FCSPose<FCompactPose>& Pose, const FBoneReference& Bone);
 
	static MEDIAPIPE_API FCompactPoseBoneIndex GetParentPoseBoneIndex(const FCSPose<FCompactPose>& Pose, const FBoneReference& Bone);

	// Get worldspace location of a bone
	static MEDIAPIPE_API FVector GetBoneWorldLocation(USkeletalMeshComponent* SkelComp,
	                                                  FCSPose<FCompactPose>& MeshBases,
	                                                  FCompactPoseBoneIndex BoneIndex);

	// Get worldspace transform of a bone
	static MEDIAPIPE_API FTransform GetBoneWorldTransform(USkeletalMeshComponent* SkelComp,
	                                                      FCSPose<FCompactPose>& MeshBases,
	                                                      FCompactPoseBoneIndex BoneIndex);

	// Get bonespace location of a bone
	static MEDIAPIPE_API FVector GetBoneSpaceLocation(USkeletalMeshComponent* SkelComp,
	                                                  FCSPose<FCompactPose>& MeshBases,
	                                                  FCompactPoseBoneIndex BoneIndex);

	// Get bonespace transform of a bone
	static MEDIAPIPE_API FTransform GetBoneSpaceTransform(USkeletalMeshComponent* SkelComp,
	                                                      FCSPose<FCompactPose>& MeshBases,
	                                                      FCompactPoseBoneIndex BoneIndex);



	static MEDIAPIPE_API TOptional<FBoneTransform> GetBoneTransform(const FTransform& ComponentTransform, FCSPose<FCompactPose>& Pose,
																	FCompactPoseBoneIndex BoneIndex,
																	EBoneControlSpace BoneSpace);

	static MEDIAPIPE_API TOptional<FBoneTransform> GetBoneTransform(FComponentSpacePoseContext& Context,
																	const FBoneReference& Bone,
																	EBoneControlSpace BoneSpace);

	static MEDIAPIPE_API TOptional<FBoneTransform> GetBoneTransform(FComponentSpacePoseContext& Context,
	                                                                FCompactPoseBoneIndex BoneIndex,
	                                                                EBoneControlSpace BoneSpace);

	static MEDIAPIPE_API TOptional<FBoneTransform> RotateBone(
		FComponentSpacePoseContext& Context,
		const FCompactPoseBoneIndex& BoneIndex,
		const FQuat& InRotation,
		EBoneControlSpace BoneSpace = BCS_ComponentSpace,
		EModificationMode Mode = EModificationMode::Replace,
		float Smooth = 0);

	
	static MEDIAPIPE_API std::string ConvertToUTF8(const FString& Str);
	static MEDIAPIPE_API FString ConvertFromUTF8(const std::string& Str);
	static MEDIAPIPE_API FString ConvertFromUTF8(const char* Chars, int Length);
	
	// static MEDIAPIPE_API bool BuildBoneIndices(const FAnimInstanceProxy* AnimInstanceProxy, const FName& BoneName, FSkeletonBone& OutBone);
	// static MEDIAPIPE_API void BuildBoneIndices(const FBoneContainer& RequiredBoneContainer, const FBoneReference& BoneReference, FSkeletonBone& OutBone);
	static MEDIAPIPE_API void BuildBoneIndices(const FBoneContainer& RequiredBoneContainer, FMeshPoseBoneIndex MeshBoneIndex, FSkeletonBone& OutBone);
	static MEDIAPIPE_API void BuildBoneIndices(const FBoneContainer& RequiredBoneContainer, FCompactPoseBoneIndex PoseBoneIndex, FSkeletonBone& OutBone);
	
	static MEDIAPIPE_API bool GetAllBonesInComponentSpace(const UAnimInstance* AnimInstance,
	                                                      TMap<FName, FBoneItem>& OutBones);

	static MEDIAPIPE_API bool GetHeadTowardsFromFaceMesh(const TArray<FMediaPipeLandmark>& FaceMeshes, FVector& Forward, FVector& Up, std::function<FVector(int Index, const FVector&)> Filter);

	static MEDIAPIPE_API bool GetHeadTowardsFromFaceMesh(const TArray<FMediaPipeLandmark>& FaceMeshes, FVector& Forward, FVector& Up);

	static MEDIAPIPE_API FRotator CalculateBodyRotatorFromLandmarks(const TArray<FMediaPipeLandmark>& PoseLandmarks);
	static MEDIAPIPE_API FRotator CalculateHeadRotatorFromFaceMesh(const TArray<FMediaPipeLandmark>& FaceMeshes);

	static MEDIAPIPE_API void BuildBoneChainChildToParent(const FCSPose<FCompactPose>& Pose, const FBoneReference& RootBone, const FBoneReference& TipBone, TArray<FCompactPoseBoneIndex>& OutBoneChain);
	static MEDIAPIPE_API void BuildBoneChainParentToChild(const FCSPose<FCompactPose>& Pose, const FBoneReference& RootBone, const FBoneReference& TipBone, TArray<FCompactPoseBoneIndex>& OutBoneChain);

	static MEDIAPIPE_API bool GetBoneName(const FCompactPose& Pose, FCompactPoseBoneIndex CompactPoseBoneIndex, FName& BoneName);
	static MEDIAPIPE_API bool GetBoneName(const FCompactPose& Pose, FMeshPoseBoneIndex MeshPoseBoneIndex, FName& BoneName);
	
	static const MEDIAPIPE_API TArray<FMediaPipeLandmark> EmptyLandmarks;

	static MEDIAPIPE_API FString GetThirdPartyBinariesFolder(const FString& PluginName, const FString& ThirdPartyFolderName);

	/**
	 * @brief 
	 * @param Date always use __DATE__ marco
	 * @return 
	 */
	static MEDIAPIPE_API FString GetCompiledTime(const char* Date);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	static MEDIAPIPE_API int64 GetTimeMills();
};



