// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "BonePresets.h"
#include "IBoneSettingsProvider.h"
#include "IHandSolver.h"
#include "BodyIKControls.h"
#include "CalibrationPolicy.h"
#include "IKControlsAlignment.h"
#include "ILocationSolver.h"
#include "IPoseSolver.h"
#include "MediaPipeAnimContext.h"
#include "MediaPipeAnimMode.h"
#include "MediaPipeAutoConnect.h"
#include "MediaPipeSource.h"
#include "MediaPipeHolisticComponent.h"
#include "MediaPipeRemapAsset.h"
#include "TransformValueType.h"
#include "Animation/AnimInstance.h"
#include "Head/IHeadSolver.h"
#include "LiveLinkInterface/Public/LiveLinkTypes.h"
#include "MediaPipeAnimInstance.generated.h"


/**
 * 
 */
UCLASS(BlueprintType)
class MEDIAPIPE_API UMediaPipeAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UMediaPipeAnimInstance();

	TSharedPtr<ILocationSolver> GetLocationSolver() { return LocationSolver; }
	TSharedPtr<IPoseSolver> GetPoseSolver() { return PoseSolver; }
	TSharedPtr<IHandSolver> GetHandsSolver() { return HandsSolver; }
	TSharedPtr<IHeadSolver> GetHeadSolver() { return HeadSolver; }
	TSharedPtr<FSolverUtils> GetSolverUtils() { return SolverUtils; }
	TSharedPtr<IGroundSolver> GetGroundIKSolver() { return GroundIKSolver; }

	const TSharedPtr<FMediaPipeAnimContext>& GetContext() const;

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	void GetSolverFPS(float& AnimationFPS, float& MediaPipeFPS);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MediaPipe")
	EMediaPipeAnimMode Mode = EMediaPipeAnimMode::FullBody;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MediaPipe")
	bool ResetOnPipelineStopped = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MediaPipe")
	bool bSolveFingers = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MediaPipe")
	bool bSolveHeadFromFaceMesh = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MediaPipe")
	bool bSolveLocation = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MediaPipe")
	float MinPoseScoreThresh = 0.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MediaPipe")
	float MinHandScoreThresh = 0.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MediaPipe")
	bool bTwistCorrectionEnabled = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MediaPipe")
	EMediaPipeAutoConnect AutoConnectToMediaPipe = EMediaPipeAutoConnect::Enabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MediaPipe|LiveLink")
	FLiveLinkSubjectName LiveLinkSubject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MediaPipe|LiveLink")
	bool bLiveLinkEnabled = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MediaPipe|Debug")
	bool bDebugDraw = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MediaPipe|Calibration", meta = (PinShownByDefault, ClampMin=1.f, ClampMax=60.f))
	int CalibrationCountdownSeconds = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MediaPipe|Calibration")
	ECalibrationPolicy CalibrationPolicy = ECalibrationPolicy::AlwaysOnStart;


	FVector OriginHipLocation;
	FVector OriginActorLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	EBonePresets BonePreset = EBonePresets::UE5;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MediaPipe",  meta=(EditCondition="BonePreset == EBonePresets::Custom"))
	TObjectPtr<UMediaPipeRemapAsset> BoneRemap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MediaPipe")
	TObjectPtr<UPoseAsset> PoseAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MediaPipe")
	FName PoseForInit = NAME_None;
	
	virtual void NativeBeginPlay() override;

	TWeakPtr<FHumanoidBoneSettings> GetBoneSettings();

	virtual FAnimInstanceProxy* CreateAnimInstanceProxy() override;

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	bool IsMediaPipeRunning();

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	bool IsPaused() const;

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	void Pause() const;

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	void Resume() const;

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	bool ConnectToMediaPipeInLevel();

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	bool ConnectToMediaPipe(UMediaPipeHolisticComponent* MediaPipeComponent);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	bool IsMediaPipeConnected() const;

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	void DisconnectFromMediaPipe();

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	bool LoadBoneSettingsFromJsonContent(const FString& JsonContent);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	bool LoadBoneSettingsFromJsonFile(const FString& FilePath);

	UFUNCTION(BlueprintCallable, Category="MediaPipe|Calibration")
	void PerformCalibration();

	UFUNCTION(BlueprintCallable, Category="MediaPipe|Calibration")
	void UnCalibration();

	UFUNCTION(BlueprintCallable, Category="MediaPipe|Calibration")
	int GetCalibrationRemainingSeconds();
	
	virtual bool LoadBoneSettings(TSharedPtr<IBoneSettingsProvider> = nullptr);

	UFUNCTION(BlueprintPure, Category="MediaPipe", meta=(BlueprintThreadSafe))
	bool GetBodyControlIK(EBoneControlSpace Space,ETransformValueType ValueType,FBodyIKControls& IKControls) const;

	FIKControlsAlignment* GetIKControlsAlignment() const;
