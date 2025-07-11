#include "ConstantBufferBase.h"

void mce::ConstantBufferBase::createConstantBuffer(mce::RenderContext &context, unsigned int count)
{
    m_bindingSlots.resize(count);
}

unsigned int& mce::ConstantBufferBase::getInternalMemory()
{
    return m_bindingSlots.back();
}