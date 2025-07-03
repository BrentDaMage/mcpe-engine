#include "OGL_API.h"

#include "ShaderConstantWithDataOGL.h"

//template class mce::ShaderConstantWithDataOGL<mce::SHADER_PRIMITIVE_FLOAT1>;
void mce::ShaderConstantWithDataOGL<mce::SHADER_PRIMITIVE_FLOAT1>::syncUniform(int value)
{
    glUniform1fv(value, 1, m_data);
    ShaderConstant::syncUniform(value);
};

void mce::ShaderConstantWithDataOGL<mce::SHADER_PRIMITIVE_FLOAT2>::syncUniform(int value)
{
    glUniform2fv(value, 1, m_data);
    ShaderConstant::syncUniform(value);
};

void mce::ShaderConstantWithDataOGL<mce::SHADER_PRIMITIVE_FLOAT3>::syncUniform(int value)
{
    glUniform3fv(value, 1, m_data);
    ShaderConstant::syncUniform(value);
};

void mce::ShaderConstantWithDataOGL<mce::SHADER_PRIMITIVE_FLOAT4>::syncUniform(int value)
{
    glUniform4fv(value, 1, m_data);
    ShaderConstant::syncUniform(value);
};