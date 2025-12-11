#pragma once

#include "API_OGL.h"

#include "ShaderConstantWithDataBase.h"

namespace mce
{
    template <ShaderPrimitiveTypes T>
    class ShaderConstantWithDataOGL : public ShaderConstantWithDataBase
    {
    public:
        ShaderConstantWithDataOGL(ShaderPrimitiveTypes primitiveType)
            : ShaderConstantWithDataBase(primitiveType)
        {
        }

        void syncUniform(int location) override;
    };
}
