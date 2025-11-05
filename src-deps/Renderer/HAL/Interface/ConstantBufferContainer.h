#pragma once

#include "OGL/ConstantBufferContainerOGL.h"

namespace mce
{
    class ConstantBufferContainer : public ConstantBufferContainerOGL
    {
    public:
        ConstantBufferContainer();

        void bindConstantBuffer(RenderContext& context, unsigned int, unsigned int);

        void sync(RenderContext& context);
        void allocateRenderContextBuffer(RenderContext& context);
        void registerReflectedShaderParameter(const UniformMetaData& uniMeta);
        void finalizeConstantBufferLayout();
        ShaderConstant* getUnspecializedShaderConstant(const std::string& name);
        bool isDirty() const;
        std::string getConstantBufferName() const;
    };
}