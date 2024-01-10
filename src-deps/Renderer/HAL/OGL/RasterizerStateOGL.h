class RasterizerStateOGL {
private:
    GLenum m_cullFace;
    bool m_enableScissorTest;
    bool m_cullMode;
    GLfloat m_depthScale;

public:
    bool bindRaserizerState(RenderContext* ctx, int forceBind);
    void setRasterizerStateDescription(RenderContext* ctx, const RasterizerStateDescription* desc);
    void setScissorRect(RenderContext* ctx, GLint x, GLint y, GLsizei width, GLsizei height);
}