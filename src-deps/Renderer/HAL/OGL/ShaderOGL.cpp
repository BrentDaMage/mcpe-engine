void ShaderOGL::linkShader()
{
    glLinkProgram(program);
    ErrorHandler::checkForErrorS();

    GLint parameter = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &parameter);

    if (parameter == GL_FALSE)
    {
        
    }
}

void ShaderOGL::reflectShader()
{
    reflectShaderUniforms();
    reflectShaderAttributes();
}