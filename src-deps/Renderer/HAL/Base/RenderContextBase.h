#pragma once

#include "RenderContextStateBase.h"
#include "../../VertexFormat.h"

namespace mce
{
    class RenderContextBase
    {
    public:
        mce::RenderContextStateBase m_state;
        mce::VertexFormat m_vertexFormat;
    };
}