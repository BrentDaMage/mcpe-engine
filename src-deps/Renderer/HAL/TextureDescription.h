#pragma once

#include <stdint.h>
#include "ImageDescription.h"
#include "Enums/TextureFiltering.h"

namespace mce
{
	class TextureDescription : mce::ImageDescription
	{
	public:
        unsigned int unknown1;
        unsigned int m_mipmapEnabled;
        bool unknown2;
        mce::TextureFiltering m_filteringLevel;
        uint8_t unknown3;
		
		TextureDescription();
	};
}
