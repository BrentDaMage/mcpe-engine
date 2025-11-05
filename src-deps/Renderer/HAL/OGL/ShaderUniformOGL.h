#include <string>

#include "ShaderPrimitiveTypes.h"
#include "ShaderConstantOGL.h"

namespace mce
{
    // ShaderUniform is specific to OpenGL
    class ShaderUniformOGL
    {
    public:
        int m_location;
        int m_elements;
        ShaderPrimitiveTypes m_shaderPrimitiveType;
        uint8_t m_unknown; // @TODO
        std::string m_name;
        ShaderConstantOGL* m_shaderConstant;

    public:
        ShaderUniformOGL(const std::string& name, int location, int elements, ShaderPrimitiveTypes shaderPrimitiveType);

        void bind(bool forceBind);
    };
}
