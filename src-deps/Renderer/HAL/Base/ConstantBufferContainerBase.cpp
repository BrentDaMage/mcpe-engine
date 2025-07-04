#include <typeinfo>

#include "ShaderConstantWithData.h"
#include "ConstantBufferContainerBase.h"

void mce::ConstantBufferContainerBase::_init()
{
    m_reflectedShaderConstants = std::vector<mce::ShaderConstantBase>();
    m_constantBufferName = "";
    m_shaderConstants = std::vector<mce::ShaderConstant*>();
    m_constantBufferBytes = std::vector<uint8_t>();
    m_currentlyMapped = false;
}

mce::ConstantBufferContainerBase::ConstantBufferContainerBase(mce::ConstantBufferContainerBase& other)
{
    _init();
    m_shaderConstants = other.m_shaderConstants;
    other.m_shaderConstants = std::vector<mce::ShaderConstant*>();
    m_constantBufferBytes = other.m_constantBufferBytes;
    other.m_constantBufferBytes = std::vector<uint8_t>();
}

void mce::ConstantBufferContainerBase::reserveMemoryForShaderConstants(unsigned int shaderConstSize, unsigned int constBufferSize)
{
    m_shaderConstants.reserve(shaderConstSize);
    m_constantBufferBytes.reserve(constBufferSize);
}

void mce::ConstantBufferContainerBase::registerReflectedShaderParameter(const mce::UniformMetaData& uniMeta)
{
    mce::ShaderConstantBase shaderConst(uniMeta);

    for (std::vector<mce::ShaderConstantBase>::iterator it = m_reflectedShaderConstants.begin(); it != m_reflectedShaderConstants.end(); it++)
    {
        if (*it == shaderConst)
        {
            *it = shaderConst;
            return;
        }
    }

    m_reflectedShaderConstants.push_back(shaderConst);
}

void mce::ConstantBufferContainerBase::registerShaderParameter(const mce::ShaderConstantBase &shaderConstantBase)
{
    mce::ShaderConstantWithDataBase* newConst;
    uint8_t* buffer = &m_constantBufferBytes[shaderConstantBase.m_byteOffset];
    //shaderConstantBase.getSize(); // called for fun?

    switch (shaderConstantBase.getType())
    {
        case SHADER_PRIMITIVE_FLOAT1:
            newConst = new mce::ShaderConstantFloat1();
            break;
        case SHADER_PRIMITIVE_FLOAT2:
            newConst = new mce::ShaderConstantFloat2();
            break;
        case SHADER_PRIMITIVE_FLOAT3:
            newConst = new mce::ShaderConstantFloat3();
            break;
        case SHADER_PRIMITIVE_FLOAT4:
            newConst = new mce::ShaderConstantFloat4();
            break;
        case SHADER_PRIMITIVE_INT1:
            newConst = new mce::ShaderConstantInt1();
            break;
        case SHADER_PRIMITIVE_INT2:
            newConst = new mce::ShaderConstantInt2();
            break;
        case SHADER_PRIMITIVE_INT3:
            newConst = new mce::ShaderConstantInt3();
            break;
        case SHADER_PRIMITIVE_INT4:
            newConst = new mce::ShaderConstantInt4();
            break;
        case SHADER_PRIMITIVE_MATRIX2x2:
            newConst = new mce::ShaderConstantMatrix2x2();
            break;
        case SHADER_PRIMITIVE_MATRIX3x3:
            newConst = new mce::ShaderConstantMatrix3x3();
            break;
        case SHADER_PRIMITIVE_MATRIX4x4:
            newConst = new mce::ShaderConstantMatrix3x3();
            break;
        default:
            //LOG_E("Unknown shaderConstantBase.shaderPrimitiveType: %d", shaderConstantBase.m_shaderPrimitiveType); // line 101
            throw std::bad_cast();
    }

    newConst->m_data = buffer;
    newConst->m_name = shaderConstantBase.m_name;
    newConst->m_byteOffset = shaderConstantBase.m_byteOffset;
    m_shaderConstants.push_back(newConst);
}

void mce::ConstantBufferContainerBase::finalizeConstantBufferLayout()
{
    for (std::vector<mce::ShaderConstantBase>::iterator it = m_reflectedShaderConstants.begin(); it != m_reflectedShaderConstants.end(); it++)
    {
        registerShaderParameter(*it);
    }
}

bool mce::ConstantBufferContainerBase::isDirty() const
{
    for (std::vector<mce::ShaderConstant*>::const_iterator it = m_shaderConstants.begin(); it != m_shaderConstants.end(); it++)
    {
        if ((*it)->isDirty())
            return true;
    }

    return false;
}