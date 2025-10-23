#include "RenderContextStateBase.h"

using namespace mce;

RenderContextStateBase::RenderContextStateBase()
{
    m_blendStateDescription = BlendStateDescription();
    m_depthStencilStateDescription = DepthStencilStateDescription();
    m_rasterizerStateDescription = RasterizerStateDescription();
    m_bBoundBlendState = false;
    m_bBoundDepthStencilState = false;
    m_bBoundRasterizerState = false;
}