#pragma once

#include "CullMode.h"

namespace mce
{
	struct RasterizerStateDescription
	{
        float depthBias;
        CullMode cullMode;
        bool enableScissorTest;
	
		RasterizerStateDescription();

		bool operator==(const RasterizerStateDescription& other) const;
		bool operator!=(const RasterizerStateDescription& other) const;
	};
}
