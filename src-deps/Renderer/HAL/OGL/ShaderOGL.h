#pragma once

#include "API_OGL.h"
#include "../../RenderContextImmediate.h"
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
    GLuint m_vertexShaderObject;
    GLuint m_fragmentShaderObject;
    GLuint m_geometryShaderObject;
    GLint m_uniformLocations[8]; // technically an std::array

public:
    ShaderOGL(ShaderProgram& vertexShader, ShaderProgram& fragmentShader, ShaderProgram& geometryShader);
    ~ShaderOGL();

    void deleteShader();
    void finalizeShaderUniforms(); // @TODO
    void freeCompilerResources(); // @TODO
    void resetLastProgram();
    void createAndAttachPrograms();
    void linkShader();
    void bindVertexPointers(VertexFormat const&, void*); // @TODO
    void bindShader(RenderContext&, VertexFormat const&, void*, unsigned int); // @TODO
    void reflectShaderUniforms(); // @TODO
    void reflectShaderAttributes(); // @TODO
    void reflectShader();
};
}
