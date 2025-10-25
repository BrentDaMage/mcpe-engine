#include "ConstantBufferMetaDataManager.h"
#include "GlobalConstantBufferManager.h"

using namespace mce;

ConstantBufferMetaDataManager::ConstantBufferMetaDataManager()
{
}

void ConstantBufferMetaDataManager::allocateConstantBufferContainers()
{
    GlobalConstantBufferManager* bufferManager = GlobalConstantBufferManager::getInstance();
    bufferManager->m_constantBufferContainers.reserve(m_constantBufferMetaDataList.size());
    
    for (int i = 0; i < m_constantBufferMetaDataList.size(); i++)
    {
        ConstantBufferMetaData& bufferMeta = m_constantBufferMetaDataList[i];
        ConstantBufferContainer buffer;

        unsigned int uniformCount = bufferMeta.m_uniformMetaData.size();
        unsigned int bufferSize = bufferMeta.getRequiredSpaceForUniforms();
        buffer.reserveMemoryForShaderConstants(uniformCount, bufferSize);

        buffer.m_constantBufferName = bufferMeta.getConstantBufferName();

        for (int i = 0; i < bufferMeta.m_uniformMetaData.size(); i++)
        {
            UniformMetaData& uniformMeta = bufferMeta.m_uniformMetaData[i];
            buffer.registerReflectedShaderParameter(uniformMeta);
        }

        buffer.finalizeConstantBufferLayout();
        bufferManager->m_constantBufferContainers.push_back(buffer);
    }
}

const UniformMetaData& ConstantBufferMetaDataManager::findUniformMetaData(const std::string& uniformName) const
{
    for (int i = 0; i < m_constantBufferMetaDataList.size(); i++)
    {
        const ConstantBufferMetaData& bufferMeta = m_constantBufferMetaDataList[i];
        const UniformMetaData* uniformMeta = bufferMeta.getUniformMetaData(uniformName);
        if (uniformMeta)
            return *uniformMeta;
    }

    //LOG_E("Couldn't find uniform: %s in the constant buffer metadata list", uniformName.c_str());
    throw std::bad_cast();
}

const ConstantBufferMetaData& ConstantBufferMetaDataManager::findConstantBuffer(const std::string& bufferName) const
{
    for (int i = 0; i < m_constantBufferMetaDataList.size(); i++)
    {
        const ConstantBufferMetaData& bufferMeta = m_constantBufferMetaDataList[i];
        if (bufferMeta.getConstantBufferName() == bufferName)
        {
            return bufferMeta;
        }
    }

    //LOG_E("Couldn't find the constant buffer named: %s was it properly reflected in the uniforms metadata file?", bufferName.c_str());
    throw std::bad_cast();
}