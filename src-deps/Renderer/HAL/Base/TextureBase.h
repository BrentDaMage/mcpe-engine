#pragma once

#include "TextureDescription.h"

namespace mce
{

class TextureBase
{
public:
    TextureDescription m_description;

private:
    bool m_created;

public:
    void getDescription() { }
    void deleteTexture() { m_created = false; }
    bool isLoaded() { return m_created; }
    void createTexture(const TextureDescription& description) { m_description = description; }
    void convertToMipmapedTexture(unsigned int mipmaps);
};

}
