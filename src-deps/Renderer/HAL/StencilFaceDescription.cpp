#include "StencilFaceDescription.h"

mce::StencilFaceDescription::StencilFaceDescription()
{
    stencilFailOp = STENCIL_OP_KEEP;
    stencilFunc = COMPARISON_FUNC_ALWAYS;
    stencilDepthFailOp = STENCIL_OP_KEEP;
    stencilPassOp = STENCIL_OP_KEEP;
}

bool mce::StencilFaceDescription::operator==(const mce::StencilFaceDescription& other) const
{
	return stencilFunc == other.stencilFunc &&
		   stencilFailOp == other.stencilFailOp &&
		   stencilDepthFailOp == other.stencilDepthFailOp &&
		   stencilPassOp == other.stencilPassOp;
}

bool mce::StencilFaceDescription::operator!=(const mce::StencilFaceDescription& other) const
{
	return !(*this == other);
}
