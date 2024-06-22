#include "BufferBase.h"

mce::BufferBase::BufferBase()
{
    m_stride = 0;
    m_bufferType = BUFFER_TYPE_UNKNOWN;
    m_count = 0;
    _bufferSize = 0;
    release();
}

mce::BufferBase::~BufferBase()
{
    release();
}

mce::BufferBase::BufferBase(const mce::BufferBase& other)
{
    m_bufferType = other.m_bufferType;
    m_stride = other.m_stride;
    m_count = other.m_count;
    _bufferSize = other._bufferSize;
}

mce::BufferBase::BufferBase(mce::BufferBase& other)
{
    *this = other;
    release();
}

void mce::BufferBase::release()
{
    m_stride = 0;
    m_bufferType = BUFFER_TYPE_UNKNOWN;
    m_count = 0;
}

void mce::BufferBase::createBuffer(mce::RenderContext& ctx, unsigned int itemSize, const void *data, unsigned int itemCount, mce::BufferType bufferType)
{
    m_stride = itemSize;
    m_count = itemCount;
    m_bufferType = bufferType;
    _bufferSize = itemCount * itemSize;
}

void mce::BufferBase::createDynamicBuffer(mce::RenderContext& ctx, unsigned int bufferSize, mce::BufferType bufferType, const void *data)
{
    _bufferSize = bufferSize;
    m_bufferType = bufferType;
    m_stride = 0;
    m_count = 0;
}

void mce::BufferBase::updateBuffer(mce::RenderContext& ctx, unsigned int itemSize, const void *data, unsigned int itemCount)
{
    m_stride = itemSize;
    m_count = itemCount;
}

void mce::BufferBase::operator=(mce::BufferBase& other)
{
    unsigned int stride = m_stride;
    m_stride = other.m_stride;
    other.m_stride = stride;

    mce::BufferType bufferType = m_bufferType;
    m_bufferType = other.m_bufferType;
    other.m_bufferType = bufferType;
    
    unsigned int internalSize = _bufferSize;
    _bufferSize = other._bufferSize;
    other._bufferSize = internalSize;

    unsigned int count = m_count;
    m_count = other.m_count;
    other.m_count = count;
}