#pragma once

#include "BlendStateDescription.h"
#include "RenderContext.h"

namespace mce
{
	class BlendStateBase
	{
	public:
        BlendStateDescription m_description;
		
		BlendStateBase();
		
		void createBlendState(RenderContext& context, const BlendStateDescription& desc);
        bool bindBlendState(RenderContext& context);
	};
}
