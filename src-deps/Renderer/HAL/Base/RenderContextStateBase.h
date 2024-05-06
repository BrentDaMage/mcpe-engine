#pragma once

#include "../BlendStateDescription.h"
#include "../DepthStencilStateDescription.h"
#include "../RasterizerStateDescription.h"

namespace mce
{
    class RenderContextStateBase
    {
    public:
        mce::BlendStateDescription m_blendStateDescription;
        mce::DepthStencilStateDescription m_depthStencilStateDescription;
        mce::RasterizerStateDescription m_rasterizerStateDescription;
        bool m_bBoundBlendState;
        bool m_bBoundDepthStencilState;
        bool m_bBoundRasterizerState;
    };
}