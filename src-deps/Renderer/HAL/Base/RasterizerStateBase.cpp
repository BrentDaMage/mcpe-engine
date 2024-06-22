#include "RasterizerStateBase.h"

mce::RasterizerStateBase::RasterizerStateBase()
{
    m_description = mce::RasterizerStateDescription();
}

void mce::RasterizerStateBase::createRasterizerStateDescription(mce::RenderContext& ctx, const mce::RasterizerStateDescription& desc)
{
    m_description = desc;
}

bool mce::RasterizerStateBase::bindRasterizerState(mce::RenderContext& ctx)
{
    return ctx.m_state.m_rasterizerStateDescription == m_description;
}