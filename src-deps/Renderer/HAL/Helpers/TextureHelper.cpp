#include <typeinfo>
#include "TextureHelper.h"

int mce::TextureHelper::textureFormatToByteStride(mce::TextureFormat textureFormat)
{
    if ( textureFormat == TEXTURE_FORMAT_R8G8B8A8_UNORM )
        return 4;

    //LOG_E("Unknown textureFormat: " << textureFormat);
    throw std::bad_cast();
}