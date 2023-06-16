// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "IMediaPipeSolver.h"

class ISolverProvider
{
public:
	virtual ~ISolverProvider() = default;
	virtual  IMediaPipeSolver* GetSolver() =0;
};
