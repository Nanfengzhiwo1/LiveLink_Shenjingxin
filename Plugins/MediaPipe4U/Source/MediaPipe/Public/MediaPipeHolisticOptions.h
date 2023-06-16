// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "AutoBooleanValue.h"
#include "ModelComplexity.h"
#include "RotationAngle.h"
#include "MediaPipeHolisticOptions.generated.h"

USTRUCT(BlueprintType)
struct FMediaPipeHolisticOptions
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe | Holistic")
	ERotationAngle InputAngle = ERotationAngle::Rotation0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe | Holistic")
	bool InputHorizontallyFlipped = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe | Holistic")
	bool bInputVerticallyFlipped = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe | Holistic")
	EModelComplexity ModelComplexity = EModelComplexity::Full;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe | Holistic")
	bool bSmoothLandmarks = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe | Holistic")
	bool bEnableSegmentation = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe | Holistic")
	bool bSmoothSegmentation = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaPipe | Holistic")
	bool bUsePrevLandmarks = false;

	void AddToSidePacket(void* SidePacket, void* PacketAPI) const;
};
