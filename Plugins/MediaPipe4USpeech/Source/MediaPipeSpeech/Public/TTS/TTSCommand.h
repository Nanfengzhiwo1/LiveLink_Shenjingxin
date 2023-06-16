// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once
#include "SpeechSentence.h"
#include "TTSSolution.h"
#include "UObject/WeakInterfacePtr.h"


class FTTSCommand : public IQueuedWork
{
public:
	FTTSCommand(ITTSSolution* InSolution, const TSharedRef<FSpeechSentence>& InSentence);
	virtual ~FTTSCommand() override;

	virtual void DoThreadedWork() override;

	virtual void Cancel();
	bool IsCompleted() const;
private:
	virtual void Abandon() override;
	void Execute();
	ITTSSolution* GetTTSSolution() const;
	bool bCanceled = false;
	int SpkID = -1;
	TWeakInterfacePtr<ITTSSolution> Solution;
	TSharedPtr<FSpeechSentence> Sentence;
	bool bCompleted = false;
};
