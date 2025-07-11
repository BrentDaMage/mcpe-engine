#pragma once

#include "Interface/ConstantBufferConstants.h"
#include "Interface/ShaderConstantWithData.h"

namespace mce
{
    class EntityConstants : public ConstantBufferConstants
    {
    public:
        mce::ShaderConstantFloat4 *OVERLAY_COLOR;
        mce::ShaderConstantFloat4 *TILE_LIGHT_COLOR;
        mce::ShaderConstantFloat4 *CHANGE_COLOR;
        mce::ShaderConstantFloat2 *UV_ANIM;
        mce::ShaderConstantFloat2 *UV_OFFSET;
        mce::ShaderConstantFloat2 *UV_ROTATION;
        mce::ShaderConstantFloat2 *GLINT_UV_SCALE;

    public:
        EntityConstants();

        void init();
    };
}