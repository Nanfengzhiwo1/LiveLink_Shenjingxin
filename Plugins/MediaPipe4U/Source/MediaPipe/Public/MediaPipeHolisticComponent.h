// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "CameraParams.h"
#include "DynamicTexture.h"
#include "MediaPipeFaceMesh.h"
#include "MediaPipeHolisticOptions.h"
#include "MediaPipeImageSource.h"
#include "MediaPipeLandmark.h"
#include "MediaPipeSourceInfo.h"
#include "VideoDisplay.h"
#include "WebcamImageSourceComponent.h"
#include "Components/ActorComponent.h"
#include "MediaPipeHolisticComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnVideoTextureCreated, UTexture2D*, NewTexture, int, TextureWidth, int, TextureHeight);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMediaLifeCycle);

class FMediaPipeConnector;
class SMediaPipeCapturePanel;
class IUmpPacketCallback;
class UMediaPipeHolisticComponent;

USTRUCT(BlueprintType)
struct MEDIAPIPE_API FMediaPipeTaskContext
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MediaPipe", Transient)
	UMediaPipeHolisticComponent* MediaPipeHolisticComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MediaPipe", Transient)
	TScriptInterface<IMediaPipeImageSource> ImageSourceInfo{};

	IMediaPipeImageSource* NativeImageSourceInfo = nullptr;

	MediaPipeGraphCnf* GraphConfiguration = nullptr;
};

UCLASS(ClassGroup="MediaPipe", meta=(BlueprintSpawnableComponent))
class MEDIAPIPE_API UMediaPipeHolisticComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	typedef TMap<FName, float> MediaPipeClassifications;
	
	DECLARE_EVENT_ThreeParams(UMediaPipeHolisticComponent, FVideoTextureCreatedEvent, UTexture2D*, int, int);
	DECLARE_EVENT_OneParam(UMediaPipeHolisticComponent, FBeforeMediaPipeHolisticStart, FMediaPipeTaskContext&);
	DECLARE_EVENT_OneParam(UMediaPipeHolisticComponent, FOnMediaPipeHolisticStateChanged, UMediaPipeHolisticComponent*);
	DECLARE_EVENT_TwoParams(UMediaPipeHolisticComponent, FLandmarksOutEvent, const TSharedPtr<TArray<FMediaPipeLandmark>>&, const FMediaPipeSourceInfo&);
	DECLARE_EVENT_TwoParams(UMediaPipeHolisticComponent, FaceGeometryOutEvent, const TSharedPtr<FMediaPipeFaceMesh>&, const FMediaPipeSourceInfo&);
	DECLARE_EVENT_TwoParams(UMediaPipeHolisticComponent, FClassificationsOutEvent, const TSharedPtr<MediaPipeClassifications>&, const FMediaPipeSourceInfo&);
	
	
	//multi_face_geometry
	FLandmarksOutEvent& PoseLandmarksEventTrigger() { return PoseLandmarksEvent; }
	FLandmarksOutEvent& LeftHandLandmarksEventTrigger() { return LeftHandLandmarksEvent; };
	FLandmarksOutEvent& RightHandLandmarksEventTrigger() { return RightHandLandmarksEvent; }
	FLandmarksOutEvent& FaceLandmarksEventTrigger() { return FaceLandmarksEvent; }
	FLandmarksOutEvent& PoseWorldLandmarksEventTrigger() { return PoseWorldLandmarksEvent; }
	FaceGeometryOutEvent& FaceGeometryEventTrigger() { return FaceGeometryEvent; }
	FClassificationsOutEvent& FaceBlendShapesEventTrigger() { return FaceBlendShapesEvent; }
	FVideoTextureCreatedEvent& VideoTextureCreatedEventTrigger() { return VideoTextureCreatedEvent; }


	FOnMediaPipeHolisticStateChanged& OnMediaPipeHolisticStoppedTrigger() { return OnStoppedEvent; }
	FBeforeMediaPipeHolisticStart& BeforeMediaPipeHolisticStartTrigger() { return BeforeStartEvent;  }
	FOnMediaPipeHolisticStateChanged& OnMediaPipeHolisticStartFailedTrigger() { return OnStartFailedEvent;  }
	FOnMediaPipeHolisticStateChanged& OnMediaPipeHolisticStartedTrigger() { return OnStartedEvent; }
	
	// Sets default values for this component's properties
	UMediaPipeHolisticComponent();
	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	IMediaPipeImageSource* GetCurrentImageSource() const;

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	bool IsNativeImageSource() const;

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	bool IsWebcamCapture();

	UFUNCTION(BlueprintCallable, Category="MediaPipe")
	UTexture2D* GetVideoTexture();

	UFUNCTION(BlueprintCallable, Category="MediaPipe") 
	bool GetImageSourceFPS(float& SourceFrameRate, float& StreamingFrameRate);


	UFUNCTION(Category="MediaPipe", BlueprintCallable)
	FCameraParams  GetCurrentCameraParams();
	
	UFUNCTION(Category="MediaPipe", BlueprintCallable)
	bool StartCamera(int DeviceId = 0, int ResolutionX = 1280, int ResolutionY = 720, int FPS = 30);

	UFUNCTION(Category="MediaPipe", BlueprintCallable)
	bool StartImageSource(const TScriptInterface<IMediaPipeImageSource>& ImageSource);

	UFUNCTION(Category="MediaPipe", BlueprintCallable)
	float GetSourceTextureAspectRatio() const { return MediaPipeSourceInfo.IsValid() ? static_cast<float>(MediaPipeSourceInfo.ImageWidth) / MediaPipeSourceInfo.ImageHeight : 0.0f; }

	UFUNCTION(Category="MediaPipe", BlueprintCallable)
	virtual void Stop();

	UFUNCTION(Category="MediaPipe", BlueprintCallable)
	bool IsRunning() const;

	UPROPERTY(Category="MediaPipe", BlueprintReadWrite, EditAnywhere)
	EVideoDisplay VideoDisplay = EVideoDisplay::Annotated;

	UPROPERTY(Category="MediaPipe", BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "VideoDisplay == EVideoDisplay::Annotated"))
	EMediaPipeAnnotations OverlayAnnotations = EMediaPipeAnnotations::HolisticTracking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	FMediaPipeHolisticOptions Options;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MediaPipe|Image Source", Transient)
	FMediaPipeSourceInfo MediaPipeSourceInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	int GraphTimeoutSeconds = 10;

	UFUNCTION(Category="MediaPipe", BlueprintCallable)
	bool IsStaticImageSource();

	bool StartImageSource(IMediaPipeImageSource* ImageSource);

	//Blueprint Events
	UPROPERTY(Category="MediaPipe|Events", BlueprintAssignable)
	FOnVideoTextureCreated OnVideoTextureCreated;
	
	UPROPERTY(Category="MediaPipe|Events", BlueprintAssignable)
	FOnMediaLifeCycle OnMediaPipeInitialized;

	UPROPERTY(Category="MediaPipe|Events", BlueprintAssignable)
	FOnMediaLifeCycle OnMediaPipeStarted;

	UPROPERTY(Category="MediaPipe|Events", BlueprintAssignable)
	FOnMediaLifeCycle OnMediaPipeStopped;

	UPROPERTY(Category="MediaPipe|Events", BlueprintAssignable)
	FOnMediaLifeCycle OnMediaPipeThreadFault;

	//ImageSource
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe|Image Source")
	EResolutionLimits  SourceResolutionLimits = EResolutionLimits::P720_16_9;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe|Image Source")
	bool  bSourceHorizontalFlip = false;
	
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
 	virtual bool HandlePoseLandmarks(class IUmpObserver* Observer, void* Packet);
	virtual bool HandleLeftHandLandmarks(class IUmpObserver* Observer, void* Packet);
	virtual bool HandleRightHandLandmarks(class IUmpObserver* Observer, void* Packet);
	virtual bool HandleFaceLandmarks(class IUmpObserver* Observer, void* Packet);
	virtual bool HandlePoseWorldLandmarks(class IUmpObserver* Observer, void* Packet);
	virtual bool HandleFaceGeometry(class IUmpObserver* Observer, void* Packet);
	virtual bool HandleFaceBlendShapes(class IUmpObserver* Observer, void* Packet);

