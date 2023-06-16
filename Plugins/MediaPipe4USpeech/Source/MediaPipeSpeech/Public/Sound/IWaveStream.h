// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "WaveChunk.h"

class IWaveStream
{
public:
	virtual ~IWaveStream() = default;
	virtual void Reset() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	virtual bool IsPaused() = 0;
	
	virtual int32 PollAudio(float* OutAudio, int32 NumSamples) = 0;
	virtual bool PushChunk(const TSharedRef<FWaveChunk>& InChunk) = 0;
};
