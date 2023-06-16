// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <chrono>

#include "CoreMinimal.h"

/**
 * 
 */
class MEDIAPIPE_API FFPSCounter
{
public:

	float GetFPS() const;

	void Clear();

	bool CountFrame();
	
private:
	bool bIsStarted = false;
    std::chrono::time_point<std::chrono::steady_clock> DurationTimePoint;
	std::chrono::time_point<std::chrono::steady_clock> RefreshTimePoint;
	float FrameCount = 0;
	float FPS = 0.0f;
};
