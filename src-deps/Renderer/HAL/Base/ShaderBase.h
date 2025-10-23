#pragma once

#include "ShaderProgram.h"

namespace mce
{
    class ShaderBase
    {
    public:
        unsigned int m_attributeListIndex;
        ShaderProgram& m_vertexShader;
        ShaderProgram& m_fragmentShader;
        ShaderProgram& m_geometryShader;

        ShaderBase(ShaderProgram& vertexShader, ShaderProgram& fragmentShader, ShaderProgram& geometryShader);
    };
}