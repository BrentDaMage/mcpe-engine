#include <typeinfo>
#include "RasterizerStateOGL.h"

bool mce::RasterizerStateOGL::bindRasterizerState(mce::RenderContext& ctx, bool forceBind)
{
    mce::RasterizerStateDescription& ctxDesc = ctx.m_state.m_rasterizerStateDescription;

    if (forceBind || ctxDesc.cullMode != m_description.cullMode)
    {
        if (m_cullMode)
        {
            glEnable(GL_CULL_FACE);
            glCullFace(m_cullFace);
        }
        else
        {
            glDisable(GL_CULL_FACE);
        }
        ctxDesc.cullMode = m_description.cullMode;
    }

    if (forceBind || ctxDesc.enableScissorTest != m_description.enableScissorTest)
    {
        if (m_enableScissorTest)
        {
            glEnable(GL_SCISSOR_TEST);
        }
        else
        {
            glDisable(GL_SCISSOR_TEST);
        }
        ctxDesc.enableScissorTest = m_description.enableScissorTest;
    }

    if (forceBind || ctxDesc.depthBias != m_description.depthBias)
    {
        if (m_depthScale == 0.0f)
        {
            glDisable(GL_POLYGON_OFFSET_FILL);
        }
        else
        {
            glEnable(GL_POLYGON_OFFSET_FILL);
        }
        glPolygonOffset(m_depthScale * 5.0f, m_depthScale * 5.0f);
        ctxDesc.depthBias = m_description.depthBias;
    }
}

void mce::RasterizerStateOGL::setRasterizerStateDescription(mce::RenderContext& ctx, const mce::RasterizerStateDescription& desc)
{
    createRasterizerStateDescription(ctx, desc);
    m_enableScissorTest = desc.enableScissorTest;
    switch (desc.cullMode)
    {
        case CULL_NONE:
            break;
        case CULL_FRONT:
            m_cullFace = GL_FRONT;
            break;
        case CULL_BACK:
            m_cullFace = GL_BACK;
            break;
        default:
            //LOG_E("Unknown cullMode: %d", desc.cullMode);
            throw std::bad_cast();
    }

    m_depthScale = desc.depthBias;
    if ( !ctx.m_state.m_bBoundRasterizerState )
    {
        bindRasterizerState(ctx, true);
        ctx.m_state.m_rasterizerStateDescription = desc;
        ctx.m_state.m_bBoundRasterizerState = 1;
    }
}

void mce::RasterizerStateOGL::setScissorRect(mce::RenderContext& ctx, GLint x, GLint y, GLsizei width, GLsizei height)
{
    if (m_enableScissorTest)
        glScissor(x, y, width, height);
}
