#pragma once

#include <vector>

#include "Core/Utility/Singleton.h"
#include "Interface/ConstantBufferContainer.h"

namespace mce
{
    class GlobalConstantBufferManager : public Singleton<GlobalConstantBufferManager>
    {
    public:
        std::vector<ConstantBufferContainer> m_constantBufferContainers;

    public:
        GlobalConstantBufferManager();

    public:
        void refreshWorldConstants();
        void allocateAndSetupConstantBuffersFromMetadata(RenderContext& context);
        ConstantBufferContainer* findConstantBufferContainer(const std::string& bufferName);
    };
}