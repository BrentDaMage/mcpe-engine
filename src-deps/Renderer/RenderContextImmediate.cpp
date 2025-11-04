#include "HAL/Interface/RenderDevice.h"
#include "RenderContextImmediate.h"

using namespace mce;

RenderContext& RenderContextImmediate::get()
{
    return RenderDevice::getInstance().getRenderContext();
}

const RenderContext& RenderContextImmediate::getAsConst()
{
    return RenderDevice::getInstance().getRenderContextAsConst();
}