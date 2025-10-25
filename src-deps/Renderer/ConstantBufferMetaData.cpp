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

const UniformMetaData* ConstantBufferMetaData::getUniformMetaData(const std::string& uniformName) const
{
    for (int i = 0; i < m_uniformMetaData.size(); i++)
    {
        const UniformMetaData& uniformMeta = m_uniformMetaData[i];
        if (uniformMeta.m_uniformName == uniformName)
            return &uniformMeta;
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