#pragma once

#include "../BlendStateDescription.h"
#include "../Interface/RenderContext.h"

namespace mce
{
	class BlendStateBase
	{
	public:
        mce::BlendStateDescription m_description;
		
		BlendStateBase();
		
		virtual void createBlendState(mce::RenderContext& context, const mce::BlendStateDescription& description);
        virtual bool bindBlendState(mce::RenderContext& context);
	};
}
