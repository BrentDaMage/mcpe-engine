#pragma once

#include <windows.h>

namespace mce::Platform::OGL
{
    bool InitBindings(); // technically returns a InitBindingsResult, but it's just Success and Failure
    void GetProcAddress(const char* name, PROC functionAddress); // calls wglGetProcAddress
}