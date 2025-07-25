#pragma once

#include "API_OGL.h"
#include "../Base/ShaderBase.h"
#include "ShaderProgram.h"
#include "VertexFormat.h"
#include "RenderContext.h"
#include "ErrorHandler.h"
#include "ErrorHandler.h"

namespace mce
{
class ShaderOGL : ShaderBase
{
private:
    GLuint m_shaderProgram;
    GLuint m_vertexShaderObject;
    GLuint m_fragmentShaderObject;
    GLuint m_geometryShaderObject;

public:
    ShaderOGL(ShaderProgram& vertexShader, ShaderProgram& fragmentShader, ShaderProgram& geometryShader);
    ~ShaderOGL();

    void deleteShader();
    void finalizeShaderUniforms();
    void freeCompilerResources()
    resetLastProgram();
    void createAndAttachPrograms();
    void linkShader();
    void bindVertexPointers(VertexFormat const&, void*);
    void binsShader(RenderContext&, VertexFormat const&, void*, uint);
    void reflectShaderUniforms();
    void reflectShaderAttributes();
    void reflectShader();
};
}
