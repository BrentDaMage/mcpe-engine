using namespace mce;

enum ShaderPrimitiveTypes {
    UnknownPrimitiveType = 0,
    Float1 = 1,
    Float2 = 2,
    Float3 = 3,
    Float4 = 4,
    Int1 = 5,
    Int2 = 6,
    Int3 = 7,
    Int4 = 8,
    Matrix2x2 = 9,
    Matrix3x3 = 10,
    Matrix3x4 = 11,
    Matrix2x4 = 12,
    Matrix4x4 = 13
}

class ShaderPrimitiveTypeHelper {
public:
    int sizeInBytesFromShaderPrimitiveType(ShaderPrimitiveTypes* shaderPrimitiveType)
}
