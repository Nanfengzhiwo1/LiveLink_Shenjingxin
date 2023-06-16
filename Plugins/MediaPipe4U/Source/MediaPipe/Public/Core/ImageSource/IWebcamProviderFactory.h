// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "IWebcamProvider.h"

class IWebcamProviderFactory
{
public:
	virtual ~IWebcamProviderFactory() = default;
	virtual  TSharedPtr<IWebcamProvider> CreateCamera() = 0;
};
