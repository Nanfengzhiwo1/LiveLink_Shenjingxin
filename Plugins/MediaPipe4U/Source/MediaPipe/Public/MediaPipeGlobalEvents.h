// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "MediaPipeHolisticComponent.h"


#define DECLARE_GLOBAL_EVENT_METHOD(OwningType, EventName) \
public: \
	DECLARE_EVENT(EventName, F##EventName##Event) \
	\
	inline void Publish##EventName##() \
	{ \
		if(##EventName##Event.IsBound()) \
		{ \
			##EventName##Event.Broadcast(); \
		} \
	} \
	\
	inline void Unsubscribe##EventName##(void* InUserObject) \
	{ \
			if(InUserObject) \
			{ \
			##EventName##Event.RemoveAll(InUserObject); \
			} \
	} \
	\
	template <typename UserClass, ESPMode Mode, typename... VarTypes> \
	inline FDelegateHandle Subscribe##EventName##SP(const TSharedRef<UserClass, Mode>& InUserObjectRef, typename TMemFunPtrType<false, UserClass, void (VarTypes...)>::Type InFunc, VarTypes... Vars) \
	{ \
		return EventName##Event.AddSP(InUserObjectRef, InFunc, Vars...); \
	} \
	\
	template <typename UserClass, typename... VarTypes> \
	inline FDelegateHandle Subscribe##EventName##UObject(UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, void (VarTypes...)>::Type InFunc, VarTypes... Vars) \
	{ \
		return EventName##Event.AddUObject(InUserObject, InFunc, Vars...); \
		\
	} \
private: \
	F##EventName##Event EventName##Event;

#define DECLARE_GLOBAL_EVENT_OneParam(OwningType, EventName, Param1Type, Param1Name) \
public: \
	DECLARE_EVENT_OneParam(EventName, F##EventName##Event, Param1Type) \
	inline void Publish##EventName##(Param1Type Param1Name) \
	{ \
		if(##EventName##Event.IsBound()) \
		{ \
			##EventName##Event.Broadcast(Param1Name); \
		} \
	} \
	\
	inline void Unsubscribe##EventName##(void* InUserObject) \
	{ \
		if(InUserObject) \
		{ \
			##EventName##Event.RemoveAll(InUserObject); \
		} \
	} \
	\
	template <typename UserClass, typename... VarTypes> \
	inline FDelegateHandle Subscribe##EventName##SP(UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, void (Param1Type, VarTypes...)>::Type InFunc, VarTypes... Vars) \
	{ \
		Unsubscribe##EventName##(InUserObject); \
		return EventName##Event.AddSP(InUserObject, InFunc, Vars...); \
	} \
	\
	template <typename UserClass, typename... VarTypes> \
	inline FDelegateHandle Subscribe##EventName##UObject(UserClass* InUserObject, typename TMemFunPtrType<false, UserClass, void (Param1Type, VarTypes...)>::Type InFunc, VarTypes... Vars) \
	{ \
		Unsubscribe##EventName##(InUserObject); \
		return EventName##Event.AddUObject(InUserObject, InFunc, Vars...); \
	\
	} \
public: \
	F##EventName##Event EventName##Event;


struct MEDIAPIPE_API FMediaPipeGlobalEvents
{
	DECLARE_GLOBAL_EVENT_OneParam(FMediaPipeGlobalEvents, MediaPipeHolisticUninitialized, UMediaPipeHolisticComponent*, HolisticComponent)
	DECLARE_GLOBAL_EVENT_OneParam(FMediaPipeGlobalEvents, MediaPipeHolisticInitialized, UMediaPipeHolisticComponent*, HolisticComponent)

public:
	FMediaPipeGlobalEvents();
};


extern MEDIAPIPE_API FMediaPipeGlobalEvents* GMediaPipeEvents;