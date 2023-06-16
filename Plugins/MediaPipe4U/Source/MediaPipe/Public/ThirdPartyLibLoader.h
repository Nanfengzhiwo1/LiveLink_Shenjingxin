// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"

class MEDIAPIPE_API FThirdPartyLibLoader
{
public:
	FThirdPartyLibLoader();
	FThirdPartyLibLoader(const FThirdPartyLibLoader& Other);
	FThirdPartyLibLoader(FThirdPartyLibLoader&& Other) noexcept;
	FThirdPartyLibLoader(const TCHAR* LibName, const TCHAR* ThirdPartyFolderName, const FString& PluginName = "MediaPipe4U");

	void* GetDLLExport(const TCHAR* ProcName) const;

	template<typename FuncPtr>
	inline FuncPtr GetDLLExportFunction(const TCHAR* ProcName) const
	{
		void* ptr = GetDLLExport(ProcName);
		auto f = ptr ? static_cast<FuncPtr>(ptr) : nullptr;
		return f;
	}
	
	void FreeHandle();
	FString FileName{};
	FString FullFilePath{};
	FString BinariesDir{};

	void* LibHandle = nullptr;

	

	FThirdPartyLibLoader& operator=(const FThirdPartyLibLoader& Other);
	FThirdPartyLibLoader& operator=(FThirdPartyLibLoader&& Other) noexcept;
};
