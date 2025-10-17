#pragma once

class AppPlatformListener
{
private:
    bool m_listenerRegistered = false;

public:
    AppPlatformListener()
    {
        initListener(1.0f);
    }

    virtual void onLowMemory() {}
    virtual void onAppResumed() {}
    virtual void onAppFocusLost() {}
    virtual void onAppFocusGained() {}
    virtual void onAppTerminated() {}
    virtual void onAppSuspended() {}

    void initListener(float unknown)
    {
        // todo
    }

    void terminate()
    {
        onAppFocusLost();
        m_listenerRegistered = false;
    }
};
