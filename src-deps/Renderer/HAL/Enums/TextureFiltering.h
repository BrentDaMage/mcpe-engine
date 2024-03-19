#pragma once

namespace mce
{
    enum TextureFiltering
    {
        TEXTURE_FILTERING_POINT,
        TEXTURE_FILTERING_BILINEAR,
        TEXTURE_FILTERING_MIPMAP_BILINEAR,
        TEXTURE_FILTERING_TEXEL_AA = 0x4,
        TEXTURE_FILTERING_PCF
    };
}