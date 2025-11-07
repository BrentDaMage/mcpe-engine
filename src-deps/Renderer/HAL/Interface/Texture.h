#pragma once

#include "ShaderStagesBits.h"

#include "TextureOGL.h"

namespace mce
{
    class Texture : public TextureOGL
    {
    public:
        Texture();

    public:
        void bindTexture(RenderContext& context, unsigned int textureUnit, unsigned int shaderStagesBits = SHADER_STAGE_BIT_PIXEL);
        void loadMipMap(RenderContext& context, const void* rawTextureData, unsigned int mipMapLevel);
    };
}