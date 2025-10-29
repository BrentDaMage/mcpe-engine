#pragma once

#include <vector>

#include "API_OGL.h"
#include "RenderContextBase.h"

namespace mce
{
    class RenderContextOGL : public RenderContextBase
    {
    public:
        class ActiveTextureUnit
        {
            public:
                GLuint m_textureUnit;
                bool m_bIsShaderUniformDirty;
        };

    public:
        GLuint m_activeTexture;
        GLuint m_activeShaderProgram;
        GLuint m_activeBuffer[2];
        ActiveTextureUnit m_activeTextureUnits[8];
        std::vector<const GLvoid *> field_A4;
    };
}
