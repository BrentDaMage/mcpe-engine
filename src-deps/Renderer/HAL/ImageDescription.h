#pragma once

#include <stdint.h>
#include "TextureFormat.h"

namespace mce
{
	struct ImageDescription
	{
        unsigned int width;
        unsigned int height;
        void* pixels;
        TextureFormat textureFormat;
		
		ImageDescription();
		
		unsigned int getSizeInBytes() const;
	};
}
