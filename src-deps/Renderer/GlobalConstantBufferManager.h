#pragma once

#include <vector>

#include "Core/Utility/Singleton.h"
#include "Interface/ConstantBufferContainer.h"

namespace mce
{
    class GlobalConstantBufferManager : public Singleton<GlobalConstantBufferManager>
    {
    public:
        std::vector<mce::ConstantBufferContainer> m_constantBufferContainers;

    public:
        GlobalConstantBufferManager();

    public:
        void refreshWorldConstants();
        void allocateAndSetupConstantBuffersFromMetadata(mce::RenderContext& ctx);
        mce::ConstantBufferContainer* findConstantBufferContainer(const std::string& bufferName);
    };
}