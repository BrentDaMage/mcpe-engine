#pragma once

#include "API_OGL.h"
#include "ShaderProgramBase.h"

namespace mce
{
    class ShaderProgramOGL : public ShaderProgramBase
    {
    public:
        GLuint m_shaderName;

    public:
        ShaderProgramOGL(ShaderType shaderType, const std::string& shaderSource, const std::string& header, const std::string& shaderPath);
        ~ShaderProgramOGL();

    protected:
        void deleteShader();
    };
}