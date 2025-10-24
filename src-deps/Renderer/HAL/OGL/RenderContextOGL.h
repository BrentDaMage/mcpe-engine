#pragma once

#include <vector>

#include "API_OGL.h"
#include "RenderContextBase.h"

namespace mce
{
    class RenderContextOGL : public RenderContextBase
    {
    public:
        GLuint *m_buffers[2];
        unsigned int m_uniformValue;
        unsigned int m_bSetUniformValue;

        // need to confirm the rest
        unsigned int field_6C;
        unsigned int field_70;
        unsigned int field_74;
        unsigned int field_78;
        unsigned int field_7C;
        unsigned int field_80;
        unsigned int field_84;
        unsigned int field_88;
        unsigned int field_8C;
        unsigned int field_90;
        unsigned int field_94;
        unsigned int field_98;
        unsigned int field_9C;
        unsigned int field_A0;
        std::vector<uint8_t> field_A4;
    };
}
