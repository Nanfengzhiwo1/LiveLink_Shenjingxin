// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include <atomic>
#include "CoreMinimal.h"
#include "MediaPipeLandmark.h"
#include "MediaPipeFaceMesh.h"
#include "MediaPipeFrame.h"
#include "MediaPipeLandmarksType.h"
#include "MediaPipeSourceInfo.h"

struct MEDIAPIPE_API FMediaPipeSource
{
public:
	FMediaPipeSourceInfo SourceInfo;

	void CycleLandmarks(const EMediaPipeLandmarksType TargetType);
	void CycleFaceGeometry();
	void CycleAll();

	void Reset(bool bClearLandmarks = true);
	
	void UpdateFaceGeometry(const  TSharedPtr<FMediaPipeFaceMesh>& InFaceGeometry);
	void UpdateSourceInfo(const FMediaPipeSourceInfo& Info);
	void UpdatePose(const TSharedPtr<TArray<FMediaPipeLandmark>>& Landmarks);
	void UpdatePoseWorld(const  TSharedPtr<TArray<FMediaPipeLandmark>>& Landmarks);
	void UpdateLeftHand(const  TSharedPtr<TArray<FMediaPipeLandmark>>& Landmarks);
	void UpdateRightHand(const  TSharedPtr<TArray<FMediaPipeLandmark>>& Landmarks);
	void UpdateFace(const  TSharedPtr<TArray<FMediaPipeLandmark>>& Landmarks);

	TSharedPtr<TArray<FMediaPipeLandmark>> GetSnapshotLandmarks(const EMediaPipeLandmarksType TargetType) const;
	TSharedPtr<FMediaPipeFaceMesh> GetSnapshotFaceGeometry() const;

	bool TryPopulateLandmarks(const EMediaPipeLandmarksType TargetType, FMediaPipeFrame& MediaPipeFrame);
	bool TryPopulateFaceGeometry(FMediaPipeFaceGeometryFrame& MediaPipeFrame);
private:
	TSharedPtr<TArray<FMediaPipeLandmark>> PoseLandmarks;
	TSharedPtr<TArray<FMediaPipeLandmark>> PoseWorldLandmarks;
	TSharedPtr<TArray<FMediaPipeLandmark>> LeftHandLandmarks;
	TSharedPtr<TArray<FMediaPipeLandmark>> RightHandLandmarks;
	TSharedPtr<TArray<FMediaPipeLandmark>> FaceLandmarks;
	TSharedPtr<FMediaPipeFaceMesh> FaceGeometry;

	FRWLock PoseLandmarksLock;
	FRWLock PoseWorldLandmarksLock;
	FRWLock LeftHandLandmarksLock;
	FRWLock RightHandLandmarksLock;
	FRWLock FaceLandmarksLock;
	FRWLock FaceGeometryLock;
	
	std::atomic<bool> bIsPoseUpdated{false};
	std::atomic<bool> bIsPoseWorldUpdated{false};
	std::atomic<bool> bIsLeftHandUpdated{false};
	std::atomic<bool> bIsRightHandUpdated{false};
	std::atomic<bool> bIsFaceUpdated{false};
	std::atomic<bool> bIsFaceGeometryUpdated{false};
};
