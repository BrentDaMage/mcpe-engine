#pragma once

#include "HAL/Interface/RenderContext.h"

namespace mce
{
    class RenderContextImmediate
    {
    public:
        static RenderContext& get();
        static const RenderContext& getAsConst();
    };
}