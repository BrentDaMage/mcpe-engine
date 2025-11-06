#pragma once

#include "Interface/ConstantBufferContainer.h"

namespace mce
{
    class ConstantBufferConstantsBase
    {
    protected:
        ConstantBufferContainer *m_constantBuffer;
            
    public:
        ConstantBufferConstantsBase();
        virtual ~ConstantBufferConstantsBase() {};
    
        virtual void init() = 0;
    };
}
