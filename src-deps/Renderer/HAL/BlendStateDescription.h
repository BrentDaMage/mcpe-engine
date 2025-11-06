#pragma once

#include "BlendTarget.h"
#include "ColorWriteMask.h"

namespace mce
{
	struct BlendStateDescription
	{
		BlendTarget blendSource;
		BlendTarget blendDestination;
		ColorWriteMask colorWriteMask;
		bool enableBlend;
		
		BlendStateDescription();
		
		bool operator==(const BlendStateDescription& other) const;
		bool operator!=(const BlendStateDescription& other) const;
	};
}
