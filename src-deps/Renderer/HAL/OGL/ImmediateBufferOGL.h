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

        void createDynamicBuffer(RenderContext& context, unsigned int bufferSize, BufferType bufferType, void const* data);
        void updateBuffer(RenderContext& context, unsigned int itemSize, void const* data, unsigned int bufferSize);
        
        bool isValid() const;
    };
}