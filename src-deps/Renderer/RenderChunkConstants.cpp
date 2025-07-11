#include "RenderChunkConstants.h"
#include "GlobalConstantBufferManager.h"

mce::RenderChunkConstants::RenderChunkConstants()
{
    CHUNK_ORIGIN = nullptr;
}

void mce::RenderChunkConstants::init()
{
    mce::GlobalConstantBufferManager* pBufferManager = mce::GlobalConstantBufferManager::getInstance();
    m_constantBuffer = pBufferManager->findConstantBufferContainer("RenderChunkConstants");

    mce::ShaderConstantBase* pChunkOrigin = m_constantBuffer->getUnspecializedShaderConstant("CHUNK_ORIGIN");
    if (pChunkOrigin)
    {
        if (pChunkOrigin->getType() == SHADER_PRIMITIVE_FLOAT3)
        {
            CHUNK_ORIGIN = (mce::ShaderConstantFloat3*)pChunkOrigin;
        }
        else
        {
            CHUNK_ORIGIN = nullptr;
        }
    }
}