#include <typeinfo>

#include "TextureBase.h"

using namespace mce;

void TextureBase::convertToMipmapedTexture(unsigned int mipmaps)
{
    if (m_description.m_mipCount == mipmaps)
        return;
    
    if (m_description.m_filteringLevel == TEXTURE_FILTERING_BILINEAR)
    {
        //LOG_E("Unsupported filtering level for mip maps, please add the correct filtering case: " << m_description << m_filteringLevel);
        throw std::bad_cast();
    }

    m_description.m_filteringLevel = TEXTURE_FILTERING_MIPMAP_BILINEAR;
}
