//------------------------------------------------------------------------
// Copyright(c) 2023 Arvin Plugin.
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace MyCompanyName {
//------------------------------------------------------------------------
static const Steinberg::FUID kArvinDelayFXProcessorUID (0x9169991D, 0x1CF554B8, 0xADE7BA48, 0xAE2D7D4B);
static const Steinberg::FUID kArvinDelayFXControllerUID (0x75780470, 0xAAA95775, 0xBE7268F6, 0xCBFE8D3A);

#define ArvinDelayFXVST3Category "Fx"

//------------------------------------------------------------------------
} // namespace MyCompanyName
