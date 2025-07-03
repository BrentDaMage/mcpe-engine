#include "ConstantBufferContainerBase.h"

void mce::ConstantBufferContainerBase::_init()
{
    m_reflectedShaderConstants = std::vector<mce::ShaderConstantBase>();
    m_constantBufferName = "";
    m_shaderConstants = std::vector<mce::ShaderConstant*>();
    m_constantBufferBytes = std::vector<unsigned char>();
    m_currentlyMapped = false;
}

mce::ConstantBufferContainerBase::ConstantBufferContainerBase(mce::ConstantBufferContainerBase& other)
{
    _init();
    m_shaderConstants = other.m_shaderConstants;
    other.m_shaderConstants = std::vector<mce::ShaderConstant*>();
    m_constantBufferBytes = other.m_constantBufferBytes;
    other.m_constantBufferBytes = std::vector<unsigned char>();
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

bool mce::ConstantBufferContainerBase::isDirty() const
{
    for (std::vector<mce::ShaderConstant*>::const_iterator it = m_shaderConstants.begin(); it != m_shaderConstants.end(); it++)
    {
        if ((*it)->isDirty())
            return true;
    }

    return false;
}