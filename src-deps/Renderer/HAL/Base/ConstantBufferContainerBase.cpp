#include "ConstantBufferContainerBase.h"

mce::ConstantBufferContainerBase::ConstantBufferContainerBase()
{
    m_reflectedShaderConstants = std::vector<mce::ShaderConstantBase>();
    m_constantBufferName = "";
    m_shaderConstants = std::vector<mce::ShaderConstant*>();
    m_constantBufferBytes = std::vector<unsigned char>();
    m_currentlyMapped = false;
}

mce::ConstantBufferContainerBase::ConstantBufferContainerBase(mce::ConstantBufferContainerBase& other)
    : ConstantBufferContainerBase()
{
    m_shaderConstants = other.m_shaderConstants;
    other.m_shaderConstants = std::vector<mce::ShaderConstant*>();
    m_constantBufferBytes = other.m_constantBufferBytes;
    other.m_constantBufferBytes = std::vector<unsigned char>();
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

void mce::ConstantBufferContainerBase::reserveMemoryForShaderConstants(unsigned int shaderConstSize, unsigned int constBufferSize)
{
    m_shaderConstants.reserve(shaderConstSize);
    m_constantBufferBytes.reserve(constBufferSize);
}

void mce::ConstantBufferContainerBase::registerReflectedShaderParameter(const mce::UniformMetaData& uniMeta)
{
  mce::ShaderConstantBase shaderConst = mce::ShaderConstantBase();
  shaderConst.m_name = uniMeta.m_uniformName;
  std::vector<mce::ShaderConstantBase>::iterator itr = m_reflectedShaderConstants.begin();
  shaderConst.m_shaderPrimitiveType = uniMeta.m_shaderPrimitiveType;
  shaderConst.m_numberOfElements = uniMeta.m_numberOfElements;
  int v6 = -858993459 * ((m_reflectedShaderConstants.size()) >> 2);
  shaderConst.m_byteOffset = uniMeta.m_byteOffset;
  int v7 = v6 >> 2;
  if ( v6 >= SHADER_PRIMITIVE_FLOAT4 )
  {
    while ( 1 )
    {
      if (uniMeta.m_uniformName != m_reflectedShaderConstants[0].getName())
      {
        if (uniMeta.m_uniformName != m_reflectedShaderConstants[1].getName())
        {
            if (uniMeta.m_uniformName != m_reflectedShaderConstants[2].getName())
            {
                if (uniMeta.m_uniformName != m_reflectedShaderConstants[3].getName())
                {
                    if ( !--v7 )
                    {
                        v6 = -858993459 * ((m_reflectedShaderConstants.size()) >> 2);
                        break;
                    }
                }
            }
        }
        else
        {
            if (m_reflectedShaderConstants[1] != m_reflectedShaderConstants.end())
                return; // get the fuck out
        }
      }
    }
  }
  else if ( v6 == SHADER_PRIMITIVE_FLOAT2 )
  {
    if (uniMeta.m_uniformName != m_reflectedShaderConstants[0].getName())
    {
        if (uniMeta.m_uniformName != m_reflectedShaderConstants[1].getName())
        {
            itr = m_reflectedShaderConstants.end();
        }
    }
  }
  else if ( v6 == SHADER_PRIMITIVE_FLOAT3 )
  {
    if (uniMeta.m_uniformName != m_reflectedShaderConstants[0].getName())
    {
        if (uniMeta.m_uniformName != m_reflectedShaderConstants[1].getName())
        {
            if (uniMeta.m_uniformName != m_reflectedShaderConstants[2].getName())
            {
                itr = m_reflectedShaderConstants.end();
            }
        }
    }
  }
  else if ( v6 == SHADER_PRIMITIVE_FLOAT1 )
  {
    if (uniMeta.m_uniformName != m_reflectedShaderConstants[0].getName())
    {
        itr = m_reflectedShaderConstants.end();
    }
  }

  if (m_reflectedShaderConstants.empty())
  {
    if ( itr == m_reflectedShaderConstants._Myend )
    {
      m_reflectedShaderConstants.emplace_back(&shaderConst);
    }
    else
    {
      m_reflectedShaderConstants.push_back(shaderConst);
    }
  }
  else
  {
    mce::ShaderConstantBase::operator==(&shaderConst, itr);
  }
  mce::ShaderConstantBase::~ShaderConstantBase(&shaderConst);
}
}