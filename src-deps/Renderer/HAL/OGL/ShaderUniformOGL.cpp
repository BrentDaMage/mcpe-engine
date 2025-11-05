#include "ShaderUniformOGL.h"

using namespace mce;

ShaderUniformOGL::ShaderUniformOGL(const std::string& name, int location, int elements, ShaderPrimitiveTypes shaderPrimitiveType)
    : m_location(location)
    , m_elements(elements)
    , m_name(name)
    , m_shaderPrimitiveType(shaderPrimitiveType)
{
    m_unknown = 0;
    m_shaderConstant = nullptr;
}

void ShaderUniformOGL::bind(bool forceBind)
{
    if (forceBind || m_shaderConstant->isDirty())
    {
        m_shaderConstant->syncUniform(m_location);
    }
}
