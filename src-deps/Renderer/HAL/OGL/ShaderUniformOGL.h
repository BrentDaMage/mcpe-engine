#include <string>

#include "../Enums/ShaderPrimitiveTypes.h"
#include "../Base/ShaderConstantBase.h"

namespace mce
{

class ShaderUniformOGL
{
public:
    int m_location;
    int m_size;
    ShaderPrimitiveTypes m_shaderPrimitiveType;
    unsigned char byte9; // @TODO
    std::string m_name;
    ShaderConstantBase* m_shaderConstant;
    int dword14; // @TODO

public:
    ShaderUniformOGL(std::string name, int location, int size, ShaderPrimitiveTypes shaderPrimitiveType)
        : m_location(location)
        , m_size(size)
        , byte9(0)
        , m_shaderConstant(0)
        , m_name(name)
        , dword14(0)
        , m_shaderPrimitiveType(shaderPrimitiveType)
    {}

    void bind(bool forceBind);
};

}
