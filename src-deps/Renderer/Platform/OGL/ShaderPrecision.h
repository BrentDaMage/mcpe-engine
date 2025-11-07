#pragma once

#include <string>

#include "HAL/OGL/API_OGL.h"

namespace mce
{
    namespace Platform
    {
        namespace OGL
        {
            class Precision
            {
            public:
                static const std::string name[3];
                static const std::string typeName[3];

            private:
                GLint m_precision[3];

            public:
                Precision(GLenum shaderType);

            private:
                GLint _getPrecision(GLenum shaderType, GLenum precisionType);

            public:
                static const std::string& atLeast(int atleast);
                static std::string buildHeader();
            };
        }
    }
}