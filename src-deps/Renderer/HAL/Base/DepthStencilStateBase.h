#pragma once

#include "DepthStencilStateDescription.h"
#include "RenderContext.h"

namespace mce
{
	class DepthStencilStateBase
	{
	public:
        mce::DepthStencilStateDescription m_description;
		
		DepthStencilStateBase();
		
		void createDepthState(mce::RenderContext& context, const mce::DepthStencilStateDescription& desc);
        bool bindDepthStencilState(mce::RenderContext& context);
	};
}
