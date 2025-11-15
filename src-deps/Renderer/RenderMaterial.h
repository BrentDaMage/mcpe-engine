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

#include "ShaderGroup.h"

namespace mce
{
    class RenderMaterial
    {
    public:
        static RenderMaterial* lastUsedMaterial;

    public:
        std::set<std::string> m_defines;
        int32_t m_stateMask;
        std::string m_vertexShader;
        std::string m_fragmentShader;
        std::string m_geometryShader;
        float m_polygonOffsetLevel;
        Shader *m_pShader; // we DO NOT own this, so don't delete it
        BlendState m_blendState;
        BlendStateDescription m_blendStateDescription;
        DepthStencilState m_depthStencilState;
        DepthStencilStateDescription m_depthStencilStateDescription;
        RasterizerState m_rasterizerState;
        RasterizerStateDescription m_rasterizerStateDescription;

    public:
        RenderMaterial();
        RenderMaterial(const RenderMaterial& other);
        RenderMaterial(const rapidjson::Value& root, const RenderMaterial& parent);

    protected:
        RenderState _parseStateName(const std::string& stateName) const;
        void _parseRenderStates(const rapidjson::Value& root);
        void _parseRuntimeStates(const rapidjson::Value& root);
        void _parseDepthStencilFace(const rapidjson::Value& root, const char* depthStencilFaceName, StencilFaceDescription& faceDescription) const;
        void _parseDepthStencilState(const rapidjson::Value& root);
        void _parseBlendState(const rapidjson::Value& root);
        void _parseShaderPaths(const rapidjson::Value& root);
        void _parseDefines(const rapidjson::Value& root);
        std::string _buildHeader();
        void _loadShader(ShaderGroup& shaderGroup);
        void _applyRenderStates();

    public:
        void useWith(RenderContext& context, const VertexFormat& vertexFormat, const void *basePtr);
        void addState(RenderState state);
        bool hasState(RenderState state) const { return (m_stateMask & (1 << state)) != 0; }

    protected:
        static void SpliceShaderPath(std::string& shaderName);
    public:
        static void initContext();
    };
}