#pragma once

#include <stdint.h>
#include "TextureFormat.h"

namespace mce
{
	struct ImageDescription
	{
        uint32_t width;
        uint32_t height;
        char *pixels;
        TextureFormat textureFormat;
		
		ImageDescription();
		
		unsigned int getSizeInBytes() const;
	};
}
