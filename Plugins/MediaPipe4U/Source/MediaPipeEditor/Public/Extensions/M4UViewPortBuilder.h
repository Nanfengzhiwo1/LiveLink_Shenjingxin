// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "MediaPipeEditorUIExtender.h"

class FM4UViewPortExtension;

class MEDIAPIPEEDITOR_API FM4UViewPortBuilder
{
public:
	FM4UViewPortBuilder& Content(const FM4UContentDelegate& InContentDelegate);
	FM4UViewPortBuilder& Header(const FText& InText);
private:
	TSharedPtr<FM4UViewPortExtension> Extension;
	FM4UViewPortBuilder(const TSharedRef<FM4UViewPortExtension>& InExtensions);
	friend class FM4UViewPortExtension;
};
