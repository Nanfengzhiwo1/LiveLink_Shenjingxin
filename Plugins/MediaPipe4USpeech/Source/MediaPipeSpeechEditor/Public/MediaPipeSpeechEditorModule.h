#pragma once

#include "CoreMinimal.h"

class FMediaPipeSpeechEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
