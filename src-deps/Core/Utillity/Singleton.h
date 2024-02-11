#pragma once

#define LOG_INFO " @ " << __FUNC__ << " (" << __FILE__ << ":" << __LINE__ << ")"

namespace mce {

template <typename T>
class Singleton {

private:
    static T* instance;

public:
    Singleton()
    {
        if (instance != nullptr)
        {
            std::ostringstream oss;
            oss << "You attempted to create a singleton where one already exists" << LOG_INFO;
            __android_log_print(ANDROID_LOG_ERROR, "MinecraftPE", "%s", oss.str());
            return;
        }
        instance = static_cast<T*>(this);
    }

    static T* getInstance()
    {
        if (instance == nullptr)
        {
            std::ostringstream oss;
            oss << "The singleton instance doesn't exist" << LOG_INFO;
            __android_log_print(ANDROID_LOG_ERROR, "MinecraftPE", "%s", oss.str());
            return nullptr;
        }
        return instance;
    }
}

}