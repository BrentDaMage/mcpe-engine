#pragma once

#include "Enums/CullMode.h"

namespace mce
{
	class RasterizerStateDescription
	{
	public:
        float depthBias;
        mce::CullMode cullMode;
        bool enableScissorTest;
		
		RasterizerStateDescription();

		bool operator==(const mce::RasterizerStateDescription& other) const;
		bool operator!=(const mce::RasterizerStateDescription& other) const;
	};
}
