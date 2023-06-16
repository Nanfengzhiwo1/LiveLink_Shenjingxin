// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MEDIAPIPEEDITOR_API SFormItemWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SFormItemWidget) :
			_VAlign(VAlign_Top),
			_ValueAlign(HAlign_Left)
		{
		}

		SLATE_ARGUMENT(FText, Label)
		SLATE_ARGUMENT(float, LabelWidth)
		SLATE_ARGUMENT(float, ValueWidth)

		SLATE_ATTRIBUTE(FText, Value)
		SLATE_ATTRIBUTE(FSlateFontInfo, LabelFont)
		SLATE_ARGUMENT(EVerticalAlignment, VAlign)
		SLATE_ARGUMENT(EHorizontalAlignment, ValueAlign)

		SLATE_DEFAULT_SLOT(FArguments, ValueContent)

	SLATE_END_ARGS();

	void Construct(const FArguments& InArgs);
};
