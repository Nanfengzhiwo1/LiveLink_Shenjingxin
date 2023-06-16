// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "Styling/SlateBrush.h"
#include "Fonts/SlateFontInfo.h"
#include "Misc/EngineVersionComparison.h"
#include "Framework/Docking/WorkspaceItem.h"

#if UE_VERSION_OLDER_THAN(5, 1, 0)
typedef FName FObjectPath;
#else
typedef FSoftObjectPath FObjectPath;
#endif

enum class EIconBrush
{
	Info,
	Warning,
	Error,
};

class MEDIAPIPEEDITOR_API FMediaPipeEditorUtils
{
public:
	static FAssetData CreateSkeletonSelectionDialog();
	
	static const ISlateStyle& GetStyle();
	static FName GetStyleSetName();
	static const FSlateBrush* GetBrush(FName PropertyName, const ANSICHAR* Specifier = nullptr);
	static FSlateFontInfo GetFontStyle(FName PropertyName, const ANSICHAR* Specifier = nullptr);
	static const FLinearColor& GetPrimaryColor();
	static UMaterial* CreateTextureMaterial(const FName& MaterialName, const FName& TextureParameterName, UTexture2D* DefaultTexture = nullptr);
	static TSharedPtr<FWorkspaceItem> GetLevelEditorRuntimeToolCategory(); 
	static TSharedPtr<FWorkspaceItem> GetLevelEditorAssetToolCategory();
	static FObjectPath GetObjectPath(const FAssetData& Data);
	static const FSlateBrush* GetIconBrush(EIconBrush Icon);
private:
	static void AddExpressionToMaterial(UMaterial* Material, UMaterialExpression* Expression);
};
