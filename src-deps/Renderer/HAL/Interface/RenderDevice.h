#pragma once

#include "Core/Utility/Singleton.h"
#include "OGL/RenderDeviceOGL.h"

namespace mce
{
    class RenderDevice : public RenderDeviceOGL, Singleton<RenderDevice>
    {
    public:
        RenderContext *m_immediateContext;

    public:
        RenderDevice();
        ~RenderDevice();

    public:
        RenderContext& getRenderContext();
        const RenderContext& getRenderContextAsConst() const;
    };
}