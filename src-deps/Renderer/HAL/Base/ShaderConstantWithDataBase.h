#pragma once

#include "Interface/ShaderConstant.h"

namespace mce
{
    class ShaderConstantWithDataBase : public ShaderConstant
    {
    public:
        uint8_t* m_data;

    public:
        void setData(const void* data)
        {
            memcpy(m_data, data, getSize());
            m_dirty = true;
        }
    };
}
