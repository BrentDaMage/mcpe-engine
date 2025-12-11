#pragma once

#include "ShaderConstantBase.h"

namespace mce
{
    class ShaderConstantOGL : public ShaderConstantBase
    {
    public:
        virtual void syncUniform(int location);
    };
}