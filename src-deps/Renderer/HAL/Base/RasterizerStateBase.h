#pragma once

#include "RasterizerStateDescription.h"
#include "RenderContext.h"

namespace mce
{
	class RasterizerStateBase
	{
	public:
        RasterizerStateDescription m_description;
		
		RasterizerStateBase();
		
		void createRasterizerStateDescription(RenderContext& context, const RasterizerStateDescription& desc);
        bool bindRasterizerState(RenderContext& context);
		void setScissorRect(RenderContext &context, int x, int y, int width, int height) {}
	};
}
