#pragma once

#include "Interface/ConstantBufferConstants.h"
#include "Interface/ShaderConstantWithData.h"

namespace mce
{
    class RenderChunkConstants : public ConstantBufferConstants
    {
    public:
        mce::ShaderConstantFloat3* CHUNK_ORIGIN;

    public:
        RenderChunkConstants();

        void init();
    };
}