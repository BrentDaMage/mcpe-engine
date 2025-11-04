#include <typeinfo>
#include "GlobalConstantBuffers.h"
#include "ShaderConstants.h"
#include "GlobalConstantBufferManager.h"

using namespace mce;

GlobalConstantBufferManager::GlobalConstantBufferManager()
{
    // should call Singleton constructor automatically
    // should initialize m_constantBufferContainers automatically
}

void GlobalConstantBufferManager::refreshWorldConstants()
{
    GlobalConstantBuffers& buffers = GlobalConstantBuffers::getInstance();

    buffers.m_worldConstants.refreshWorldConstants();
    buffers.m_shaderConstants.setShaderColors(currentShaderColor, currentShaderDarkColor);
}

void GlobalConstantBufferManager::allocateAndSetupConstantBuffersFromMetadata(RenderContext& ctx)
{
    for (std::vector<ConstantBufferContainer>::iterator it = m_constantBufferContainers.begin(); it != m_constantBufferContainers.end(); it++)
    {
        it->allocateRenderContextBuffer(ctx);
    }
}

ConstantBufferContainer* GlobalConstantBufferManager::findConstantBufferContainer(const std::string& bufferName)
{
    for (std::vector<ConstantBufferContainer>::iterator it = m_constantBufferContainers.begin(); it != m_constantBufferContainers.end(); it++)
    {
        if (it->getConstantBufferName() == bufferName)
            return &*it; // solid
    }

    //LOG_E("Couldn't find the constant buffer named: %s was it properly reflected in the uniforms metadata file?", bufferName);
    throw std::bad_cast();
}