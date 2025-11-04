#include "ShaderUniformOGL.h"

using namespace mce;

void ShaderUniformOGL::bind(bool forceBind)
{
    if (forceBind || m_shaderConstant->isDirty())
    {
        m_shaderConstant->syncUniform(m_location);
    }
}
