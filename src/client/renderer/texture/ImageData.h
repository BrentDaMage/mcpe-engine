#pragma once

#include <string>
#include "ColorSpace.h"

struct ImageData
{
    unsigned int m_width;
    unsigned int m_height;
    std::string m_data;
    unsigned int m_mipCount;
    ColorSpace m_colorSpace;

    ImageData()
    {
        m_width = 0;
        m_height = 0;
        m_mipCount = 0;
        m_colorSpace = COLOR_SPACE_RGBA;
    }
};