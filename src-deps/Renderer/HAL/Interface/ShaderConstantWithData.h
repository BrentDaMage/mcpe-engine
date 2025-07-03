#pragma once

#include "OGL/ShaderConstantWithDataOGL.h"

namespace mce
{
    template <mce::ShaderPrimitiveTypes T>
    class ShaderConstantWithData : public ShaderConstantWithDataOGL<T>
    {
    };
}
