#include "ImmediateBufferOGL.h"

ImmediateBufferOGL::ImmediateBufferOGL()
    : m_bufferType(BUFFER_UNKNOWN),
    , m_target(0)
{}

void ImmediateBufferOGL::createDynamicBuffer(RenderContext* context, unsigned int bufferSize, BufferType bufferType, void const* data)
{
    m_bufferType = bufferType;
    m_target = glTargetFromBufferType(bufferType);
}

void ImmediateBufferOGL::updateBuffer(RenderContext* context, unsigned int itemSize, void const* data, unsigned int bufferSize)
{
    glBindBuffer(m_target, 0);
    // ...
}

bool ImmediateBufferOGL::isValid()
{
    return m_target != GL_NONE;
}