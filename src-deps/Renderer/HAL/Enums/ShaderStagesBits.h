#pragma once

namespace mce
{
    enum ShaderStagesBits
    {
        SHADER_STAGE_BIT_NO_SHADER = 0x0,
        SHADER_STAGE_BIT_VERTEX = 0x1,
        SHADER_STAGE_BIT_PIXEL = 0x2,
        SHADER_STAGE_BIT_GOMETRY = 0x4
    };
}