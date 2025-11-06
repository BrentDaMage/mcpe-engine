#include "Singleton.h"

using namespace mce;

template <typename T>
T* Singleton<T>::instance = nullptr;