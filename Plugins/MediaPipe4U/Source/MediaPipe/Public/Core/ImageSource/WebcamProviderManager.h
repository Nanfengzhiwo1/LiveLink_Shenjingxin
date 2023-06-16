// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "IWebcamProviderFactory.h"
#include "Containers/Map.h"
#include "Templates/SharedPointer.h"

class FLazySingleton;

class FWebcamProviderManager
{
public:
	static  FWebcamProviderManager & Get();

	bool ListWebcams(const FName& ProviderName, TArray<FString>& OutNames);
	bool ContainsProvider(const FName& ProviderName) const;
	bool CreateWebcamProvider(const FName& ProviderName, TSharedPtr<IWebcamProvider>& OutProvider);
	bool RegisterFactory(const FName& ProviderName, const TSharedPtr<IWebcamProviderFactory>& Factory);
	bool UnregisterFactory(const FName& ProviderName);
private:
	TMap<FName, TSharedPtr<IWebcamProviderFactory>> Factories;
	TMap<FName, TSharedPtr<IWebcamProvider>> ProviderInstances;
	FCriticalSection RegistryMutex;
	FWebcamProviderManager();
	friend class FLazySingleton;
};
