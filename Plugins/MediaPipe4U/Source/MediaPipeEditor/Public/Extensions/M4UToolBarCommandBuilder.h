// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "CoreMinimal.h"
#include "ExtensionCommons.h"

class SMediaPipeCapturePanelToolbar;
class FMediaPipeEditorUIExtender;
class FM4UToolBarExtension;
/**
 * 
 */
class MEDIAPIPEEDITOR_API FM4UToolBarCommandBuilder
{
public:
	
	FM4UToolBarCommandBuilder& Text(const FText DisplayText);
	/**
	 * 
	 * @param Icon fontawesome icon , use FEditorFontGlyphs class const
	 * @return 
	 */
	FM4UToolBarCommandBuilder& FontAwesomeIcon(const FText Icon);
	FM4UToolBarCommandBuilder& ToolTipText(const FText Icon);
	FM4UToolBarCommandBuilder& CanExecute(const FM4UActionCanExecuteDelegate& InDelegate);
	FM4UToolBarCommandBuilder& OnExecute(const FM4UActionDelegate& InDelegate);
	
private:
	TSharedPtr<FM4UToolBarExtension> Extensions;
	FM4UToolBarCommandBuilder(TSharedRef<FM4UToolBarExtension> InExtension);
	friend class FM4UToolBarExtension;
};
