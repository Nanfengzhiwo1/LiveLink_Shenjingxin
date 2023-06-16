// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#pragma once
#include "TextureSupported.generated.h"

UENUM()
enum class ETextureSupported: uint8
{
	Texture2D,
	MediaTexture,
	UTextureRenderTarget2D,
};
