#include "ShaderProgramOGL.h"
#include "RenderContextOGL.h"

using namespace mce;

const GLenum shaderTypeMap[] = {
    /*SHADER_TYPE_VERTEX*/   GL_VERTEX_SHADER,
    /*SHADER_TYPE_FRAGMENT*/ GL_FRAGMENT_SHADER
};

ShaderProgramOGL::ShaderProgramOGL(ShaderType shaderType, const std::string& shaderSource, const std::string& header, const std::string& shaderPath)
    : ShaderProgramBase(header, shaderPath, shaderType)
{
    if (shaderSource.empty() || shaderType > SHADER_TYPE_FRAGMENT)
    {
        m_bValid = false;
        return;
    }

    const GLint sourceLength = shaderSource.size();
    const GLchar* sourceStr = (const GLchar*)shaderSource.data();
    m_shaderName = glCreateShader(shaderTypeMap[shaderType]);
    glShaderSource(m_shaderName, 1, &sourceStr, &sourceLength);
    glCompileShader(m_shaderName);

    GLint compileStatus;
    glGetShaderiv(m_shaderName, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(m_shaderName, GL_INFO_LOG_LENGTH, &maxLength);
        if (maxLength > 1)
        {
            std::string infoLog(maxLength, 0);
            glGetShaderInfoLog(m_shaderName, maxLength, &maxLength, (GLchar*)infoLog.data());
            //LOG_E("Compiler error:\n %s", infoLog.c_str());
        }
        m_bValid = false;
        return;
    }
    
    m_bValid = true;
}

ShaderProgramOGL::~ShaderProgramOGL()
{
    deleteShader();
}

void ShaderProgramOGL::deleteShader()
{
    glDeleteShader(m_shaderName);
    m_shaderName = GL_NONE;
}