#pragma once

#include "Interface/ConstantBufferConstants.h"
#include "Interface/ShaderConstantWithData.h"
#include "Core/Math/Color.h"

Color currentShaderColor;
Color currentShaderDarkColor;

namespace mce
{
    class ShaderConstants : public mce::ConstantBufferConstants
    {
    public:
        mce::ShaderConstantFloat4* CURRENT_COLOR;
        mce::ShaderConstantFloat4* DARKEN;

    public:
        ShaderConstants();

        void setShaderColor(const Color& shaderColor);
        void setShaderColors( const Color& shaderColor, const Color& shaderDarkenColor);

        void init();
    };
}