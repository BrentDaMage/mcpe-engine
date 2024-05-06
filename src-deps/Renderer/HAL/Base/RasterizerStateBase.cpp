#include "RasterizerStateBase.h"

mce::RasterizerStateBase::RasterizerStateBase()
{
    m_description = mce::RasterizerStateDescription();
}

void mce::RasterizerStateBase::createRasterizerStateDescription(mce::RenderContext& context, const mce::RasterizerStateDescription& description)
{
    m_description = description;
}

bool mce::RasterizerStateBase::bindRasterizerState(mce::RenderContext& context)
{
    return context.m_currentState.m_rasterizerStateDescription == m_description;
}