#pragma once

#include <set>
#include <string>
#include <stdint.h>

#include "HAL/Interface/Shader.h"
#include "HAL/Interface/BlendState.h"
#include "HAL/Interface/DepthStencilState.h"
#include "HAL/Interface/RasterizerState.h"

namespace mce
{
    class RenderMaterial
    {
    public:
        std::set<std::string> m_defines;
        int32_t m_stateMask;
        std::string m_vertexShader;
        std::string m_fragmentShader;
        std::string m_geometryShader;
        float m_polygonOffsetLevel;
        mce::Shader *m_shader;
        mce::BlendState m_blendState;
        mce::BlendStateDescription m_blendStateDescription;
        mce::DepthStencilState m_depthStencilState;
        mce::DepthStencilStateDescription m_depthStencilStateDescription;
        mce::RasterizerState m_rasterizerState;
        const mce::RasterizerStateDescription m_rasterizerStateDescription;

    public:
        RenderMaterial();
        RenderMaterial(const RenderMaterial& other);
    };
}