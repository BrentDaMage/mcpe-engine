#pragma once

#include "Interface/ConstantBufferContainer.h"
#include "ShaderStage.h"

namespace mce
{
    class ConstantBufferBase
    {
    public:
        std::vector<unsigned int> m_bindingSlots;
        ShaderStage m_shaderStage;
        ConstantBufferContainer* m_pConstantBufferContainer;

        void createConstantBuffer(RenderContext &context, unsigned int count);
        unsigned int& getInternalMemory();
    };
}