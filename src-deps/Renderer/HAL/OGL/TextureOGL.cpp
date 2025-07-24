#include <typeinfo>

#include "TextureOGL.h"

using namespace mce;

TextureOGL::TextureOGL()
    : m_textureTarget(GL_TEXTURE_2D)
    , m_created(false)
    , m_glObj(0)
    , m_internalFormat(0)
    , m_format(0)
    , m_type(0)
{}

void TextureOGL::deleteTexture()
{
    glDeleteTextures(1, &m_glObj);
    TextureBase::deleteTexture();

    TextureOGL newInstance;
    *this = newInstance;

    //ErrorHandler::checkForErrors();
}

void TextureOGL::convertToMipmapedTexture(RenderContext& ctx, GLuint mipmaps)
{
    if (mipmaps == 0)
    {
        //LOG_E("You must have a positive number of mip maps that is greater than 1");
        throw std::bad_cast();
    }

    bindTexture(ctx, 0, 2);
    TextureBase::convertToMipmapedTexture(mipmaps - 1);

    glTexParameteri(m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(m_textureTarget, GL_TEXTURE_MAX_LEVEL, mipmaps - 1);

    //ErrorHandler::checkForErrors();
}

void TextureOGL::bindTexture(RenderContext& context, GLuint var1, GLuint var2)
{
    // todo
}

void TextureOGL::subBuffer(RenderContext& ctx, GLvoid const* pixels, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLint level)
{
    bindTexture(ctx, GL_FALSE, GL_LINE_LOOP);
    //ErrorHandler::checkForErrors();

    if (m_textureTarget != GL_TEXTURE_2D)
    {
        //LOG_E("Unknown textureTarget " << m_textureTarget);
        throw std::bad_cast();
    }

    glTexSubImage2D(GL_TEXTURE_2D, level, xoffset, yoffset, width, height, m_internalFormat, m_type, pixels);
    //ErrorHandler::checkForErrors();
}

void TextureOGL::subBuffer(RenderContext& ctx, GLvoid const* pixels)
{
    subBuffer(ctx, pixels, 0, 0, m_description.m_width, m_description.m_height, 0);
}

void TextureOGL::createMipMap(RenderContext& context, GLvoid const* pixels, Glsizei width, Glsizei height, GLint level)
{
    if (m_textureTarget != GL_TEXTURE_2D)
    {
        //LOG_E("Unknown textureTarget " << m_textureTarget);
        throw std::bad_cast();
    }

    glTexImage2D(GL_TEXTURE_2D, level, m_internalFormat, width, height, 0, m_format, m_type, pixels);
    m_created = true;
}

void TextureOGL::createTexture(RenderContext& context, TextureDescription const& description)
{
    TextureBase::createTexture(description);
    glGenTextures(1, &m_glObj);
    //ErrorHandler::checkForErrors();
    
    if (description.m_textureFormat != TEXTURE_FORMAT_R8G8B8A8_UNORM)
    {
        //LOG_E("Unknown textureFormat: " << (description.m_textureFormat);
        throw std::bad_cast();
    }

    m_internalFormat = GL_RGBA;
    m_format = GL_RGBA;
    m_type = GL_UNSIGNED_BYTE;

    bindTexture(context, 0, 2);
    //mce::ErrorHandler::checkForErrors();
    createMipMap(context, 0, description.m_width, description.m_height, 0);

    switch (description.m_filteringLevel)
    {
    case TEXTURE_FILTERING_BILINEAR:
        glTexParameteri(m_textureTarget, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(m_textureTarget, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(m_textureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        break;
    case TEXTURE_FILTERING_POINT:
        glTexParameteri(m_textureTarget, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(m_textureTarget, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(m_textureTarget, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        break;
    case TEXTURE_FILTERING_MIPMAP_BILINEAR:
        glTexParameteri(m_textureTarget, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(m_textureTarget, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
        glTexParameteri(m_textureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        break;
    }

    //mce::ErrorHandler::checkForErrors();
}

void TextureOGL::lock(RenderContext& ctx)
{
    // todo
}

void TextureOGL::unlock(RenderContext& ctx)
{
    // todo
}

bool TextureOGL::supportsMipMaps()
{
    return gl::supportsMipmaps();
}