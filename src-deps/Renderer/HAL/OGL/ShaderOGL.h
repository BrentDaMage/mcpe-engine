#pragma once

class ShaderOGL {
private:
    GLuint program;

public:
    void deleteShader();
    finalizeShaderUniforms();
    freeCompilerResources()
    resetLastProgram();
    void createAndAttachPrograms();
    void linkShader();
    ~ShaderOGL();
    void bindVertexPointers(VertexFormat const&, void*);
    void binsShader(RenderContext&, VertexFormat const&, void*, uint);
    void reflectShaderUniforms();
    void reflectShaderAttributes();
    void reflectShader();
    ShaderOGL(ShaderProgram&, ShaderProgram?&, ShaderProgram&);
}