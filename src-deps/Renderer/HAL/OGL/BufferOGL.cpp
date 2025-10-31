#include <typeinfo>
#include "BufferOGL.h"
#include "ErrorHandler.h"

using namespace mce;

GLenum glTargetFromBufferType(BufferType bufferType)
{
    switch (bufferType)
    {
        case BUFFER_TYPE_VERTEX:
            return GL_ARRAY_BUFFER;
        case BUFFER_TYPE_INDEX:
            return GL_ELEMENT_ARRAY_BUFFER;
        default:
            //LOG_E("Unknown bufferType: %d", bufferType);
            throw std::bad_cast();
    }
}

BufferOGL::BufferOGL()
{
    m_bufferName = GL_NONE;
    m_target = GL_NONE;
}

BufferOGL::~BufferOGL()
{
    release();
}

void BufferOGL::release()
{
    if (isValid())
        glDeleteBuffers(1, &m_bufferName);

    m_bufferName = GL_NONE;
    m_target = GL_NONE;

    BufferBase::release();
}

void BufferOGL::bindBuffer(RenderContext& context)
{
    GLuint& activeBuffer = context.getActiveBuffer(m_bufferType);
    if (activeBuffer == m_bufferName)
        return;
    
    glBindBuffer(m_target, m_bufferName);
    activeBuffer = m_bufferName;
}

void BufferOGL::createBuffer(RenderContext& context, unsigned int stride, const void *data, unsigned int count, BufferType bufferType)
{
    BufferBase::createBuffer(context, stride, data, count, bufferType);
    m_target = mce::glTargetFromBufferType(bufferType);

    glGenBuffers(1, &m_bufferName);
    glBindBuffer(m_target, m_bufferName);

    // Set active buffer
    GLuint& activeBuffer = context.getActiveBuffer(m_bufferType);
    activeBuffer = m_bufferName;

    m_internalSize = count * stride;
    glBufferData(m_target, m_internalSize, data, GL_STATIC_DRAW);

    ErrorHandler::checkForErrors();
}

void BufferOGL::createDynamicBuffer(RenderContext& context, unsigned int size, BufferType bufferType, const void *data)
{
    BufferBase::createDynamicBuffer(context, size, bufferType, data);
    m_target = mce::glTargetFromBufferType(bufferType);

    glGenBuffers(1, &m_bufferName);
    glBindBuffer(m_target, m_bufferName);

    // Set active buffer
    GLuint& activeBuffer = context.getActiveBuffer(m_bufferType);
    activeBuffer = m_bufferName;

    glBufferData(m_target, size, data, GL_STATIC_DRAW);
    mce::ErrorHandler::checkForErrors();
}

void BufferOGL::resizeBuffer(RenderContext& context, const void* data, unsigned int size)
{
    glBufferData(m_target, size, data, GL_STATIC_DRAW);
    m_internalSize = size;
}

void BufferOGL::updateBuffer(RenderContext& context, unsigned int stride, const void *data, unsigned int count)
{
    bindBuffer(context);

    const unsigned int size = count * stride;

    if (size <= m_internalSize)
        glBufferSubData(m_target, 0, size, data);
    else
        resizeBuffer(context, data, size);
        
    BufferBase::updateBuffer(context, stride, data, count);
}

void BufferOGL::operator=(BufferOGL&& other)
{
    this->m_bufferType = other.m_bufferType;
    this->m_stride = other.m_stride;
    this->m_count = other.m_count;
    this->m_internalSize = other.m_internalSize;
    this->m_bufferName = other.m_bufferName;
    this->m_target = other.m_target;

    other.m_bufferType = BUFFER_TYPE_NONE;
    other.m_stride = 0;
    other.m_target = GL_NONE;
    other.m_bufferName = GL_NONE;
}