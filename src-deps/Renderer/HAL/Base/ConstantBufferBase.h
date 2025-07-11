#pragma once

#include "Interface/ConstantBufferContainer.h"
#include "ShaderStage.h"

namespace mce
{
    class ConstantBufferBase
    {
    public:
        std::vector<unsigned int> m_bindingSlots;
        mce::ShaderStage m_shaderStage;
        mce::ConstantBufferContainer *m_constantBufferContainer;

        void createConstantBuffer(mce::RenderContext &context, unsigned int count);
        unsigned int& getInternalMemory();
    };
}