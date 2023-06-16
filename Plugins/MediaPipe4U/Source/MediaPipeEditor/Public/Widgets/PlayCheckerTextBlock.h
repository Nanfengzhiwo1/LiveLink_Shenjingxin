// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MEDIAPIPEEDITOR_API SPlayCheckerTextBlock: public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SPlayCheckerTextBlock)
		:_UseHiddenMode(false)
	{}

	SLATE_ARGUMENT(bool, UseHiddenMode)
	SLATE_END_ARGS();

	EVisibility CheckVisibility() const;
	void Construct(const FArguments& InArgs);

private:
	bool bUseHidden = false;
};
