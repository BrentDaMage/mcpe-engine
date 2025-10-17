#pragma once

#include "BufferType.h"
#include "RenderContext.h"

namespace mce
{
	class ImmediateBufferBase
	{
	public:
        BufferType m_bufferType;
		
        ImmediateBufferBase();

        void createDynamicBuffer(RenderContext& context, unsigned int bufferSize, BufferType bufferType, const void *data);
	};
}
