#pragma once

#include "TextureBase.h"
#include "RenderContext.h"

namespace mce
{

class TextureOGL : public TextureBase
{
private:
    TextureDescription description;
    bool m_created;
    GLuint* m_glObj;
    GLenum m_textureTarget;
    GLint m_internalFormat;
    GLenum m_format;
    GLenum m_type;

public:
    TextureOGL();
    
    void deleteTexture();
    void bindTexture(RenderContext& context, GLuint texture, GLuint);
    
    void convertToMipmapedTexture(RenderContext& context, GLuint mipmaps);

    void subBuffer(RenderContext& context, GLvoid const* pixels, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLint level);
    void subBuffer(RenderContext& context, GLvoid const* pixels);

    void copyTexture(RenderContext& context, Texture* texture, uint_t, uint_t, uint_t, uint_t) { }

    void createMipMap(RenderContext& context, GLvoid const* pixels, Glsizei width, Glsizei height, GLint level);
    void createTexture(RenderContext& context, TextureDescription const&);

    void lock(RenderContext& context);
    void unlock(RenderContext& context);

    bool supportsMipMaps();
};

}
