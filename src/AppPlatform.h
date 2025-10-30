#pragma once

#include <map>

class AppPlatformListener;
class AppPlatform
{
public:
    std::multimap<float, AppPlatformListener *> m_listeners;

    static AppPlatform* singleton() { return nullptr; }
};