#pragma once

#include "Interface/ConstantBufferConstants.h"
#include "Interface/ShaderConstantWithData.h"

namespace mce
{
    class WorldConstants : public ConstantBufferConstants
    {
    public:
        mce::ShaderConstantMatrix4x4* WORLDVIEWPROJ;
        mce::ShaderConstantMatrix4x4* WORLD;

    public:
        WorldConstants();

        void refreshWorldConstants();

        void init();
    };
}