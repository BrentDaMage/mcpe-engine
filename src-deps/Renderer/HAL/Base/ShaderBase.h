#pragma once

#include <map>
#include <string>

#include "ShaderProgram.h"
#include "Attribute.h"
#include "VertexFormat.h"
#include "RenderDevice.h"

namespace mce
{
    class ShaderBase
    {
    public:
        unsigned int m_attributeListIndex;
        ShaderProgram& m_vertexShader;
        ShaderProgram& m_fragmentShader;
        ShaderProgram& m_geometryShader;

        static std::map<std::string, VertexField> builtinAttributeMap;

        ShaderBase(ShaderProgram& vertexShader, ShaderProgram& fragmentShader, ShaderProgram& geometryShader);

        bool isBuiltFrom(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentPath, const std::string& geometryPath) const;
        void validateVertexFormat(const VertexFormat& vertexFormat);
        void reflectShader(RenderDevice& renderDevice);
        const mce::VertexField& getAttributeForName(const std::string& name, unsigned int id) const;
    };
}