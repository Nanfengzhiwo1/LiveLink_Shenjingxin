// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MEDIAPIPESPEECH_API FSpeechConfigReader
{
public:
	/**
	 * Read parameters from string, format ex:
	 * --a=b
	 * --d=c
	 * will get result: a:b, d:c
	 */
	static bool ReadConfigFile(const FString& FilePath, TMap<FString, FString>& NameAndValues);

	static bool ReadConfigParameterFromFile(const FString& FilePath, const FString& ParameterName, FString& Value);

	/**
	 * Read dictionary from string, format ex:
	 * A  D
	 * B  C
	 * will get result: A:D, B:C
	 */
	static bool ReadDictionaryFile(const FString& FilePath, TMap<FString, FString>& KeysAndValues);

private:
	static bool SplitStringView(const FStringView& View, FString& OutLeft, FString& OutRight);
};
