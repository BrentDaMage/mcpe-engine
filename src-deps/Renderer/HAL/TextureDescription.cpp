#include "TextureDescription.h"

mce::TextureDescription::TextureDescription()
{
    unknown1 = 1;
    m_mipmapEnabled = 1;
    unknown2 = 0;
    m_filteringLevel = TEXTURE_FILTERING_POINT;
    unknown3 = 0;
}