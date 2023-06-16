// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FaceSmoothParams.h"
#include "IFaceDataPostProcessor.h"
#include "IFaceLinkLinkSource.h"
#include "MediaPipeHolisticComponent.h"
#include "GameFramework/Actor.h"
#include "BlendShapesPublishedEventArguments.h"
#include "FaceLiveLinkActor.generated.h"

class AFaceLiveLinkActor;



DECLARE_EVENT_OneParam(AFaceLiveLinkActor, FBlendShapesPublishedEvent, const FBlendShapesPublishedEventArguments&);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBlendShapesPublished , const FBlendShapesPublishedEventArguments&, EventArgs);

UCLASS(Abstract)
class MEDIAPIPE_API AFaceLiveLinkActor : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	AFaceLiveLinkActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe")
	bool bDisabled = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiveLink")
	FName LiveLinkSubjectName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiveLink")
	FFaceSmoothParams SmoothParams{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiveLink")
	bool bSmoothEnabled = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiveLink")
	bool bPublishHeadRotation = true;

	FBlendShapesPublishedEvent& BlendShapesPublishedTrigger();

	UPROPERTY(Category="MediaPipe|Events", BlueprintAssignable)
	FOnBlendShapesPublished OnBlendShapesPublished;
	
protected:
	virtual const FName& GetLiveLinkDeviceID() const PURE_VIRTUAL(AFaceLiveLinkActor::GetLiveLinkTypeName, return DefaultDeviceID;);
	virtual FText GetLiveLinkTypeName() PURE_VIRTUAL(AFaceLiveLinkActor::GetLiveLinkTypeName, return FText::FromString("MediaPipe Live Link");)
	virtual bool PostProcess(const TSharedRef<FARBlendShapeMap>& BlendShapes, bool bIsStatic);
	TSharedPtr<IFaceDataPostProcessor> GetSmoothProcessor();
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void AddLiveLinkSource();
	void RemoveLiveLinkSource();
	TSharedPtr<IFaceLinkLinkSource> Source;
	
public:
	virtual void Tick(float DeltaTime) override;
private:
	FGuid LiveLinkSourceID;
	FName DefaultDeviceID = FName(TEXT("M4U_LiveLinkSource"));
	TSharedPtr<IFaceDataPostProcessor> SmoothProcessor;
	bool WriteBlendShapeWeights(const FARBlendShapeMap& Weights) const;
	FCriticalSection LiveLinkSourceLock;
	FFacePostProcessingContext PostProcessingContext;

	FBlendShapesPublishedEvent BlendShapesPublishedEvent;
};
