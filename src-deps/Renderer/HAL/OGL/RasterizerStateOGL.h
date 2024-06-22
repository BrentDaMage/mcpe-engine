#pragma once

#include <gl/GL.h>
#include "../Base/RasterizerStateBase.h"
#include "../Interface/RenderContext.h"

namespace mce
{
    class RasterizerStateOGL : RasterizerStateBase
    {
    private:
        GLenum m_cullFace;
        bool m_enableScissorTest;
        bool m_cullMode;
        GLfloat m_depthScale;

    public:
        bool bindRasterizerState(RenderContext& context, bool forceBind = false);
        void setRasterizerStateDescription(RenderContext& context, const RasterizerStateDescription& description);
        void setScissorRect(RenderContext &context, GLint x, GLint y, GLsizei width, GLsizei height);
    };
}