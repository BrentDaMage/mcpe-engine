#pragma once

#include <string>

#include "Enums/ShaderType.h"
#include "ShaderProgramOGL.h"

namespace mce
{
    class ShaderProgram : public ShaderProgramOGL
    {
    public:
        ShaderProgram(ShaderType shaderType, const std::string& shaderSource, const std::string& header, const std::string& shaderPath);
    };
}