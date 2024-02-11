#pragma once

#include "Enums/BlendTarget.h"
#include "Enums/ColorWriteMask.h"

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
