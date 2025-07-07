#pragma once

#include "Base/ConstantBufferContainerBase.h"

namespace mce
{
    class ConstantBufferContainerOGL : public ConstantBufferContainerBase
    {
    public:
        ConstantBufferContainerOGL();
        ConstantBufferContainerOGL(mce::ConstantBufferContainerOGL& other);
        
        ~ConstantBufferContainerOGL();

        void sync();
    };
}