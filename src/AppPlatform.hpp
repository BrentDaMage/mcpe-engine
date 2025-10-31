#pragma once

#include <map>
#include <string>

class AppPlatformListener;
class AppPlatform
{
public:
    std::multimap<float, AppPlatformListener *> m_listeners;

    virtual std::string readAssetFile(const std::string&) const { return ""; }

    static AppPlatform* singleton() { return nullptr; }
};