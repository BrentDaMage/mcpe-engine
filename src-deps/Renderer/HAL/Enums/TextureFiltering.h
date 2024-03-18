#pragma once

namespace mce
{
    enum TextureFiltering
    {
        TEXTURE_FILTERING_POINT,
        TEXTURE_FILTERING_BILINEAR,
        TEXTURE_FILTERING_MIPMAP_BILINEAR,
        TEXTURE_FILTERING_TEXEL_AA,
        TEXTURE_FILTERING_PCF,
    };
}