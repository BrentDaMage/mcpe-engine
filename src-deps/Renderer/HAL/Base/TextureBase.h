#pragma once

#include "TextureDescription.h"

namespace mce
{
    class TextureBase
    {
    public:
        TextureDescription m_description;

    protected:
        bool m_bCreated;

    public:
        const TextureDescription& getDescription() const;
        void deleteTexture();
        bool isLoaded() const;
        void createTexture(const TextureDescription& description);
        void convertToMipmapedTexture(unsigned int mipmaps);
    };
}
