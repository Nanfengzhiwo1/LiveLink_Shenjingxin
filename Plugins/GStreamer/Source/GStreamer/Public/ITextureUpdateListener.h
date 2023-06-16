#pragma once
#include "GstTextureContext.h"

class GSTREAMER_API ITextureUpdateListener
{
public:
	virtual ~ITextureUpdateListener() = default;
	virtual  void OnUpdated(FGstTextureContext& Context) =0;
};
