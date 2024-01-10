bool RasterizerStateOGL::bindRaserizerState(RenderContext* ctx, int forceBind)
{

}

void RasterizerStateOGL::setRasterizerStateDescription(RenderContext* ctx, const RasterizerStateDescription* desc)
{
}

void RasterizerStateOGL::setScissorRect(RenderContext* ctx, GLint x, GLint y, GLsizei width, GLsizei height)
{
    if (m_enableScissorTest)
        glScissor(x, y, width, height);
}
