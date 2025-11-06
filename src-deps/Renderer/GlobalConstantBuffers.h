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
        RenderChunkConstants m_renderChunkConstants;
        WorldConstants m_worldConstants;
        PerFrameConstants m_perFrameConstants;
        EntityConstants m_entityConstants;
        ShaderConstants m_shaderConstants;
        WeatherConstants m_weatherConstants;

    public:
        void init();
    };
}