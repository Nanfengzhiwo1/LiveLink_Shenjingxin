// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "M4UDetailsViewExtension.h"
class FM4UDetailsViewExtension;

class MEDIAPIPEEDITOR_API FM4UDetailsViewBuilder
{
public:
	template <typename UserClass, typename... VarTypes>
	 FM4UDetailsViewBuilder&  OnDetailsViewCreated(
	 	UserClass* InUserObject,
	 	typename TMemFunPtrType<false, UserClass, bool (TSharedRef<IDetailsView>&, VarTypes...)>::Type InFunc,
	 	VarTypes... Vars)
	{
		if(Extensions.IsValid())
		{
			Extensions->OnDetailsViewCreatedChanged = FM4UOnDetailsViewCreated::CreateSP(InUserObject, InFunc, Vars...);
		}
		return *this;
	}

private:
 TSharedPtr<FM4UDetailsViewExtension> Extensions;
 FM4UDetailsViewBuilder(TSharedRef<FM4UDetailsViewExtension> InExtension);
 friend class FM4UDetailsViewExtension;
};
