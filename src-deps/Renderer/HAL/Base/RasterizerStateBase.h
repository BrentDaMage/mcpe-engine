#pragma once

#include "../RasterizerStateDescription.h"
#include "../Interface/RenderContext.h"

namespace mce
{
	class RasterizerStateBase
	{
	public:
        mce::RasterizerStateDescription m_description;
		
		RasterizerStateBase();
		
		virtual void createRasterizerStateDescription(mce::RenderContext& context, const mce::RasterizerStateDescription& description);
        virtual bool bindRasterizerState(mce::RenderContext& context);
	};
}
