#include "RenderContextStateBase.h"

using namespace mce;

RenderContextStateBase::RenderContextStateBase()
{
    m_bBoundBlendState = false;
    m_bBoundDepthStencilState = false;
    m_bBoundRasterizerState = false;
}