#include "ImageDescription.h"
#include "TextureHelper.h"

using namespace mce;

ImageDescription::ImageDescription()
{
	m_width = 0;
	m_height = 0;
	m_pixels = nullptr;
	m_textureFormat = TEXTURE_FORMAT_UNKNOWN;
}

unsigned int ImageDescription::getSizeInBytes() const
{
	uint32_t size = m_width * m_height;
	return TextureHelper::textureFormatToByteStride(m_textureFormat) * size;
}
