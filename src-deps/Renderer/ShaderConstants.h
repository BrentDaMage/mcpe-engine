#pragma once

#include "Interface/ConstantBufferConstants.h"
#include "Interface/ShaderConstantWithData.h"
#include "Core/Math/Color.h"

// couldn't find that these were even initialized
static Color currentShaderColor;
static Color currentShaderDarkColor;

namespace mce
{
    class ShaderConstants : public ConstantBufferConstants
    {
    public:
        ShaderConstantFloat4* CURRENT_COLOR;
        ShaderConstantFloat4* DARKEN;

    public:
        ShaderConstants();

        void setShaderColor(const Color& shaderColor);
        void setShaderColors( const Color& shaderColor, const Color& shaderDarkenColor);

        void init();
    };
}