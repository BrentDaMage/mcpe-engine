#pragma once

#include "HAL/Interface/RenderContext.h"
#include "HAL/Base/RenderContextBase.h"

namespace mce
{
    class RenderContextImmediate : public RenderContextBase
    {
    public:
        static mce::RenderContext& get();
        static const mce::RenderContext& getAsConst();
    }
}