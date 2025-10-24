#pragma once

#include "BufferType.h"

namespace mce
{
	class RenderContext;
	
	class ImmediateBufferBase
	{
	public:
        BufferType m_bufferType;
		
        ImmediateBufferBase();

        void createDynamicBuffer(RenderContext& context, unsigned int bufferSize, BufferType bufferType, const void *data);
	};
}
