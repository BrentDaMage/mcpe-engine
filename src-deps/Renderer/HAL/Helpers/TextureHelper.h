#pragma once

#include "TextureFormat.h"

namespace mce
{
    class TextureHelper
    {
    public:
        static unsigned int textureFormatToByteStride(TextureFormat textureFormat);
    };
}