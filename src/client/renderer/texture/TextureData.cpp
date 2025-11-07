#include "TextureData.h"
#include "Util.hpp"
#include "Renderer/RenderContextImmediate.h"

void TextureData::_init()
{
    m_bEnableFiltering = false;
    m_bWrap = false;
}

TextureData::TextureData()
{
    _init();
}

TextureData::TextureData(TextureData&& other)
{
    _init();
    _move(other);
}

TextureData::TextureData(unsigned int width, unsigned int height, bool enableFiltering)
{
    _init();

    m_imageData.m_width = width;
    m_imageData.m_height = height;
    m_imageData.m_colorSpace = COLOR_SPACE_RGBA;
    m_imageData.m_data.resize(4 * height * width);

    m_bEnableFiltering = enableFiltering;
}

TextureData::~TextureData()
{
    unload();
}

void TextureData::_move(TextureData& other)
{
    this->m_bEnableFiltering = other.m_bEnableFiltering;
    this->m_imageData.m_height = other.m_imageData.m_height;
    this->m_imageData.m_mipCount = other.m_imageData.m_mipCount;
    this->m_imageData.m_width = other.m_imageData.m_width;
    this->m_imageData.m_data.swap(other.m_imageData.m_data);
    this->m_texture = other.m_texture;
    this->m_imageData.m_colorSpace = other.m_imageData.m_colorSpace;
    this->m_imageData.m_mipCount = other.m_imageData.m_mipCount;
}

void TextureData::_loadTexData(mce::Texture& texture, bool enableFiltering, bool wrap)
{
    unsigned int width = m_imageData.m_width;
    unsigned int height = m_imageData.m_height;
    ColorSpace colorSpace = m_imageData.m_colorSpace;
    
    mce::TextureDescription desc;
    desc.filteringLevel = enableFiltering ? mce::TEXTURE_FILTERING_BILINEAR : mce::TEXTURE_FILTERING_POINT;
    desc.bWrap = wrap;
    desc.width = width;
    desc.height = height;

    uint8_t* rgbaData = nullptr;

    if (colorSpace == COLOR_SPACE_RGBA)
    {
        desc.textureFormat = mce::TEXTURE_FORMAT_R8G8B8A8_UNORM;
    }
    else if (colorSpace == COLOR_SPACE_RGB)
    {
        desc.textureFormat = mce::TEXTURE_FORMAT_R8G8B8A8_UNORM;
        
        unsigned int size = height * width;
        uint8_t* rgbData = (uint8_t*)m_imageData.m_data.data();
        rgbaData = new uint8_t[4 * height * width];

        // translate RGB buffer into RGBA buffer
        uint8_t* rgbDataEnd = &rgbData[3 * size];
        while (rgbData != rgbDataEnd)
        {
            rgbaData[0] = rgbData[0]; // red
            rgbaData[1] = rgbData[1]; // green
            rgbaData[2] = rgbData[2]; // blue
            rgbaData[3] = -1;         // alpha

            rgbData += 3;
            rgbaData += 4;
        }
    }

    if (!texture.isLoaded())
    {
        texture.createTexture(mce::RenderContextImmediate::get(), desc);
    }

    if (rgbaData)
    {
        texture.subBuffer(mce::RenderContextImmediate::get(), rgbaData);
        delete[] rgbaData;
    }
    else
    {
        texture.subBuffer(mce::RenderContextImmediate::get(), m_imageData.m_data.data());
    }
}

void TextureData::_loadMipmap(ImageData& data)
{
    if (data.m_colorSpace == COLOR_SPACE_RGB)
    {
        //LOG_E("Functionality for mips and non RGBA textures isn't supported yet");
        throw std::bad_cast();
    }

    m_texture.convertToMipmapedTexture(mce::RenderContextImmediate::get(), 5);
    m_texture.loadMipMap(mce::RenderContextImmediate::get(), data.m_data.data(), data.m_mipCount);
}

void TextureData::unload()
{
    m_texture.deleteTexture();
}

void TextureData::clear()
{
    unload();
    m_imageData.m_data = Util::EMPTY_STRING;
}

void TextureData::bind(unsigned int textureUnit)
{
    if (m_texture.isLoaded() && lastBoundTexture[textureUnit] != this )
    {
        lastBoundTexture[textureUnit] = this;
        m_texture.bindTexture(mce::RenderContextImmediate::get(), textureUnit);
    }
}

void TextureData::sync()
{
    if (m_texture.isLoaded())
    {
        _loadTexData(m_texture, m_bEnableFiltering, m_bWrap);
    }
}

void TextureData::setData(const std::string& data)
{
    m_imageData.m_data = data;
    sync();
}

void TextureData::load()
{
    _loadTexData(m_texture, m_bEnableFiltering, m_bWrap);
    for (int i = 0; i < m_mipmaps.size(); i++)
    {
        _loadMipmap(m_mipmaps[i]);
    }
}

void TextureData::loadMipmap(ImageData& data)
{
    _loadMipmap(data);
    m_mipmaps.push_back(data);
}

void TextureData::operator=(TextureData&& other)
{
    unload();
    _move(other);
}

void TextureData::unbind(unsigned int textureUnit)
{
    lastBoundTexture[textureUnit] = nullptr;
}