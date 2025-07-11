#pragma once

#include "Core/Utility/Singleton.h"

namespace mce
{
    class RenderDevice : public Singleton<RenderDevice>
    {
    public:
        RenderDevice();
    }
}