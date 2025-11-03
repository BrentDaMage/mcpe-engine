#pragma once

namespace mce::Platform::OGL
{
    bool InitBindings();
    void* GetProcAddress(const char* name);
}