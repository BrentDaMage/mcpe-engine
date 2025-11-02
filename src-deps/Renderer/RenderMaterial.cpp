#include "RenderMaterial.h"
#include "PlatformDefinitions.h"
#include "HAL/Enums/RenderState_JsonParser.h"
#include "HAL/Enums/ComparisonFunc_JsonParser.h"
#include "HAL/Enums/StencilOp_JsonParser.h"

#if MCE_GFX_API_OGL
#include "Platform/OGL/ShaderPrecision.h"
#endif

using namespace mce;

RenderMaterial::RenderMaterial()
{
    m_stateMask = 0;
    m_polygonOffsetLevel = -2.0f;
}

RenderMaterial::RenderMaterial(const rapidjson::Value& root, const RenderMaterial& other)
    : RenderMaterial(other)
{
    const rapidjson::Value& statesValue = root["states"];
    for (rapidjson::Value::ConstValueIterator it = statesValue.Begin(); it != statesValue.End(); it++)
    {
        std::string stateName = it->GetString();
        RenderState state = _parseStateName(stateName);
        addState(state);
    }

    _parseRuntimeStates(root);

    {
        const rapidjson::Value& pathValue = root["vertexShader"];
        if (!pathValue.IsNull())
            m_vertexShader = pathValue.GetString();
    }
    {
        const rapidjson::Value& pathValue = root["fragmentShader"];
        if (!pathValue.IsNull())
            m_fragmentShader = pathValue.GetString();
    }
    {
        const rapidjson::Value& pathValue = root["geometryShader"];
        if (!pathValue.IsNull())
            m_geometryShader = pathValue.GetString();
    }

    _buildHeader(root);
}

RenderState RenderMaterial::_parseStateName(const std::string& stateName) const
{
    return _renderStateMap.at(stateName);
}

void RenderMaterial::_parseRuntimeStates(const rapidjson::Value& root)
{
    _parseDepthStencilState(root);
    _parseBlendState(root);

    const rapidjson::Value& polygonOffsetLevelValue = root["polygonOffsetLevel"];
    if (!polygonOffsetLevelValue.IsNull())
        m_polygonOffsetLevel = polygonOffsetLevelValue.GetFloat();
}

void RenderMaterial::_parseDepthStencilFace(const rapidjson::Value& root, const char* depthStencilFaceName, StencilFaceDescription& faceDescription) const
{
    const rapidjson::Value& value = root[depthStencilFaceName];
    if (value.IsNull())
        return;
    
    parse(value, "stencilFunc", faceDescription.stencilFunc);
    parse(value, "stencilFailOp", faceDescription.stencilFailOp);
    parse(value, "stencilDepthFailOp", faceDescription.stencilDepthFailOp);
    parse(value, "stencilPassOp", faceDescription.stencilPassOp);
}

void RenderMaterial::_parseDepthStencilState(const rapidjson::Value& root)
{
    DepthStencilStateDescription& desc = m_depthStencilStateDescription;
    
    parse(root, "depthFunc", desc.depthFunc);
    _parseDepthStencilFace(root, "frontFace", desc.frontFace);
    _parseDepthStencilFace(root, "backFace", desc.frontFace);

    {
        const rapidjson::Value& stencilRefValue = root["stencilRef"];
        if (!stencilRefValue.IsNull())
        {
            desc.overwroteStencilRef = true;
            desc.stencilRef.stencilRef = stencilRefValue.GetUint();
        }
    }

    {
        const rapidjson::Value& stencilReadMaskValue = root["stencilReadMask"];
        if (!stencilReadMaskValue.IsNull())
        {
            desc.stencilReadMask = stencilReadMaskValue.GetUint();
        }
    }
}

void RenderMaterial::_parseBlendState(const rapidjson::Value& root)
{
    parse(root, "blendSrc", m_blendStateDescription.blendSource);
    parse(root, "blendDst", m_blendStateDescription.blendDestination);
}

std::string RenderMaterial::_buildHeader(const rapidjson::Value& root)
{
    const rapidjson::Value& definesValue = root["defines"];
    for (rapidjson::Value::ConstValueIterator it = definesValue.Begin(); it != definesValue.End(); it++)
    {
        std::string defineStr = it->GetString();
        m_defines.insert("#define " + defineStr + "\n");
    }

#if MCE_GFX_API_OGL
    // Platform::OGL::Precision::buildHeader(); or some shit
#endif
}

void RenderMaterial::addState(RenderState state)
{
    m_stateMask |= 1 << (state & 0x1F);
}