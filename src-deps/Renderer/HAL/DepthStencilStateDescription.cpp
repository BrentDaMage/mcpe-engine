#include "DepthStencilStateDescription.h"

mce::DepthStencilStateDescription::DepthStencilStateDescription()
{
    depthFunc = COMPARISON_FUNC_LESS;
    depthTestEnabled = true;
    stencilTestEnabled = false;
    frontFace = StencilFaceDescription();
    backFace = StencilFaceDescription();
    depthWriteMask = DEPTH_WRITE_MASK_ALL;

    stencilRef = StencilRefObject(0);
    overwroteStencilRef = false;
    stencilReadMask = 0xFFFFFFFF;
    stencilWriteMask = 0xFFFFFFFF;
}

bool mce::DepthStencilStateDescription::operator==(const mce::DepthStencilStateDescription& other) const
{
	return depthTestEnabled == other.depthTestEnabled &&
           frontFace == other.frontFace &&
		   backFace == other.backFace &&
		   depthWriteMask == other.depthWriteMask &&
		   stencilReadMask == other.stencilReadMask &&
           stencilWriteMask == other.stencilWriteMask &&
           stencilRef == other.stencilRef &&
           overwroteStencilRef == other.overwroteStencilRef;
}

bool mce::DepthStencilStateDescription::operator!=(const mce::DepthStencilStateDescription& other) const
{
	return !(*this == other);
}