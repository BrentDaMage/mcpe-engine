#pragma once

#include "DepthStencilStateDescription.h"
#include "RenderContext.h"

namespace mce
{
	class DepthStencilStateBase
	{
	public:
        DepthStencilStateDescription m_description;
		
	public:
		DepthStencilStateBase();
		
	public:
		void createDepthState(RenderContext& context, const DepthStencilStateDescription& description);
        bool bindDepthStencilState(RenderContext& context);
	};
}
