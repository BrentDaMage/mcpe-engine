#include "TextureDescription.h"

mce::TextureDescription::TextureDescription()
{
    unknown1 = 0;
    m_mipCount = 1;
    m_bUnknown2 = false;
    m_filteringLevel = TEXTURE_FILTERING_POINT;
    unknown3 = 0;
}