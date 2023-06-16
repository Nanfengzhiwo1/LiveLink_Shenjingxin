// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

class IBvHWriter
{
public:
	virtual ~IBvHWriter() = default;
	virtual bool WriteMotion(int32 JointIndex, const FTransform& BoneSpaceTransform) = 0;
	virtual  void IncreaseFrame() = 0;
	virtual bool SaveToFile(const FString& File) = 0;
	virtual bool IsHighPrecision() const = 0;
	virtual void SetHighPrecision(bool bEnabled) = 0;
};
