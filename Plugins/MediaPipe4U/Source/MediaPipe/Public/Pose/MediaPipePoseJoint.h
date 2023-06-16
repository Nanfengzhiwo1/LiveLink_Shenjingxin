// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "CoreMinimal.h"
#include "MediaPipePoseJoint.generated.h"

UENUM(BlueprintType)
enum class EMediaPipePoseJoint : uint8
{
	Nose = 0,
	LeftEyeInner = 1,
	LeftEye = 2,
	LeftEyeOuter = 3,
	RightEyeInner = 4,
	RightEye = 5,
	RightEyeOuter = 6,
	LeftEar = 7,
	RightEar = 8,
	MouthLeft = 9,
	MouthRight = 10,
	LeftShoulder = 11,
	RightShoulder = 12,
	LeftElbow = 13,
	RightElbow = 14,
	LeftWrist = 15,
	RightWrist = 16,
	LeftPinky = 17,
	RightPinky = 18,
	LeftIndex = 19,
	RightIndex = 20,
	LeftThumb = 21,
	RightThumb  = 22,
	LeftHip = 23,
	RightHip = 24,
	LeftKnee = 25,
	RightKnee = 26,
	LeftAnkle = 27,
	RightAnkle = 28,
	LeftHeel = 29,
	RightHeel = 30,
	LeftFootIndex = 31,
	RightFootIndex = 32,

	//Calculated coordinates
	Hip,
	Head,
	Neck,
	Chest,
	Spine,
	Jaw,

	Count
};