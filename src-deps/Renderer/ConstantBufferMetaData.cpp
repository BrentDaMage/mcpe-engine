#include "AlignmentHelper.h"
#include "ConstantBufferMetaData.h"

using namespace mce;

ConstantBufferMetaData::ConstantBufferMetaData()
{
    m_uniformMetaData = std::vector<UniformMetaData>();
    m_constantBufferName = "";
}

const std::string& ConstantBufferMetaData::getConstantBufferName() const
{
    return m_constantBufferName;
}

UniformMetaData* ConstantBufferMetaData::getUniformMetaData(const std::string& uniformName)
{
    for (std::vector<UniformMetaData>::iterator it = m_uniformMetaData.begin(); it != m_uniformMetaData.end(); it++)
    {
        if (it->m_uniformName == uniformName)
            return &*it; // solid
    }

    return nullptr;
}

unsigned int ConstantBufferMetaData::getRequiredSpaceForUniforms() const
{
    if (m_uniformMetaData.empty())
        return 0;
    
    const UniformMetaData& lastUniform = m_uniformMetaData.back();
    unsigned int unalignedSize = lastUniform.getSize() + lastUniform.m_byteOffset;

    return AlignmentHelper::getAlignedOffset(unalignedSize, 16);
}