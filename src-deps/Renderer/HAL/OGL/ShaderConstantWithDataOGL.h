#pragma once

#include "API_OGL.h"

#include "ShaderConstantWithDataBase.h"

namespace mce
{
    template <ShaderPrimitiveTypes T>
    class ShaderConstantWithDataOGL : public ShaderConstantWithDataBase
    {
    public:
        ShaderConstantWithDataOGL(ShaderPrimitiveTypes primitiveType)
            : ShaderConstantWithDataBase(primitiveType)
        {
        }

        void syncUniform(int value);
    };

    template <>
    void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_FLOAT1>::syncUniform(int value)    { glUniform1fv(value, 1, (const GLfloat*)m_data); }
    template <>
    void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_FLOAT2>::syncUniform(int value)    { glUniform2fv(value, 1, (const GLfloat*)m_data); }
    template <>
    void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_FLOAT3>::syncUniform(int value)    { glUniform3fv(value, 1, (const GLfloat*)m_data); }
    template <>
    void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_FLOAT4>::syncUniform(int value)    { glUniform4fv(value, 1, (const GLfloat*)m_data); }
    template <>
    void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_INT1>::syncUniform(int value)      { glUniform1iv(value, 1, (const GLint*)m_data); }
    template <>
    void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_INT2>::syncUniform(int value)      { glUniform2iv(value, 1, (const GLint*)m_data); }
    template <>
    void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_INT3>::syncUniform(int value)      { glUniform3iv(value, 1, (const GLint*)m_data); }
    template <>
    void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_INT4>::syncUniform(int value)      { glUniform4iv(value, 1, (const GLint*)m_data); }
    template <>
    void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_MATRIX2x2>::syncUniform(int value) { glUniformMatrix2fv(value, 1, 0, (const GLfloat*)m_data); }
    template <>
    void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_MATRIX3x3>::syncUniform(int value) { glUniformMatrix3fv(value, 1, 0, (const GLfloat*)m_data); }
    template <>
    void ShaderConstantWithDataOGL<SHADER_PRIMITIVE_MATRIX4x4>::syncUniform(int value) { glUniformMatrix4fv(value, 1, 0, (const GLfloat*)m_data); }
}
