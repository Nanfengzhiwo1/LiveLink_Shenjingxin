// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "OptionalPinRigControl.generated.h"

USTRUCT()
struct MEDIAPIPEEDITOR_API FOptionalPinRigControl
{
	GENERATED_BODY()
	
	FOptionalPinRigControl(const FOptionalPinRigControl& Other)
		: Control(Other.Control),
		  PropertyName(Other.PropertyName),
		  PropertyTooltip(Other.PropertyTooltip),
		  CategoryName(Other.CategoryName),
		  bShowPin(Other.bShowPin)
	{
	}

	FOptionalPinRigControl(FOptionalPinRigControl&& Other) noexcept
		: Control(std::move(Other.Control)),
		  PropertyName(std::move(Other.PropertyName)),
		  PropertyTooltip(std::move(Other.PropertyTooltip)),
		  CategoryName(std::move(Other.CategoryName)),
		  bShowPin(Other.bShowPin)
	{
	}

	FOptionalPinRigControl& operator=(const FOptionalPinRigControl& Other)
	{
		if (this == &Other)
			return *this;
		Control = Other.Control;
		PropertyName = Other.PropertyName;
		PropertyTooltip = Other.PropertyTooltip;
		CategoryName = Other.CategoryName;
		bShowPin = Other.bShowPin;
		return *this;
	}

	FOptionalPinRigControl& operator=(FOptionalPinRigControl&& Other) noexcept
	{
		if (this == &Other)
			return *this;
		Control = std::move(Other.Control);
		PropertyName = std::move(Other.PropertyName);
		PropertyTooltip = std::move(Other.PropertyTooltip);
		CategoryName = std::move(Other.CategoryName);
		bShowPin = Other.bShowPin;
		return *this;
	}

	FOptionalPinRigControl(){}
	
	UPROPERTY(EditAnywhere, Category= OptionalPin)
	FName Control;

	UPROPERTY(EditAnywhere, Category= OptionalPin)
	FName PropertyName;

	UPROPERTY(EditAnywhere, Category= OptionalPin)
	FText PropertyTooltip;

	UPROPERTY(EditAnywhere, Category=OptionalPin)
	FName CategoryName;

	UPROPERTY(EditAnywhere, Category=OptionalPin)
	bool bShowPin = false;
};
