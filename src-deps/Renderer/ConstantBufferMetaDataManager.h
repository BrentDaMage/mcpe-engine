#pragma once

#include <vector>

#include "Core/Utility/Singleton.h"
#include "ConstantBufferMetaData.h"

namespace mce
{
    class ConstantBufferMetaDataManager : public Singleton<ConstantBufferMetaDataManager>
    {
    private:
        std::vector<ConstantBufferMetaData> m_constantBufferMetaDataList;

    public:
        ConstantBufferMetaDataManager();

    public:
        void allocateConstantBufferContainers();
        const UniformMetaData& findUniformMetaData(const std::string& uniformName) const;
        const ConstantBufferMetaData& findConstantBuffer(const std::string& bufferName) const;
    };
}