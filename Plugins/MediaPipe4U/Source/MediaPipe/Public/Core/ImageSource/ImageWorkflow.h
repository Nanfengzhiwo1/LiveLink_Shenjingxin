// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "IImageConsumer.h"
#include "ImageConsumerProvider.h"
#include "ImageConsumerPtr.h"

/**
 * 
 */
struct MEDIAPIPE_API FImageWorkflow
{
public:
	static FImageWorkflow& Get();
	
	int ConsumeTexture(const FImageSourceInfo& ImageSourceInfo, MediaPipeTexture* InTexture);
	bool RegisterConsumer(IImageConsumerProvider* ConsumerProvider);
	bool RegisterConsumer(TSharedPtr<IImageConsumer> Consumer);

	bool UnregisterConsumer(IImageConsumerProvider* ConsumerProvider);
	bool UnregisterConsumer(TSharedPtr<IImageConsumer> Consumer);
	void UnregisterAllConsumers();
private:
	FImageWorkflow();
	bool RegisterConsumer(FImageConsumerPtr&& Consumer);
	bool UnregisterConsumer(const FImageConsumerPtr& Consumer);
	TSet<FImageConsumerPtr> Consumers;
	FRWLock SetLock;
	friend class FLazySingleton;
};
