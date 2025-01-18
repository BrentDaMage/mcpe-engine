#pragma once

#include <vector>
#include <string>
#include "ShaderConstantBase.h"
#include "ShaderConstant.h"
#include "RenderContext.h"
#include "UniformMetaData.h"

namespace mce
{
    class ConstantBufferContainerBase
    {
    public:
        std::vector<mce::ShaderConstantBase> m_reflectedShaderConstants;
        std::vector<mce::ShaderConstant*> m_shaderConstants;
        std::vector<unsigned char> m_constantBufferBytes;
        std::string m_constantBufferName;
        bool m_currentlyMapped;

        ConstantBufferContainerBase();
        ConstantBufferContainerBase(mce::ConstantBufferContainerBase& other);

        void bindConstantBuffer(mce::RenderContext& ctx, unsigned int, unsigned int) { }

        void sync(mce::RenderContext& ctx) { }
        void allocateRenderContextBuffer(mce::RenderContext& ctx) { }
        void reserveMemoryForShaderConstants(unsigned int shaderConstSize, unsigned int constBufferSize);
        void registerReflectedShaderParameter(const mce::UniformMetaData& uniMeta);
        bool isDirty() const;
        const std::string& getConstantBufferName() const {return m_constantBufferName; }
    };
}