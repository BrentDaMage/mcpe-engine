#pragma once

#include "../Base/TextureBase.h"

class TextureOGL : TextureBase
{
private:
    TextureDescription description;
    bool createdMipMaps;
    GLuint* id;
    GLenum textureTarget;
    GLint internalFormat;
    GLenum format;
    GLenum type;

public:
    TextureOGL();
    
    void deleteTexture();
    void bindTexture(RenderContext& context, GLuint texture, GLuint);
    
    void convertToMipmapedTexture(RenderContext& context, GLuint mipMaps);

    void subBuffer(RenderContext& context, GLvoid const* pixels, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLint level);
    void subBuffer(RenderContext& context, GLvoid const* pixels);

    void copyTexture(RenderContext& context, Texture* texture, uint_t, uint_t, uint_t, uint_t);

    void createMipMap(RenderContext& context, GLvoid const* pixels, Glsizei width, Glsizei height, GLint level);
    void createTexture(RenderContext& context, TextureDescription const&);

    void lock(RenderContext& context);
    void unlock(RenderContext& context);

    bool supportsMipMaps();
}
