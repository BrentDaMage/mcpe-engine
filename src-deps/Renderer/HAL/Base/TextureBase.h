#pragma once

#include "TextureDescription.h"

namespace mce
{

class TextureBase {
private:
    TextureDescription m_description;
    bool m_created;

public:
    void getDescription() { }
    void deleteTexture() { m_created = false; }
    bool isLoaded() { return m_created; }
    void createTexture(const TextureDescription& description);
    void convertToMipmapedTexture(unsigned int mipmapEnabled);
};

}
