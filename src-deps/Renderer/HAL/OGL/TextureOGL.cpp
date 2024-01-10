#include "TextureOGL.h"

TextureOGL::TextureOGL()
    : textureTarget(GL_TEXTURE_2D)
    , createdMipMaps(false)
    , id(0)
    , internalFormat(0)
    , format(0)
    , type(0)
{}

void TextureOGL::deleteTexture()
{
    glDeleteTextures(1, &id);
    Super::deleteTexture();
    // TODO
    ErrorHandler::checkForErrors();
}

void convertToMipmapedTexture(RenderContext& ctx, GLuint mipMaps)
{
    if (mipMaps < 1)
    {
        LOG_E("You must have a positive number of mip maps that is greater than 1");
    }
    bindTexture(ctx, 0, 2u);
    convertToMipmapedTexture(mipMaps - 1);
    glTexParameteri(textureTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(textureTarget, GL_TEXTURE_MAX_LEVEL, mipMaps - 1);
    ErrorHandler::checkForErrors();
}

void TextureOGL::subBuffer(RenderContext& ctx, void const* pixels, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLint level)
{
    bindTexture(ctx, GL_FALSE, GL_LINE_LOOP);
    ErrorHandler::checkForErrors();
    if (textureTarget != GL_TEXTURE_2D)
    {
        LOG_E("Unknown textureTarget " << textureTarget);
    }
    glTexSubImage2D(GL_TEXTURE_2D, level, xoffset, yoffset, width, height, format, type, pixels);
}

void TextureOGL::subBuffer(RenderContext& ctx, void const* pixels)
{
    subBuffer(ctx, pixels, 0, 0, description->m_image->m_width, description->m_image->m_height, 0);
}

void lock(RenderContext& ctx)
{

}

void unlock(RenderContext& ctx)
{
    bindTexture(ctx, GL_FALSE, GL_LINE_LOOP);
    subBuffer(ctx, context->pixels);
    context->pxels = context->pixels;
}


bool TextureOGL::supportsMipMaps() {}