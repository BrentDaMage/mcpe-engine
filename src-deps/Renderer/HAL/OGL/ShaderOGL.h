#pragma once

#include <vector>

#include "API_OGL.h"
#include "ShaderBase.h"
#include "../../RenderContextImmediate.h"
#include "ShaderUniformOGL.h"
#include "ShaderProgram.h"
#include "ShaderPrimitiveTypes.h"
#include "VertexFormat.h"
#include "RenderContext.h"
#include "ErrorHandler.h"

namespace mce
{
    class ShaderOGL : public ShaderBase
    {
    public:
        struct VertexFieldFormat
        {
            GLenum componentsType;
            GLint components;
            GLboolean normalized;
        };

    private:
        GLuint m_program;
        std::vector<ShaderUniformOGL> m_uniformList;
        std::vector<ShaderResourceOGL> m_textureList;

    public:
        ShaderOGL(ShaderProgram& vertex, ShaderProgram& fragment, ShaderProgram& geometry);
        ~ShaderOGL();

    public:
        static ShaderPrimitiveTypes shaderPrimitiveTypeFromOGLUniformType(GLenum uniformType);

        void deleteShader();
        void finalizeShaderUniforms();
        static void freeCompilerResources();
        static void resetLastProgram();
        void createAndAttachPrograms();
        void linkShader();
        void bindVertexPointers(const VertexFormat&, const void*);
        void bindShader(RenderContext& context, const VertexFormat& format, const void *dataBasePtr, unsigned int shaderStageBits);
        void reflectShaderUniforms(); // @TODO
        void reflectShaderAttributes();
        void reflectShader();
    };
}
