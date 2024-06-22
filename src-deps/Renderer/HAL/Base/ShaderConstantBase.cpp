#include "ShaderConstantBase.h"

mce::ShaderConstantBase::ShaderConstantBase()
{
    m_numberOfElements = 0;
    m_byteOffset = 0;
    m_shaderPrimitiveType = SHADER_PRIMITIVE_UNKNOWN;
    m_dirty = 0;
}

mce::ShaderConstantBase::~ShaderConstantBase()
{

}

bool mce::ShaderConstantBase::operator==(const mce::ShaderConstantBase& other) const
{
    return m_name == other.m_name &&
           m_numberOfElements == other.m_numberOfElements &&
           m_shaderPrimitiveType == other.m_shaderPrimitiveType &&
           m_byteOffset == other.m_byteOffset;
}