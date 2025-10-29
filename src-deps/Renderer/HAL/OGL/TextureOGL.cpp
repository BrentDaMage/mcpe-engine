#include <typeinfo>

#include "API_OGL.h"
#include "TextureOGL.h"

using namespace mce;

TextureOGL::TextureOGL()
    : TextureBase()
{
}

void TextureOGL::deleteTexture()
{
    glDeleteTextures(1, m_state.m_textureArray);
    TextureBase::deleteTexture();

    *this = TextureOGL();

    //ErrorHandler::checkForErrors();
}

void TextureOGL::bindTexture(RenderContext& context, unsigned int var1, unsigned int var2)
{
    // @TODO
}

GLenum TextureOGL::getOpenGLTextureFormat(TextureFormat textureFormat)
{
    switch (textureFormat)
    {
        case TEXTURE_FORMAT_R8G8B8A8_UNORM:
            return GL_RGBA;
        default:
            //LOG_E("Unknown textureFormat: %d", textureFormat);
            throw std::bad_cast();
    }
}

GLint TextureOGL::getOpenGLInternalTextureFormatFromTextureFormat(TextureFormat textureFormat)
{
    switch (textureFormat)
    {
        case TEXTURE_FORMAT_R8G8B8A8_UNORM:
            return GL_RGBA;
        default:
            //LOG_E("Unknown textureFormat: %d", textureFormat);
            throw std::bad_cast();
    }
}

GLenum TextureOGL::getOpenGLTextureTypeFromTextureFormat(TextureFormat textureFormat)
{
    switch (textureFormat)
    {
        case TEXTURE_FORMAT_R8G8B8A8_UNORM:
            return GL_UNSIGNED_BYTE;
        default:
            //LOG_E("Unknown textureFormat: %d", textureFormat);
            throw std::bad_cast();
    }
}

void TextureOGL::convertToMipmapedTexture(RenderContext& ctx, unsigned int mipmaps)
{
    if (mipmaps == 0)
    {
        //LOG_E("You must have a positive number of mip maps that is greater than 1");
        throw std::bad_cast();
    }

    bindTexture(ctx, 0, 2);
    TextureBase::convertToMipmapedTexture(mipmaps - 1);

    glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
     // @NOTE: Need GL 1.2 for GL_TEXTURE_MAX_LEVEL
    glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_MAX_LEVEL, mipmaps - 1);

    //ErrorHandler::checkForErrors();
}

void TextureOGL::subBuffer(RenderContext& ctx, void const* pixels, unsigned int xoffset, unsigned int yoffset, unsigned int width, unsigned int height, unsigned int level)
{
    bindTexture(ctx, GL_FALSE, GL_LINE_LOOP);
    //ErrorHandler::checkForErrors();

    if (m_state.m_textureTarget != GL_TEXTURE_2D)
    {
        //LOG_E("Unknown textureTarget " << m_state.m_textureTarget);
        throw std::bad_cast();
    }

    glTexSubImage2D(GL_TEXTURE_2D, level, xoffset, yoffset, width, height, m_state.m_internalTextureFormat, m_state.m_textureType, pixels);
    //ErrorHandler::checkForErrors();
}

void TextureOGL::subBuffer(RenderContext& ctx, void const* pixels)
{
    subBuffer(ctx, pixels, 0, 0, m_description.m_width, m_description.m_height, 0);
}

void TextureOGL::createMipMap(RenderContext& context, void const* pixels, unsigned int width, unsigned int height, unsigned int level)
{
    if (m_state.m_textureTarget != GL_TEXTURE_2D)
    {
        //LOG_E("Unknown textureTarget %d", m_state.m_textureTarget);
        throw std::bad_cast();
    }

    glTexImage2D(GL_TEXTURE_2D, level, m_state.m_internalTextureFormat, width, height, 0, m_state.m_textureFormat, m_state.m_textureType, pixels);
    m_bCreated = true;
}

void TextureOGL::createTexture(RenderContext& context, TextureDescription const& description)
{
    TextureBase::createTexture(description);
    glGenTextures(1, m_state.m_textureArray);
    //ErrorHandler::checkForErrors();
    
    m_state.m_internalTextureFormat = getOpenGLInternalTextureFormatFromTextureFormat(description.m_textureFormat);
    m_state.m_textureFormat = getOpenGLTextureFormat(description.m_textureFormat);
    m_state.m_textureType = getOpenGLTextureTypeFromTextureFormat(description.m_textureFormat);

    bindTexture(context, 0, 2);
    //ErrorHandler::checkForErrors();
    createMipMap(context, 0, description.m_width, description.m_height, 0);

    switch (description.m_filteringLevel)
    {
    case TEXTURE_FILTERING_BILINEAR:
        // @NOTE: Need GL 1.2 for GL_CLAMP_TO_EDGE
        glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        break;
    case TEXTURE_FILTERING_POINT:
        glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        break;
    case TEXTURE_FILTERING_MIPMAP_BILINEAR:
        glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
        glTexParameteri(m_state.m_textureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        break;
    default:
        break;
    }

    //mce::ErrorHandler::checkForErrors();
}

void TextureOGL::lock(RenderContext& ctx)
{
    // @TODO
}

void TextureOGL::unlock(RenderContext& ctx)
{
    // @TODO
}

bool TextureOGL::supportsMipMaps()
{
    return gl::supportsMipmaps();
}