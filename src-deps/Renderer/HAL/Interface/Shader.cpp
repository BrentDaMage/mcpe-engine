#include "Shader.h"

using namespace mce;

Shader::Shader(ShaderProgram& vertex, ShaderProgram& fragment, ShaderProgram& geometry)
    : ShaderOGL(vertex, fragment, geometry)
{
}