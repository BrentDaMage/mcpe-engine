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
        // confirmed std::vector<mce::ShaderConstantBase>
        std::vector<mce::ShaderConstantBase> m_reflectedShaderConstants;
        // confirmed std::vector<std::unique_ptr<mce::ShaderConstant>>
        std::vector<mce::ShaderConstant*> m_shaderConstants;
        std::vector<uint8_t> m_constantBufferBytes;
        std::string m_constantBufferName;
        bool m_currentlyMapped;

    private:
        void _init();
    public:
        ConstantBufferContainerBase() { _init(); }
        ConstantBufferContainerBase(mce::ConstantBufferContainerBase& other);

        void bindConstantBuffer(mce::RenderContext& ctx, unsigned int, unsigned int) { }

        void sync(mce::RenderContext& ctx) { }
        void allocateRenderContextBuffer(mce::RenderContext& ctx) { }
        void reserveMemoryForShaderConstants(unsigned int shaderConstSize, unsigned int constBufferSize);
        void registerReflectedShaderParameter(const mce::UniformMetaData& uniMeta);
        void registerShaderParameter(const mce::ShaderConstantBase &shaderConst);
        void finalizeConstantBufferLayout();
        // gets inlined in mce::ConstantBufferContainer::getUnspecializedShaderConstant
        mce::ShaderConstant* getUnspecializedShaderConstant(const std::string& name)
        {
            for (std::vector<mce::ShaderConstant*>::iterator it = m_shaderConstants.begin(); it != m_shaderConstants.end(); it++)
            {
                if ((*it)->getName() == name)
                {
                    return *it;
                }
            }

            return nullptr;
        }
        bool isDirty() const;
        std::string getConstantBufferName() const { return m_constantBufferName; }
    };
}