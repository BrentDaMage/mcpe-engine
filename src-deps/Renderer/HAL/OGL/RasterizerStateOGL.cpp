#include <typeinfo>
#include "RasterizerStateOGL.h"

bool mce::RasterizerStateOGL::bindRasterizerState(mce::RenderContext& ctx, bool forceBind)
{
    mce::RasterizerStateDescription& ctxDesc = ctx.m_state.m_rasterizerStateDescription;

    if (ctxDesc.cullMode != m_description.cullMode || forceBind)
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
        
        if (ctxDesc.enableScissorTest == m_description.enableScissorTest && !forceBind)
        {
LABEL_21:
            if (ctxDesc.depthBias == m_description.depthBias)
                return mce::RasterizerStateBase::bindRasterizerState(ctx);
            goto LABEL_10;
        }
    }
    else if (ctxDesc.enableScissorTest == m_description.enableScissorTest)
    {
        goto LABEL_21;
    }

    if ( m_enableScissorTest )
        glEnable(GL_SCISSOR_TEST);
    else
        glDisable(GL_SCISSOR_TEST);
    ctxDesc.enableScissorTest = m_description.enableScissorTest;

    if (ctxDesc.depthBias == m_description.depthBias && !forceBind)
        return mce::RasterizerStateBase::bindRasterizerState(ctx);

LABEL_10:
    if (m_depthScale == 0.0f)
        glDisable(GL_POLYGON_OFFSET_FILL);
    else
        glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(m_depthScale * 5.0f, m_depthScale * 5.0f);
    ctxDesc.depthBias = m_description.depthBias;

    return mce::RasterizerStateBase::bindRasterizerState(ctx);
}

void mce::RasterizerStateOGL::setRasterizerStateDescription(mce::RenderContext& ctx, const mce::RasterizerStateDescription& desc)
{
    createRasterizerStateDescription(ctx, desc);
    m_enableScissorTest = desc.enableScissorTest;
    m_cullMode = desc.cullMode;
    switch (m_cullMode)
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
            //LOG_E("Unknown cullMode: %d", m_cullMode);
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