protected:
	void PrepareSolvers(IBoneSettingsProvider* Provider);
	TSharedRef<FHumanoidBoneSettings> BoneSettings = MakeShared<FHumanoidBoneSettings>();

	virtual void OnBoneSettingsApplied(FHumanoidBoneSettings& Settings) {};

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUninitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativePostEvaluateAnimation() override;

	
	virtual void HandlePoseOut(const TSharedPtr<TArray<FMediaPipeLandmark>>& Landmarks, const FMediaPipeSourceInfo& SourceInfo);
	virtual void HandlePoseWorldOut(const TSharedPtr<TArray<FMediaPipeLandmark>>& Landmarks, const FMediaPipeSourceInfo& SourceInfo);
	virtual void HandleFaceGeometryOut(const TSharedPtr<FMediaPipeFaceMesh>& FaceGeometry, const FMediaPipeSourceInfo& SourceInfo);
	virtual void HandleFaceLandmarksOut(const TSharedPtr<TArray<FMediaPipeLandmark>>& Landmarks, const FMediaPipeSourceInfo& SourceInfo);
	virtual void HandleLeftHandOut(const TSharedPtr<TArray<FMediaPipeLandmark>>& Landmarks, const FMediaPipeSourceInfo& SourceInfo);
	virtual void HandleRightHandOut(const TSharedPtr<TArray<FMediaPipeLandmark>>& Landmarks, const FMediaPipeSourceInfo& SourceInfo);

	virtual void HandleMediaPipeHolisticStopped(UMediaPipeHolisticComponent* Component);
	virtual void HandleBeforeMediaPipeHolisticStart(FMediaPipeTaskContext& Context);
	virtual void HandleMediaPipeHolisticStarted(UMediaPipeHolisticComponent* Component);
	virtual void HandleMediaPipeHolisticUninitialized(UMediaPipeHolisticComponent* Component);
	virtual void HandleMediaPipeHolisticInitialized(UMediaPipeHolisticComponent* Component);
	void ResetMediaPipeState();

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	void ResetAllSolvers();

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	void EnableAllSolvers(bool bIsEnabled);

	UFUNCTION(BlueprintCallable, Category="MediaPipe|Calibration")
	void ResetCalibrationCounter();

	UFUNCTION(BlueprintCallable, Category="MediaPipe|Calibration")
	bool CalibrationCount();

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<UMediaPipeHolisticComponent> MediaPipeHolisticComponent;

	TSharedPtr<FMediaPipeSource> GetMediaPipeSource();
	bool bBoneCached = false;
	bool bAutoReconnect = false;
	void RegisterEventHandler();
	void UnRegisterEventHandler() const;

	//int CalibrationSecondsElapsed = 0;
	float CalibrationSecondsRemaining = 0;
	

	void DrawIKChain(const FVector& A, const FVector& B, const FVector& C);

	TSharedPtr<FMediaPipeAnimContext> SharedContext;
	
	TSharedPtr<IPoseSolver> PoseSolver;
	TSharedPtr<ILocationSolver> LocationSolver;
	TSharedPtr<IHandSolver> HandsSolver;
	TSharedPtr<IHeadSolver> HeadSolver;
	TSharedPtr<FSolverUtils> SolverUtils;
	TSharedPtr<IGroundSolver> GroundIKSolver;

	TArray<TSharedPtr<ISolverProvider>> AllProviders;

	static void UpdateSolverEnabled(TWeakObjectPtr<UMediaPipeHolisticComponent>Component, UMediaPipeAnimInstance* AnimInstance);
};




