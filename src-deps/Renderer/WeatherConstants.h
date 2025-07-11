#pragma once

#include "Interface/ConstantBufferConstants.h"
#include "Interface/ShaderConstantWithData.h"

namespace mce
{
    class WeatherConstants : public ConstantBufferConstants
    {
    public:
        mce::ShaderConstantFloat4 *POSITION_OFFSET;
        mce::ShaderConstantFloat4 *VELOCITY;
        mce::ShaderConstantFloat4 *ALPHA;
        mce::ShaderConstantFloat4 *VIEW_POSITION;
        mce::ShaderConstantFloat4 *SIZE_SCALE;
        mce::ShaderConstantFloat4 *FORWARD;
        mce::ShaderConstantFloat4 *UV_INFO;
        mce::ShaderConstantFloat4 *PARTICLE_BOX;

    public:
        WeatherConstants();

        void init();
    };
}