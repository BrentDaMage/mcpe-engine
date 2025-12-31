#include "ShaderResourceOGL.h"
#include "ShaderConstantOGL.h"
#include "ConstantBufferContainer.h"

namespace mce
{
    // ShaderUniform is specific to OpenGL
    class ShaderUniformOGL : public ShaderResourceOGL
    {
    public:
        ShaderConstantOGL* m_shaderConstant;
        ConstantBufferContainer *m_pConstantBufferContainer;

    public:
        ShaderUniformOGL(const std::string& name, int location, int elements, ShaderPrimitiveTypes shaderPrimitiveType);

        void bind(bool forceBind);
    };
}
