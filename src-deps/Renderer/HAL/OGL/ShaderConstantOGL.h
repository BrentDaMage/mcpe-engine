#pragma once

#include "ShaderConstantBase.h"

namespace mce
{
    class ShaderConstantOGL : public ShaderConstantBase
    {
    public:
        void syncUniform(int);
    };
}