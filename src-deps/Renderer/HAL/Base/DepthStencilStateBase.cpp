#include "DepthStencilStateBase.h"

mce::DepthStencilStateBase::DepthStencilStateBase()
{
    m_description = mce::DepthStencilStateDescription();
}

void mce::DepthStencilStateBase::createDepthState(mce::RenderContext& context, const mce::DepthStencilStateDescription& description)
{
    m_description = description;
}

bool mce::DepthStencilStateBase::bindDepthStencilState(mce::RenderContext& context)
{
    return context.m_currentState.m_depthStencilStateDescription == m_description;
}