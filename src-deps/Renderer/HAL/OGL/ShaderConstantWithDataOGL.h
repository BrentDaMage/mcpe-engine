#pragma once

#include "Base/ShaderConstantWithDataBase.h"

namespace mce
{
    template <mce::ShaderPrimitiveTypes T>
    class ShaderConstantWithDataOGL : public ShaderConstantWithDataBase<T>
    {
        void syncUniform(int) = 0;
    };
}
