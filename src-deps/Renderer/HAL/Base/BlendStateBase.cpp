#include "BlendStateBase.h"

mce::BlendStateBase::BlendStateBase()
{
    m_description = mce::BlendStateDescription();
}

void mce::BlendStateBase::createBlendState(mce::RenderContext& context, const mce::BlendStateDescription& description)
{
    m_description = description;
}

bool mce::BlendStateBase::bindBlendState(mce::RenderContext& context)
{
    return context.m_currentState.m_blendStateDescription == m_description;
}