#pragma once

#include "ShaderStagesBits.h"

namespace mce
{
    class ShaderStage
    {
    public:
        mce::ShaderStagesBits m_shaderStageBitsEnum;
        unsigned int m_shaderStageBits;
    };
}