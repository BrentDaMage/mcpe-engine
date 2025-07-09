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

void mce::ShaderConstants::setShaderColors( const Color& shaderColor, const Color& shaderDarkenColor)
{
    Color* currentColor = (Color*)CURRENT_COLOR->m_data;
    *currentColor = shaderColor;
    CURRENT_COLOR->m_dirty = true;

    Color* darkenColor = (Color*)DARKEN->m_data;
    *darkenColor = shaderDarkenColor;
    DARKEN->m_dirty = true;
    m_constantBuffer->sync(mce::RenderContextImmediate::get());
}

void mce::ShaderConstants::init()
{
    // @TODO: this
}