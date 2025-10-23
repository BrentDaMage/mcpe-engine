#include <stdexcept>

#include "ImmediateBufferOGL.h"
#include "BufferOGL.h"

using namespace mce;

ImmediateBufferOGL::ImmediateBufferOGL()
    : ImmediateBufferBase()
{
    m_target = GL_NONE;
}

void ImmediateBufferOGL::createDynamicBuffer(RenderContext* context, unsigned int bufferSize, BufferType bufferType, void const* data)
{
    m_bufferType = bufferType;
    m_target = glTargetFromBufferType(bufferType);
}

void ImmediateBufferOGL::updateBuffer(RenderContext* context, unsigned int itemSize, void const* data, unsigned int bufferSize)
{
    glBindBuffer(m_target, GL_NONE);
    if (m_bufferType > BUFFER_TYPES_MAX)
        throw std::out_of_range("bufferType");
    context->m_buffers[m_bufferType] = GL_NONE;
}

bool ImmediateBufferOGL::isValid() const
{
    return m_target != GL_NONE;
}