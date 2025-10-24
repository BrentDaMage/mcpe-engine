#include "RenderDevice.h"
#include "RenderContext.h"

using namespace mce;

RenderDevice::RenderDevice()
{
    m_immediateContext = new RenderContext();
}

RenderDevice::~RenderDevice()
{
    if (m_immediateContext)
        delete m_immediateContext;
}

RenderContext& RenderDevice::getRenderContext()
{
    if (!m_immediateContext)
    {
        //LOG_E("Immediate context doesn't exist anymore!");
        throw std::bad_cast();
    }

    return *m_immediateContext;
}

const RenderContext& RenderDevice::getRenderContextAsConst() const
{
    if (!m_immediateContext)
    {
        //LOG_E("Immediate context doesn't exist anymore!");
        throw std::bad_cast();
    }

    return *m_immediateContext;
}