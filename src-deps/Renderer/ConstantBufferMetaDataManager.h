#pragma once

#include "Core/Utility/Singleton.h"

namespace mce
{
    class ConstantBufferMetaDataManager : public Singleton<ConstantBufferMetaDataManager>
    {
    public:
        ConstantBufferMetaDataManager();

    public:
        void getConstantBufferName() const;
    };
}