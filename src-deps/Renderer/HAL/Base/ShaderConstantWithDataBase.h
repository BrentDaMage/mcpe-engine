#pragma once

#include "Interface/ShaderConstant.h"

namespace mce
{
    class ShaderConstantWithDataBase : public ShaderConstant
    {
    public:
        uint8_t* m_data;
    };
}
