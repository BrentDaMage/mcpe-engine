#include <typeinfo>

#include "TextureBase.h"

using namespace mce;

const TextureDescription& TextureBase::getDescription() const
{
    return m_description;
}

void TextureBase::deleteTexture()
{
    m_created = false;
}

bool TextureBase::isLoaded() const
{
    return m_created;
}

void TextureBase::createTexture(const TextureDescription& description)
{
    m_description = description;
}

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
