#pragma once

#include "../Base/ShaderConstantBase.h"

namespace mce
{
    class ShaderConstantOGL : ShaderConstantBase
    {
    public:
        void syncUniform(int);
    };
}