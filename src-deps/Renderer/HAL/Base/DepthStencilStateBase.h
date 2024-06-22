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
		
		void createDepthState(mce::RenderContext& ctx, const mce::DepthStencilStateDescription& desc);
        bool bindDepthStencilState(mce::RenderContext& ctx);
	};
}
