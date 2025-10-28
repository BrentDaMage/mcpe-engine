#include <typeinfo>

#include "ShaderOGL.h"

using namespace mce;

struct GLVertexAttrInfo
{
    GLenum type;
    GLint size;
    GLboolean normalized;
};

static GLVertexAttrInfo vertexAttrInfo[] = {
    { GL_FLOAT,          3, GL_FALSE },
    { GL_UNSIGNED_BYTE,  4, GL_TRUE },
    { GL_BYTE,           4, GL_FALSE },
    { GL_UNSIGNED_SHORT, 2, GL_TRUE },
    { GL_UNSIGNED_SHORT, 2, GL_TRUE }
};

ShaderOGL::ShaderOGL(ShaderProgram& vertexShader, ShaderProgram& fragmentShader, ShaderProgram& geometryShader)
    : ShaderBase(vertexShader, fragmentShader, geometryShader)
{
    m_shaderProgram = GL_NONE;
    m_vertexShaderObject = GL_NONE;
    m_fragmentShaderObject = GL_NONE;
    m_geometryShaderObject = GL_NONE;

    createAndAttachPrograms();
    linkShader();
    reflectShader();
}

void ShaderOGL::deleteShader()
{
    glDeleteProgram(m_shaderProgram);
    m_shaderProgram = GL_NONE;
}

void ShaderOGL::freeCompilerResources()
{
    glReleaseShaderCompiler();
    glGetError();
}

void ShaderOGL::resetLastProgram()
{
    RenderContextImmediate::get().m_lastShaderProgram = GL_NONE;
}

void ShaderOGL::createAndAttachPrograms()
{
    GLuint program = glCreateProgram();
    m_shaderProgram = program;

    glAttachShader(program, m_vertexShader.m_shaderObject);
    glAttachShader(m_shaderProgram, m_fragmentShader.m_shaderObject);
    if (m_geometryShader.m_valid) glAttachShader(m_shaderProgram, m_geometryShader.m_shaderObject);
    
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

    if (m_geometryShader.m_valid)
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

void ShaderOGL::bindVertexPointers(const VertexFormat& vertexFormat, void* vertexData)
{
    RenderDevice* device = RenderDevice::getInstance();
    RenderDeviceBase::AttributeList attrList = device->getAttributeList(m_attributeListIndex);

    for (int i = 0; i < attrList.size(); i++)
    {
        const Attribute& attr = attrList[i];
        VertexField vertexField = attr.getVertexField();

        if (!vertexFormat.hasField(vertexField))
            continue;

        GLuint location = attr.getLocation();

        const GLVertexAttrInfo& data = vertexAttrInfo[vertexField];

        //ErrorHandler::checkForErrors();
        //ErrorHandler::checkForErrors();

        GLboolean normalized = data.normalized;
        GLenum type = data.type;
        GLint size = data.size;

        GLsizei stride = vertexFormat.getVertexSize();
        const void* pointer = vertexFormat.getFieldOffset(vertexField, vertexData);

        glVertexAttribPointer(location, size, type, normalized, stride, pointer);
        ErrorHandler::checkForErrors();
    }
}

void ShaderOGL::reflectShader()
{
    reflectShaderUniforms();
    reflectShaderAttributes();
}
