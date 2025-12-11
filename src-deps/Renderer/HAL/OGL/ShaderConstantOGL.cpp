#include "ShaderConstantOGL.h"

using namespace mce;

void ShaderConstantOGL::syncUniform(int location)
{
    m_dirty = false;
}