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
private:
    GLuint m_shaderProgram;
    ShaderUniformOGL* m_vertexShadefinalizeShaderUniformsrUniform;
    ShaderUniformOGL* m_fragmentShaderUniform;
    ShaderUniformOGL* m_geometryShaderUniform;
    std::vector<ShaderUniformOGL*> m_uniforms;

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
