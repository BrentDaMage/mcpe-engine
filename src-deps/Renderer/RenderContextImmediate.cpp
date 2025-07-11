#include "HAL/Interface/RenderDevice.h"
#include "RenderContextImmediate.h"

mce::RenderContext& mce::RenderContextImmediate::get()
{
    return *(mce::RenderDevice::getInstance()->getRenderContext());
}

const mce::RenderContext& mce::RenderContextImmediate::getAsConst()
{
    return *(mce::RenderDevice::getInstance()->getRenderContextAsConst());
}