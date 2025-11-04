#pragma once

#include <vector>

#include "API_OGL.h"
#include "../../RenderContextImmediate.h"
#include "ShaderUniformOGL.h"
#include "ShaderBase.h"
#include "ShaderProgram.h"
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
            unsigned int componentsType;
            int components;
            bool normalized;
        };

    private:
        GLuint m_shaderProgram;
        std::vector<ShaderUniformOGL> m_uniformList;
        unsigned int m_vertexArrayObjectName;
        VertexFieldFormat m_vffmap[10];

    public:
        ShaderOGL(ShaderProgram& vertex, ShaderProgram& fragment, ShaderProgram& geometry);
        ~ShaderOGL();

        void deleteShader();
        void finalizeShaderUniforms(); // @TODO
        void freeCompilerResources();
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
