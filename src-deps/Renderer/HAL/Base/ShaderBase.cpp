#include <sstream>

#include "ShaderBase.h"

using namespace mce;

ShaderBase::ShaderBase(ShaderProgram& vertexShader, ShaderProgram& fragmentShader, ShaderProgram& geometryShader)
    : m_vertexShader(vertexShader)
    , m_fragmentShader(fragmentShader)
    , m_geometryShader(geometryShader)
{
    m_attributeListIndex = 0;
}

bool ShaderBase::isBuiltFrom(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentPath, const std::string& geometryPath) const
{
    return m_vertexShader.m_header == (shaderName + vertexPath) &&
           m_fragmentShader.m_header == (shaderName + fragmentPath) &&
          (m_geometryShader.m_header == (shaderName + geometryPath) || !m_geometryShader.m_valid);
}

void ShaderBase::validateVertexFormat(const VertexFormat& vertexFormat)
{
}

void ShaderBase::reflectShader(mce::RenderDevice& renderDevice)
{
}

const mce::VertexField& ShaderBase::getAttributeForName(const std::string& name, unsigned int id) const
{
    std::map<std::string, VertexField>::iterator it = builtinAttributeMap.find(name);

    if (it != builtinAttributeMap.end())
    {
        return it->second;
    }
    else
    {
        std::stringstream ss;
        ss << name << id;
        it = builtinAttributeMap.find(ss.str());

        return it->second;
    }
}