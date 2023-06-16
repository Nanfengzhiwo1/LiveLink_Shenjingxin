// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "CoreMinimal.h"
#include "MediaPipeFaceMesh.h"
#include "MediaPipeLandmark.h"
#include "MediaPipeSourceInfo.h"

struct FMediaPipeSource;

struct MEDIAPIPE_API FMediaPipeFrame
{
	int64 FrameId = -1;
	FMediaPipeSourceInfo SourceInfo;
	bool bIsNew;
	
	bool IsValid() const;
	void Reset();
	TArray<FMediaPipeLandmark>& GetLandmarks() const;
private:
	TSharedPtr<TArray<FMediaPipeLandmark>> Landmarks;
	friend FMediaPipeSource;
};

struct MEDIAPIPE_API FMediaPipeFaceGeometryFrame
{
	int64 FrameId = -1;
	
	bool IsValid() const;
	void Reset();
	FMediaPipeFaceMesh& GetFaceMesh() const;
private:
	TSharedPtr<FMediaPipeFaceMesh> Mesh;
	friend FMediaPipeSource;
};
