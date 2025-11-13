#pragma once

#include "API_OGL.h"
#include "ImmediateBufferBase.h"

namespace mce
{
    class ImmediateBufferOGL : public ImmediateBufferBase
    {
    private:
        GLenum m_target;

    public:
        ImmediateBufferOGL();

        void createDynamicBuffer(RenderContext& context, unsigned int stride, BufferType bufferType, void const* data);
        void updateBuffer(RenderContext& context, unsigned int stride, const void* data, unsigned int count);
        
        bool isValid() const;
    };
}