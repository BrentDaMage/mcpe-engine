#pragma once

#include "BlendStateDescription.h"
#include "DepthStencilStateDescription.h"
#include "RasterizerStateDescription.h"

namespace mce
{
    class RenderContextStateBase
    {
    public:
        BlendStateDescription m_blendStateDescription;
        DepthStencilStateDescription m_depthStencilStateDescription;
        RasterizerStateDescription m_rasterizerStateDescription;
        bool m_bBoundBlendState;
        bool m_bBoundDepthStencilState;
        bool m_bBoundRasterizerState;

    public:
        RenderContextStateBase();
    };
}