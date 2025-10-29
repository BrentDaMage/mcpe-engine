#include "RenderContextOGL.h"

using namespace mce;

RenderContextOGL::RenderContextOGL()
    : RenderContextBase()
{
    m_activeTexture = GL_NONE;
    m_activeShaderProgram = GL_NONE;
}

void RenderContextOGL::draw(PrimitiveMode primitiveMode, unsigned int startOffset, unsigned int count)
{
    glDrawArrays(modeMap[primitiveMode], startOffset, count);
}

void RenderContextOGL::drawIndexed(PrimitiveMode primitiveMode, unsigned int count, uint8_t indexSize)
{
    glDrawElements(modeMap[primitiveMode], count, indexType[indexSize], nullptr);
}

void RenderContextOGL::drawIndexed(PrimitiveMode primitiveMode, unsigned int count, unsigned int startOffset, uint8_t indexSize)
{
    glDrawElements(modeMap[primitiveMode], count, indexType[indexSize], (const GLvoid*)(startOffset * indexSize));
}

void RenderContextOGL::setDepthRange(float nearVal, float farVal)
{
    // glDepthRange on GL, glDepthRangef on GLES
    glDepthRange(nearVal, farVal);
}

void RenderContextOGL::setViewport(unsigned int width, unsigned int height, float nearVal, float farVal)
{
    glViewport(0, 0, width, height);
    setDepthRange(nearVal, farVal);
}

void RenderContextOGL::clearFrameBuffer(const Color& color)
{
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void RenderContextOGL::clearStencilBuffer()
{
    glStencilMask(0xFFFFFFFF);
    glClear(GL_STENCIL_BUFFER_BIT);
}

void RenderContextOGL::clearDepthStencilBuffer()
{
    glStencilMask(0xFFFFFFFF);
    glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void RenderContextOGL::setRenderTarget()
{
}

void RenderContextOGL::swapBuffers()
{
}

void RenderContextOGL::lostContext()
{
    m_activeTexture = GL_NONE;
    m_activeBuffer[0] = GL_NONE;
    m_activeBuffer[1] = GL_NONE;
}

int RenderContextOGL::getMaxVertexCount() const
{
    return gl::getMaxVertexCount();
}