#include "UniformMetaData.h"

mce::UniformMetaData::UniformMetaData()
{
    m_numberOfElements = 1;
    m_byteOffset = 0;
    m_uniformName = "";
    m_shaderPrimitiveType = SHADER_PRIMITIVE_UNKNOWN;
    m_constantBufferMetaDataParent = nullptr;
}

unsigned int mce::UniformMetaData::getSize() const
{
    return mce::ShaderPrimitiveTypeHelper::sizeInBytesFromShaderPrimitiveType(m_shaderPrimitiveType);
}