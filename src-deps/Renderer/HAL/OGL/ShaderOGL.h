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
    std::vector<ShaderUniformOGL, std::allocator<ShaderUniformOGL>> uniformList;
    unsigned int vertexArrayObjectName;
    VertexFieldFormat vffmap[10];

public:
    ShaderOGL(ShaderProgram& vertexShader, ShaderProgram& fragmentShader, ShaderProgram& geometryShader);
    ~ShaderOGL();

    void deleteShader();
    void finalizeShaderUniforms(); // @TODO
    void freeCompilerResources();
    void resetLastProgram();
    void createAndAttachPrograms();
    void linkShader();
    void bindVertexPointers(VertexFormat const&, void*);
    void bindShader(RenderContext&, VertexFormat const&, void*, unsigned int);
    void reflectShaderUniforms(); // @TODO
    void reflectShaderAttributes(); // @TODO
    void reflectShader();
};
}
