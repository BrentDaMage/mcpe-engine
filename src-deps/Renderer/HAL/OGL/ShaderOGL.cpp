#include <typeinfo>

#include "ShaderOGL.h"

using namespace mce;

ShaderOGL::ShaderOGL(ShaderProgram& vertexShader, ShaderProgram& fragmentShader, ShaderProgram& geometryShader)
{
    ShaderBase::ShaderBase(vertexShader, fragmentShader, geometryShader);

    m_shaderProgram = 0;
    m_vertexShaderObject = 0;
    m_fragmentShaderObject = 0;
    m_geometryShaderObject = 0;

    m_attributeListIndex = 0;
    m_vertexShader = 0;
    m_fragmentShader = 0;

    createAndAttachPrograms();
    linkShader();
    reflectShader();
}

void ShaderOGL::createAndAttachPrograms()
{
    GLuint program = glCreateProgram();
    m_shaderProgram = program;

    glAttachShader(program, m_vertexShader->m_shaderObject);
    glAttachShader(m_shaderProgram, m_fragmentShader->m_shaderObject);
    if (m_geometryShader->m_valid) glAttachShader(m_shaderProgram, m_geometryShader->m_shaderObject);
    
    ErrorHandler::checkForErrors();
}

void ShaderOGL::linkShader()
{
    glLinkProgram(m_shaderProgram);

    ErrorHandler::checkForErrors();

    GLint linkStatus;
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &linkStatus);

    if (linkStatus == GL_TRUE)
        return;

    if (m_geometryShader->m_valid)
    {
        //LOG_E("Failed to link " << m_vertexShader->m_shaderPath
        //    << " to " << m_fragmentShader->m_shaderPath
        //    << " and " << m_geometryShader->m_shaderPath);
        throw std::bad_cast();
    }
    else
    {
        //LOG_E("Failed to link " << m_vertexShader->m_shaderPath
        //    << " to " << m_fragmentShader->m_shaderPath);
        throw std::bad_cast();
    }

    GLint logLength = 0;
    glGetProgramiv(m_shaderProgram, GL_INFO_LOG_LENGTH, &logLength);

    if (logLength > 1)
    {
        int charsWritten = 0;
        char* infoLog;
        glGetProgramInfoLog(m_shaderProgram, logLength, &charsWritten, infoLog);

        //LOG_E("Compiler error:\n" << infoLog);
        throw std::bad_cast();
    }

    glDeleteProgram(m_shaderProgram);
    m_shaderProgram = 0;
}

void ShaderOGL::reflectShader()
{
    reflectShaderUniforms();
    reflectShaderAttributes();
}