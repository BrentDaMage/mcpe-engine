#pragma once

#include "Interface/ConstantBufferContainer.h"

namespace mce
{
    class ConstantBufferConstantsBase
    {
    public:
        // might be private
        mce::ConstantBufferContainer *m_constantBuffer;
                    
        ConstantBufferConstantsBase();
        virtual ~ConstantBufferConstantsBase() {};
    
        virtual void init() = 0;
    };
}
