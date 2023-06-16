#pragma once

#include "Components/SceneComponent.h"
#include "GstElementComponent.generated.h"

UCLASS( ClassGroup=(GStreamer) )
class GSTREAMER_API UGstElementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UGstElementComponent();

	virtual void InitializeComponent() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void UninitializeComponent() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void CbPipelineStart(class IGstPipeline* Pipeline) {}
	virtual void CbPipelineStop() {}

	UPROPERTY(Category="GstPipeline", EditAnywhere, BlueprintReadWrite)
	FString PipelineName;

protected:
	static bool IsGStreamerValid();
};
