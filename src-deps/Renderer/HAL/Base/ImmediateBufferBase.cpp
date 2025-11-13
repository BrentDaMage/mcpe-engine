#include "ImmediateBufferBase.h"

using namespace mce;

ImmediateBufferBase::ImmediateBufferBase()
{
    m_bufferType = BUFFER_TYPE_NONE;
}

void ImmediateBufferBase::createDynamicBuffer(RenderContext& context, unsigned int stride, BufferType bufferType, const void *data)
{
    m_bufferType = bufferType;
}

void ImmediateBufferBase::updateBuffer(RenderContext& context, unsigned int stride, void const* data, unsigned int count)
{
}

bool ImmediateBufferBase::isValid() const
{
    return false;
}