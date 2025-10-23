#pragma once

#include "API_OGL.h"
#include "ShaderProgramBase.h"

namespace mce
{
    class ShaderProgramOGL : public ShaderProgramBase
    {
    public:
        GLuint m_shaderObject;
    };
}