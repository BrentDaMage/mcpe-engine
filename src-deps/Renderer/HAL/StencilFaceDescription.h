#pragma once

#include "ComparisonFunc.h"
#include "StencilOp.h"

namespace mce
{
	class StencilFaceDescription
	{
	public:
        mce::ComparisonFunc stencilFunc;
        mce::StencilOp stencilFailOp;
        mce::StencilOp stencilDepthFailOp;
        mce::StencilOp stencilPassOp;
		
		StencilFaceDescription();

		bool operator==(const mce::StencilFaceDescription& other) const;
		bool operator!=(const mce::StencilFaceDescription& other) const;
	};
}
