#pragma once

#include <stdint.h>
#include "TextureFormat.h"

namespace mce
{
	class ImageDescription
	{
	public:
        uint32_t m_width;
        uint32_t m_height;
        unsigned int bufferProbably;
        mce::TextureFormat m_textureFormat;
		
		ImageDescription();
		
		int getSizeInBytes();
	};
}
