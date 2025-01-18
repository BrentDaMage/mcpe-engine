#pragma once

#include "BlendStateDescription.h"
#include "RenderContext.h"

namespace mce
{
	class BlendStateBase
	{
	public:
        mce::BlendStateDescription m_description;
		
		BlendStateBase();
		
		void createBlendState(mce::RenderContext& ctx, const mce::BlendStateDescription& desc);
        bool bindBlendState(mce::RenderContext& ctx);
	};
}
