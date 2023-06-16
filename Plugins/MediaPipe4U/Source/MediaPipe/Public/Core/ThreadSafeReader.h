// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "HAL/CriticalSection.h"
/**
 * 
 */
template<class  T>
struct MEDIAPIPE_API TThreadSafeReader
{
public:
	TThreadSafeReader(T& InData, FRWLock& InLock) : Data(InData), Lock(InLock)
	{
		InLock.ReadLock();
	}

	const T& GetData() { return Data; }
	
	void EndRead() const
	{
		Lock.ReadUnlock();
	}
private:
	T& Data;
	FRWLock& Lock;
};
