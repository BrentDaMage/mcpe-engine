#include "Core/Utility/JsonParser.h"
#include "StencilOp.h"

using namespace mce;

const std::map<std::string, StencilOp> _stencilOpMap = {
    {"Keep", STENCIL_OP_KEEP},
    {"Replace", STENCIL_OP_REPLACE}
};

template <>
bool mce::parse<StencilOp>(const rapidjson::Value& root, const std::string& name, StencilOp& out)
{
    return parse<StencilOp>(root, name, _stencilOpMap, out);
}
