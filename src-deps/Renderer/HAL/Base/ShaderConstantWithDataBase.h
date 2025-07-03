#pragma once

#include "Interface/ShaderConstant.h"

namespace mce
{
    template <mce::ShaderPrimitiveTypes T>
    class ShaderConstantWithDataBase : public ShaderConstant
    {
    public:
        void* m_data;

    public:
        ShaderConstantWithDataBase() : ShaderConstant()
        {
            m_shaderPrimitiveType = T;
        }
    };
}
