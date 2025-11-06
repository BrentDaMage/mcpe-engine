#pragma once

#include <string>

#include "ShaderPrimitiveTypes.h"

namespace mce
{
    class ShaderResourceOGL
    {
    public:
        int m_location;
        int m_elements;
        ShaderPrimitiveTypes m_shaderPrimitiveType;
        bool m_bValid;
        std::string m_name;

        ShaderResourceOGL(const std::string& name, int location, int elements, ShaderPrimitiveTypes shaderPrimitiveType);
    }
}