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
        // confirmed std::vector<ShaderConstantBase>
        std::vector<ShaderConstantBase> m_reflectedShaderConstants;
        // confirmed std::vector<std::unique_ptr<ShaderConstant>>
        std::vector<ShaderConstant*> m_shaderConstants;
        std::vector<uint8_t> m_constantBufferBytes;
        std::string m_constantBufferName;
        bool m_currentlyMapped;

    private:
        void _init();
    public:
        ConstantBufferContainerBase() { _init(); }
        ConstantBufferContainerBase(ConstantBufferContainerBase&& other);

        void bindConstantBuffer(RenderContext& ctx, unsigned int, unsigned int) { }

        void sync(RenderContext& ctx) { }
        void allocateRenderContextBuffer(RenderContext& ctx) { }
        void reserveMemoryForShaderConstants(unsigned int shaderConstSize, unsigned int constBufferSize);
        void registerReflectedShaderParameter(const UniformMetaData& uniMeta);
        void registerShaderParameter(const ShaderConstantBase &shaderConst);
        void finalizeConstantBufferLayout();
        // gets inlined in ConstantBufferContainer::getUnspecializedShaderConstant
        ShaderConstant* getUnspecializedShaderConstant(const std::string& name)
        {
            for (std::vector<ShaderConstant*>::iterator it = m_shaderConstants.begin(); it != m_shaderConstants.end(); it++)
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