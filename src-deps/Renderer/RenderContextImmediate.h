#pragma once

#include "HAL/Interface/RenderContext.h"

namespace mce
{
    class RenderContextImmediate
    {
    public:
        static mce::RenderContext& get();
        static const mce::RenderContext& getAsConst();
    }
}