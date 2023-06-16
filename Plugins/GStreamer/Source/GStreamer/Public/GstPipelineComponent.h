#pragma once

#include "GstElementComponent.h"
#include "GstPipelineState.h"
#include "GstTime.h"
#include "IGstListener.h"
#include "GstPipelineComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGstPipelineStateChanged, EGstPipelineState, OldState, EGstPipelineState, NewState);

UCLASS( ClassGroup=(GStreamer), meta=(BlueprintSpawnableComponent) )
class GSTREAMER_API UGstPipelineComponent : public UGstElementComponent, public IGstListener
{
	GENERATED_BODY()

public:	

	UGstPipelineComponent();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void UninitializeComponent() override;

	UPROPERTY(Category="GstPipeline", EditAnywhere, BlueprintReadWrite)
	FString PipelineConfig;

	UPROPERTY(Category="GstPipeline", EditAnywhere, BlueprintReadWrite)
	bool PipelineAutostart;

	UFUNCTION(Category="GstPipeline", BlueprintCallable)
	bool StartPipeline();

	UFUNCTION(Category="GstPipeline", BlueprintCallable)
	void StopPipeline();

	UFUNCTION(Category="GstPipeline", BlueprintCallable)
	bool PausePipeline();

	UFUNCTION(Category="GstPipeline", BlueprintCallable)
	bool ResumePipeline();

	UFUNCTION(Category="GstPipeline", BlueprintCallable)
	bool SeekPipeline(float Percent);

	bool QueryTime(FGstTime& OutTime);

	UFUNCTION(Category="GstPipeline", BlueprintCallable)
	static void SetVerbosity(int Verbosity);

	FOnGstPipelineStateChanged& StateChangedTrigger() { return StateChanged; };

	virtual void OnStateChanged(EGstPipelineState OldState, EGstPipelineState NewState);
protected:
	virtual void OnGstError(bool loop_quit) override final;
	virtual void OnGstStateChanged(int old_state, int new_state) override final;

	void ResetState();

	UPROPERTY(BlueprintAssignable, Category="GstPipeline");
	FOnGstPipelineStateChanged StateChanged;
	
	IGstPipeline* Pipeline = nullptr;
	signed long long TotalTime;
private:
	FCriticalSection RunMutex;
};
