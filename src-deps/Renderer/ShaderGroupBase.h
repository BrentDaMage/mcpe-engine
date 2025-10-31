#pragma once

#include <vector>
#include <map>
#include <string>
#include "HAL/Interface/Shader.h"
#include "HAL/Interface/ShaderProgram.h"

namespace mce
{
    class ShaderGroupBase
    {
    public:
        std::vector<Shader*> m_shaders;
        std::map<std::string, ShaderProgram*> m_programs;

    public:
        ShaderGroupBase();
    };
}