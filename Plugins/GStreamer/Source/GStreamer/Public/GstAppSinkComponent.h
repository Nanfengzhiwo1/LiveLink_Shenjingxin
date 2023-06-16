#pragma once

#include "GstElementComponent.h"
#include "GstAppSinkImpl.h"
#include "GstTexture.h"
#include "GstVideoFormat.h"
#include "GstAppSinkComponent.generated.h"

class UGstAppSinkComponent;

USTRUCT()
struct FGstSampleReference
{
	GENERATED_BODY();

	IGstSample* Sample = nullptr;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FGstTextureCreatedSignature, UGstAppSinkComponent*, AppSink, UTexture2D*, NewTexture, EGstVideoFormat, Format, int, Width, int, Height);
DECLARE_EVENT_OneParam(UGstAppSinkComponent, OnGstTextureUpdated, FGstTextureContext&);

UCLASS( ClassGroup=(GStreamer), meta=(BlueprintSpawnableComponent) )
class GSTREAMER_API UGstAppSinkComponent : public UGstElementComponent, public IGstAppSinkCallback, public IGstTextureCallback, public ITextureUpdateListener
{
	GENERATED_BODY()

public:	

	UGstAppSinkComponent();

	// UActorComponent
	void UninitializeComponent() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// UGstElementComponent
	virtual void CbPipelineStart(class IGstPipeline* Pipeline) override;
	virtual void CbPipelineStop() override;

	// IGstAppSinkCallback
	virtual void CbGstSampleReceived(class IGstSample* Sample) override;

	// IGstTextureCallback
	virtual void CbGstTextureCreated() override;

	UPROPERTY(Category="GstAppSink", EditAnywhere, BlueprintReadWrite)
	FString AppSinkName;

	UPROPERTY(Category="GstAppSink", EditAnywhere, BlueprintReadWrite)
	bool AppSinkEnabled;

	UFUNCTION(Category="GstAppSink", BlueprintCallable)
	UTexture2D* GetTexture() { return Texture->GetTextureObject(); }

	UPROPERTY(Category="GstAppSink", BlueprintAssignable)
	FGstTextureCreatedSignature OnGstTextureCreated;

	FGstTextureCreatedSignature& OnGstTextureCreatedTrigger() { return OnGstTextureCreated; }
	OnGstTextureUpdated& OnGstTextureUpdatedTrigger() { return OnGstTextureUpdatedEvent; }
protected:
	/*GStreamer caps for app sink (optional), example: video/x-raw,format=(string)RGBA*/
	FString AppSinkCaps = TEXT("");
	
	void ResetState();
	

	IGstAppSink* AppSink = nullptr;
	FGstTexture* Texture = nullptr;
	
	OnGstTextureUpdated OnGstTextureUpdatedEvent;

	virtual void OnUpdated(FGstTextureContext& Context) override;
};
