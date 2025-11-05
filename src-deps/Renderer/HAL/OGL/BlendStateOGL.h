#pragma once

#include "API_OGL.h"
#include "BlendStateBase.h"

namespace mce
{
    class BlendStateOGL : public BlendStateBase
    {
    public:
        bool m_bBlend;
        bool m_bRed;
        bool m_bGreen;
        bool m_bBlue;
        bool m_bAlpha;
        GLenum m_sfactor;
        GLenum m_dfactor;

    public:
        BlendStateOGL();

        GLenum translateBlendFunc(BlendTarget blendTarget);

		void createBlendState(mce::RenderContext& context, const mce::BlendStateDescription& desc);
        bool bindBlendState(mce::RenderContext& context, bool forceBind = false);
    };
}