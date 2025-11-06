#pragma once

#include <stdint.h>
#include "ImageDescription.h"
#include "TextureFiltering.h"

namespace mce
{
	struct TextureDescription : public ImageDescription
	{
        unsigned int unknown1;
        unsigned int mipCount;
        bool bUnknown2;
        TextureFiltering filteringLevel;
        uint8_t unknown3;
		
		TextureDescription();
	};
}
