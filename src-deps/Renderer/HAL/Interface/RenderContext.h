#pragma once

#include "../Base/RenderContextBase.h"

namespace mce
{
    // This is temporary, and RenderContext should instead inherit RenderContextOGL, since it's an interface.
    class RenderContext : public RenderContextBase
    {
    };
}