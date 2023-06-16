// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once

#include "KalmanPoint.h"


class MEDIAPIPE_API SimpleKalmanFilter
{
public:
	static void Update(FKalmanPoint& Measurement, double KalmanParamQ = 0.001, double KalmanParamR = 0.0015f, float Smooth = 0.0f);
private:
	static void Measure(FKalmanPoint& measurement, double Q, double R);
};
