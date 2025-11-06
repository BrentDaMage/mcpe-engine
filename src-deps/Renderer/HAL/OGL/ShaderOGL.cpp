#include <typeinfo>
#include <stdexcept>

#include "ShaderOGL.h"

using namespace mce;

static ShaderOGL::VertexFieldFormat vertexFieldFormats[] = {
    { GL_FLOAT,          3, GL_FALSE }, // VERTEX_FIELD_POSITION
    { GL_UNSIGNED_BYTE,  4, GL_TRUE  }, // VERTEX_FIELD_COLOR
    { GL_BYTE,           4, GL_FALSE }, // VERTEX_FIELD_NORMAL
    { GL_UNSIGNED_SHORT, 2, GL_TRUE  }, // VERTEX_FIELD_UV0
    { GL_UNSIGNED_SHORT, 2, GL_TRUE  }  // VERTEX_FIELD_UV1
};

ShaderOGL::ShaderOGL(ShaderProgram& vertex, ShaderProgram& fragment, ShaderProgram& geometry)
    : ShaderBase(vertex, fragment, geometry)
{
    m_program = GL_NONE;

    createAndAttachPrograms();
    linkShader();
    reflectShader();
}

ShaderOGL::~ShaderOGL()
{
    deleteShader();
}

void ShaderOGL::deleteShader()
{
    glDeleteProgram(m_program);
    m_program = GL_NONE;
}

void ShaderOGL::finalizeShaderUniforms()
{
    for (int i = 0; i < m_uniformList.size(); i++)
    {
        ShaderUniformOGL& uniform = m_uniformList[i];
        uniform.m_shaderConstant = uniform.m_constantBufferContainer->getUnspecializedShaderConstant(uniform.m_name);
    }
}

void ShaderOGL::freeCompilerResources()
{
    glReleaseShaderCompiler();
    glGetError();
}

void ShaderOGL::resetLastProgram()
{
    RenderContextImmediate::get().m_activeShaderProgram = GL_NONE;
}

void ShaderOGL::createAndAttachPrograms()
{
    GLuint program = glCreateProgram();
    m_program = program;

    glAttachShader(program, m_vertexShader.m_shaderName);
    glAttachShader(m_program, m_fragmentShader.m_shaderName);
    if (m_geometryShader.isValid()) glAttachShader(m_program, m_geometryShader.m_shaderName);
    
    ErrorHandler::checkForErrors();
}

void ShaderOGL::linkShader()
{
    glLinkProgram(m_program);

    ErrorHandler::checkForErrors();

    GLint linkStatus;
    glGetProgramiv(m_program, GL_LINK_STATUS, &linkStatus);

    if (linkStatus == GL_TRUE)
        return;

    if (m_geometryShader.isValid())
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
    glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &logLength);

    if (logLength > 1)
    {
        int charsWritten = 0;
        char* infoLog;
        glGetProgramInfoLog(m_program, logLength, &charsWritten, infoLog);

        //LOG_E("Compiler error:\n" << infoLog);
        throw std::bad_cast();
    }

    glDeleteProgram(m_program);
    m_program = 0;
}

void ShaderOGL::bindVertexPointers(const VertexFormat& vertexFormat, const void* vertexData)
{
    RenderDevice& device = RenderDevice::getInstance();
    RenderDeviceBase::AttributeList attrList = device.getAttributeList(m_attributeListIndex);

    for (int i = 0; i < attrList.size(); i++)
    {
        const Attribute& attr = attrList[i];
        
        VertexField vertexField = attr.getVertexField();
        if (!vertexFormat.hasField(vertexField))
            continue;

        GLuint location = attr.getLocation();
        const VertexFieldFormat& format = vertexFieldFormats[vertexField];
        glVertexAttribPointer(
            location,
            format.components,
            format.componentsType,
            format.normalized,
            vertexFormat.getVertexSize(),
            vertexFormat.getFieldOffset(vertexField, vertexData)
        );

        ErrorHandler::checkForErrors();
    }
}

void ShaderOGL::bindShader(RenderContext& context, const VertexFormat& format, const void *dataBasePtr, unsigned int shaderStageBits)
{
    bool shaderChanged = context.m_activeShaderProgram != m_program;

    if (shaderChanged)
    {
        glUseProgram(m_program);
        context.m_activeShaderProgram = m_program;
    }

    bindVertexPointers(format, dataBasePtr);

    for (int i = 0; i < m_textureList.size(); i++)
    {
        const ShaderResourceOGL& resource = m_textureList[i];
        RenderContextOGL::ActiveTextureUnit& activeTextureUnit = context.getActiveTextureUnit(i);
        if ((shaderChanged && resource.m_bValid) || activeTextureUnit.m_bIsShaderUniformDirty)
        {
            glUniform1i(resource.m_location, activeTextureUnit.m_textureUnit);
            activeTextureUnit.m_bIsShaderUniformDirty = false;
        }
    }

    for (int i = 0; i < m_uniformList.size(); i++)
    {
        ShaderUniformOGL& shaderUniform = m_uniformList[i];
        shaderUniform.bind(shaderChanged);
    }
}

void ShaderOGL::reflectShaderAttributes()
{
    RenderDeviceBase::AttributeList* attrList = nullptr;

    GLint attrCount;
    glGetProgramiv(m_program, GL_ACTIVE_ATTRIBUTES, &attrCount);

    if (attrCount)
    {
        char name[1024];
        GLsizei nameLen;
        GLint size;
        GLenum type;

        for (GLint i = 0; i < attrCount; i++)
        {
            glGetActiveAttrib(m_program, i, sizeof(name), &nameLen, &size, &type, name);
            GLint location = glGetAttribLocation(this->m_program, name);
            if (location < 0)
                continue;

            std::string attrName(name);
            VertexField vertexField = getAttributeForName(attrName, 0);

            if (attrList == nullptr)
            {
                attrList = new RenderDeviceBase::AttributeList();
            }

            Attribute attr(location, size, vertexField);
            attrList->push_back(attr);

            glEnableVertexAttribArray(location);
            glVertexAttribPointer(0, 1, GL_UNSIGNED_BYTE, 0, 1, this);
        }
    }

    m_attributeListIndex = RenderDevice::getInstance().registerOrGetAttributeListIndex(*attrList);
}

void ShaderOGL::reflectShader()
{
    reflectShaderUniforms();
    reflectShaderAttributes();
}
