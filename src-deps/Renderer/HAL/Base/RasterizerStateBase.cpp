#include "RasterizerStateBase.h"

using namespace mce;

RasterizerStateBase::RasterizerStateBase()
{
    m_description = RasterizerStateDescription();
}

void RasterizerStateBase::createRasterizerStateDescription(RenderContext& context, const RasterizerStateDescription& desc)
{
    m_description = desc;
}

bool RasterizerStateBase::bindRasterizerState(RenderContext& context)
{
    return context.m_currentState.m_rasterizerStateDescription == m_description;
}