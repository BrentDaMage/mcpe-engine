#pragma once

#include "OGL/ConstantBufferContainerOGL.h"

namespace mce
{
    class ConstantBufferContainer : public ConstantBufferContainerOGL
    {
    public:
        ConstantBufferContainer();
        ConstantBufferContainer(mce::ConstantBufferContainerBase& other);

        void bindConstantBuffer(mce::RenderContext& ctx, unsigned int, unsigned int);
        mce::ShaderConstant* getUnspecializedShaderConstant(const std::string& name);

        void sync(mce::RenderContext& ctx);
        void allocateRenderContextBuffer(mce::RenderContext& ctx);
        void registerReflectedShaderParameter(const mce::UniformMetaData& uniMeta);
        void finalizeConstantBufferLayout();
        bool isDirty() const;
        std::string getConstantBufferName() const;
    };
}