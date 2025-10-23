#include "ShaderBase.h"

using namespace mce;

ShaderBase::ShaderBase(ShaderProgram& vertexShader, ShaderProgram& fragmentShader, ShaderProgram& geometryShader)
    : m_vertexShader(vertexShader)
    , m_fragmentShader(fragmentShader)
    , m_geometryShader(geometryShader)
{
    m_attributeListIndex = 0;
}