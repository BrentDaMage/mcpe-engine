#include "WeatherConstants.h"
#include "GlobalConstantBufferManager.h"

mce::WeatherConstants::WeatherConstants()
{
    POSITION_OFFSET = nullptr;
    VELOCITY = nullptr;
    ALPHA = nullptr;
    VIEW_POSITION = nullptr;
    SIZE_SCALE = nullptr;
    FORWARD = nullptr;
    UV_INFO = nullptr;
    PARTICLE_BOX = nullptr;
}

void mce::WeatherConstants::init()
{
    mce::GlobalConstantBufferManager* pBufferManager = mce::GlobalConstantBufferManager::getInstance();
    m_constantBuffer = pBufferManager->findConstantBufferContainer("WeatherConstants");

    mce::ShaderConstantBase* pPositionOffset = m_constantBuffer->getUnspecializedShaderConstant("POSITION_OFFSET");
    if (pPositionOffset)
    {
        if (pPositionOffset->getType() == SHADER_PRIMITIVE_FLOAT4)
        {
            POSITION_OFFSET = (mce::ShaderConstantFloat4*)pPositionOffset;
        }
        else
        {
            POSITION_OFFSET = nullptr;
        }
    }

    mce::ShaderConstantBase* pVelocity = m_constantBuffer->getUnspecializedShaderConstant("VELOCITY");
    if (pVelocity)
    {
        if (pVelocity->getType() == SHADER_PRIMITIVE_FLOAT4)
        {
            VELOCITY = (mce::ShaderConstantFloat4*)pVelocity;
        }
        else
        {
            VELOCITY = nullptr;
        }
    }

    mce::ShaderConstantBase* pAlpha = m_constantBuffer->getUnspecializedShaderConstant("ALPHA");
    if (pAlpha)
    {
        if (pAlpha->getType() == SHADER_PRIMITIVE_FLOAT4)
        {
            ALPHA = (mce::ShaderConstantFloat4*)pAlpha;
        }
        else
        {
            ALPHA = nullptr;
        }
    }

    mce::ShaderConstantBase* pViewPosition = m_constantBuffer->getUnspecializedShaderConstant("VIEW_POSITION");
    if (pViewPosition)
    {
        if (pViewPosition->getType() == SHADER_PRIMITIVE_FLOAT4)
        {
            VIEW_POSITION = (mce::ShaderConstantFloat4*)pViewPosition;
        }
        else
        {
            VIEW_POSITION = nullptr;
        }
    }

    mce::ShaderConstantBase* pSizeScale = m_constantBuffer->getUnspecializedShaderConstant("SIZE_SCALE");
    if (pSizeScale)
    {
        if (pSizeScale->getType() == SHADER_PRIMITIVE_FLOAT4)
        {
            SIZE_SCALE = (mce::ShaderConstantFloat4*)pSizeScale;
        }
        else
        {
            SIZE_SCALE = nullptr;
        }
    }

    mce::ShaderConstantBase* pForward = m_constantBuffer->getUnspecializedShaderConstant("FORWARD");
    if (pForward)
    {
        if (pForward->getType() == SHADER_PRIMITIVE_FLOAT4)
        {
            FORWARD = (mce::ShaderConstantFloat4*)pForward;
        }
        else
        {
            FORWARD = nullptr;
        }
    }

    mce::ShaderConstantBase* pUvInfo = m_constantBuffer->getUnspecializedShaderConstant("UV_INFO");
    if (pUvInfo)
    {
        if (pUvInfo->getType() == SHADER_PRIMITIVE_FLOAT4)
        {
            UV_INFO = (mce::ShaderConstantFloat4*)pUvInfo;
        }
        else
        {
            UV_INFO = nullptr;
        }
    }

    mce::ShaderConstantBase* pParticleBox = m_constantBuffer->getUnspecializedShaderConstant("PARTICLE_BOX");
    if (pParticleBox)
    {
        if (pParticleBox->getType() == SHADER_PRIMITIVE_FLOAT4)
        {
            PARTICLE_BOX = (mce::ShaderConstantFloat4*)pParticleBox;
        }
        else
        {
            PARTICLE_BOX = nullptr;
        }
    }
}