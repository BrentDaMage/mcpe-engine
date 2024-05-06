#pragma once

#include "RenderContextStateBase.h"
#include "../../VertexFormat.h"

namespace mce
{
    class RenderContextBase
    {
    public:
        mce::RenderContextStateBase m_currentState;
        mce::VertexFormat m_lastVertexFormat;
    };
}