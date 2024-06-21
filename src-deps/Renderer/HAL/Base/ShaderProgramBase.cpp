#include "ShaderProgramBase.h"

mce::ShaderProgramBase::ShaderProgramBase(const std::string& header, const std::string& shaderPath, mce::ShaderType shaderType)
    : m_header(header), m_shaderPath(shaderPath), m_shaderType(shaderType)
{
    m_valid = false;
}