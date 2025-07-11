#include "GlobalConstantBufferManager.h"

mce::GlobalConstantBufferManager::GlobalConstantBufferManager()
{
    // should call Singleton constructor automatically
    // should initialize m_constantBufferContainers automatically
}

void mce::GlobalConstantBufferManager::refreshWorldConstants()
{
    // @TODO: this
}

void mce::GlobalConstantBufferManager::allocateAndSetupConstantBuffersFromMetadata(mce::RenderContext& ctx)
{
    for (std::vector<mce::ConstantBufferContainer>::iterator it = m_constantBufferContainers.begin(); it != m_constantBufferContainers.end(); it++)
    {
        it->allocateRenderContextBuffer(ctx);
    }
}

mce::ConstantBufferContainer* mce::GlobalConstantBufferManager::findConstantBufferContainer(const std::string& bufferName)
{
    // @TODO: this
}