#include "ShaderConstantWithDataOGL.h"

using namespace mce;

template <>
void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_FLOAT1>::syncUniform(int location)    { glUniform1fv(location, 1, (const GLfloat*)m_data); }
template <>
void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_FLOAT2>::syncUniform(int location)    { glUniform2fv(location, 1, (const GLfloat*)m_data); }
template <>
void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_FLOAT3>::syncUniform(int location)    { glUniform3fv(location, 1, (const GLfloat*)m_data); }
template <>
void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_FLOAT4>::syncUniform(int location)    { glUniform4fv(location, 1, (const GLfloat*)m_data); }
template <>
void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_INT1>::syncUniform(int location)      { glUniform1iv(location, 1, (const GLint*)m_data); }
template <>
void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_INT2>::syncUniform(int location)      { glUniform2iv(location, 1, (const GLint*)m_data); }
template <>
void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_INT3>::syncUniform(int location)      { glUniform3iv(location, 1, (const GLint*)m_data); }
template <>
void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_INT4>::syncUniform(int location)      { glUniform4iv(location, 1, (const GLint*)m_data); }
template <>
void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_MATRIX2x2>::syncUniform(int location) { glUniformMatrix2fv(location, 1, 0, (const GLfloat*)m_data); }
template <>
void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_MATRIX3x3>::syncUniform(int location) { glUniformMatrix3fv(location, 1, 0, (const GLfloat*)m_data); }
template <>
void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_MATRIX4x4>::syncUniform(int location) { glUniformMatrix4fv(location, 1, 0, (const GLfloat*)m_data); }