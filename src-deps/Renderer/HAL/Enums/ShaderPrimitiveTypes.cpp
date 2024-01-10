using namespace mce;

int ShaderPrimitiveTypeHelper::sizeInBytesFromShaderPrimitiveType(ShaderPrimitiveTypes* shaderPrimitiveType)
{
    switch (shaderPrimitiveType)
    {
        case Float1:
        case Int1:
            return 4;
        case Float2:
        case Int2:
            return 8;
        case Float3:
        case Int3:
            return 12;
        case Float4:
        case Int4:
        case Matrix2x2:
            return 16;
        case Matrix3x3:
            return 36;
        case Matrix3x4:
            return 64;
        default:
            LOG_E("Unknown shaderPrimitiveType: " << shaderPrimitiveType);
            return nullptr;
    }
}
