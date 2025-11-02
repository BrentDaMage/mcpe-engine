#pragma once

#include <string>

#include "HAL/OGL/API_OGL.h"

namespace mce::Platform::OGL
{
    class Precision
    {
    public:
        static const std::string name, typeName;

    private:
        GLint m_precision[3];

    public:
        Precision(GLenum shaderType);
        
    protected:
        GLint _getPrecision(GLenum shaderType, GLenum precisionType);

    public:
        const std::string& atLeast(int atleast);
        void buildHeader(std::string& headerStream);
    };
}