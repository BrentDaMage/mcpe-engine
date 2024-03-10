#include "ImageDescription.h"
#include "../Helpers/TextureHelper.h"

mce::ImageDescription::ImageDescription()
{
	m_width = 0;
	m_height = 0;
	bufferProbably = 0;
	m_textureFormat = TEXTURE_FORMAT_UNKNOWN;
}

int mce::ImageDescription::getSizeInBytes()
{
  uint32_t size = m_width * m_height;
  return mce::TextureHelper::textureFormatToByteStride(m_textureFormat) * size;
}
