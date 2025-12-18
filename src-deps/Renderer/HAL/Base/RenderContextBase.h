#pragma once

#include "RenderContextStateBase.h"
#include "VertexFormat.h"
#include "PrimitiveMode.h"
#include "ShaderType.h"
#include "ShaderProgram.h"
#include "ImmediateBuffer.h"
#include "RenderDevice.h"

namespace mce
{
    class RenderContextBase
    {
    public:
        RenderContextStateBase m_currentState;
        
        // Only used in DX11
        VertexFormat m_lastVertexFormat;
        unsigned int m_lastAttributeListIndex;
        ShaderProgram *m_lastShaderPrograms[SHADER_TYPES_COUNT];

        ImmediateBuffer m_immediateBuffer;
        StencilRefObject m_stencilReference;
        RenderDevice *m_renderDevice;

    public:
        RenderContextBase();

    public:
        void draw(PrimitiveMode primitiveMode, unsigned int startOffset, unsigned int count);
        void drawIndexed(PrimitiveMode primitiveMode, unsigned int count, uint8_t indexSize);
        void drawIndexed(PrimitiveMode primitiveMode, unsigned int count, unsigned int startOffset, uint8_t indexSize);
        void lostContext();

        RenderDevice* getDevice();
        void setStencilReference(unsigned int value);
        unsigned int getStencilReference() const;

        static int getMaxVertexCount();
    };
}