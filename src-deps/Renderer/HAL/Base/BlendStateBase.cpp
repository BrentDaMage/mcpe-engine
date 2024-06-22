#include "BlendStateBase.h"

mce::BlendStateBase::BlendStateBase()
{
    m_description = mce::BlendStateDescription();
}

void mce::BlendStateBase::createBlendState(mce::RenderContext& ctx, const mce::BlendStateDescription& desc)
{
    m_description = desc;
}

bool mce::BlendStateBase::bindBlendState(mce::RenderContext& ctx)
{
    return ctx.m_state.m_blendStateDescription == m_description;
}