// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ExtensionCommons.h"
#include "M4UExtensionBase.h"

/**
 * 
 */
class MEDIAPIPEEDITOR_API FM4UDetailsViewExtension : public FM4UExtensionBase
{
public:
	FM4UOnDetailsViewCreated OnDetailsViewCreatedChanged;
	FM4UDetailsViewExtensionDelegate ExtensionDelegate;
	
	void Build();
};
