#pragma once

#include "RasterizerStateDescription.h"
#include "RenderContext.h"

namespace mce
{
	class RasterizerStateBase
	{
	public:
        mce::RasterizerStateDescription m_description;
		
		RasterizerStateBase();
		
		void createRasterizerStateDescription(mce::RenderContext& ctx, const mce::RasterizerStateDescription& desc);
        bool bindRasterizerState(mce::RenderContext& ctx);
	};
}
