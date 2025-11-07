#pragma once

#include "Base/ConstantBufferContainerBase.h"

namespace mce
{
    class ConstantBufferContainerOGL : public ConstantBufferContainerBase
    {
    public:
        ConstantBufferContainerOGL();

        void sync(RenderContext& context);
    };
}