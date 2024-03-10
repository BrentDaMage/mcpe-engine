#pragma once

#include "../Enums/TextureFormat.h"

namespace mce
{
    class TextureHelper
    {
    public:
        static int textureFormatToByteStride(mce::TextureFormat textureFormat);
    };
}