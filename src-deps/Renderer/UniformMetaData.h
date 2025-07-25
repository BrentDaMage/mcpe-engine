#pragma once

#include <string>
#include "ShaderPrimitiveTypes.h"

namespace mce
{
    class ConstantBufferMetaData;

    class UniformMetaData
    {
    public:
        unsigned int m_numberOfElements;
        unsigned int m_byteOffset;
        mce::ShaderPrimitiveTypes m_shaderPrimitiveType;
        mce::ConstantBufferMetaData* m_constantBufferMetaDataParent;
        std::string m_uniformName;

    public:
        UniformMetaData();

        unsigned int getSize() const;
    };
}
