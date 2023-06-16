// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink	

#pragma once

#include "CoreMinimal.h"
#include "IFaceSolution.h"

/**
 * 
 */
class MEDIAPIPELIVELINK_API FFaceSolutionManager
{
public:
	~FFaceSolutionManager() = default;

	static FFaceSolutionManager& Get();

	TSharedPtr<IFaceSolution> FindSolution(const FName& SolutionName);
	bool RegisterSolution(const FName& SolutionName, TSharedPtr<IFaceSolution> Solution);
	bool UnregisterSolution(const FName& SolutionName);
	int ListSolutions(TArray<FName>& SolutionNames) const;

	template<typename T>
	inline bool RegisterSolution(const FName& SolutionName)
	{
		TSharedPtr<T> shared = MakeShared<T>();
		return RegisterSolution(SolutionName, shared);
	}

private:
	FFaceSolutionManager();
	TMap<FName, TSharedPtr<IFaceSolution>> Solutions;
	
	friend class FLazySingleton;
};

