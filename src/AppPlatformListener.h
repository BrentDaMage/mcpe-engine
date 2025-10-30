#pragma once

#include "AppPlatform.h"

class AppPlatformListener
{
public:
    AppPlatformListener(bool doInit = true);

    virtual void onLowMemory() {}
    virtual void onAppResumed() {}
    virtual void onAppFocusLost() {}
    virtual void onAppFocusGained() {}
    virtual void onAppTerminated() {}
    virtual void onAppSuspended() {}

    void initListener(float priority);
    void terminate();

private:
    AppPlatform* m_pPlatform;
};
