#include "ShaderPrecision.h"

using namespace mce::Platform::OGL;

GLint Precision::_getPrecision(GLenum shaderType, GLenum precisionType)
{
    GLint range, precision;
    glGetShaderPrecisionFormat(shaderType, precisionType, &range, &precision);

    return precision;
}

const std::string& Precision::atLeast(int atleast)
{
    info
}

void Precision::buildHeader(std::string& headerStream)
{

}