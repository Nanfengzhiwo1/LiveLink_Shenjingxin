// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

class MEDIAPIPE_API IImageSourceLoopThread
{
public:
	virtual ~IImageSourceLoopThread() = default;
	virtual uint32 GetThreadID() = 0;
	virtual  bool IsRunning() = 0;
	virtual  bool WaitToRun() = 0;
	virtual  void StopAndWaitCompleted() = 0;
};
