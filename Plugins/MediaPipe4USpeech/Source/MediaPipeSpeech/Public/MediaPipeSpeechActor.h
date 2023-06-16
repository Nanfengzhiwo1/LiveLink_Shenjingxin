// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "TTSSolution.h"
#include "GameFramework/Actor.h"
#include "LocalTTSSolutionComponent.h"
#include "SpeechSynthComponent.h"
#include "UObject/WeakInterfacePtr.h"
#include "IAudioProxyInitializer.h"
#include "LipSync/LipSyncComponent.h"
#include "MediaPipeSpeechActor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTTSInferenceCompleted, const FGuid&, SentenceId,  ESpeechState, State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTTSWavChunkReceived, const FWaveChunk&, WavChunk);

UCLASS(ClassGroup=MediaPipeSpeech, Blueprintable, BlueprintType)
class MEDIAPIPESPEECH_API AMediaPipeSpeechActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMediaPipeSpeechActor();
	
	UFUNCTION(BlueprintCallable, Category="TTS")
	FGuid GetCurrentSentenceId() const;

	UFUNCTION(BlueprintCallable, Category="TTS")
	bool SpeakText(const FString& Text);

	UFUNCTION(BlueprintCallable, Category="TTS")
	bool SetSolution(const TScriptInterface<ITTSSolution>& Solution);
	
	bool SetSolutionUObject(ITTSSolution* Solution);
	void SetSolutionNative(TSharedRef<ITTSSolution>& Solution);
	
	UFUNCTION(BlueprintCallable, Category="TTS")
	void StopSpeak();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="TTS")
	TObjectPtr<ULocalTTSSolutionComponent> LocalTTSSolution;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<USpeechSynthComponent> Synth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<ULipSyncComponent> LipSync;
	
	UPROPERTY(Category="TTS|Events", BlueprintAssignable)
	FOnTTSInferenceCompleted OnInferenceCompleted;
	
	UPROPERTY(Category="TTS|Events", BlueprintAssignable)
	FOnTTSWavChunkReceived OnWavChunkReceived;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TTS")
	bool bDebugLogEnabled = false;

	UFUNCTION(Category="TTS", BlueprintCallable)
	bool IsBusy() const;
	
protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginDestroy() override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	ITTSSolution* GetCurrentSolution() const;
	virtual void TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;
private:
	void SafeStop();
	void HandleLipSyncFrame(const TSharedPtr<FOVRLipSyncFrame>& Frame);
	void OnSolutionCompleted(const FGuid& SentenceId, ESpeechState State);
	void OnSolutionWavChunkReceived( const TSharedRef<FWaveChunk>& WavChunk) const;
	bool DoSpeak(const FString& Text, ITTSSolution* Solution, FGuid& SentenceId);
	FGuid CurrentSentenceId;
	bool bIsNativeSolution = true;
	TWeakInterfacePtr<ITTSSolution> ObjectSolution;
	FTTSCommand* PeekBusyCommand();
	FTTSCommand* ExecuteNextCommand();
	TSharedPtr<ITTSSolution> NativeSolution;
	TQueue<FTTSCommand*> ExecutionQueue;
	TQueue<FTTSCommand*> PendingQueue;
	FRWLock CommandsMutex;
};

