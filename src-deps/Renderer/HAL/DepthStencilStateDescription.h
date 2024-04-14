#pragma once

#include "StencilFaceDescription.h"
#include "../StencilRefObject.h"
#include "Enums/ComparisonFunc.h"
#include "Enums/DepthWriteMask.h"

namespace mce
{
	class DepthStencilStateDescription
	{
	public:
        bool depthTestEnabled;
        bool stencilTestEnabled;
        mce::ComparisonFunc depthFunc;
        mce::StencilFaceDescription frontFace;
        mce::StencilFaceDescription backFace;
        mce::DepthWriteMask depthWriteMask;
        unsigned int stencilReadMask;
        unsigned int stencilWriteMask;
        mce::StencilRefObject stencilRef;
        bool overwroteStencilRef;
		
		DepthStencilStateDescription();

		bool operator==(const mce::DepthStencilStateDescription& other) const;
		bool operator!=(const mce::DepthStencilStateDescription& other) const;
	};
}
