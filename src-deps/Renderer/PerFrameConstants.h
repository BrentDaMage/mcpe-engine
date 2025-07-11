#pragma once

#include "Interface/ConstantBufferConstants.h"
#include "Interface/ShaderConstantWithData.h"

namespace mce
{
    class PerFrameConstants : public ConstantBufferConstants
    {
    public:
        mce::ShaderConstantFloat3 *VIEW_DIRECTION;
        mce::ShaderConstantFloat1 *TIME;
        mce::ShaderConstantFloat3 *VIEW_POS;
        mce::ShaderConstantFloat1 *FAR_CHUNKS_DISTANCE;
        mce::ShaderConstantFloat4 *FOG_COLOR;
        mce::ShaderConstantFloat2 *FOG_CONTROL;
        mce::ShaderConstantFloat1 *RENDER_DISTANCE;

    public:
        PerFrameConstants();

        void init();
    };
}