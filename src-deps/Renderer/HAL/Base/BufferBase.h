#pragma once

#include "BufferType.h"
#include "RenderContext.h"

namespace mce
{
	class BufferBase
	{
	public:
        BufferType m_bufferType;
        unsigned int m_stride;
        unsigned int m_count;
        unsigned int m_internalSize;
		
        BufferBase();
        ~BufferBase();
		BufferBase(const BufferBase& other);
		BufferBase(BufferBase& other);

        void release();
		void createBuffer(RenderContext& context, unsigned int stride, const void *data, unsigned int count, BufferType bufferType);
		void createDynamicBuffer(RenderContext& context, unsigned int stride, BufferType bufferType, const void *data);
        void updateBuffer(RenderContext& context, unsigned int stride, const void *data, unsigned int count);
        unsigned int getInternalBufferSize() const { return m_internalSize; }

        void operator=(BufferBase& other);
	};
}
