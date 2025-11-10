#include <map>
#include <string>
#include "RenderState.h"

namespace mce
{
    const std::map<std::string, RenderState> _renderStateMap = {
        {"DisableDepthTest", RS_DISABLE_DEPTH_TEST},
        {"Blending", RS_BLENDING},
        {"PolygonOffset", RS_POLYGON_OFFSET},
        {"DisableCulling", RS_DISABLE_CULLING},
        {"DisableColorWrite", RS_DISABLE_COLOR_WRITE},
        {"DisableDepthWrite", RS_DISABLE_DEPTH_WRITE},
        {"StencilWrite", RS_STENCIL_WRITE},
        {"InvertCulling", RS_INVERT_CULLING},
        {"EnableStencilTest", RS_ENABLE_STENCIL_TEST},
    };
}