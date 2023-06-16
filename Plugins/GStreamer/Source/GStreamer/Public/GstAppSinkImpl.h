#pragma once

#include "GstCoreImpl.h"

class IGstAppSinkCallback
{
public:
	virtual ~IGstAppSinkCallback() = default;
	virtual void CbGstSampleReceived(class IGstSample* Sample) = 0;
};

class IGstAppSink
{
	GST_INTERFACE_IMPL(IGstAppSink)

public:

	virtual bool Connect(class IGstPipeline* Pipeline, const char* ElementName, const char* Caps, IGstAppSinkCallback* Callback) = 0;
	virtual void Disconnect() = 0;
	virtual void ReleaseSample(class IGstSample* Sample) = 0;
};
