// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "ump_commons.h"

class MEDIAPIPE_API IPooledFrame : public IReleasable
{
public:
	virtual  int GetFormat() const = 0;
	virtual int GetWidth() const = 0;
	virtual  int GetHeight() const = 0;
	virtual  long GetImageId() const = 0;
	virtual void SetIsReturnRequired(bool bMustReturn) = 0;
	virtual bool IsReturnRequired() const = 0;
	virtual void AddReference(int Amount = 1) = 0;
};
