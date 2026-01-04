#pragma once

#include <stdint.h>
#include "ImageDescription.h"
#include "TextureFiltering.h"

namespace mce
{
	struct TextureDescription : public ImageDescription
	{
        unsigned int sampleCount;
        unsigned int mipCount;
        bool bWrap;
        TextureFiltering filteringLevel;
        bool bIsStaging;
		
		TextureDescription();
	};
}
