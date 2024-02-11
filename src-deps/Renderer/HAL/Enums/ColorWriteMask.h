#pragma once

namespace mce
{
	enum ColorWriteMask
	{
	  COLOR_WRITE_MASK_NONE = 0x0,
	  COLOR_WRITE_MASK_RED = 0x1,
	  COLOR_WRITE_MASK_GREEN = 0x2,
	  COLOR_WRITE_MASK_BLUE = 0x4,
	  COLOR_WRITE_MASK_ALPHA = 0x8,
	  COLOR_WRITE_MASK_ALL = 0xF,
	};
}