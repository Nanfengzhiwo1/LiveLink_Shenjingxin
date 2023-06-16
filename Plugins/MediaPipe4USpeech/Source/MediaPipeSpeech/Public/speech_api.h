// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual bool IsDebugEnabled() = 0;
    virtual void SetDebugEnabled(bool enabled) = 0;
    virtual void LogInfo(const char* msg) const = 0;
    virtual void LogWarning(const char* msg) const = 0;
    virtual void LogError(const char* msg) const = 0;
    virtual void LogDebug(const char* msg) const = 0;
};

enum class WavFormat : int
{
    WAV_FORMAT_16BIT_PCM = 0,
    WAV_FORMAT_32BIT_FLOAT = 1
};

struct ISpeechOptions
{
    WavFormat AudioFormat = WavFormat::WAV_FORMAT_32BIT_FLOAT;
    int ThreadNumbers = 1;
    int SampleRate = 24000;
    const char* AcousticModelFile = nullptr;
    int AcousticModelFileLen = 0;
    
    const char* VoCoderModelFile = nullptr;
    int VoCoderModelFileLen = 0;
    
    const char* FrontCnfFile = nullptr;
    int FrontCnfFileLen = 0;

    const char* G2pEncoderModelFile = nullptr;
    int G2pEncoderModelFileLen = 0;

    const char* G2pDecoderModelFile = nullptr;
    int G2pDecoderModelFileLen = 0;
};
