#include <typeinfo>
#include "GlobalConstantBuffers.h"
#include "ShaderConstants.h"
#include "GlobalConstantBufferManager.h"

mce::GlobalConstantBufferManager::GlobalConstantBufferManager()
{
    // should call Singleton constructor automatically
    // should initialize m_constantBufferContainers automatically
}

void mce::GlobalConstantBufferManager::refreshWorldConstants()
{
    mce::GlobalConstantBuffers* pBuffers = mce::GlobalConstantBuffers::getInstance();

    pBuffers->m_worldConstants.refreshWorldConstants();
    pBuffers->m_shaderConstants.setShaderColors(currentShaderColor, currentShaderDarkColor);
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
    for (std::vector<ConstantBufferContainer>::iterator it = m_constantBufferContainers.begin(); it != m_constantBufferContainers.end(); it++)
    {
        if (it->getConstantBufferName() == bufferName)
            return &*it; // solid
    }

    //LOG_E("Couldn't find the constant buffer named: %s was it properly reflected in the uniforms metadata file?", bufferName);
    throw std::bad_cast();
}