#pragma once

#include "ShaderProgramBase.h"
#include "ShaderProgramOGL.h"

namespace mce
{
    // This is temporary, and ShaderProgram should instead inherit ShaderProgramOGL, since it's an interface.
    class ShaderProgram : public ShaderProgramOGL
    {
    };
}