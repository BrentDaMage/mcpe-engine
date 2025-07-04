#pragma once

#include "API_OGL.h"

#include "Base/ShaderConstantWithDataBase.h"

namespace mce
{
    template <mce::ShaderPrimitiveTypes T>
    class ShaderConstantWithDataOGL : public ShaderConstantWithDataBase
    {
    public:
        template class ShaderConstantWithDataOGL<SHADER_PRIMITIVE_FLOAT1>;
        void syncUniform(int value) { glUniform1fv(value, 1, m_data); }

        template class ShaderConstantWithDataOGL<SHADER_PRIMITIVE_FLOAT2>;
        void syncUniform(int value) { glUniform2fv(value, 1, m_data); }

        template class ShaderConstantWithDataOGL<SHADER_PRIMITIVE_FLOAT3>;
        void syncUniform(int value) { glUniform3fv(value, 1, m_data); }

        template class ShaderConstantWithDataOGL<SHADER_PRIMITIVE_FLOAT4>;
        void syncUniform(int value) { glUniform4fv(value, 1, m_data); }

        template class ShaderConstantWithDataOGL<SHADER_PRIMITIVE_INT1>;
        void syncUniform(int value) { glUniform1iv(value, 1, m_data); }

        template class ShaderConstantWithDataOGL<SHADER_PRIMITIVE_INT2>;
        void syncUniform(int value) { glUniform2iv(value, 1, m_data); }

        template class ShaderConstantWithDataOGL<SHADER_PRIMITIVE_INT3>;
        void syncUniform(int value) { glUniform3iv(value, 1, m_data); }

        template class ShaderConstantWithDataOGL<SHADER_PRIMITIVE_INT4>;
        void syncUniform(int value) { glUniform4iv(value, 1, m_data); }

        template class ShaderConstantWithDataOGL<SHADER_PRIMITIVE_MATRIX2x2>;
        void syncUniform(int value) { glUniformMatrix2fv(value, 1, 0, m_data); }

        template class ShaderConstantWithDataOGL<SHADER_PRIMITIVE_MATRIX3x3>;
        void syncUniform(int value) { glUniformMatrix3fv(value, 1, 0, m_data); }

        template class ShaderConstantWithDataOGL<SHADER_PRIMITIVE_MATRIX4x4>;
        void syncUniform(int value) { glUniformMatrix4fv(value, 1, 0, m_data); }
    };
}
