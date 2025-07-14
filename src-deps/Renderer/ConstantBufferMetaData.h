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
        std::vector<mce::UniformMetaData> m_uniformMetaData;

    public:
        ConstantBufferMetaData();

    public:
        std::string getConstantBufferName() const;
        mce::UniformMetaData* getUniformMetaData(const std::string& uniformName);
        unsigned int getRequiredSpaceForUniforms() const;
    };
}