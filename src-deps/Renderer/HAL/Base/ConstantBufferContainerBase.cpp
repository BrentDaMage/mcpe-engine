#include <typeinfo>

#include "ShaderConstantWithData.h"
#include "ConstantBufferContainerBase.h"

using namespace mce;

void ConstantBufferContainerBase::_init()
{
    m_reflectedShaderConstants = std::vector<ShaderConstantBase>();
    m_constantBufferName = "";
    m_shaderConstants = std::vector<ShaderConstant*>();
    m_constantBufferBytes = std::vector<uint8_t>();
    m_currentlyMapped = false;
}

ConstantBufferContainerBase::ConstantBufferContainerBase(ConstantBufferContainerBase&& other)
{
    _init();
    m_shaderConstants = other.m_shaderConstants;
    other.m_shaderConstants = std::vector<ShaderConstant*>();
    m_constantBufferBytes = other.m_constantBufferBytes;
    other.m_constantBufferBytes = std::vector<uint8_t>();
}

void ConstantBufferContainerBase::reserveMemoryForShaderConstants(unsigned int shaderConstSize, unsigned int constBufferSize)
{
    m_shaderConstants.reserve(shaderConstSize);
    m_constantBufferBytes.reserve(constBufferSize);
}

void ConstantBufferContainerBase::registerReflectedShaderParameter(const UniformMetaData& uniMeta)
{
    ShaderConstantBase shaderConst(uniMeta);

    for (std::vector<ShaderConstantBase>::iterator it = m_reflectedShaderConstants.begin(); it != m_reflectedShaderConstants.end(); it++)
    {
        if (*it == shaderConst)
        {
            *it = shaderConst;
            return;
        }
    }

    m_reflectedShaderConstants.push_back(shaderConst);
}

void ConstantBufferContainerBase::registerShaderParameter(const ShaderConstantBase &shaderConstantBase)
{
    ShaderConstantWithDataBase* newConst;
    uint8_t* buffer = &m_constantBufferBytes[shaderConstantBase.m_byteOffset];
    //shaderConstantBase.getSize(); // called for fun?

    switch (shaderConstantBase.getType())
    {
        case SHADER_PRIMITIVE_FLOAT1:
            newConst = new ShaderConstantFloat1();
            break;
        case SHADER_PRIMITIVE_FLOAT2:
            newConst = new ShaderConstantFloat2();
            break;
        case SHADER_PRIMITIVE_FLOAT3:
            newConst = new ShaderConstantFloat3();
            break;
        case SHADER_PRIMITIVE_FLOAT4:
            newConst = new ShaderConstantFloat4();
            break;
        case SHADER_PRIMITIVE_INT1:
            newConst = new ShaderConstantInt1();
            break;
        case SHADER_PRIMITIVE_INT2:
            newConst = new ShaderConstantInt2();
            break;
        case SHADER_PRIMITIVE_INT3:
            newConst = new ShaderConstantInt3();
            break;
        case SHADER_PRIMITIVE_INT4:
            newConst = new ShaderConstantInt4();
            break;
        case SHADER_PRIMITIVE_MATRIX2x2:
            newConst = new ShaderConstantMatrix2x2();
            break;
        case SHADER_PRIMITIVE_MATRIX3x3:
            newConst = new ShaderConstantMatrix3x3();
            break;
        case SHADER_PRIMITIVE_MATRIX4x4:
            newConst = new ShaderConstantMatrix3x3();
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

void ConstantBufferContainerBase::finalizeConstantBufferLayout()
{
    for (std::vector<ShaderConstantBase>::iterator it = m_reflectedShaderConstants.begin(); it != m_reflectedShaderConstants.end(); it++)
    {
        registerShaderParameter(*it);
    }
}

bool ConstantBufferContainerBase::isDirty() const
{
    for (std::vector<ShaderConstant*>::const_iterator it = m_shaderConstants.begin(); it != m_shaderConstants.end(); it++)
    {
        if ((*it)->isDirty())
            return true;
    }

    return false;
}