// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "CoreMinimal.h"

struct FFaceCanonicalPoints
{
	TArray<int> EyeRight{ 33, 246, 161, 160, 159, 158, 157, 173, 133, 155, 154, 153, 145, 144, 163, 7};
	TArray<int> EyeLeft { 263, 466, 388, 387, 386, 385, 384, 398, 362, 382, 381, 380, 374, 373, 390, 249 };

	TArray<int> UpperLip{
		0,37, 39,40,185,61,76,62,78,191,80,81,82,13,312,311,310,415,308,292, 306,291,409,270,269,267
	};
	TArray<int> LowerLip{
		17,84,181,91,146,61,76,62,78,95,88,178,87,14,317,402,318,324,308,292,306,291,375,321,405,314
	};

	TArray<int> IrisLeftEdge{
		474, 475, 476, 477
	};

	TArray<int> IrisRightEdge{
		469, 470, 471,472
	};

	int IrisLeftCenter = 473;
	int IrisRightCenter = 468;

	int EyeRightCenter = 145;
	int EyeLeftCenter = 374;
	
	TArray<int> Head { 10, 152 };
	int NoseTip = 1;
	int UpperLipBottomCenter = 13;
	int LowerLipTopCenter = 14;
	int UpperOuterLip = 12;
	
	int MouthSmileCornerLeft = 310;
	int MouthSmileCornerRight = 81;
	
	int MouthCornerLeft = 291;
	int MouthCornerRight = 61;
	int LowestChin = 152;
	int UpperHead = 10;
	int MouthFrownLeft = 422;
	int MouthFrownRight = 202;
	int MouthLeftStretch = 287;
	int MouthRightStretch = 57;
	int LowestLip = 17;
	int UnderLip = 18;
	int OverUpperLip = 164;
	TArray<int> LeftUpperPress { 40, 80 };
	TArray<int> LeftLowerPress { 88, 91 };
	TArray<int> RightUpperPress { 270, 310 };
	TArray<int> RightLowerPress { 318, 321 };
	TArray<int> SquintLeft { 253, 450 };
	TArray<int> SquintRight { 23, 230 };
	TArray<int> RightBrowLower { 53, 52, 65 };
	
	TArray<int> LeftBrowLower { 283, 282, 295 };
	int InnerBrow = 9;
	int UpperNose = 6;
	TArray<int> CheekSquintLeft { 359, 342 };
	TArray<int> CheekSquintRight { 130, 113 };
};
