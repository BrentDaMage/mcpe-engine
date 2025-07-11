#include "GlobalConstantBufferManager.h"
#include "ShaderConstants.h"

mce::ShaderConstants::ShaderConstants()
    : mce::ConstantBufferConstants()
{
    CURRENT_COLOR = nullptr;
    DARKEN = nullptr;
}

void mce::ShaderConstants::setShaderColor(const Color& shaderColor)
{
    CURRENT_COLOR->m_data = (uint8_t*)&shaderColor;
    CURRENT_COLOR->m_dirty = true;
    m_constantBuffer->sync(mce::RenderContextImmediate::get());
}

void mce::ShaderConstants::setShaderColors(const Color& shaderColor, const Color& shaderDarkenColor)
{
    Color* pCurrentColor = (Color*)CURRENT_COLOR->m_data;
    *pCurrentColor = shaderColor;
    CURRENT_COLOR->m_dirty = true;

    Color* pDarkenColor = (Color*)DARKEN->m_data;
    *pDarkenColor = shaderDarkenColor;
    DARKEN->m_dirty = true;
    m_constantBuffer->sync(mce::RenderContextImmediate::get());
}

void mce::ShaderConstants::init()
{
    mce::GlobalConstantBufferManager* pBufferManager = mce::GlobalConstantBufferManager::getInstance();
    m_constantBuffer = pBufferManager->findConstantBufferContainer("ShaderConstants");

    mce::ShaderConstantBase* pCurrentColor = m_constantBuffer->getUnspecializedShaderConstant("CURRENT_COLOR");
    if (pCurrentColor)
    {
        if (pCurrentColor->getType() == SHADER_PRIMITIVE_FLOAT4)
        {
            CURRENT_COLOR = (mce::ShaderConstantFloat4*)pCurrentColor;
        }
        else
        {
            CURRENT_COLOR = nullptr;
        }
    }

    mce::ShaderConstantBase* pDarkenColor = m_constantBuffer->getUnspecializedShaderConstant("DARKEN");
    if (pDarkenColor)
    {
        if (pDarkenColor->getType() == SHADER_PRIMITIVE_FLOAT4)
        {
            DARKEN = (mce::ShaderConstantFloat4*)pDarkenColor;
        }
        else
        {
            DARKEN = nullptr;
        }
    }
}