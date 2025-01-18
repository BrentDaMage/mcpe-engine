#pragma once

#include "BlendTarget.h"
#include "ColorWriteMask.h"

namespace mce
{
	class BlendStateDescription
	{
	public:
		mce::BlendTarget blendSource;
		mce::BlendTarget blendDestination;
		mce::ColorWriteMask colorWriteMask;
		bool enableBlend;
		
		BlendStateDescription();
		
		bool operator==(const mce::BlendStateDescription& other) const;
		bool operator!=(const mce::BlendStateDescription& other) const;
	};
}
