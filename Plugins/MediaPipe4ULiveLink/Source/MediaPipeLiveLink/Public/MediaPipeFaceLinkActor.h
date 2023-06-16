// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "FaceLiveLinkActor.h"
#include "FPSCounter.h"
#include "IBlendShapesNormalizer.h"
#include "IFaceSolution.h"
#include "ImageConsumerProvider.h"
#include "MediaPipeAutoConnect.h"
#include "MediaPipeFaceLinkActor.generated.h"


class FFaceLinkFrameTask;

typedef TMap<EARFaceBlendShape, float> FFaceBlendShapeMap;

USTRUCT(BlueprintType)
struct FFaceFrameData
{
	GENERATED_BODY()
	
	FFaceFrameData() {}

	FFaceFrameData(const FFaceBlendShapeMap& InBlendShapes, const FName& FaceSolution): BlendShapes(InBlendShapes), FaceSolution(FaceSolution)
	{
	
	}
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="LiveLink")
	TMap<EARFaceBlendShape, float> BlendShapes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="LiveLink")
	FName FaceSolution;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFaceCalibrated, const FFaceFrameData&, FaceFrame);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFaceLinkStarted, const FName&, FaceSolution);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFaceLinkStopped, const FName&, FaceSolution);

UCLASS(Blueprintable, BlueprintType)
class MEDIAPIPELIVELINK_API AMediaPipeFaceLinkActor : public AFaceLiveLinkActor, public IImageConsumer, public IImageConsumerProvider
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AMediaPipeFaceLinkActor();

	inline static const FName MediaPipeFaceSolutionName = FName(TEXT("MediaPipe"));
	inline static const FName RemotingSolutionName = FName(TEXT("Remoting"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MediaPipe")
	EMediaPipeAutoConnect AutoConnectToMediaPipe = EMediaPipeAutoConnect::Enabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiveLink")
	FName FaceSolution = MediaPipeFaceSolutionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiveLink", meta=(ClampMin=1,  ClampMax=65535, ToolTip="Use only for 'Remoting' face solution."))
	int RemotingServicePort = 22345;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiveLink")
	bool bAllowSolutionDegradation = true;

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	bool ConnectToMediaPipeInLevel();

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	bool ConnectToMediaPipe(UMediaPipeHolisticComponent* MediaPipeComponent);

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	bool IsMediaPipeConnected() const;

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	void DisconnectFromMediaPipe();

	UFUNCTION(BlueprintCallable, CallInEditor, Category="LiveLink")
	float GetFPS() const;
	
	UFUNCTION(BlueprintCallable, CallInEditor, Category="LiveLink")
	const FName& GetActualFaceSolution();

	UFUNCTION(BlueprintCallable, CallInEditor, Category="LiveLink")
	void PerformCalibrationImmediately(const TMap<EARFaceBlendShape, float>& CalibrationFrame, bool RaiseOnFaceCalibratedEvent = true);

	UFUNCTION(BlueprintCallable, CallInEditor, Category="LiveLink")
	void PerformCalibration();

	UFUNCTION(BlueprintCallable, CallInEditor, Category="LiveLink")
	void UnCalibration();

	UPROPERTY(BlueprintAssignable, Category = "LiveLink|Event")
	FOnFaceCalibrated OnFaceCalibrated;

	UPROPERTY(BlueprintAssignable, Category = "LiveLink|Event")
	FOnFaceLinkStarted OnFaceLinkStarted;

	UPROPERTY(BlueprintAssignable, Category = "LiveLink|Event")
	FOnFaceLinkStopped OnFaceLinkStopped;

protected:
	virtual FText GetLiveLinkTypeName() override;
	virtual const FName& GetLiveLinkDeviceID() const override;
	
	// image consumer interface
	virtual bool CanConsume() override;
	virtual bool Consume(const FImageSourceInfo& SourceInfo, IMediaPipeTexture* Texture) override;
	//image consumer provider
	virtual IImageConsumer* GetImageConsumer() override;
	
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void BeginDestroy() override;

	void SubscribeMediaPipeEvents(UMediaPipeHolisticComponent* MediaPipeHolisticComponent);
	void UnsubscribeMediaPipeEvents(UMediaPipeHolisticComponent* MediaPipeHolisticComponent);
	bool DetermineFaceSolution(FName& OutSolutionName);

	void HandleFaceSolutionSolved(TSharedPtr<FARBlendShapeMap> ShaderRefBase);
	void BeforeMediaPipeStart(FMediaPipeTaskContext& Context);
	void OnMediaPipeStarted(UMediaPipeHolisticComponent* MediaPipeHolisticComponent);
	void OnMediaPipeStopped(UMediaPipeHolisticComponent* MediaPipeHolisticComponent);
	void OnMediaPipeStartFailed(UMediaPipeHolisticComponent* MediaPipeHolisticComponent);
	
	void OnMediaPipeHolisticInitialized(UMediaPipeHolisticComponent* MediaPipeHolisticComponent);
	void OnMediaPipeHolisticUninitialized(UMediaPipeHolisticComponent* MediaPipeHolisticComponent);
	
	TQueue<IMediaPipeTexture*> FrameQueue;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	FCriticalSection EventSubMutex;
	FFPSCounter FPSCounter;
	TWeakObjectPtr<UMediaPipeHolisticComponent> HookedMediaPipeHolisticComponent;
	FName ActualSolutionName{};
	FName LiveLinkDeviceID{};
	void PrepareFaceLink(FMediaPipeTaskContext& Context);
	void CloseFaceLink(UMediaPipeHolisticComponent* MediaPipeHolisticComponent);
	
	void ClearSolution(UMediaPipeHolisticComponent* MediaPipeHolisticComponent);
	void StartFrameTaskThread(); 
	void StopFrameTaskThread();
	bool bSolutionInitialized = false;
	bool bIsStaticImage = false;
	void ClearFrameQueue();
	bool bIsCalibrationRequested = false;
	bool bUnCalibrationRequested = false;
	bool bAutoReconnectToMediaPipe = true;
	FDelegateHandle FaceSolveHandle;
	TSharedPtr<IFaceSolution> FaceSolutionInstance;
	TSharedPtr<IBlendShapesNormalizer> BlendShapeNormalizer;
	TSharedPtr<FFaceLinkFrameTask> FrameTask;
	void RemoveHeadExpressions(TMap<EARFaceBlendShape, float>& InOutFaceBlendShapes);
};

