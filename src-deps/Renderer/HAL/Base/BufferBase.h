#pragma once

#include "BufferType.h"
#include "RenderContext.h"

namespace mce
{
	class BufferBase
	{
    private:
        unsigned int _bufferSize;
	public:
        mce::BufferType m_bufferType;
        unsigned int m_stride;
        unsigned int m_count;
		
        BufferBase();
        ~BufferBase();
		BufferBase(const mce::BufferBase& other);
		BufferBase(mce::BufferBase& other);

        void release();
		void createBuffer(mce::RenderContext& ctx, unsigned int itemSize, const void *data, unsigned int itemCount, mce::BufferType bufferType);
		void createDynamicBuffer(mce::RenderContext& ctx, unsigned int bufferSize, mce::BufferType bufferType, const void *data);
        void updateBuffer(mce::RenderContext& ctx, unsigned int itemSize, const void *data, unsigned int itemCount);
        unsigned int getInternalBufferSize() const { return _bufferSize; }

        void operator=(mce::BufferBase& other);
	};
}
