// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"

DECLARE_DELEGATE_RetVal(TArray<FName>, FOnGetNameDataSource);
DECLARE_DELEGATE_OneParam(FOnSelectedNameChanged, const FName&);

class MEDIAPIPEEDITOR_API SNameComboButton : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SNameComboButton)
	{}
	SLATE_ARGUMENT(FText, DropDownTitle)
	SLATE_ARGUMENT(FName, CurrentName)
	SLATE_EVENT(FOnGetNameDataSource, OnGetNameDataSource)
	SLATE_EVENT(FOnSelectedNameChanged, OnSelectedNameChanged)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	void SetCurrentName(const FName& InName);
	void RefreshDataSource();
private:
	TSharedRef<SWidget> OnGetMenuContent();
	TSharedPtr<STextBlock> ComboText;
	TSharedPtr<SComboButton> Button;
	TSharedPtr<SWidget> NameListView;
	void OnListViewSelectionChanged(FName Name);
	FOnGetNameDataSource OnGetDataSource;
	FOnSelectedNameChanged OnSelectedNameChanged;
	FName CurrentName;
	TArray<FName> AvailableNames;
	FText DropDownTitle;
};

