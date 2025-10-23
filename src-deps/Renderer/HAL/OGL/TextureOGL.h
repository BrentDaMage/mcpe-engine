#pragma once

#include "TextureBase.h"
#include "RenderContext.h"

namespace mce
{
    class Texture;

    class TextureOGL : public TextureBase
    {
    private:
        GLuint* m_glObj;
        GLenum m_textureTarget;
        GLint m_internalFormat;
        GLenum m_format;
        GLenum m_type;

    public:
        TextureOGL();
        
        void deleteTexture();
        void bindTexture(RenderContext& context, unsigned int texture, unsigned int);
        
        GLenum getOpenGLTextureFormat(TextureFormat textureFormat);
        GLint getOpenGLInternalTextureFormatFromTextureFormat(TextureFormat textureFormat);
        GLenum getOpenGLTextureTypeFromTextureFormat(TextureFormat textureFormat);
        
        void convertToMipmapedTexture(RenderContext& context, unsigned int mipmaps);

        void subBuffer(RenderContext& context, GLvoid const* pixels, unsigned int xoffset, unsigned int yoffset, unsigned int width, unsigned int height, unsigned int level);
        void subBuffer(RenderContext& context, GLvoid const* pixels);

        void copyTexture(RenderContext& context, Texture* texture, unsigned int, unsigned int, unsigned int, unsigned int) { }

        void createMipMap(RenderContext& context, void const* pixels, unsigned int width, unsigned int height, unsigned int level);
        void createTexture(RenderContext& context, TextureDescription const&);

        void lock(RenderContext& context);
        void unlock(RenderContext& context);

        bool supportsMipMaps();
    };
}
