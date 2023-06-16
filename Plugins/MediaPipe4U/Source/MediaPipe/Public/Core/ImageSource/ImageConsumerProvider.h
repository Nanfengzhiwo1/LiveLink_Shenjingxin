// Power by Anders Xiao

#pragma once

#include "CoreMinimal.h"
#include "IImageConsumer.h"
#include "UObject/Interface.h"
#include "ImageConsumerProvider.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UImageConsumerProvider : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MEDIAPIPE_API IImageConsumerProvider
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual IImageConsumer* GetImageConsumer() = 0;
};
