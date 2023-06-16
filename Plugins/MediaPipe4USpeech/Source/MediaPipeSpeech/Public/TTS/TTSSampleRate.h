// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

#include "TTSSampleRate.generated.h"
/*
16000, 24000, 32000, 44100, 48000, 96000
 */
UENUM(BlueprintType)
enum class ETTSSampleRate : uint8
{
	TTS_SR_16000,
	TTS_SR_24000,
	TTS_SR_32000,
	TTS_SR_44100,
	TTS_SR_48000,
	TTS_SR_96000,
};

inline int TTSSampleRate(ETTSSampleRate SampleRate)
{
	switch (SampleRate)
	{
	case ETTSSampleRate::TTS_SR_24000: return 24000;
	case ETTSSampleRate::TTS_SR_32000:  return 32000;
	case ETTSSampleRate::TTS_SR_44100:  return 44100;
	case ETTSSampleRate::TTS_SR_48000:  return 48000;
	case ETTSSampleRate::TTS_SR_96000:  return 96000;
	case ETTSSampleRate::TTS_SR_16000: 
	default:
		return 16000;
	}
}
