#include "StencilFaceDescription.h"

mce::StencilFaceDescription::StencilFaceDescription()
{
	stencilDepthFailOp = STENCIL_OP_KEEP;
	stencilFunc = COMPARISON_FUNC_ALWAYS;
	stencilPassOp = STENCIL_OP_KEEP;
	stencilFailOp = STENCIL_OP_KEEP;
}

bool mce::StencilFaceDescription::operator==(const mce::StencilFaceDescription& other) const
{
	return stencilFunc == other.stencilFunc &&
		   stencilDepthFailOp == other.stencilDepthFailOp &&
		   stencilPassOp == other.stencilPassOp &&
		   stencilFailOp == other.stencilFailOp;
}

bool mce::StencilFaceDescription::operator!=(const mce::StencilFaceDescription& other) const
{
	return !(*this == other);
}
