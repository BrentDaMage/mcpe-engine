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

        void createDynamicBuffer(RenderContext& context, unsigned int stride, BufferType bufferType, const void *data);
		void updateBuffer(RenderContext& context, unsigned int stride, void const* data, unsigned int count);

		bool isValid() const;
	};
}
