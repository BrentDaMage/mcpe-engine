#include "Extensions.h"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace mce::Platform;

bool OGL::InitBindings()
{
    bool result = true;

#ifdef _WIN32
    // @TODO: replace with contents of xglInit() from GLExt.cpp
#endif

    return result;
}

void* OGL::GetProcAddress(const char* name)
{
    void* result = nullptr;

#ifdef _WIN32
    result = (void*)wglGetProcAddress(name);
    if (result == nullptr)
    {
        HMODULE handle = GetModuleHandle(L"opengl32.dll");
        if (handle != NULL)
        {
            result = (void*)GetProcAddress(handle, name);
        }
    }
#endif

    return result;
}