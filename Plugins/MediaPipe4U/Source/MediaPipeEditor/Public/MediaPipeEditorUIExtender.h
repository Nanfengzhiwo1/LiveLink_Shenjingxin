// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "CoreMinimal.h"
#include "Extensions/ExtensionCommons.h"
#include "Misc/Guid.h"
#include "Extensions/M4UCommandContext.h"
#include "Extensions/M4UDetailsViewExtension.h"
#include "Extensions/M4UToolBarExtension.h"
#include "Extensions/M4UViewPortExtension.h"


class MEDIAPIPEEDITOR_API FM4UContextSynchronizer
{
public: 
	/** Called to populate the menu */
	FM4UActionDelegate ComponentsLoadedDelegate;
	FM4UActionDelegate BeginUnloadComponentsDelegate;
};

class SMediaPipeCapturePanelToolbar;
class SMediaPipeCapturePanel;

class MEDIAPIPEEDITOR_API FMediaPipeEditorUIExtender
{
public:
	static FGuid SyncContext(const FM4UActionDelegate& OnMediaPipeComponentsLoaded, const FM4UActionDelegate& OnBeginUnloadMediaPipeComponents);

	static bool UnSyncContext(const FGuid& SynchronizerId);
	//ToolBar
	static TSharedRef<FM4UToolBarExtension> AddToolBarExtension(
		FName ExtensionHook,
		const FM4UToolBarExtensionDelegate& ExtensionDelegate);
	static bool RemoveToolBarExtension(const TSharedRef<FM4UToolBarExtension>& Extension);

	//View Port
	static TSharedRef<FM4UViewPortExtension> AddViewPortExtension(const FM4UViewPortExtensionDelegate& ExtensionDelegate);
	static bool RemoveViewPortExtension(const TSharedRef<FM4UViewPortExtension>& Extension);

	//Details View
	static TSharedRef<FM4UDetailsViewExtension> AddDetailsViewExtension(const FM4UDetailsViewExtensionDelegate& ExtensionDelegate);
	static bool RemoveDetailsViewExtension(const TSharedRef<FM4UDetailsViewExtension>& Extension);
private:
	static const TMap<FGuid, TSharedPtr<FM4UToolBarExtension>>& GetToolBarExtensions();
	static const TArray<TSharedPtr<FM4UViewPortExtension>>& GetViewPortExtensions();
	static const TArray<TSharedPtr<FM4UDetailsViewExtension>>& GetDetailsViewExtensions();
	static const TMap<FGuid, TSharedPtr<const FM4UContextSynchronizer>>& GetSynchronizerList();

	friend class SMediaPipeCapturePanelToolbar;
	friend class SMediaPipeCapturePanel;

};
