#include "TextureDescription.h"

using namespace mce;

TextureDescription::TextureDescription()
{
    unknown1 = 0;
    mipCount = 1;
    bUnknown2 = false;
    filteringLevel = TEXTURE_FILTERING_POINT;
    unknown3 = 0;
}