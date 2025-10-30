#pragma once

#include "AppPlatformListener.hpp"
#include "HAL/Interface/Buffer.h"

namespace mce
{
    class QuadIndexBuffer : public AppPlatformListener
    {
    private:
        static QuadIndexBuffer* instance;

    private:
        Buffer m_globalBuffer;
        unsigned int m_capacity;
        uint8_t m_indexSize;

    public:
        QuadIndexBuffer();

    private:
        template <typename T>
        void _makeIndexBuffer(std::vector<T>& indices, unsigned int numQuads);

    public:
        void onAppTerminated() override;
        void onAppSuspended() override;

        Buffer& getGlobalQuadBuffer(RenderContext& context, unsigned int requiredCapacity, uint8_t& outIndexSize);
    };
}