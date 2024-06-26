#pragma once

namespace mce
{
	enum ShaderPrimitiveTypes
	{
		SHADER_PRIMITIVE_UNKNOWN,
		SHADER_PRIMITIVE_FLOAT1,
		SHADER_PRIMITIVE_FLOAT2,
		SHADER_PRIMITIVE_FLOAT3,
		SHADER_PRIMITIVE_FLOAT4,
		SHADER_PRIMITIVE_INT1,
		SHADER_PRIMITIVE_INT2,
		SHADER_PRIMITIVE_INT3,
		SHADER_PRIMITIVE_INT4,
		SHADER_PRIMITIVE_MATRIX2x2,
		SHADER_PRIMITIVE_MATRIX3x3,
		SHADER_PRIMITIVE_MATRIX4x4,
		SHADER_PRIMITIVES_END,
		SHADER_PRIMITIVE_SAMPLER1D,
		SHADER_PRIMITIVE_SAMPLER2D,
		SHADER_PRIMITIVE_SAMPLER3D,
		SHADER_PRIMITIVES_MAX
	};

	class ShaderPrimitiveTypeHelper
	{
	public:
		static int sizeInBytesFromShaderPrimitiveType(mce::ShaderPrimitiveTypes shaderPrimitiveType);
	};
}