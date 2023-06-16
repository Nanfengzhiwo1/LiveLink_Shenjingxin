// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "ImageConsumerProvider.h"

struct MEDIAPIPE_API FImageConsumerPtr
{
	FImageConsumerPtr();
	explicit FImageConsumerPtr(IImageConsumerProvider* InObject);
	explicit FImageConsumerPtr(const TSharedPtr<IImageConsumer>& ObjectConsumer);
public:
	IImageConsumer* Get() const;
	bool IsValid() const;
	FImageConsumerPtr& operator=(FImageConsumerPtr& Ptr);
	bool operator==(const FImageConsumerPtr& Ptr) const;
private:
	TWeakObjectPtr<UObject> ConsumerProvider;
	IImageConsumerProvider* Interface;
	TSharedPtr<IImageConsumer> NativeConsumer;
	bool bIsNative;
};

MEDIAPIPE_API uint32 GetTypeHash(const FImageConsumerPtr& Key);
// template <typename ValueType>
// struct ImageConsumerKeyFuncs : BaseKeyFuncs<TPair<FImageConsumerPtr, ValueType>, FString>
// {
// private:
// 	typedef BaseKeyFuncs<TPair<FImageConsumerPtr, ValueType>, FString> Super;
// public:
// 	typedef typename Super::ElementInitType ElementInitType;
// 	typedef typename Super::KeyInitType     KeyInitType;
//
// 	static KeyInitType GetSetKey(ElementInitType Element)
// 	{
// 		return reinterpret_cast<uint32>(Element.Get());
// 	}
//
// 	static bool Matches(KeyInitType A, KeyInitType B)
// 	{
// 		return A == B;
// 	}
//
// 	static uint32 GetKeyHash(KeyInitType Key)
// 	{
// 		return Key;
// 	}
// };