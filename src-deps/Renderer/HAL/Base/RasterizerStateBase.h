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
		
		void createRasterizerStateDescription(RenderContext& ctx, const RasterizerStateDescription& desc);
		void setRasterizerStateDescription(RenderContext& ctx, const RasterizerStateDescription& desc);
        bool bindRasterizerState(RenderContext& ctx);
		void setScissorRect(RenderContext &context, int x, int y, int width, int height) {}
	};
}
