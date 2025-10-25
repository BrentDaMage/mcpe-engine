#pragma once

#include <string>
#include <vector>
#include "UniformMetaData.h"

namespace mce
{
    class ConstantBufferMetaData
    {
    public:
        std::string m_constantBufferName;
        std::vector<UniformMetaData> m_uniformMetaData;

    public:
        ConstantBufferMetaData();

    public:
        const std::string& getConstantBufferName() const;
        const UniformMetaData* getUniformMetaData(const std::string& uniformName) const;
        unsigned int getRequiredSpaceForUniforms() const;
    };
}