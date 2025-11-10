#include "Core/Utility/JsonParser.h"
#include "RenderState_JsonParser.h"

using namespace mce;

template <>
bool mce::parse<RenderState>(const rapidjson::Value& root, const std::string& name, RenderState& out)
{
    return parse<RenderState>(root, name, _renderStateMap, out);
}
