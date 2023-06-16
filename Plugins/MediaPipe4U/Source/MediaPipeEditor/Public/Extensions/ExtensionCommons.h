// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "M4UCommandContext.h"

DECLARE_DELEGATE(FM4UEdtiorCallDelegate);
DECLARE_DELEGATE_OneParam(FM4UActionDelegate, const TSharedRef<FM4UCommandContext>&);
DECLARE_DELEGATE_RetVal(TSharedRef<SWidget>, FM4UContentDelegate);  
DECLARE_DELEGATE_RetVal_OneParam(bool, FM4UActionCanExecuteDelegate, const TSharedRef<FM4UCommandContext>&);


DECLARE_DELEGATE_RetVal_OneParam(bool, FM4UOnDetailsViewCreated, TSharedRef<IDetailsView>&);

//Build Delegate
DECLARE_DELEGATE_OneParam(FM4UViewPortExtensionDelegate, class FM4UViewPortBuilder&);
DECLARE_DELEGATE_OneParam(FM4UToolBarExtensionDelegate, class FM4UToolBarCommandBuilder&);
DECLARE_DELEGATE_OneParam(FM4UDetailsViewExtensionDelegate,  class FM4UDetailsViewBuilder&);

