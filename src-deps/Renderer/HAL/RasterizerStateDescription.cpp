#include "RasterizerStateDescription.h"

mce::RasterizerStateDescription::RasterizerStateDescription()
{
    depthBias = 0.0;
    cullMode = CULL_BACK;
    enableScissorTest = 0;
}

bool mce::RasterizerStateDescription::operator==(const mce::RasterizerStateDescription& other) const
{
	return depthBias == other.depthBias &&
		   cullMode == other.cullMode;
}

bool mce::RasterizerStateDescription::operator!=(const mce::RasterizerStateDescription& other) const
{
	return !(*this == other);
}
