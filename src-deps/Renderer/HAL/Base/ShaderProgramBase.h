#pragma once

#include <string>
#include "../Enums/ShaderType.h"

namespace mce
{
    class ShaderProgramBase
    {
    public:
        const std::string m_header;
        const std::string m_shaderPath;
        const mce::ShaderType m_shaderType;
        bool m_valid;

       ShaderProgramBase(const std::string& header, const std::string& shaderPath, mce::ShaderType shaderType);
    };
}