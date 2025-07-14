#include "AlignmentHelper.h"
#include "ConstantBufferMetaData.h"

mce::ConstantBufferMetaData::ConstantBufferMetaData()
{
    m_uniformMetaData = std::vector<mce::UniformMetaData>();
    m_constantBufferName = "";
}

std::string mce::ConstantBufferMetaData::getConstantBufferName() const
{

}

mce::UniformMetaData* mce::ConstantBufferMetaData::getUniformMetaData(const std::string& uniformName)
{
    for (std::vector<mce::UniformMetaData>::iterator it = m_uniformMetaData.begin(); it != m_uniformMetaData.end(); it++)
    {
        if (it->m_uniformName == uniformName)
            return &*it; // solid
    }

    return nullptr;
}

unsigned int mce::ConstantBufferMetaData::getRequiredSpaceForUniforms() const
{
    if (m_uniformMetaData.empty())
        return 0;
    
    const UniformMetaData& lastUniform = m_uniformMetaData.back();
    unsigned int unalignedSize = lastUniform.getSize() + lastUniform.m_byteOffset;

    return mce::AlignmentHelper::getAlignedOffset(unalignedSize, 16);
}