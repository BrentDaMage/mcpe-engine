#pragma once

#include <set>
#include <string>
#include <stdint.h>

#include "rapidjson/document.h"

#include "HAL/Enums/RenderState.h"
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
        Shader *m_shader;
        BlendState m_blendState;
        BlendStateDescription m_blendStateDescription;
        DepthStencilState m_depthStencilState;
        DepthStencilStateDescription m_depthStencilStateDescription;
        RasterizerState m_rasterizerState;
        const RasterizerStateDescription m_rasterizerStateDescription;

    public:
        RenderMaterial();
        RenderMaterial(const RenderMaterial& other);
        RenderMaterial(const rapidjson::Value& root, const RenderMaterial& other);

    protected:
        RenderState _parseStateName(const std::string& stateName) const;
        void _parseRuntimeStates(const rapidjson::Value& root);
        void _parseDepthStencilFace(const rapidjson::Value& root, const char* depthStencilFaceName, StencilFaceDescription& faceDescription) const;
        void _parseDepthStencilState(const rapidjson::Value& root);
        void _parseBlendState(const rapidjson::Value& root);
        std::string _buildHeader(const rapidjson::Value& root);

    public:
        void addState(RenderState state);
    };
}