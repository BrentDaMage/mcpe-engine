#include "TextureBase.h"

#include <typeinfo>

using namespace mce;

void TextureBase::createTexture(const TextureDescription& description)
{
    m_description = description;
}

void TextureBase::convertToMipmapedTexture(unsigned int mipmapEnabled)
{
    if (m_description.m_mipmapEnabled == mipmapEnabled)
        return;
    
    if (m_description.m_filteringLevel == TEXTURE_FILTERING_BILINEAR)
    {
        //LOG_E("Unsupported filtering level for mip maps, please add the correct filtering case: " << m_description << m_filteringLevel);
        std::bad_cast();
    }

    m_description.m_filteringLevel = TEXTURE_FILTERING_MIPMAP_BILINEAR;
}
