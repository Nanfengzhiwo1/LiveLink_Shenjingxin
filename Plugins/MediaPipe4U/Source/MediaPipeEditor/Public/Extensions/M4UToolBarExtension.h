// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "ExtensionCommons.h"
#include "M4UExtensionBase.h"

class MEDIAPIPEEDITOR_API FM4UToolBarExtension: public FM4UExtensionBase
{
public:
	FName Hook;
	FText ButtonIcon;
	FText ButtonText;
	FText ButtonToolTip;
	/** Called to populate the menu */
	FM4UToolBarExtensionDelegate ExtensionDelegate;
	FM4UActionDelegate Action;
	FM4UActionCanExecuteDelegate CanExecuteAction;

	void Build();
};
