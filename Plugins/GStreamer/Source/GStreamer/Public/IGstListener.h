// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink

#pragma once

class IGstListener
{
public:
	virtual ~IGstListener() = default;
	virtual void OnGstStateChanged(int old_state, int new_state) = 0;
	virtual void OnGstError(bool loop_quit) = 0;
};
