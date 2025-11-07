#pragma once

#include <string>

#include <windows.h>
#include <gl/GL.h>

// This file is actually titled "gl_header.h", but I like "API_OGL.h" better

namespace gl
{
    static bool hardwareOverideOpenGLES3;
    
    std::string getOpenGLVendor();
    std::string getOpenGLRenderer();
    std::string getOpenGLVersion();
    unsigned int getOpenGLMajorVersion();
    bool isOpenGLES3();
    int getMaxVertexCount();
    std::string getOpenGLExtensions();
    bool supportsMipmaps();
}