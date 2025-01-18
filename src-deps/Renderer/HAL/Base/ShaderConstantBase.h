#pragma once

#include <string>
#include "ShaderPrimitiveTypes.h"

namespace mce
{
    class ShaderConstantBase
    {
    public:
        std::string m_name;
        unsigned int m_numberOfElements;
        unsigned int m_byteOffset;
        mce::ShaderPrimitiveTypes m_shaderPrimitiveType;
        bool m_dirty;

    public:
        ShaderConstantBase();
        virtual ~ShaderConstantBase();

        void release();
        const std::string& getName() const { return m_name; }
        const unsigned int getSize() const { return mce::ShaderPrimitiveTypeHelper::sizeInBytesFromShaderPrimitiveType(m_shaderPrimitiveType); }
        mce::ShaderPrimitiveTypes getType() const { return m_shaderPrimitiveType; }
        bool isDirty() const { return m_dirty; }

        bool operator==(const mce::ShaderConstantBase& other) const;
    };
}
