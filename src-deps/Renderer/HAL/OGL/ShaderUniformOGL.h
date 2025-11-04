#include <string>

#include "../Enums/ShaderPrimitiveTypes.h"
#include "../Base/ShaderConstantBase.h"
#include "ShaderConstantOGL.h"

namespace mce
{

class ShaderUniformOGL : public ShaderConstantBase
{
public:
    int m_location;
    int m_size;
    ShaderPrimitiveTypes m_shaderPrimitiveType;
    unsigned char byte9; // @TODO
    std::string m_name;
    ShaderConstantOGL* m_shaderConstant;

public:
    ShaderUniformOGL(std::string name, int location, int size, ShaderPrimitiveTypes shaderPrimitiveType)
        : m_location(location)
        , m_size(size)
        , byte9(0)
        , m_shaderConstant(0)
        , m_name(name)
        , m_shaderPrimitiveType(shaderPrimitiveType)
    {}

    void bind(bool forceBind);
};

}
