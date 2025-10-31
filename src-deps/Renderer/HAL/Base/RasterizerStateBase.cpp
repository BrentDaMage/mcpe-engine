#include "RasterizerStateBase.h"

using namespace mce;

RasterizerStateBase::RasterizerStateBase()
{
    m_description = RasterizerStateDescription();
}

void RasterizerStateBase::createRasterizerStateDescription(RenderContext& ctx, const RasterizerStateDescription& desc)
{
    setRasterizerStateDescription(ctx, desc);
}

void RasterizerStateBase::setRasterizerStateDescription(RenderContext& ctx, const RasterizerStateDescription& desc)
{
    m_description = desc;
}

bool RasterizerStateBase::bindRasterizerState(RenderContext& ctx)
{
    return ctx.m_currentState.m_rasterizerStateDescription == m_description;
}