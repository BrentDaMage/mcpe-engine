#pragma once

#include "Core/Utility/Singleton.h"
#include "RenderChunkConstants.h"
#include "WorldConstants.h"
#include "PerFrameConstants.h"
#include "EntityConstants.h"
#include "ShaderConstants.h"
#include "WeatherConstants.h"

namespace mce
{
    class GlobalConstantBuffers : public Singleton<GlobalConstantBuffers>
    {
    public:
        mce::RenderChunkConstants m_renderChunkConstants;
        mce::WorldConstants m_worldConstants;
        mce::PerFrameConstants m_perFrameConstants;
        mce::EntityConstants m_entityConstants;
        mce::ShaderConstants m_shaderConstants;
        mce::WeatherConstants m_weatherConstants;

    public:
        void init();
    };
}