#pragma once

#include "Interface/ConstantBufferConstants.h"
#include "Interface/ShaderConstantWithData.h"

namespace mce
{
    class WorldConstants : public ConstantBufferConstants
    {
    public:
        ShaderConstantMatrix4x4* WORLDVIEWPROJ;
        ShaderConstantMatrix4x4* WORLD;

    public:
        WorldConstants();

        void refreshWorldConstants();

        void init();
    };
}