private:

	UPROPERTY(Transient)
	TObjectPtr<UWebcamImageSourceComponent> WebcamSource;
	
	void ClearWebcamImageSource();
	
	FLandmarksOutEvent PoseWorldLandmarksEvent;
	FLandmarksOutEvent PoseLandmarksEvent;
	FLandmarksOutEvent LeftHandLandmarksEvent;
	FLandmarksOutEvent RightHandLandmarksEvent;
	FLandmarksOutEvent FaceLandmarksEvent;
	FClassificationsOutEvent FaceBlendShapesEvent;
	FaceGeometryOutEvent FaceGeometryEvent;

	TMap<FString, TSharedPtr<IUmpPacketCallback>> Observers;
	
	bool bIsPipelineRunning;

	TUniquePtr<FDynamicTexture> VideoTexture;
	TWeakObjectPtr<UTexture2D> ImageSourceTexture;

	UPROPERTY()
	TScriptInterface<IMediaPipeImageSource> ScriptImageSource;
	IMediaPipeImageSource* NativeImageSource;

	FCameraParams CurrentCamera;

	//pipeline linstener
	virtual void OnFrameOut(IMediaPipeOutFrame* InMat);
	bool StartInternal(IMediaPipeImageSource* InImageSource);
	bool StopInternal(long long SessionId);
	void DoStop();

	virtual  void OnPipelineWorkThreadFault(long long SessionId);
	virtual void OnExitPipelineWorkThread(long long SessionId);
	virtual void OnEnterPipelineWorkThread(long long SessionId);
	virtual  void OnImageSizeReceived(int Width, int Height);
	void SetCurrentImageSource(IMediaPipeImageSource* ImageSource);
	
	void SetupObservers();
	void ClearObservers();

	void CreateObserver(FString StreamName,  TMemFunPtrType<false, UMediaPipeHolisticComponent, bool (IUmpObserver*, void*)>::Type Callback);
	
	UFUNCTION()
	void RaiseTextureCreated(UTexture2D* Texture, int Width, int Height);

	FBeforeMediaPipeHolisticStart BeforeStartEvent;
	FOnMediaPipeHolisticStateChanged OnStartFailedEvent;
	FOnMediaPipeHolisticStateChanged OnStoppedEvent;
	FOnMediaPipeHolisticStateChanged OnStartedEvent;
	FVideoTextureCreatedEvent VideoTextureCreatedEvent;
	
	friend FMediaPipeConnector;
	friend SMediaPipeCapturePanel;
private:
	mutable FCriticalSection StateCS;
	int64 CurrentSessionId = 0;
	bool bInitialized = false;
	bool bIsStopping = false;
};

