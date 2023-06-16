// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

#include "CoreMinimal.h"
#include "OVRLipSync.h"
#include "OVRLipSyncFrame.h"

DECLARE_DELEGATE_OneParam(FLipSyncAsyncCallback, TSharedPtr<FOVRLipSyncFrame>&);

class OVRLipInvoker;

class MEDIAPIPESPEECH_API FOVRLipSyncProcessor 
{
public:
	explicit FOVRLipSyncProcessor(ovrLipSyncContextProvider Provider,
		int SampleRate = 48000,
		int BufferSize = 4096,
		FString ModelPath = FString(),
		bool Accelerate = true);
	~FOVRLipSyncProcessor();
	
	bool ProcessFrame(const void*AudioData, int AudioDataSize, ovrLipSyncAudioDataType AudioFormat, FOVRLipSyncFrame& Output);

	// Async processing

	void SetAsyncCallback(const FLipSyncAsyncCallback& Callback);
	void ProcessFrameAsync(const void* AudioData, int AudioDataSize, ovrLipSyncAudioDataType AudioFormat);

private:
	FLipSyncAsyncCallback LipSyncCallback;
	ovrLipSyncContext LipSyncContext = 0;
	bool bLoaded = false;
	friend class OVRLipInvoker;
	
};

