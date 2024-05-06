#include "RenderContextStateBase.h"

mce::RenderContextStateBase::RenderContextStateBase()
{
  m_blendStateDescription = mce::BlendStateDescription();
  m_depthStencilStateDescription = mce::DepthStencilStateDescription();
  m_rasterizerStateDescription = mce::RasterizerStateDescription();
  m_bBoundBlendState = false;
  m_bBoundDepthStencilState = false;
  m_bBoundRasterizerState = false;
}