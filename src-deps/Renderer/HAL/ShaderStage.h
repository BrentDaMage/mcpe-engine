#pragma once

#include "ShaderStagesBits.h"

namespace mce
{
    class ShaderStage
    {
    public:
        ShaderStagesBits m_shaderStageBitsEnum;
        unsigned int m_shaderStageBits;
    };
}