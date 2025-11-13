#include <stdexcept>

#include "ImmediateBufferOGL.h"
#include "BufferOGL.h"

using namespace mce;

ImmediateBufferOGL::ImmediateBufferOGL()
    : ImmediateBufferBase()
{
    m_target = GL_NONE;
}

void ImmediateBufferOGL::createDynamicBuffer(RenderContext& context, unsigned int stride, BufferType bufferType, void const* data)
{
    m_bufferType = bufferType;
    m_target = glTargetFromBufferType(bufferType);
}

void ImmediateBufferOGL::updateBuffer(RenderContext& context, unsigned int stride, const void* data, unsigned int count)
{
    glBindBuffer(m_target, GL_NONE);
    GLuint& activeBuffer = context.getActiveBuffer(m_bufferType);
    activeBuffer = GL_NONE;
}

bool ImmediateBufferOGL::isValid() const
{
    return m_target != GL_NONE;
}