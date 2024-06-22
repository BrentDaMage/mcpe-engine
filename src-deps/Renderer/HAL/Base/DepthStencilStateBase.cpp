#include "DepthStencilStateBase.h"

mce::DepthStencilStateBase::DepthStencilStateBase()
{
    m_description = mce::DepthStencilStateDescription();
}

void mce::DepthStencilStateBase::createDepthState(mce::RenderContext& ctx, const mce::DepthStencilStateDescription& desc)
{
    m_description = desc;
}

bool mce::DepthStencilStateBase::bindDepthStencilState(mce::RenderContext& ctx)
{
    return ctx.m_state.m_depthStencilStateDescription == m_description;
}