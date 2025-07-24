#pragma once

#include "../OGL/RenderContextOGL.h"
#include "RenderContextBase.h"

namespace mce
{
    // This is temporary, and RenderContext should instead inherit RenderContextOGL, since it's an interface.
    class RenderContext : public RenderContextOGL
    {
    };
}