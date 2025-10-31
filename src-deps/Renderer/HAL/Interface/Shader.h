#pragma once

#include "ShaderProgram.h"
#include "OGL/ShaderOGL.h"

namespace mce
{
    class Shader : public ShaderOGL
    {
    public:
        Shader(ShaderProgram& vertex, ShaderProgram& fragment, ShaderProgram& geometry);
    };
}