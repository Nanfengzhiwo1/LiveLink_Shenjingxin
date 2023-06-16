// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

#include "CoreMinimal.h"

class GSTREAMER_API GstUtils
{
public:
	static FString GetDurationString(int64 Duration, int64 Totals);
	static FString FormatTime(int64 InTimestamp); 
	static bool GetProtocolFromUri(const FString& Uri,  FString& OutProtocol);
	static bool IsSupportedSourceUri(const FString& Uri);
	static bool GetUriFromFilePath(const FString& FilePath, FString& OutUri, bool bLogError = true);
};
