#pragma once

#include "OGL/ConstantBufferContainerOGL.h"

namespace mce
{
    class ConstantBufferContainer : public ConstantBufferContainerOGL
    {
    public:
        ConstantBufferContainer();
        ConstantBufferContainer(ConstantBufferContainer&& other);

        void bindConstantBuffer(RenderContext& ctx, unsigned int, unsigned int);

        void sync(RenderContext& ctx);
        void allocateRenderContextBuffer(RenderContext& ctx);
        void registerReflectedShaderParameter(const UniformMetaData& uniMeta);
        void finalizeConstantBufferLayout();
        ShaderConstant* getUnspecializedShaderConstant(const std::string& name);
        bool isDirty() const;
        std::string getConstantBufferName() const;
    };
}