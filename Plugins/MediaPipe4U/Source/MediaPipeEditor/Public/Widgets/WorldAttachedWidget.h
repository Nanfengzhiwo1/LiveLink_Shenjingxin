// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

class MEDIAPIPEEDITOR_API SWorldAttachedWidget : public SCompoundWidget
{
public:
	virtual void Close();
protected:
	SWorldAttachedWidget();

	void AttachToWorld();
	virtual  void OnEditorTick(float X);
	bool bHasWorld = false;
	virtual void BeginPlay(UWorld* PlayWorld);
	virtual void EndPlay();
private:
	void RefreshWorld();
	void OnPlayWorldChanged(UWorld* PlayWorld);
};