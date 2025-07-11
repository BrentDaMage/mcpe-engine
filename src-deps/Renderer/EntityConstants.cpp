#include "EntityConstants.h"
#include "GlobalConstantBufferManager.h"

mce::EntityConstants::EntityConstants()
{
    OVERLAY_COLOR = nullptr;
    TILE_LIGHT_COLOR = nullptr;
    CHANGE_COLOR = nullptr;
    // only these were initialized for some reason.
    // I guess everything else can go fuck itself
}

void mce::EntityConstants::init()
{
    mce::GlobalConstantBufferManager* pBufferManager = mce::GlobalConstantBufferManager::getInstance();
    m_constantBuffer = pBufferManager->findConstantBufferContainer("EntityConstants");

    mce::ShaderConstantBase* pOverlayColor = m_constantBuffer->getUnspecializedShaderConstant("OVERLAY_COLOR");
    if (pOverlayColor)
    {
        if (pOverlayColor->getType() == SHADER_PRIMITIVE_FLOAT4)
        {
            OVERLAY_COLOR = (mce::ShaderConstantFloat4*)pOverlayColor;
        }
        else
        {
            OVERLAY_COLOR = nullptr;
        }
    }

    mce::ShaderConstantBase* pTileLightColor = m_constantBuffer->getUnspecializedShaderConstant("TILE_LIGHT_COLOR");
    if (pTileLightColor)
    {
        if (pTileLightColor->getType() == SHADER_PRIMITIVE_FLOAT4)
        {
            TILE_LIGHT_COLOR = (mce::ShaderConstantFloat4*)pTileLightColor;
        }
        else
        {
            TILE_LIGHT_COLOR = nullptr;
        }
    }

    mce::ShaderConstantBase* pChangeColor = m_constantBuffer->getUnspecializedShaderConstant("CHANGE_COLOR");
    if (pChangeColor)
    {
        if (pChangeColor->getType() == SHADER_PRIMITIVE_FLOAT4)
        {
            CHANGE_COLOR = (mce::ShaderConstantFloat4*)pChangeColor;
        }
        else
        {
            CHANGE_COLOR = nullptr;
        }
    }

    mce::ShaderConstantBase* pUvAnim = m_constantBuffer->getUnspecializedShaderConstant("UV_ANIM");
    if (pUvAnim)
    {
        if (pUvAnim->getType() == SHADER_PRIMITIVE_FLOAT2)
        {
            UV_ANIM = (mce::ShaderConstantFloat2*)pUvAnim;
        }
        else
        {
            UV_ANIM = nullptr;
        }
    }

    mce::ShaderConstantBase* pUvOffset = m_constantBuffer->getUnspecializedShaderConstant("UV_OFFSET");
    if (pUvOffset)
    {
        if (pUvOffset->getType() == SHADER_PRIMITIVE_FLOAT2)
        {
            UV_OFFSET = (mce::ShaderConstantFloat2*)pUvOffset;
        }
        else
        {
            UV_OFFSET = nullptr;
        }
    }

    mce::ShaderConstantBase* pUvRotation = m_constantBuffer->getUnspecializedShaderConstant("UV_ROTATION");
    if (pUvRotation)
    {
        if (pUvRotation->getType() == SHADER_PRIMITIVE_FLOAT2)
        {
            UV_ROTATION = (mce::ShaderConstantFloat2*)pUvRotation;
        }
        else
        {
            UV_ROTATION = nullptr;
        }
    }

    mce::ShaderConstantBase* pGlintUvScale = m_constantBuffer->getUnspecializedShaderConstant("GLINT_UV_SCALE");
    if (pGlintUvScale)
    {
        if (pGlintUvScale->getType() == SHADER_PRIMITIVE_FLOAT2)
        {
            GLINT_UV_SCALE = (mce::ShaderConstantFloat2*)pGlintUvScale;
        }
        else
        {
            GLINT_UV_SCALE = nullptr;
        }
    }
}