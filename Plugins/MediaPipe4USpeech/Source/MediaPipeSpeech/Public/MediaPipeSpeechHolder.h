// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "MediaPipeSpeechActor.h"

class FLazySingleton;

class MEDIAPIPESPEECH_API FMediaPipeSpeechHolder
{
public:
	static FMediaPipeSpeechHolder& Get();

	bool SetSpeechActor(const AMediaPipeSpeechActor* InActor) const;
	bool HasSpeechActor() const;
	AMediaPipeSpeechActor* GetSpeechActor() const;

	TSharedPtr<FOVRLipSyncFrame>LatestFrame;
	
private:
	FMediaPipeSpeechHolder(){}
	TWeakObjectPtr<AMediaPipeSpeechActor> SpeechActor;
	friend class FLazySingleton;
};
