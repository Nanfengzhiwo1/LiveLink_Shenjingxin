// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

template<class  TFactory, class TSolver>
struct TSolverProxy
{
	typedef TWeakPtr<TSolver> (TFactory::*Getter)();
	TSolverProxy()
	{
	}
	
	TSolverProxy(TWeakObjectPtr<TFactory>  Factory, Getter SolverGetter = nullptr)
	{
		if(Factory.IsValid() && SolverGetter)
		{
			auto This = Factory.Get();
			Ptr = (This->*SolverGetter)();
			GetFunc = SolverGetter;
			Owner = Factory;
		}
	}

	FORCEINLINE TSolver* Get()
	{
		if(Ptr.IsValid())
		{
			return Ptr.Pin().Get();
		}
		if(GetFunc && Owner.IsValid())
		{
			auto* This = Owner.Get();
			TWeakPtr<TSolver> current = (This->*GetFunc)();
			if(current.IsValid())
			{
				Ptr = TWeakPtr<TSolver>(current.Pin());
				return current.Pin().Get();
			}
		}
		return nullptr;
	}

	explicit operator bool()
	{
		TSolver* solver = Get();
		return solver != nullptr;
	}
	
	FORCEINLINE TSolver* operator->()
	{
		return Get();
	}
	
private:
	TWeakObjectPtr<TFactory> Owner{};
	Getter GetFunc = nullptr;
	TWeakPtr<TSolver> Ptr{};
};
