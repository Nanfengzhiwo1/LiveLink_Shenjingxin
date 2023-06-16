// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "CoreMinimal.h"
#include "KalmanPoint.generated.h"

class SimpleKalmanFilter;

USTRUCT(BlueprintType)
struct MEDIAPIPE_API FKalmanPoint
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MediaPipe")
	int BufferSize = 10;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MediaPipe")
	FVector RawData = FVector::Zero();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MediaPipe")
	FVector FilteredData = FVector::Zero();

	void ClearHistory();
private:
	TArray<FVector> History;
	FVector P = FVector::Zero();
	FVector X = FVector::Zero();
	FVector K = FVector::Zero();

	friend class SimpleKalmanFilter;
};
