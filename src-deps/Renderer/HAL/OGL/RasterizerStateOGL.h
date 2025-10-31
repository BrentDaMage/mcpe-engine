#pragma once

#include "API_OGL.h"
#include "RasterizerStateBase.h"
#include "RenderContext.h"

namespace mce
{
    class RasterizerStateOGL : public RasterizerStateBase
    {
    private:
        GLenum m_cullFace;
        bool m_enableScissorTest;
        bool m_cullMode;
        GLfloat m_depthScale;

    public:
        bool bindRasterizerState(RenderContext& context, bool forceBind = false);
        void setRasterizerStateDescription(RenderContext& context, const RasterizerStateDescription& desc);
        void setScissorRect(RenderContext &context, int x, int y, int width, int height);
    };
}