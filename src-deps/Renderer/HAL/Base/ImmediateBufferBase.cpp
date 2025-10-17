#include "ImmediateBufferBase.h"

using namespace mce;

ImmediateBufferBase::ImmediateBufferBase()
{
    m_bufferType = BUFFER_TYPE_NONE;
}

void ImmediateBufferBase::createDynamicBuffer(RenderContext& context, unsigned int bufferSize, BufferType bufferType, const void *data)
{
    m_bufferType = bufferType;
}