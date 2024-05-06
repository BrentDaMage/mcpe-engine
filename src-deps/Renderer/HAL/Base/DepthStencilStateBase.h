#pragma once

#include "../DepthStencilStateDescription.h"
#include "../Interface/RenderContext.h"

namespace mce
{
	class DepthStencilStateBase
	{
	public:
        mce::DepthStencilStateDescription m_description;
		
		DepthStencilStateBase();
		
		virtual void createDepthState(mce::RenderContext& context, const mce::DepthStencilStateDescription& description);
        virtual bool bindDepthStencilState(mce::RenderContext& context);
	};
}
