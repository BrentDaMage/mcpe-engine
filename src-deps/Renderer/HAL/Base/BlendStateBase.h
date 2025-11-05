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
		
		void createBlendState(mce::RenderContext& context, const mce::BlendStateDescription& desc);
        bool bindBlendState(mce::RenderContext& context);
	};
}
