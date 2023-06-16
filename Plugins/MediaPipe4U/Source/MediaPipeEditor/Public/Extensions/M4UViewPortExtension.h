// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ExtensionCommons.h"
#include "M4UExtensionBase.h"

/**
 * 
 */
class MEDIAPIPEEDITOR_API FM4UViewPortExtension : public FM4UExtensionBase
{
public:
	FText HeaderText;
	FM4UContentDelegate ContentDelegate;
	FM4UViewPortExtensionDelegate ExtensionDelegate;

	void Build();
};

