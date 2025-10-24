#pragma once

#include <string>

#include <windows.h>
#include <gl/GL.h>

namespace gl
{
    extern bool hardwareOverideOpenGLES3;
    
    std::string getOpenGLVendor();
    std::string getOpenGLRenderer();
    std::string getOpenGLVersion();
    unsigned int getOpenGLMajorVersion();
    bool isOpenGLES3();
    int getMaxVertexCount();
    std::string getOpenGLExtensions();
    bool supportsMipmaps();
}