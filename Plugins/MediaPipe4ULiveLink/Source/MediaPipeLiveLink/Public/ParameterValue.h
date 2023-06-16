// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"

struct MEDIAPIPELIVELINK_API FParameterValue
{
	enum class EValueType : uint8
	{
		Int32,
		Int64,
		Float,
		String,
		Name
	};

	explicit FParameterValue(int32 InValue)
	{
		Int32Value = InValue;
		ValueType = EValueType::Int32;
	}

	explicit FParameterValue(int64 InValue)
	{
		Int64Value = InValue;
		ValueType = EValueType::Int64;
	}

	explicit FParameterValue(const FString& InValue)
	{
		StringValue = InValue;
		ValueType = EValueType::String;
	}

	explicit FParameterValue(const FName& InValue)
	{
		NameValue = InValue;
		ValueType = EValueType::Int32;
	}

	explicit FParameterValue(float InValue)
	{
		FloatValue = InValue;
		ValueType = EValueType::Float;
	}

	void* GetValue() const
	{
		switch (ValueType)
		{
		case EValueType::Int32:
			return &Int32Value;
		case EValueType::Int64:
			return &Int64Value;
		case EValueType::Name:
			return &NameValue;
		case EValueType::String:
			return &StringValue;
		case EValueType::Float:
			return &FloatValue;
		default:
			return nullptr;
		}
	}

private:
	EValueType ValueType = EValueType::String;
	mutable int64 Int64Value = 0;
	mutable int32 Int32Value = 0;
	mutable FString StringValue{};
	mutable FName NameValue{};
	mutable float FloatValue = 0.0f;
};
