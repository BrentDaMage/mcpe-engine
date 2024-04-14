#include "StencilRefObject.h"

mce::StencilRefObject::StencilRefObject(unsigned int ref)
{
    stencilRef = ref;
}

bool mce::StencilRefObject::operator==(const mce::StencilRefObject& other) const
{
	return stencilRef == other.stencilRef;
}

bool mce::StencilRefObject::operator!=(const mce::StencilRefObject& other) const
{
	return !(*this == other);
}