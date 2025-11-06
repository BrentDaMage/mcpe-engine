#pragma once

#include "TextureBase.h"
#include "RenderContext.h"

namespace mce
{
    class Texture;

    class TextureOGL : public TextureBase
    {
    private:
        struct State
        {
            GLuint* m_textureArray;
            GLenum m_textureTarget;
            GLenum m_internalTextureFormat;
            GLenum m_textureFormat;
            GLenum m_textureType;

            State()
            {
                m_textureArray = nullptr;
                m_textureTarget = GL_TEXTURE_2D;
                m_internalTextureFormat = GL_NONE;
                m_textureFormat = GL_NONE;
                m_textureType = GL_NONE;
            }
        };
    private:
        State m_state;

    public:
        TextureOGL();
        
        static GLenum getOpenGLTextureFormat(TextureFormat textureFormat);
        static GLint getOpenGLInternalTextureFormatFromTextureFormat(TextureFormat textureFormat);
        static GLenum getOpenGLTextureTypeFromTextureFormat(TextureFormat textureFormat);

        void deleteTexture();
        void bindTexture(RenderContext& context, unsigned int textureUnit, unsigned int shaderStagesBits); // @TODO
        
        void convertToMipmapedTexture(RenderContext& context, unsigned int mipmaps);

        void subBuffer(RenderContext& context, const void* pixels, unsigned int xoffset, unsigned int yoffset, unsigned int width, unsigned int height, unsigned int level);
        void subBuffer(RenderContext& context, const void* pixels);

        void createMipMap(RenderContext& context, const void* pixels, unsigned int width, unsigned int height, unsigned int level);
        void createTexture(RenderContext& context, TextureDescription const&);

        void lock(RenderContext& context); // @TODO
        void unlock(RenderContext& context); // @TODO

        bool supportsMipMaps();
    };
}
